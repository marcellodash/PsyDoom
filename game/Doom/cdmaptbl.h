#pragma once

#include "Wess/psxcd.h"

//------------------------------------------------------------------------------------------------------------------------------------------
// A list of file ids representing files on the disc.
// These ids are used when opening files for IO, to index a table of harcoded file locations, rather than strings.
// The retail version of the game uses this mechanism for efficiency rather than needing to consult the filesystem.
//
// Note: depending on the game (Doom vs Final Doom) not all of these files will be present or available.
//------------------------------------------------------------------------------------------------------------------------------------------
enum class CdFileId : int32_t {
    SYSTEM_CNF,
    SLUS_000_77,
    DEMO1_LMP,
    DEMO2_LMP,
    MAPSPR60_IMG,
    MOVIE_STR,
    PSXDOOM_EXE,
    PSXDOOM_WAD,
    MAP01_WAD,
    MAP02_WAD,
    MAP03_WAD,
    MAP04_WAD,
    MAP05_WAD,
    MAP06_WAD,
    MAP07_WAD,
    MAP08_WAD,
    MAPSPR01_IMG,
    MAPSPR02_IMG,
    MAPSPR03_IMG,
    MAPSPR04_IMG,
    MAPSPR05_IMG,
    MAPSPR06_IMG,
    MAPSPR07_IMG,
    MAPSPR08_IMG,
    MAPTEX01_IMG,
    MAPTEX02_IMG,
    MAPTEX03_IMG,
    MAPTEX04_IMG,
    MAPTEX05_IMG,
    MAPTEX06_IMG,
    MAPTEX07_IMG,
    MAPTEX08_IMG,
    MAP09_WAD,
    MAP10_WAD,
    MAP11_WAD,
    MAP12_WAD,
    MAP13_WAD,
    MAP14_WAD,
    MAP15_WAD,
    MAP16_WAD,
    MAPSPR09_IMG,
    MAPSPR10_IMG,
    MAPSPR11_IMG,
    MAPSPR12_IMG,
    MAPSPR13_IMG,
    MAPSPR14_IMG,
    MAPSPR15_IMG,
    MAPSPR16_IMG,
    MAPTEX09_IMG,
    MAPTEX10_IMG,
    MAPTEX11_IMG,
    MAPTEX12_IMG,
    MAPTEX13_IMG,
    MAPTEX14_IMG,
    MAPTEX15_IMG,
    MAPTEX16_IMG,
    MAP17_WAD,
    MAP18_WAD,
    MAP19_WAD,
    MAP20_WAD,
    MAP21_WAD,
    MAP22_WAD,
    MAP23_WAD,
    MAP24_WAD,
    MAPSPR17_IMG,
    MAPSPR18_IMG,
    MAPSPR19_IMG,
    MAPSPR20_IMG,
    MAPSPR21_IMG,
    MAPSPR22_IMG,
    MAPSPR23_IMG,
    MAPSPR24_IMG,
    MAPTEX17_IMG,
    MAPTEX18_IMG,
    MAPTEX19_IMG,
    MAPTEX20_IMG,
    MAPTEX21_IMG,
    MAPTEX22_IMG,
    MAPTEX23_IMG,
    MAPTEX24_IMG,
    MAP25_WAD,
    MAP26_WAD,
    MAP27_WAD,
    MAP28_WAD,
    MAP29_WAD,
    MAP30_WAD,
    MAP31_WAD,
    MAP32_WAD,
    MAPSPR25_IMG,
    MAPSPR26_IMG,
    MAPSPR27_IMG,
    MAPSPR28_IMG,
    MAPSPR29_IMG,
    MAPSPR30_IMG,
    MAPSPR31_IMG,
    MAPSPR32_IMG,
    MAPTEX25_IMG,
    MAPTEX26_IMG,
    MAPTEX27_IMG,
    MAPTEX28_IMG,
    MAPTEX29_IMG,
    MAPTEX30_IMG,
    MAPTEX31_IMG,
    MAPTEX32_IMG,
    MAP33_WAD,
    MAP34_WAD,
    MAP35_WAD,
    MAP36_WAD,
    MAP37_WAD,
    MAP38_WAD,
    MAP39_WAD,
    MAP40_WAD,
    MAPSPR33_IMG,
    MAPSPR34_IMG,
    MAPSPR35_IMG,
    MAPSPR36_IMG,
    MAPSPR37_IMG,
    MAPSPR38_IMG,
    MAPSPR39_IMG,
    MAPSPR40_IMG,
    MAPTEX33_IMG,
    MAPTEX34_IMG,
    MAPTEX35_IMG,
    MAPTEX36_IMG,
    MAPTEX37_IMG,
    MAPTEX38_IMG,
    MAPTEX39_IMG,
    MAPTEX40_IMG,
    MAP41_WAD,
    MAP42_WAD,
    MAP43_WAD,
    MAP44_WAD,
    MAP45_WAD,
    MAP46_WAD,
    MAP47_WAD,
    MAP48_WAD,
    MAPSPR41_IMG,
    MAPSPR42_IMG,
    MAPSPR43_IMG,
    MAPSPR44_IMG,
    MAPSPR45_IMG,
    MAPSPR46_IMG,
    MAPSPR47_IMG,
    MAPSPR48_IMG,
    MAPTEX41_IMG,
    MAPTEX42_IMG,
    MAPTEX43_IMG,
    MAPTEX44_IMG,
    MAPTEX45_IMG,
    MAPTEX46_IMG,
    MAPTEX47_IMG,
    MAPTEX48_IMG,
    MAP49_WAD,
    MAP50_WAD,
    MAP51_WAD,
    MAP52_WAD,
    MAP53_WAD,
    MAP54_WAD,
    MAP55_WAD,
    MAP56_WAD,
    MAPSPR49_IMG,
    MAPSPR50_IMG,
    MAPSPR51_IMG,
    MAPSPR52_IMG,
    MAPSPR53_IMG,
    MAPSPR54_IMG,
    MAPSPR55_IMG,
    MAPSPR56_IMG,
    MAPTEX49_IMG,
    MAPTEX50_IMG,
    MAPTEX51_IMG,
    MAPTEX52_IMG,
    MAPTEX53_IMG,
    MAPTEX54_IMG,
    MAPTEX55_IMG,
    MAPTEX56_IMG,
    MAP57_WAD,
    MAP58_WAD,
    MAP59_WAD,
    MAP60_PAD,
    MAP61_PAD,
    MAP62_PAD,
    MAP63_PAD,
    MAP64_PAD,
    MAPSPR57_IMG,
    MAPSPR58_IMG,
    MAPSPR59_IMG,
    MAPSPR60_PAD,
    MAPSPR61_PAD,
    MAPSPR62_PAD,
    MAPSPR63_PAD,
    MAPSPR64_PAD,
    MAPTEX57_IMG,
    MAPTEX58_IMG,
    MAPTEX59_IMG,
    MAPTEX60_PAD,
    MAPTEX61_PAD,
    MAPTEX62_PAD,
    MAPTEX63_PAD,
    MAPTEX64_PAD,
    DOOMSFX_LCD,
    DOOMSND_WMD,
    MUSLEV1_LCD,
    MUSLEV10_LCD,
    MUSLEV11_LCD,
    MUSLEV12_LCD,
    MUSLEV13_LCD,
    MUSLEV14_LCD,
    MUSLEV15_LCD,
    MUSLEV16_LCD,
    MUSLEV17_LCD,
    MUSLEV18_LCD,
    MUSLEV19_LCD,
    MUSLEV2_LCD,
    MUSLEV20_LCD,
    MUSLEV3_LCD,
    MUSLEV4_LCD,
    MUSLEV5_LCD,
    MUSLEV6_LCD,
    MUSLEV7_LCD,
    MUSLEV8_LCD,
    MUSLEV9_LCD,
    MAP01_LCD,
    MAP02_LCD,
    MAP03_LCD,
    MAP04_LCD,
    MAP05_LCD,
    MAP06_LCD,
    MAP07_LCD,
    MAP08_LCD,
    MAP09_LCD,
    MAP10_LCD,
    MAP11_LCD,
    MAP12_LCD,
    MAP13_LCD,
    MAP14_LCD,
    MAP15_LCD,
    MAP16_LCD,
    MAP17_LCD,
    MAP18_LCD,
    MAP19_LCD,
    MAP20_LCD,
    MAP21_LCD,
    MAP22_LCD,
    MAP23_LCD,
    MAP24_LCD,
    MAP25_LCD,
    MAP26_LCD,
    MAP27_LCD,
    MAP28_LCD,
    MAP29_LCD,
    MAP30_LCD,
    MAP31_LCD,
    MAP32_LCD,
    MAP33_LCD,
    MAP34_LCD,
    MAP35_LCD,
    MAP36_LCD,
    MAP37_LCD,
    MAP38_LCD,
    MAP39_LCD,
    MAP40_LCD,
    MAP41_LCD,
    MAP42_LCD,
    MAP43_LCD,
    MAP44_LCD,
    MAP45_LCD,
    MAP46_LCD,
    MAP47_LCD,
    MAP48_LCD,
    MAP49_LCD,
    MAP50_LCD,
    MAP51_LCD,
    MAP52_LCD,
    MAP53_LCD,
    MAP54_LCD,
    MAP55_LCD,
    MAP56_LCD,
    MAP57_LCD,
    MAP58_LCD,
    MAP59_LCD,
    MAP60_LCD,
    // Final Doom specific
    MAP01_ROM,
    MAP02_ROM,
    MAP03_ROM,
    MAP04_ROM,
    MAP05_ROM,
    MAP06_ROM,
    MAP07_ROM,
    MAP08_ROM,
    MAP09_ROM,
    MAP10_ROM,
    MAP11_ROM,
    MAP12_ROM,
    MAP13_ROM,
    MAP14_ROM,
    MAP15_ROM,
    MAP16_ROM,
    MAP17_ROM,
    MAP18_ROM,
    MAP19_ROM,
    MAP20_ROM,
    MAP21_ROM,
    MAP22_ROM,
    MAP23_ROM,
    MAP24_ROM,
    MAP25_ROM,
    MAP26_ROM,
    MAP27_ROM,
    MAP28_ROM,
    MAP29_ROM,
    MAP30_ROM,
    MAP31_ROM,
    MAP32_ROM,
    END             // Note: not an actual entry, used as an end of list marker
};

// A list of all the files in the game, their start sector on the CD and size.
// This table can be indexed by using the enum above:
extern PsxCd_MapTblEntry gCdMapTbl[(uint32_t) CdFileId::END];

#if PC_PSX_DOOM_MODS
    extern const char* const gCdMapTblFileNames[(uint32_t) CdFileId::END];      // The names of all the files in the CD map table
    extern const char* const gCdMapTblFilePaths[(uint32_t) CdFileId::END];      // The paths of all the files in the CD map table

    void CdMapTbl_Init() noexcept;
#endif
