#include "le_main.h"

#include "PsxVm/PsxVm.h"

void START_Legals() noexcept {
    sp -= 0x18;
    sw(ra, sp + 0x10);
    I_ResetTexCache();
    a0 = 0x80090000;                                    // Result = 80090000
    a0 += 0x7BD0;                                       // Result = gTexInfo_LEGALS[0] (80097BD0)
    a1 = 0x80070000;                                    // Result = 80070000
    a1 += 0x7C44;                                       // Result = STR_LumpName_LEGALS[0] (80077C44)
    a2 = 0;                                             // Result = 00000000
    I_CacheTexForLumpName();
    a0 = 0;                                             // Result = 00000000
    a1 = 1;                                             // Result = 00000001
    S_StartSound();
    v0 = 0xF0;                                          // Result = 000000F0
    sw(v0, gp + 0xBB0);                                 // Store to: gTitleScreenSpriteY (80078190)
    ra = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void STOP_Legals() noexcept {
    sp -= 0x18;
    sw(ra, sp + 0x10);
    a0 = 0;                                             // Result = 00000000
    a1 = 5;                                             // Result = 00000005
    S_StartSound();
    I_CrossFadeFrameBuffers();
    ra = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void TIC_Legals() noexcept {
    v0 = lw(gp + 0xBB0);                                // Load from: gTitleScreenSpriteY (80078190)
    {
        const bool bJump = (i32(v0) <= 0);
        v0--;
        if (bJump) goto loc_80035000;
    }
    sw(v0, gp + 0xBB0);                                 // Store to: gTitleScreenSpriteY (80078190)
    {
        const bool bJump = (v0 != 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_80035044;
    }
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7EB4);                               // Load from: gTicCon (8007814C)
    sw(v0, gp + 0x92C);                                 // Store to: gMenuTimeoutStartTicCon (80077F0C)
    v0 = 0;                                             // Result = 00000000
    goto loc_80035044;
loc_80035000:
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7EB4);                               // Load from: gTicCon (8007814C)
    v1 = lw(gp + 0x92C);                                // Load from: gMenuTimeoutStartTicCon (80077F0C)
    v1 = v0 - v1;
    v0 = (i32(v1) < 0x79);
    {
        const bool bJump = (v0 != 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_80035044;
    }
    v0 = (i32(v1) < 0xB4);
    {
        const bool bJump = (v0 == 0);
        v0 = 7;                                         // Result = 00000007
        if (bJump) goto loc_80035044;
    }
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F44);                               // Load from: gPlayerPadButtons[0] (80077F44)
    v0 = (v0 > 0);
    v0 = -v0;
    v0 &= 9;
loc_80035044:
    return;
}

void DRAW_Legals() noexcept {
    sp -= 0x18;
    sw(ra, sp + 0x10);
    I_IncDrawnFrameCount();
    a0 = 0x80090000;                                    // Result = 80090000
    a0 += 0x7BD0;                                       // Result = gTexInfo_LEGALS[0] (80097BD0)
    a2 = lw(gp + 0xBB0);                                // Load from: gTitleScreenSpriteY (80078190)
    a3 = 0x800B0000;                                    // Result = 800B0000
    a3 = lh(a3 - 0x6F5C);                               // Load from: gPaletteClutId_UI (800A90A4)
    a1 = 0;                                             // Result = 00000000
    I_CacheAndDrawSprite();
    I_SubmitGpuCmds();
    I_DrawPresent();
    ra = lw(sp + 0x10);
    sp += 0x18;
    return;
}
