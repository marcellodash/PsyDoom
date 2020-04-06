#define PSX_VM_NO_REGISTER_MACROS 1     // In case of conflicts
#include "PsxVm.h"

#include <map>

extern void _thunk_D_memset() noexcept;
extern void _thunk_D_memcpy() noexcept;
extern void _thunk_D_strncasecmp() noexcept;
extern void _thunk_P_Random() noexcept;
extern void M_AddPointToBox() noexcept;
extern void G_DoLoadLevel() noexcept;
extern void G_CompleteLevel() noexcept;
extern void P_RunMobjBase() noexcept;
extern void P_XYMovement() noexcept;
extern void P_FloatChange() noexcept;
extern void P_ZMovement() noexcept;
extern void P_MobjThinker() noexcept;
extern void PB_TryMove() noexcept;
extern void PB_SetThingPosition() noexcept;
extern void PB_CheckPosition() noexcept;
extern void PB_BoxCrossLine() noexcept;
extern void PB_CheckLine() noexcept;
extern void PB_CheckThing() noexcept;
extern void PB_BlockLinesIterator() noexcept;
extern void PB_BlockThingsIterator() noexcept;
extern void T_MoveCeiling() noexcept;
extern void EV_DoCeiling() noexcept;
extern void P_AddActiveCeiling() noexcept;
extern void P_RemoveActiveCeiling() noexcept;
extern void P_ActivateInStasisCeiling() noexcept;
extern void EV_CeilingCrushStop() noexcept;
extern void P_ThingHeightClip() noexcept;
extern void PIT_ChangeSector() noexcept;
extern void P_ChangeSector() noexcept;
extern void T_VerticalDoor() noexcept;
extern void EV_DoLockedDoor() noexcept;
extern void EV_DoDoor() noexcept;
extern void EV_VerticalDoor() noexcept;
extern void P_SpawnDoorCloseIn30() noexcept;
extern void P_SpawnDoorRaiseIn5Mins() noexcept;
extern void P_CheckMeleeRange() noexcept;
extern void P_CheckMissileRange() noexcept;
extern void P_Move() noexcept;
extern void P_TryWalk() noexcept;
extern void P_NewChaseDir() noexcept;
extern void P_LookForPlayers() noexcept;
extern void A_Look() noexcept;
extern void A_Chase() noexcept;
extern void A_FaceTarget() noexcept;
extern void A_PosAttack() noexcept;
extern void A_SPosAttack() noexcept;
extern void A_CPosAttack() noexcept;
extern void A_CPosRefire() noexcept;
extern void A_SpidAttack() noexcept;
extern void A_SpidRefire() noexcept;
extern void A_BspiAttack() noexcept;
extern void A_TroopAttack() noexcept;
extern void A_SargAttack() noexcept;
extern void A_HeadAttack() noexcept;
extern void A_CyberAttack() noexcept;
extern void A_BruisAttack() noexcept;
extern void A_SkelMissile() noexcept;
extern void A_Tracer() noexcept;
extern void A_SkelWhoosh() noexcept;
extern void A_SkelFist() noexcept;
extern void A_FatRaise() noexcept;
extern void A_FatAttack1() noexcept;
extern void A_FatAttack2() noexcept;
extern void A_FatAttack3() noexcept;
extern void A_SkullAttack() noexcept;
extern void A_PainShootSkull() noexcept;
extern void A_PainAttack() noexcept;
extern void A_PainDie() noexcept;
extern void A_Scream() noexcept;
extern void A_XScream() noexcept;
extern void A_Pain() noexcept;
extern void A_Fall() noexcept;
extern void A_Explode() noexcept;
extern void A_BossDeath() noexcept;
extern void A_Hoof() noexcept;
extern void A_Metal() noexcept;
extern void A_BabyMetal() noexcept;
extern void L_MissileHit() noexcept;
extern void L_SkullBash() noexcept;
extern void T_MovePlane() noexcept;
extern void T_MoveFloor() noexcept;
extern void EV_DoFloor() noexcept;
extern void EV_BuildStairs() noexcept;
extern void P_GiveAmmo() noexcept;
extern void P_GiveWeapon() noexcept;
extern void P_GiveBody() noexcept;
extern void P_GiveArmor() noexcept;
extern void P_GiveCard() noexcept;
extern void P_GivePower() noexcept;
extern void P_TouchSpecialThing() noexcept;
extern void P_KillMObj() noexcept;
extern void P_DamageMObj() noexcept;
extern void T_FireFlicker() noexcept;
extern void P_SpawnFireFlicker() noexcept;
extern void T_LightFlash() noexcept;
extern void P_SpawnLightFlash() noexcept;
extern void T_StrobeFlash() noexcept;
extern void P_SpawnStrobeFlash() noexcept;
extern void P_SpawnRapidStrobeFlash() noexcept;
extern void EV_StartLightStrobing() noexcept;
extern void EV_TurnTagLightsOff() noexcept;
extern void EV_LightTurnOn() noexcept;
extern void T_Glow() noexcept;
extern void P_SpawnGlowingLight() noexcept;
extern void P_CheckPosition() noexcept;
extern void P_TryMove() noexcept;
extern void P_InterceptVector() noexcept;
extern void PIT_UseLines() noexcept;
extern void P_UseLines() noexcept;
extern void PIT_RadiusAttack() noexcept;
extern void P_RadiusAttack() noexcept;
extern void P_AimLineAttack() noexcept;
extern void P_LineAttack() noexcept;
extern void P_AproxDistance() noexcept;
extern void P_PointOnLineSide() noexcept;
extern void P_PointOnDivlineSide() noexcept;
extern void P_MakeDivline() noexcept;
extern void P_LineOpening() noexcept;
extern void _thunk_P_UnsetThingPosition() noexcept;
extern void _thunk_P_SetThingPosition() noexcept;
extern void P_BlockLinesIterator() noexcept;
extern void P_BlockThingsIterator() noexcept;
extern void P_RemoveMObj() noexcept;
extern void P_RespawnSpecials() noexcept;
extern void P_SetMObjState() noexcept;
extern void P_ExplodeMissile() noexcept;
extern void P_SpawnMObj() noexcept;
extern void P_SpawnPlayer() noexcept;
extern void P_SpawnMapThing() noexcept;
extern void P_SpawnPuff() noexcept;
extern void P_SpawnBlood() noexcept;
extern void P_CheckMissileSpawn() noexcept;
extern void P_SpawnMissile() noexcept;
extern void P_SpawnPlayerMissile() noexcept;
extern void P_TryMove2() noexcept;
extern void PM_PointOnDivlineSide() noexcept;
extern void PM_SetThingPosition() noexcept;
extern void PM_CheckPosition() noexcept;
extern void PM_BoxCrossLine() noexcept;
extern void PIT_CheckLine() noexcept;
extern void PIT_CheckThing() noexcept;
extern void PM_BlockLinesIterator() noexcept;
extern void PM_BlockThingsIterator() noexcept;
extern void T_PlatRaise() noexcept;
extern void EV_DoPlat() noexcept;
extern void P_ActivateInStasis() noexcept;
extern void EV_StopPlat() noexcept;
extern void P_AddActivePlat() noexcept;
extern void P_RemoveActivePlat() noexcept;
extern void P_RecursiveSound() noexcept;
extern void P_NoiseAlert() noexcept;
extern void P_SetPsprite() noexcept;
extern void P_BringUpWeapon() noexcept;
extern void P_CheckAmmo() noexcept;
extern void P_FireWeapon() noexcept;
extern void P_DropWeapon() noexcept;
extern void A_WeaponReady() noexcept;
extern void A_ReFire() noexcept;
extern void A_CheckReload() noexcept;
extern void A_Lower() noexcept;
extern void A_Raise() noexcept;
extern void A_GunFlash() noexcept;
extern void A_Punch() noexcept;
extern void A_Saw() noexcept;
extern void A_FireMissile() noexcept;
extern void A_FireBFG() noexcept;
extern void A_FirePlasma() noexcept;
extern void P_BulletSlope() noexcept;
extern void P_GunShot() noexcept;
extern void A_FirePistol() noexcept;
extern void A_FireShotgun() noexcept;
extern void A_FireShotgun2() noexcept;
extern void A_FireCGun() noexcept;
extern void A_Light0() noexcept;
extern void A_Light1() noexcept;
extern void A_Light2() noexcept;
extern void A_BFGSpray() noexcept;
extern void A_BFGsound() noexcept;
extern void A_OpenShotgun2() noexcept;
extern void A_LoadShotgun2() noexcept;
extern void A_CloseShotgun2() noexcept;
extern void P_SetupPsprites() noexcept;
extern void P_MovePsprites() noexcept;
extern void P_Shoot2() noexcept;
extern void PA_DoIntercept() noexcept;
extern void PA_ShootLine() noexcept;
extern void PA_ShootThing() noexcept;
extern void PA_SightCrossLine() noexcept;
extern void PA_CrossSubsector() noexcept;
extern void PointOnVectorSide() noexcept;
extern void PA_CrossBSPNode() noexcept;
extern void P_CheckSights() noexcept;
extern void P_CheckSight() noexcept;
extern void PS_SightCrossLine() noexcept;
extern void PS_CrossSubsector() noexcept;
extern void PS_CrossBSPNode() noexcept;
extern void P_SlideMove() noexcept;
extern void P_CompletableFrac() noexcept;
extern void SL_PointOnSide() noexcept;
extern void SL_CrossFrac() noexcept;
extern void CheckLineEnds() noexcept;
extern void ClipToLine() noexcept;
extern void SL_CheckLine() noexcept;
extern void SL_PointOnSide2() noexcept;
extern void SL_CheckSpecialLines() noexcept;
extern void getSide() noexcept;
extern void getSector() noexcept;
extern void twoSided() noexcept;
extern void getNextSector() noexcept;
extern void P_FindLowestFloorSurrounding() noexcept;
extern void P_FindHighestFloorSurrounding() noexcept;
extern void P_FindNextHighestFloor() noexcept;
extern void P_FindLowestCeilingSurrounding() noexcept;
extern void P_FindHighestCeilingSurrounding() noexcept;
extern void P_FindSectorFromLineTag() noexcept;
extern void P_FindMinSurroundingLight() noexcept;
extern void P_CrossSpecialLine() noexcept;
extern void P_ShootSpecialLine() noexcept;
extern void P_PlayerInSpecialSector() noexcept;
extern void P_UpdateSpecials() noexcept;
extern void EV_DoDonut() noexcept;
extern void G_ScheduleExitLevel() noexcept;
extern void G_BeginExitLevel() noexcept;
extern void G_ExitLevel() noexcept;
extern void G_SecretExitLevel() noexcept;
extern void P_SpawnSpecials() noexcept;
extern void P_StartButton() noexcept;
extern void P_ChangeSwitchTexture() noexcept;
extern void P_UseSpecialLine() noexcept;
extern void P_Telefrag() noexcept;
extern void EV_Teleport() noexcept;
extern void _thunk_P_AddThinker() noexcept;
extern void _thunk_P_RemoveThinker() noexcept;
extern void P_RunThinkers() noexcept;
extern void P_RunMobjLate() noexcept;
extern void P_CheckCheats() noexcept;
extern void P_Start() noexcept;
extern void P_PlayerMove() noexcept;
extern void P_PlayerXYMovement() noexcept;
extern void P_PlayerZMovement() noexcept;
extern void P_PlayerMobjThink() noexcept;
extern void P_BuildMove() noexcept;
extern void P_Thrust() noexcept;
extern void P_CalcHeight() noexcept;
extern void P_MovePlayer() noexcept;
extern void P_DeathThink() noexcept;
extern void P_PlayerThink() noexcept;
extern void _thunk_R_PointToAngle2() noexcept;
extern void _thunk_R_PointInSubsector() noexcept;
extern void _thunk_Z_Malloc() noexcept;
extern void _thunk_Z_EndMalloc() noexcept;
extern void _thunk_Z_Free2() noexcept;
extern void I_PSXInit() noexcept;
extern void I_ReadGamepad() noexcept;
extern void I_NetSetup() noexcept;
extern void I_NetUpdate() noexcept;
extern void I_NetHandshake() noexcept;
extern void I_NetSendRecv() noexcept;
extern void I_SubmitGpuCmds() noexcept;
extern void I_LocalButtonsToNet() noexcept;
extern void I_NetButtonsToLocal() noexcept;
extern void START_Legals() noexcept;
extern void START_Title() noexcept;
extern void M_Start() noexcept;
extern void START_PasswordScreen() noexcept;
extern void START_ControlsScreen() noexcept;
extern void P_ComputePassword() noexcept;
extern void P_ProcessPassword() noexcept;
extern void ST_InitEveryLevel() noexcept;
extern void ST_Ticker() noexcept;
extern void IN_Start() noexcept;
extern void F1_Start() noexcept;
extern void F2_Start() noexcept;
extern void O_Init() noexcept;
extern void _thunk_FixedMul() noexcept;
extern void _thunk_FixedDiv() noexcept;

extern void S_SetSfxVolume() noexcept;
extern void S_SetMusicVolume() noexcept;
extern void S_StopMusicSequence() noexcept;
extern void S_StartMusicSequence() noexcept;
extern void ZeroHalfWord() noexcept;
extern void S_UnloadSamples() noexcept;
extern void S_LoadSoundAndMusic() noexcept;
extern void S_Pause() noexcept;
extern void S_Resume() noexcept;
extern void S_StopSound() noexcept;
extern void I_StartSound() noexcept;
extern void _thunk_S_StartSound() noexcept;
extern void S_UpdateSounds() noexcept;
extern void PsxSoundInit() noexcept;
extern void PsxSoundExit() noexcept;
extern void _thunk_PSX_DriverInit() noexcept;
extern void _thunk_PSX_DriverExit() noexcept;
extern void PSX_DriverEntry1() noexcept;
extern void PSX_DriverEntry2() noexcept;
extern void PSX_DriverEntry3() noexcept;
extern void _thunk_PSX_TrkOff() noexcept;
extern void _thunk_PSX_TrkMute() noexcept;
extern void _thunk_PSX_PatchChg() noexcept;
extern void _thunk_PSX_PatchMod() noexcept;
extern void _thunk_PSX_PitchMod() noexcept;
extern void _thunk_PSX_ZeroMod() noexcept;
extern void _thunk_PSX_ModuMod() noexcept;
extern void _thunk_PSX_VolumeMod() noexcept;
extern void _thunk_PSX_PanMod() noexcept;
extern void _thunk_PSX_PedalMod() noexcept;
extern void _thunk_PSX_ReverbMod() noexcept;
extern void _thunk_PSX_ChorusMod() noexcept;
extern void _thunk_PSX_NoteOn() noexcept;
extern void _thunk_PSX_NoteOff() noexcept;
extern void Write_Vlq() noexcept;
extern void Len_Vlq() noexcept;
extern void _thunk_Eng_DriverInit() noexcept;
extern void _thunk_Eng_DriverExit() noexcept;
extern void Eng_DriverEntry1() noexcept;
extern void Eng_DriverEntry2() noexcept;
extern void Eng_DriverEntry3() noexcept;
extern void _thunk_Eng_TrkOff() noexcept;
extern void _thunk_Eng_TrkMute() noexcept;
extern void _thunk_Eng_PatchChg() noexcept;
extern void _thunk_Eng_PatchMod() noexcept;
extern void _thunk_Eng_PitchMod() noexcept;
extern void _thunk_Eng_ZeroMod() noexcept;
extern void _thunk_Eng_ModuMod() noexcept;
extern void _thunk_Eng_VolumeMod() noexcept;
extern void _thunk_Eng_PanMod() noexcept;
extern void _thunk_Eng_PedalMod() noexcept;
extern void _thunk_Eng_ReverbMod() noexcept;
extern void _thunk_Eng_ChorusMod() noexcept;
extern void _thunk_Eng_NoteOn() noexcept;
extern void _thunk_Eng_NoteOff() noexcept;
extern void Eng_StatusMark() noexcept;
extern void Eng_GateJump() noexcept;
extern void _thunk_Eng_IterJump() noexcept;
extern void _thunk_Eng_ResetGates() noexcept;
extern void _thunk_Eng_ResetIters() noexcept;
extern void _thunk_Eng_WriteIterBox() noexcept;
extern void Eng_SeqTempo() noexcept;
extern void Eng_SeqGosub() noexcept;
extern void Eng_SeqJump() noexcept;
extern void Eng_SeqRet() noexcept;
extern void Eng_SeqEnd() noexcept;
extern void Eng_TrkTempo() noexcept;
extern void Eng_TrkGosub() noexcept;
extern void _thunk_Eng_TrkJump() noexcept;
extern void Eng_TrkRet() noexcept;
extern void _thunk_Eng_TrkEnd() noexcept;
extern void _thunk_Eng_NullEvent() noexcept;
extern void SeqEngine() noexcept;

extern void LIBAPI_write() noexcept;
extern void LIBAPI_InitPAD() noexcept;
extern void LIBAPI_StartPAD() noexcept;
extern void LIBAPI_ChangeClearPAD() noexcept;
extern void LIBAPI_read() noexcept;
extern void LIBAPI_TestEvent() noexcept;
extern void LIBAPI_open() noexcept;
extern void LIBETC_ResetCallback() noexcept;
extern void LIBAPI_ReturnFromException() noexcept;
extern void _thunk_LIBETC_VSync() noexcept;
extern void _thunk_LIBETC_v_wait() noexcept;
extern void LIBAPI_InitHeap() noexcept;
extern void LIBAPI_DeliverEvent() noexcept;
extern void LIBCOMB_UNKNOWN_func_1() noexcept;
extern void LIBCOMB_UNKNOWN_func_2() noexcept;
extern void LIBCOMB_UNKNOWN_func_3() noexcept;
extern void LIBCOMB_UNKNOWN_func_4() noexcept;
extern void LIBCOMB_UNKNOWN_func_5() noexcept;
extern void LIBCOMB_UNKNOWN_func_6() noexcept;
extern void LIBCOMB_UNKNOWN_func_7() noexcept;
extern void LIBCOMB_UNKNOWN_func_8() noexcept;
extern void LIBCOMB_UNKNOWN_func_9() noexcept;
extern void LIBCOMB_ChangeClearSIO() noexcept;
extern void LIBCOMB_AddCOMB() noexcept;
extern void LIBCOMB_DelCOMB() noexcept;
extern void LIBCOMB_UNKNOWN_ctrl_help() noexcept;
extern void LIBCOMB__comb_control() noexcept;
extern void LIBAPI_SysEnqIntRP() noexcept;
extern void LIBAPI_AddDrv() noexcept;
extern void LIBAPI_DelDrv() noexcept;
extern void LIBCOMB__ioabort() noexcept;

namespace PsxVm {
    std::map<uint32_t, VmFunc> gFuncTable = {
        { 0x80012850, &_thunk_D_memset },
        { 0x8001290C, &_thunk_D_memcpy },
        { 0x8001297C, &_thunk_D_strncasecmp },
        { 0x80012A18, &_thunk_P_Random },
        { 0x80012B10, &M_AddPointToBox },
        { 0x80012E04, &G_DoLoadLevel },
        { 0x80013384, &G_CompleteLevel },
        { 0x80013840, &P_RunMobjBase },
        { 0x800138D8, &P_XYMovement },
        { 0x80013B38, &P_FloatChange },
        { 0x80013C00, &P_ZMovement },
        { 0x80013DE0, &P_MobjThinker },
        { 0x80013F00, &PB_TryMove },
        { 0x800140DC, &PB_SetThingPosition },
        { 0x800141DC, &PB_CheckPosition },
        { 0x800143C0, &PB_BoxCrossLine },
        { 0x800144D8, &PB_CheckLine },
        { 0x800145C4, &PB_CheckThing },
        { 0x800146F0, &PB_BlockLinesIterator },
        { 0x800149B8, &PB_BlockThingsIterator },
        { 0x80014A30, &T_MoveCeiling },
        { 0x80014C44, &EV_DoCeiling },
        { 0x80014E18, &P_AddActiveCeiling },
        { 0x80014E54, &P_RemoveActiveCeiling },
        { 0x80014EBC, &P_ActivateInStasisCeiling },
        { 0x80014F30, &EV_CeilingCrushStop },
        { 0x80014FA4, &P_ThingHeightClip },
        { 0x8001504C, &PIT_ChangeSector },
        { 0x80015238, &P_ChangeSector },
        { 0x800152FC, &T_VerticalDoor },
        { 0x80015540, &EV_DoLockedDoor },
        { 0x80015764, &EV_DoDoor },
        { 0x80015988, &EV_VerticalDoor },
        { 0x80015B84, &P_SpawnDoorCloseIn30 },
        { 0x80015C04, &P_SpawnDoorRaiseIn5Mins },
        { 0x80015CA8, &P_CheckMeleeRange },
        { 0x80015D1C, &P_CheckMissileRange },
        { 0x80015E00, &P_Move },
        { 0x80015F68, &P_TryWalk },
        { 0x80015FB4, &P_NewChaseDir },
        { 0x80016334, &P_LookForPlayers },
        { 0x800164B4, &A_Look },
        { 0x800165E0, &A_Chase },
        { 0x80016928, &A_FaceTarget },
        { 0x800169CC, &A_PosAttack },
        { 0x80016AD4, &A_SPosAttack },
        { 0x80016C24, &A_CPosAttack },
        { 0x80016D70, &A_CPosRefire },
        { 0x80016E6C, &A_SpidAttack },
        { 0x80016FBC, &A_SpidRefire },
        { 0x800170BC, &A_BspiAttack },
        { 0x80017170, &A_TroopAttack },
        { 0x800172B0, &A_SargAttack },
        { 0x80017380, &A_HeadAttack },
        { 0x800174B4, &A_CyberAttack },
        { 0x80017568, &A_BruisAttack },
        { 0x80017630, &A_SkelMissile },
        { 0x80017730, &A_Tracer },
        { 0x80017980, &A_SkelWhoosh },
        { 0x80017A30, &A_SkelFist },
        { 0x80017B90, &A_FatRaise },
        { 0x80017C40, &A_FatAttack1 },
        { 0x80017D7C, &A_FatAttack2 },
        { 0x80017EB8, &A_FatAttack3 },
        { 0x8001804C, &A_SkullAttack },
        { 0x800181FC, &A_PainShootSkull },
        { 0x80018350, &A_PainAttack },
        { 0x80018520, &A_PainDie },
        { 0x800188DC, &A_Scream },
        { 0x80018994, &A_XScream },
        { 0x800189B4, &A_Pain },
        { 0x800189EC, &A_Fall },
        { 0x80018A00, &A_Explode },
        { 0x80018A24, &A_BossDeath },
        { 0x80018C44, &A_Hoof },
        { 0x80018C78, &A_Metal },
        { 0x80018CAC, &A_BabyMetal },
        { 0x80018CE0, &L_MissileHit },
        { 0x80018D54, &L_SkullBash },
        { 0x80018DF0, &T_MovePlane },
        { 0x80019010, &T_MoveFloor },
        { 0x80019100, &EV_DoFloor },
        { 0x80019548, &EV_BuildStairs },
        { 0x800197A4, &P_GiveAmmo },
        { 0x8001998C, &P_GiveWeapon },
        { 0x80019AF4, &P_GiveBody },
        { 0x80019B40, &P_GiveArmor },
        { 0x80019B7C, &P_GiveCard },
        { 0x80019BA8, &P_GivePower },
        { 0x80019C8C, &P_TouchSpecialThing },
        { 0x8001A57C, &P_KillMObj },
        { 0x8001A8A0, &P_DamageMObj },
        { 0x8001AD74, &T_FireFlicker },
        { 0x8001AE00, &P_SpawnFireFlicker },
        { 0x8001AE8C, &T_LightFlash },
        { 0x8001AF14, &P_SpawnLightFlash },
        { 0x8001AFBC, &T_StrobeFlash },
        { 0x8001B020, &P_SpawnStrobeFlash },
        { 0x8001B0F4, &P_SpawnRapidStrobeFlash },
        { 0x8001B188, &EV_StartLightStrobing },
        { 0x8001B298, &EV_TurnTagLightsOff },
        { 0x8001B394, &EV_LightTurnOn },
        { 0x8001B4A0, &T_Glow },
        { 0x8001B558, &P_SpawnGlowingLight },
        { 0x8001B640, &P_CheckPosition },
        { 0x8001B67C, &P_TryMove },
        { 0x8001B7A4, &P_InterceptVector },
        { 0x8001B848, &PIT_UseLines },
        { 0x8001B9F4, &P_UseLines },
        { 0x8001BC30, &PIT_RadiusAttack },
        { 0x8001BD24, &P_RadiusAttack },
        { 0x8001BE04, &P_AimLineAttack },
        { 0x8001BE78, &P_LineAttack },
        { 0x8001C030, &P_AproxDistance },
        { 0x8001C068, &P_PointOnLineSide },
        { 0x8001C128, &P_PointOnDivlineSide },
        { 0x8001C21C, &P_MakeDivline },
        { 0x8001C25C, &P_LineOpening },
        { 0x8001C2F8, &_thunk_P_UnsetThingPosition },
        { 0x8001C408, &_thunk_P_SetThingPosition },
        { 0x8001C540, &P_BlockLinesIterator },
        { 0x8001C660, &P_BlockThingsIterator },
        { 0x8001C724, &P_RemoveMObj },
        { 0x8001C838, &P_RespawnSpecials },
        { 0x8001CA18, &P_SetMObjState },
        { 0x8001CB9C, &P_ExplodeMissile },
        { 0x8001CC68, &P_SpawnMObj },
        { 0x8001CE40, &P_SpawnPlayer },
        { 0x8001D184, &P_SpawnMapThing },
        { 0x8001D704, &P_SpawnPuff },
        { 0x8001D930, &P_SpawnBlood },
        { 0x8001DB78, &P_CheckMissileSpawn },
        { 0x8001DC94, &P_SpawnMissile },
        { 0x8001E0F4, &P_SpawnPlayerMissile },
        { 0x8001E4F4, &P_TryMove2 },
        { 0x8001E720, &PM_PointOnDivlineSide },
        { 0x8001E868, &PM_SetThingPosition },
        { 0x8001E978, &PM_CheckPosition },
        { 0x8001EC68, &PM_BoxCrossLine },
        { 0x8001ED74, &PIT_CheckLine },
        { 0x8001EEC4, &PIT_CheckThing },
        { 0x8001F028, &PM_BlockLinesIterator },
        { 0x8001F208, &PM_BlockThingsIterator },
        { 0x8001F280, &T_PlatRaise },
        { 0x8001F464, &EV_DoPlat },
        { 0x8001F760, &P_ActivateInStasis },
        { 0x8001F7D4, &EV_StopPlat },
        { 0x8001F848, &P_AddActivePlat },
        { 0x8001F8A0, &P_RemoveActivePlat },
        { 0x8001F918, &P_RecursiveSound },
        { 0x8001FA34, &P_NoiseAlert },
        { 0x8001FB70, &P_SetPsprite },
        { 0x8001FC18, &P_BringUpWeapon },
        { 0x8001FD4C, &P_CheckAmmo },
        { 0x8001FFBC, &P_FireWeapon },
        { 0x800201C4, &P_DropWeapon },
        { 0x80020298, &A_WeaponReady },
        { 0x80020480, &A_ReFire },
        { 0x8002051C, &A_CheckReload },
        { 0x8002053C, &A_Lower },
        { 0x800206B4, &A_Raise },
        { 0x800207A0, &A_GunFlash },
        { 0x80020874, &A_Punch },
        { 0x8002096C, &A_Saw },
        { 0x80020AE4, &A_FireMissile },
        { 0x80020B48, &A_FireBFG },
        { 0x80020BAC, &A_FirePlasma },
        { 0x80020CD4, &P_BulletSlope },
        { 0x80020D60, &P_GunShot },
        { 0x80020DF0, &A_FirePistol },
        { 0x80020F7C, &A_FireShotgun },
        { 0x8002112C, &A_FireShotgun2 },
        { 0x80021374, &A_FireCGun },
        { 0x8002155C, &A_Light0 },
        { 0x80021564, &A_Light1 },
        { 0x80021570, &A_Light2 },
        { 0x8002157C, &A_BFGSpray },
        { 0x8002166C, &A_BFGsound },
        { 0x80021690, &A_OpenShotgun2 },
        { 0x800216B4, &A_LoadShotgun2 },
        { 0x800216D8, &A_CloseShotgun2 },
        { 0x80021794, &P_SetupPsprites },
        { 0x8002190C, &P_MovePsprites },
        { 0x80023C34, &P_Shoot2 },
        { 0x80023E3C, &PA_DoIntercept },
        { 0x80023EC4, &PA_ShootLine },
        { 0x800240BC, &PA_ShootThing },
        { 0x8002425C, &PA_SightCrossLine },
        { 0x80024334, &PA_CrossSubsector },
        { 0x80024758, &PointOnVectorSide },
        { 0x8002479C, &PA_CrossBSPNode },
        { 0x80024908, &P_CheckSights },
        { 0x800249B4, &P_CheckSight },
        { 0x80024B3C, &PS_SightCrossLine },
        { 0x80024C14, &PS_CrossSubsector },
        { 0x80024EC0, &PS_CrossBSPNode },
        { 0x8002502C, &P_SlideMove },
        { 0x800251BC, &P_CompletableFrac },
        { 0x80025460, &SL_PointOnSide },
        { 0x800254D0, &SL_CrossFrac },
        { 0x80025588, &CheckLineEnds },
        { 0x80025648, &ClipToLine },
        { 0x80025840, &SL_CheckLine },
        { 0x80025A8C, &SL_PointOnSide2 },
        { 0x80025AFC, &SL_CheckSpecialLines },
        { 0x80026224, &getSide },
        { 0x80026280, &getSector },
        { 0x800262E4, &twoSided },
        { 0x80026324, &getNextSector },
        { 0x80026354, &P_FindLowestFloorSurrounding },
        { 0x800263E8, &P_FindHighestFloorSurrounding },
        { 0x80026480, &P_FindNextHighestFloor },
        { 0x80026564, &P_FindLowestCeilingSurrounding },
        { 0x80026600, &P_FindHighestCeilingSurrounding },
        { 0x80026698, &P_FindSectorFromLineTag },
        { 0x80026700, &P_FindMinSurroundingLight },
        { 0x80026794, &P_CrossSpecialLine },
        { 0x80026D40, &P_ShootSpecialLine },
        { 0x80026E08, &P_PlayerInSpecialSector },
        { 0x80026FC8, &P_UpdateSpecials },
        { 0x8002745C, &EV_DoDonut },
        { 0x800276A8, &G_ScheduleExitLevel },
        { 0x80027718, &G_BeginExitLevel },
        { 0x80027768, &G_ExitLevel },
        { 0x800277E0, &G_SecretExitLevel },
        { 0x8002784C, &P_SpawnSpecials },
        { 0x80027EA8, &P_StartButton },
        { 0x80027F3C, &P_ChangeSwitchTexture },
        { 0x8002822C, &P_UseSpecialLine },
        { 0x80028820, &P_Telefrag },
        { 0x80028918, &EV_Teleport },
        { 0x80028C38, &_thunk_P_AddThinker },
        { 0x80028C68, &_thunk_P_RemoveThinker },
        { 0x80028C74, &P_RunThinkers },
        { 0x80028D30, &P_RunMobjLate },
        { 0x80028D94, &P_CheckCheats },
        { 0x80029684, &P_Start },
        { 0x800297A0, &P_PlayerMove },
        { 0x80029918, &P_PlayerXYMovement },
        { 0x80029A08, &P_PlayerZMovement },
        { 0x80029B38, &P_PlayerMobjThink },
        { 0x80029DD4, &P_BuildMove },
        { 0x8002A2B8, &P_Thrust },
        { 0x8002A32C, &P_CalcHeight },
        { 0x8002A4E8, &P_MovePlayer },
        { 0x8002A6A0, &P_DeathThink },
        { 0x8002A7F8, &P_PlayerThink },
        { 0x80030BA0, &_thunk_R_PointToAngle2 },
        { 0x80030F5C, &_thunk_R_PointInSubsector },
        { 0x800321D0, &_thunk_Z_Malloc },
        { 0x800323C8, &_thunk_Z_EndMalloc },
        { 0x800325D8, &_thunk_Z_Free2 },
        { 0x80032934, &I_PSXInit },
        { 0x80032BB8, &I_ReadGamepad },
        { 0x8003472C, &I_NetSetup },
        { 0x80034A60, &I_NetUpdate },
        { 0x80034CB8, &I_NetHandshake },
        { 0x80034D14, &I_NetSendRecv },
        { 0x80034E58, &I_SubmitGpuCmds },
        { 0x80034EA4, &I_LocalButtonsToNet },
        { 0x80034F04, &I_NetButtonsToLocal },
        { 0x80034F54, &START_Legals },
        { 0x80035098, &START_Title },
        { 0x80035C94, &M_Start },
        { 0x80036E1C, &START_PasswordScreen },
        { 0x8003793C, &START_ControlsScreen },
        { 0x80037DBC, &P_ComputePassword },
        { 0x800381B0, &P_ProcessPassword },
        { 0x80038610, &ST_InitEveryLevel },
        { 0x80038688, &ST_Ticker },
        { 0x8003C758, &IN_Start },
        { 0x8003D6D0, &F1_Start },
        { 0x8003D9C4, &F2_Start },
        { 0x8003E910, &O_Init },
        { 0x8003F134, &_thunk_FixedMul },
        { 0x8003F180, &_thunk_FixedDiv },

        { 0x80040FAC, &S_SetSfxVolume },
        { 0x80040FCC, &S_SetMusicVolume },
        { 0x80041014, &S_StopMusicSequence },
        { 0x80041050, &S_StartMusicSequence },
        { 0x80041098, &ZeroHalfWord },
        { 0x800410A0, &S_UnloadSamples },
        { 0x80041118, &S_LoadSoundAndMusic },
        { 0x80041318, &S_Pause },
        { 0x80041340, &S_Resume },
        { 0x80041368, &S_StopSound },
        { 0x800413A8, &I_StartSound },
        { 0x800415B4, &_thunk_S_StartSound },
        { 0x800415D4, &S_UpdateSounds },
        { 0x800415EC, &PsxSoundInit },
        { 0x8004172C, &PsxSoundExit },
        { 0x80045F8C, &_thunk_PSX_DriverInit },
        { 0x800461B4, &_thunk_PSX_DriverExit },
        { 0x800461D4, &PSX_DriverEntry1 },
        { 0x80046484, &PSX_DriverEntry2 },
        { 0x8004648C, &PSX_DriverEntry3 },
        { 0x80046494, &_thunk_PSX_TrkOff },
        { 0x80046540, &_thunk_PSX_TrkMute },
        { 0x800466FC, &_thunk_PSX_PatchChg },
        { 0x80046724, &_thunk_PSX_PatchMod },
        { 0x8004672C, &_thunk_PSX_PitchMod },
        { 0x8004697C, &_thunk_PSX_ZeroMod },
        { 0x80046984, &_thunk_PSX_ModuMod },
        { 0x8004698C, &_thunk_PSX_VolumeMod },
        { 0x80046CA4, &_thunk_PSX_PanMod },
        { 0x80046F80, &_thunk_PSX_PedalMod },
        { 0x80046F88, &_thunk_PSX_ReverbMod },
        { 0x80046F90, &_thunk_PSX_ChorusMod },
        { 0x80047394, &_thunk_PSX_NoteOn },
        { 0x80047578, &_thunk_PSX_NoteOff },
        { 0x800476DC, &Write_Vlq },
        { 0x8004773C, &Len_Vlq },
        { 0x800477A8, &_thunk_Eng_DriverInit },
        { 0x800477E4, &_thunk_Eng_DriverExit },
        { 0x800477EC, &Eng_DriverEntry1 },
        { 0x800477F4, &Eng_DriverEntry2 },
        { 0x800477FC, &Eng_DriverEntry3 },
        { 0x80047804, &_thunk_Eng_TrkOff },
        { 0x800479B0, &_thunk_Eng_TrkMute },
        { 0x800479B8, &_thunk_Eng_PatchChg },
        { 0x800479E0, &_thunk_Eng_PatchMod },
        { 0x800479E8, &_thunk_Eng_PitchMod },
        { 0x80047A10, &_thunk_Eng_ZeroMod },
        { 0x80047A18, &_thunk_Eng_ModuMod },
        { 0x80047A20, &_thunk_Eng_VolumeMod },
        { 0x80047A40, &_thunk_Eng_PanMod },
        { 0x80047A60, &_thunk_Eng_PedalMod },
        { 0x80047A68, &_thunk_Eng_ReverbMod },
        { 0x80047A70, &_thunk_Eng_ChorusMod },
        { 0x80047A78, &_thunk_Eng_NoteOn },
        { 0x80047A80, &_thunk_Eng_NoteOff },
        { 0x80047A88, &Eng_StatusMark },
        { 0x80047BA4, &Eng_GateJump },
        { 0x80047C90, &_thunk_Eng_IterJump },
        { 0x80047D8C, &_thunk_Eng_ResetGates },
        { 0x80047E90, &_thunk_Eng_ResetIters },
        { 0x80047F94, &_thunk_Eng_WriteIterBox },
        { 0x80047FD8, &Eng_SeqTempo },
        { 0x80048158, &Eng_SeqGosub },
        { 0x80048334, &Eng_SeqJump },
        { 0x800484DC, &Eng_SeqRet },
        { 0x8004862C, &Eng_SeqEnd },
        { 0x800488D4, &Eng_TrkTempo },
        { 0x80048930, &Eng_TrkGosub },
        { 0x800489C4, &_thunk_Eng_TrkJump },
        { 0x80048A34, &Eng_TrkRet },
        { 0x80048A88, &_thunk_Eng_TrkEnd },
        { 0x80048B8C, &_thunk_Eng_NullEvent },
        { 0x80048B94, &SeqEngine },

        { 0x80049C3C, &LIBAPI_write },
        { 0x80049C5C, &LIBAPI_InitPAD },
        { 0x80049DEC, &LIBAPI_StartPAD },
        { 0x80049DFC, &LIBAPI_ChangeClearPAD },
        { 0x80049E1C, &LIBAPI_read },
        { 0x80049E2C, &LIBAPI_TestEvent },
        { 0x80049E4C, &LIBAPI_open },
        { 0x8004A7AC, &LIBETC_ResetCallback },
        { 0x8004AD80, &LIBAPI_ReturnFromException },
        { 0x8004BA94, &_thunk_LIBETC_VSync },
        { 0x8004BBDC, &_thunk_LIBETC_v_wait },
        { 0x80050884, &LIBAPI_InitHeap },
        { 0x80053D48, &LIBAPI_DeliverEvent },
        { 0x800574A8, &LIBCOMB_UNKNOWN_func_1 },
        { 0x800575E8, &LIBCOMB_UNKNOWN_func_2 },
        { 0x80057728, &LIBCOMB_UNKNOWN_func_3 },
        { 0x80057850, &LIBCOMB_UNKNOWN_func_4 },
        { 0x80057DA4, &LIBCOMB_UNKNOWN_func_5 },
        { 0x80057DF4, &LIBCOMB_UNKNOWN_func_6 },
        { 0x80057DFC, &LIBCOMB_UNKNOWN_func_7 },
        { 0x80057E58, &LIBCOMB_UNKNOWN_func_8 },
        { 0x80057F64, &LIBCOMB_UNKNOWN_func_9 },
        { 0x800580A8, &LIBCOMB_ChangeClearSIO },
        { 0x800580B4, &LIBCOMB_AddCOMB },
        { 0x800580E0, &LIBCOMB_DelCOMB },
        { 0x8005810C, &LIBCOMB_UNKNOWN_ctrl_help },
        { 0x80058534, &LIBCOMB__comb_control },
        { 0x80058A18, &LIBAPI_SysEnqIntRP },
        { 0x80058A28, &LIBAPI_AddDrv },
        { 0x80058A38, &LIBAPI_DelDrv },
        { 0x80058A48, &LIBCOMB__ioabort },
    };
}
