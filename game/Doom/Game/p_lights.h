#pragma once

#include <cstdint>

struct line_t;
struct sector_t;

void P_SpawnFireFlicker(sector_t& sector) noexcept;
void P_SpawnLightFlash(sector_t& sector) noexcept;
void P_SpawnStrobeFlash(sector_t& sector, const int32_t darkTime, const bool bInSync) noexcept;
void P_SpawnRapidStrobeFlash(sector_t& sector) noexcept;
void EV_StartLightStrobing(line_t& line) noexcept;
void EV_TurnTagLightsOff(line_t& line) noexcept;
void EV_LightTurnOn(line_t& line, const int32_t onLightLevel) noexcept;
void T_Glow() noexcept;
void P_SpawnGlowingLight() noexcept;
