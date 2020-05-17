#define PSX_VM_NO_REGISTER_MACROS 1     // In case of conflicts
#include "PsxVm.h"

#include <map>

extern void _thunk_D_memset() noexcept;
extern void _thunk_D_memcpy() noexcept;
extern void _thunk_D_strncasecmp() noexcept;
extern void _thunk_P_Random() noexcept;
extern void M_AddPointToBox() noexcept;
extern void _thunk_T_MoveCeiling() noexcept;
extern void _thunk_T_VerticalDoor() noexcept;
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
extern void _thunk_T_MoveFloor() noexcept;
extern void _thunk_T_FireFlicker() noexcept;
extern void _thunk_T_LightFlash() noexcept;
extern void _thunk_T_StrobeFlash() noexcept;
extern void _thunk_T_Glow() noexcept;
extern void _thunk_P_RemoveMobj() noexcept;
extern void _thunk_P_ExplodeMissile() noexcept;
extern void P_SpawnPlayer() noexcept;
extern void _thunk_T_PlatRaise() noexcept;
extern void P_RecursiveSound() noexcept;
extern void P_NoiseAlert() noexcept;
extern void P_BringUpWeapon() noexcept;
extern void P_CheckAmmo() noexcept;
extern void P_FireWeapon() noexcept;
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
extern void P_SlideMove() noexcept;
extern void P_CompletableFrac() noexcept;
extern void SL_PointOnSide() noexcept;
extern void SL_CrossFrac() noexcept;
extern void CheckLineEnds() noexcept;
extern void ClipToLine() noexcept;
extern void SL_CheckLine() noexcept;
extern void SL_PointOnSide2() noexcept;
extern void SL_CheckSpecialLines() noexcept;
extern void _thunk_T_DelayedAction() noexcept;
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
extern void I_PSXInit() noexcept;
extern void I_ReadGamepad() noexcept;
extern void I_NetSetup() noexcept;
extern void I_NetUpdate() noexcept;
extern void I_NetHandshake() noexcept;
extern void I_NetSendRecv() noexcept;
extern void I_SubmitGpuCmds() noexcept;
extern void I_LocalButtonsToNet() noexcept;
extern void I_NetButtonsToLocal() noexcept;
extern void _thunk_FixedMul() noexcept;
extern void _thunk_FixedDiv() noexcept;
extern void G_CompleteLevel() noexcept;     // TODO: remove eventually - still required because it's called via a thinker function in 'T_DelayedAction'.

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
        { 0x80014A30, &_thunk_T_MoveCeiling },
        { 0x800152FC, &_thunk_T_VerticalDoor },
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
        { 0x80019010, &_thunk_T_MoveFloor },
        { 0x8001AD74, &_thunk_T_FireFlicker },
        { 0x8001AE8C, &_thunk_T_LightFlash },
        { 0x8001AFBC, &_thunk_T_StrobeFlash },
        { 0x8001B4A0, &_thunk_T_Glow },
        { 0x8001C724, &_thunk_P_RemoveMobj },
        { 0x8001CB9C, &_thunk_P_ExplodeMissile },
        { 0x8001CE40, &P_SpawnPlayer },
        { 0x8001F280, &_thunk_T_PlatRaise },
        { 0x8001F918, &P_RecursiveSound },
        { 0x8001FA34, &P_NoiseAlert },
        { 0x8001FC18, &P_BringUpWeapon },
        { 0x8001FD4C, &P_CheckAmmo },
        { 0x8001FFBC, &P_FireWeapon },
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
        { 0x8002502C, &P_SlideMove },
        { 0x800251BC, &P_CompletableFrac },
        { 0x80025460, &SL_PointOnSide },
        { 0x800254D0, &SL_CrossFrac },
        { 0x80025588, &CheckLineEnds },
        { 0x80025648, &ClipToLine },
        { 0x80025840, &SL_CheckLine },
        { 0x80025A8C, &SL_PointOnSide2 },
        { 0x80025AFC, &SL_CheckSpecialLines },
        { 0x80027718, &_thunk_T_DelayedAction },
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
        { 0x80032934, &I_PSXInit },
        { 0x80032BB8, &I_ReadGamepad },
        { 0x8003472C, &I_NetSetup },
        { 0x80034A60, &I_NetUpdate },
        { 0x80034CB8, &I_NetHandshake },
        { 0x80034D14, &I_NetSendRecv },
        { 0x80034E58, &I_SubmitGpuCmds },
        { 0x80034EA4, &I_LocalButtonsToNet },
        { 0x80034F04, &I_NetButtonsToLocal },
        { 0x8003F134, &_thunk_FixedMul },
        { 0x8003F180, &_thunk_FixedDiv },
        { 0x80013384, &G_CompleteLevel },   // TODO: remove eventually - still required because it's called via a thinker function in 'T_DelayedAction'.
        
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
