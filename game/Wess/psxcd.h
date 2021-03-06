#pragma once

#include "PsyQ/LIBCD.h"

enum class CdFileId : int32_t;

// Number of bytes in a CD-ROM sector
static constexpr int32_t CD_SECTOR_SIZE = 2048;

// Tracks an open file on the CD-ROM.
// Contains info about the file as well as the current IO location and status.
// PC-PSX: this data structure was completely changed. See the 'old' folder for the original version.
struct PsxCd_File {
    int32_t     size;                   // How big the file is in bytes
    int32_t     startSector;            // Which 2,048 byte disc sector the file starts on
    int32_t     fileHandle;             // Handle to an open file on the game disc
    int32_t     overrideFileHandle;     // Handle to a host machine file which overrides this file on the original game disc; allows user mods/overrides of files
};

// Seek mode for seeking: similar to the C standard library seek modes
enum class PsxCd_SeekMode : int32_t {
    SET = 0,    // Set the offset
    CUR = 1,    // Seek relative to the current position
    END = 2     // Seek relative to the end
};

// Stores the location and size of a file on the CD-ROM.
// Used by the retail version of the game for fast file access, presumably not used during development as that would be painful.
// The location is stored in terms of start sector (2048 byte sector) number.
struct PsxCd_MapTblEntry {
    int32_t     startSector;    // PC-PSX: if this is '0' then it means the file is not present on the disc
    int32_t     size;
};

// Sector buffer for when we are reading data
extern uint8_t gPSXCD_sectorbuf[CD_SECTOR_SIZE];

void PSXCD_cbcomplete(const CdlSyncStatus status, const uint8_t pResult[8]) noexcept;
void PSXCD_cbready(const CdlSyncStatus status, const uint8_t pResult[8]) noexcept;
void psxcd_disable_callbacks() noexcept;
void psxcd_enable_callbacks() noexcept;
void psxcd_init() noexcept;
void psxcd_exit() noexcept;
void psxcd_set_data_mode() noexcept;
PsxCd_File* psxcd_open(const CdFileId discFile) noexcept;
bool psxcd_seeking_for_play() noexcept;
bool psxcd_waiting_for_pause() noexcept;
int32_t psxcd_read(void* const pDest, int32_t numBytes, PsxCd_File& file) noexcept;
int32_t psxcd_seek(PsxCd_File& file, int32_t offset, const PsxCd_SeekMode mode) noexcept;
int32_t psxcd_tell(const PsxCd_File& file) noexcept;
void psxcd_close(PsxCd_File& file) noexcept;
void psxcd_set_audio_mode() noexcept;
void psxcd_set_loop_volume(const int32_t vol) noexcept;

void psxcd_play_at_andloop(
    const int32_t track,
    const int32_t vol,
    const int32_t sectorOffset,
    const int32_t fadeUpTime,
    const int32_t loopTrack,
    const int32_t loopVol,
    const int32_t loopSectorOffest,
    const int32_t loopFadeUpTime
) noexcept;

void psxcd_play_at(const int32_t track, const int32_t vol, const int32_t sectorOffset) noexcept;
void psxcd_play(const int32_t track, const int32_t vol) noexcept;
void psxcd_seek_for_play_at(const int32_t track, const int32_t sectorOffset) noexcept;
void psxcd_seek_for_play(const int32_t track) noexcept;
bool psxcd_play_status() noexcept;
void psxcd_stop() noexcept;
void psxcd_pause() noexcept;
void psxcd_restart(const int32_t vol) noexcept;
int32_t psxcd_elapsed_sectors() noexcept;
void psxcd_set_stereo(const bool bStereo) noexcept;

#if PC_PSX_DOOM_MODS
    int32_t psxcd_get_file_size(const CdFileId discFile) noexcept;
#endif