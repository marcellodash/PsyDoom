#pragma once

#include "Doom/doomdef.h"

extern gameaction_t     gGameAction;
extern skill_t          gGameSkill;
extern gametype_t       gNetGame;
extern int32_t          gGameMap;
extern int32_t          gNextMap;
extern const VmPtr<player_t[MAXPLAYERS]>    gPlayers;
extern bool             gbPlayerInGame[MAXPLAYERS];
extern int32_t          gGameTic;
extern int32_t          gPrevGameTic;
extern int32_t          gLastTgtGameTicCount;
extern int32_t          gTotalKills;
extern int32_t          gTotalItems;
extern int32_t          gTotalSecret;
extern bool             gbDemoPlayback;
extern bool             gbDemoRecording;
extern bool             gbIsLevelBeingRestarted;

void G_DoLoadLevel() noexcept;
void G_PlayerFinishLevel(int32_t playerIdx) noexcept;
void G_PlayerReborn(const int32_t playerIdx) noexcept;
void G_DoReborn(const int32_t playerIdx) noexcept;
void G_CompleteLevel() noexcept;
void G_InitNew(const skill_t skill, const int32_t mapNum, const gametype_t gameType) noexcept;
void G_RunGame() noexcept;
gameaction_t G_PlayDemoPtr() noexcept;
void G_EndDemoRecording() noexcept;
