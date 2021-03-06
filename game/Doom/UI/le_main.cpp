//------------------------------------------------------------------------------------------------------------------------------------------
// Code for the 'legals' screen.
// This screen is unused in the retail version of the game, it was only used in demo builds of DOOM.
//------------------------------------------------------------------------------------------------------------------------------------------
#include "le_main.h"

#include "Doom/Base/i_crossfade.h"
#include "Doom/Base/i_main.h"
#include "Doom/Base/s_sound.h"
#include "Doom/Base/sounds.h"
#include "Doom/d_main.h"
#include "Doom/Game/p_tick.h"
#include "Doom/Renderer/r_data.h"
#include "m_main.h"
#include "ti_main.h"

// Texture for the legals screen text
static texture_t gTex_LEGALS;

//------------------------------------------------------------------------------------------------------------------------------------------
// Startup/init logic for the 'legals' screen
//------------------------------------------------------------------------------------------------------------------------------------------
void START_Legals() noexcept {
    I_PurgeTexCache();
    I_LoadAndCacheTexLump(gTex_LEGALS, "LEGALS", 0);
    
    S_StartSound(nullptr, sfx_sgcock);
    gTitleScreenSpriteY = SCREEN_H;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Shutdown logic for the 'legals' screen
//------------------------------------------------------------------------------------------------------------------------------------------
void STOP_Legals([[maybe_unused]] const gameaction_t exitAction) noexcept {
    S_StartSound(nullptr, sfx_barexp);
    I_CrossFadeFrameBuffers();
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Update logic for the 'legals' screen
//------------------------------------------------------------------------------------------------------------------------------------------
gameaction_t TIC_Legals() noexcept {
    // PC-PSX: tick only if vblanks are registered as elapsed; this restricts the code to ticking at 30 Hz for NTSC
    #if PC_PSX_DOOM_MODS
        if (gPlayersElapsedVBlanks[0] <= 0)
            return ga_nothing;
    #endif

    // Scroll the legal text, otherwise check for timeout
    if (gTitleScreenSpriteY > 0) {
        gTitleScreenSpriteY--;
    
        if (gTitleScreenSpriteY == 0) {
            gMenuTimeoutStartTicCon = gTicCon;
        }
    } else {
        // Must hold the legals text for a small amount of time before allowing skip (via a button press) or timeout
        const int32_t waitTicsElapsed = gTicCon - gMenuTimeoutStartTicCon;
        
        if (waitTicsElapsed > 120) {
            if (waitTicsElapsed >= 180)
                return ga_timeout;
            
            // PC-PSX: only accept main menu buttons to skip
            #if PC_PSX_DOOM_MODS
                if (gTickInputs[0].bMenuOk || gTickInputs[0].bMenuStart || gTickInputs[0].bMenuBack)
                    return ga_exit;
            #else
                if (gTicButtons[0] != 0)
                    return ga_exit;
            #endif
        }
    }

    return ga_nothing;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Does drawing for the 'legals' screen - very simple, just a single sprite
//------------------------------------------------------------------------------------------------------------------------------------------
void DRAW_Legals() noexcept {
    I_IncDrawnFrameCount();
    I_CacheAndDrawSprite(gTex_LEGALS, 0, (int16_t) gTitleScreenSpriteY, gPaletteClutIds[UIPAL]);

    I_SubmitGpuCmds();
    I_DrawPresent();
}
