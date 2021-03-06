#include "Utils.h"

#include "Doom/Game/p_tick.h"
#include "FatalErrors.h"
#include "Input.h"
#include "Network.h"
#include "ProgArgs.h"
#include "PsxVm.h"
#include "Video.h"
#include "Wess/psxcd.h"
#include "Wess/psxspu.h"

#include <chrono>
#include <SDL.h>
#include <thread>

BEGIN_NAMESPACE(Utils)

static constexpr const char* const SAVE_FILE_ORG        = "com.codelobster";    // Root folder to save config in (in a OS specific writable prefs location)
static constexpr const char* const SAVE_FILE_PRODUCT    = "PsyDoom";            // Sub-folder within the root folder to save the config in

// Because typing this is a pain...
typedef std::chrono::high_resolution_clock::time_point timepoint_t;

// When we last did platform updates
static timepoint_t gLastPlatformUpdateTime = {};

//------------------------------------------------------------------------------------------------------------------------------------------
// Get the folder that PsyDoom uses for user config and save data.
// If the folder does not exist then it is created, and if that fails a fatal error is issued.
// The Path is returned with a trailing path separator, so can be combined with a file name without any other modifications.
//------------------------------------------------------------------------------------------------------------------------------------------
std::string getOrCreateUserDataFolder() noexcept {
    char* const pCfgFilePath = SDL_GetPrefPath(SAVE_FILE_ORG, SAVE_FILE_PRODUCT);

    if (!pCfgFilePath) {
        FatalErrors::raise("Unable to create or determine the user data folder (config/save folder) for PsyDoom!");
    }

    std::string path = pCfgFilePath;
    SDL_free(pCfgFilePath);
    return path;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Run update actions that have to be done periodically, including running the window and processing sound
//------------------------------------------------------------------------------------------------------------------------------------------
void doPlatformUpdates() noexcept {
    // In headless mode we can skip this entirely
    if (ProgArgs::gbHeadlessMode)
        return;

    // Only do updates if enough time has elapsed.
    // Do this to prevent excessive CPU usage in loops that are periodically trying to update sound etc. while waiting for some event.
    const timepoint_t now = std::chrono::high_resolution_clock::now();
    
    if (now - gLastPlatformUpdateTime < std::chrono::milliseconds(4))
        return;
    
    // Actually do the platform updates
    gLastPlatformUpdateTime = now;

    PsxVm::generateTimerEvents();
    PsxVm::emulateSoundIfRequired();
    Network::doUpdates();
    Input::update();
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Wait for a number of seconds while still doing platform updates
//------------------------------------------------------------------------------------------------------------------------------------------
void waitForSeconds(float seconds) noexcept {
    const clock_t startTime = clock();

    while (true) {
        const clock_t now = clock();
        const double elapsed = (double)(now - startTime) / (double) CLOCKS_PER_SEC;

        if (elapsed > seconds)
            break;
        
        doPlatformUpdates();
        threadYield();
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Utility that implements a commonly used loop from the original PSX Doom, with some PC friendly modifications.
// Waits until at least 1 CD audio sector has been read before continuing.
// This modified version also does platform updates so we can escape the loop, and so the UI remains responsive.
//------------------------------------------------------------------------------------------------------------------------------------------
void waitForCdAudioPlaybackStart() noexcept {
    // Wait until some cd audio has been read...
    // This is all the original PSX Doom code did, nothing else:
    while (psxcd_elapsed_sectors() == 0) {
        // Also update everything (sound etc.) so we can eventually escape this loop and the user can close the window if required.
        // Since we are waiting a bit we can also yield some CPU time.
        Utils::doPlatformUpdates();
        Utils::threadYield();
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Utility that implements a commonly used loop from the original PSX Doom, with some PC friendly modifications.
// Waits until at CD audio has finished fading out.
// This modified version also does platform updates so we can escape the loop, and so the UI remains responsive.
//------------------------------------------------------------------------------------------------------------------------------------------
void waitForCdAudioFadeOut() noexcept {
    // Never wait for fades in headless mode
    if (ProgArgs::gbHeadlessMode)
        return;

    // Wait for the fade to complete...
    while (psxspu_get_cd_fade_status()) {
        // Also update everything (sound etc.) so we can eventually escape this loop and the user can close the window if required.
        // Since we are waiting a bit we can also yield some CPU time.
        Utils::doPlatformUpdates();
        Utils::threadYield();
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Yield some CPU time to the host machine
//------------------------------------------------------------------------------------------------------------------------------------------
void threadYield() noexcept {
    std::this_thread::yield();
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Returns the cheat sequence to execute on the pause menu using helper shortcut keys in development mode.
// These save the pain of inputting button sequences and make it easy to cheat.
//------------------------------------------------------------------------------------------------------------------------------------------
cheatseq_t getDevCheatSequenceToExec() noexcept {
    // TODO: disable this in non developer builds, or at least provide a toggle (defaulted to off)
    const uint8_t* const pKbState = SDL_GetKeyboardState(nullptr);

    if (pKbState[SDL_SCANCODE_F1] != 0) {
        return CHT_SEQ_GOD_MODE;
    } else if (pKbState[SDL_SCANCODE_F2] != 0) {
        return CHT_SEQ_NOCLIP;
    } else if (pKbState[SDL_SCANCODE_F3] != 0) {
        return CHT_SEQ_WEAPONS_AND_AMMO;
    } else if (pKbState[SDL_SCANCODE_F4] != 0) {
        return CHT_SEQ_LEVEL_WARP;
    } else if (pKbState[SDL_SCANCODE_F5] != 0) {
        return CHT_SEQ_XRAY_VISION;
    } else if (pKbState[SDL_SCANCODE_F6] != 0) {
        return CHT_SEQ_SHOW_ALL_MAP_THINGS;
    } else if (pKbState[SDL_SCANCODE_F7] != 0) {
        return CHT_SEQ_SHOW_ALL_MAP_LINES;
    } else if (pKbState[SDL_SCANCODE_F8] != 0) {
        return CHT_SEQ_VRAM_VIEWER;
    }

    return (cheatseq_t) UINT32_MAX;
}

END_NAMESPACE(Utils)
