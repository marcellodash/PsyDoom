#include "LIBETC.h"

#include "PcPsx/Assert.h"
#include "PcPsx/PsxVm.h"

#include <ctime>

// An imitation of the 1 KiB scratchpad memory/cache that the PlayStation had; now just a simple c-array
static uint8_t gScratchpad[1024];

//------------------------------------------------------------------------------------------------------------------------------------------
// Return a pointer to the specified 32-bit word in the PSX 'scratchpad' memory/cache.
// There is 1 KiB of memory in total in the scratchpad.
//------------------------------------------------------------------------------------------------------------------------------------------
void* LIBETC_getScratchAddr(const uint32_t word32Index) {
    // Sanity check: allow the 'end' pointer to be taken, but no further...
    #if ASSERTS_ENABLED
        constexpr int32_t SCRATCHPAD_END_WORD_IDX = sizeof(gScratchpad) / sizeof(uint32_t);
        ASSERT(word32Index <= SCRATCHPAD_END_WORD_IDX);
    #endif
    
    // Return the requested memory
    return gScratchpad + word32Index * sizeof(uint32_t);
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Initialize system callbacks and interrupt handlers: doesn't need to do anything for PsyDoom!
//------------------------------------------------------------------------------------------------------------------------------------------
void LIBETC_ResetCallback() noexcept {}

//------------------------------------------------------------------------------------------------------------------------------------------
// Wait for the next vblank or return the time elapsed in vblanks or hblanks.
//
//  Mode:
//      0   Block until a vsync happens. Return the total number of horizontal blanking units elapsed (16-bit wrapping).
//      1   Return the number of horizontal blanking units elapsed (16-bit wrapping).
//    > 1   Wait for 'mode - 1' vblanks since the function was last invoked in this mode.
//          Return the number of horizontal blanking units elapsed (16-bit wrapping).
//    < 0   Return the total number of vertical blank units elapsed since program start.
//------------------------------------------------------------------------------------------------------------------------------------------
int32_t LIBETC_VSync(const int32_t mode) noexcept {
    // PC-PSX: Wait for VBLANK not supported anymore! Just ignore the call.
    if (mode == 0)
        return 0;

    if (mode < 0) {
        // For the VBLANK count emulation use the time since the program started to get the count.
        // TODO: changes here to support the PAL version?
        const clock_t now = clock();
        double vblanks = ((double) now * 60.0) / (double) CLOCKS_PER_SEC;
        return (int32_t) vblanks;
    }
    else {
        // Horizontal blanking units not supported in PsyDoom, always return '0'.
        // Doom doesn't require this mode anyway, so it's OK:
        return 0;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Return the pressed buttons for pad 1 and pad 2 (digital controllers).
// The buttons for pad 1 are returned in the lower 16-bits, the buttons for pad 2 are returned in the high 16-bits.
// The input parameter is not used, and should be set to '0'.
//------------------------------------------------------------------------------------------------------------------------------------------
uint32_t LIBETC_PadRead([[maybe_unused]] const uint32_t unusedControllerId) noexcept {
    return PsxVm::getControllerButtonBits();
}
