#include "ProgElems.h"

static const ProgElem ELEMS[] = {
    { 0x80012274, 0x800123A4, "",                                   ProgElemType::FUNCTION },
    { 0x800123E4, 0x80012424, "",                                   ProgElemType::FUNCTION },
    { 0x80012424, 0x800124A8, "",                                   ProgElemType::FUNCTION },
    { 0x800124A8, 0x800124E8, "",                                   ProgElemType::FUNCTION },
    { 0x80012850, 0x8001290C, "",                                   ProgElemType::FUNCTION },
    { 0x8001290C, 0x80012940, "",                                   ProgElemType::FUNCTION },
    { 0x8001297C, 0x800129D4, "",                                   ProgElemType::FUNCTION },
    { 0x80012A18, 0x80012A44, "",                                   ProgElemType::FUNCTION },
    { 0x80012A70, 0x80012A80, "",                                   ProgElemType::FUNCTION },
    { 0x80012A80, 0x80012AA0, "",                                   ProgElemType::FUNCTION },
    { 0x80012AA0, 0x80012B10, "",                                   ProgElemType::FUNCTION },
    { 0x80012B78, 0x80012BD8, "",                                   ProgElemType::FUNCTION }, // TODO: figure out func ptr jump
    { 0x80012E04, 0x80012F00, "",                                   ProgElemType::FUNCTION },
    { 0x80013394, 0x80013528, "",                                   ProgElemType::FUNCTION },
    { 0x80013528, 0x80013714, "",                                   ProgElemType::FUNCTION },
    { 0x80013714, 0x80013838, "",                                   ProgElemType::FUNCTION },
    { 0x80013838, 0x80013840, "empty_func1",                        ProgElemType::FUNCTION },
    { 0x80014E54, 0x80014EBC, "",                                   ProgElemType::FUNCTION },
    { 0x8001C408, 0x8001C540, "",                                   ProgElemType::FUNCTION },
    { 0x8001D184, 0x8001D704, "",                                   ProgElemType::FUNCTION },
    { 0x80021BA0, 0x80021DD8, "",                                   ProgElemType::FUNCTION },
    { 0x80021EC4, 0x80022104, "",                                   ProgElemType::FUNCTION },
    { 0x80022104, 0x80022278, "",                                   ProgElemType::FUNCTION },
    { 0x8002237C, 0x80022650, "",                                   ProgElemType::FUNCTION },
    { 0x80022650, 0x800227CC, "",                                   ProgElemType::FUNCTION },
    { 0x800227CC, 0x800228CC, "",                                   ProgElemType::FUNCTION },
    { 0x80022920, 0x80022B58, "",                                   ProgElemType::FUNCTION },
    { 0x80022B58, 0x80022E68, "",                                   ProgElemType::FUNCTION },
    { 0x800230D4, 0x80023700, "",                                   ProgElemType::FUNCTION }, // TODO: appears to be referenced by func ptrs
    { 0x80028C68, 0x80028C74, "",                                   ProgElemType::FUNCTION },
    { 0x8002B9A8, 0x8002B9E0, "",                                   ProgElemType::FUNCTION },
    { 0x8002B9E0, 0x8002BB50, "",                                   ProgElemType::FUNCTION },
    { 0x8002BB50, 0x8002BC54, "",                                   ProgElemType::FUNCTION },
    { 0x8002BC54, 0x8002BDA4, "",                                   ProgElemType::FUNCTION },
    { 0x8002BDA4, 0x8002BE68, "",                                   ProgElemType::FUNCTION },
    { 0x8002BE68, 0x8002BF2C, "",                                   ProgElemType::FUNCTION },
    { 0x8002BF2C, 0x8002C07C, "",                                   ProgElemType::FUNCTION }, // TODO (stuck on referenced func 8004C438)
    { 0x800305B0, 0x80030634, "",                                   ProgElemType::FUNCTION },
    { 0x80030F5C, 0x80031088, "",                                   ProgElemType::FUNCTION },
    { 0x800310C8, 0x80031394, "",                                   ProgElemType::FUNCTION },
    { 0x80031394, 0x800314A4, "",                                   ProgElemType::FUNCTION },
    { 0x80031558, 0x80031648, "",                                   ProgElemType::FUNCTION },
    { 0x80031648, 0x80031698, "",                                   ProgElemType::FUNCTION },
    { 0x800317AC, 0x800319E4, "",                                   ProgElemType::FUNCTION },
    { 0x800319E4, 0x80031B04, "",                                   ProgElemType::FUNCTION },
    { 0x80031B04, 0x80031BD4, "",                                   ProgElemType::FUNCTION },
    { 0x80031BD4, 0x80031C24, "",                                   ProgElemType::FUNCTION },
    { 0x80031C24, 0x80031CE0, "",                                   ProgElemType::FUNCTION },
    { 0x80031CE0, 0x80031D90, "",                                   ProgElemType::FUNCTION },
    { 0x80031D90, 0x80031E48, "",                                   ProgElemType::FUNCTION },
    { 0x80031EB4, 0x80031EDC, "",                                   ProgElemType::FUNCTION },
    { 0x80031EDC, 0x80031FD8, "",                                   ProgElemType::FUNCTION },
    { 0x80031FD8, 0x80032024, "",                                   ProgElemType::FUNCTION },
    { 0x80032024, 0x8003206C, "",                                   ProgElemType::FUNCTION },
    { 0x8003206C, 0x80032144, "",                                   ProgElemType::FUNCTION },
    { 0x80032144, 0x8003219C, "",                                   ProgElemType::FUNCTION },
    { 0x8003219C, 0x800321D0, "",                                   ProgElemType::FUNCTION },
    { 0x800321D0, 0x800323C8, "",                                   ProgElemType::FUNCTION },
    { 0x800323C8, 0x800325D8, "",                                   ProgElemType::FUNCTION },
    { 0x800325D8, 0x80032640, "",                                   ProgElemType::FUNCTION },
    { 0x80032640, 0x80032770, "",                                   ProgElemType::FUNCTION },
    { 0x80032770, 0x80032838, "",                                   ProgElemType::FUNCTION },
    { 0x80032904, 0x8003290C, "empty_func2",                        ProgElemType::FUNCTION },
    { 0x8003290C, 0x80032934, "",                                   ProgElemType::FUNCTION },
    { 0x80032934, 0x80032B0C, "",                                   ProgElemType::FUNCTION }, // TODO: confused by referenced call '80058534'
    { 0x80032B0C, 0x80032BB8, "MAYBE_err_func_no_return",           ProgElemType::FUNCTION }, // TODO: confused by referenced call '8004F6AC'
    { 0x80032BF4, 0x80032D04, "",                                   ProgElemType::FUNCTION },
    { 0x80032D04, 0x80032D84, "",                                   ProgElemType::FUNCTION },
    { 0x80032D84, 0x800332E0, "",                                   ProgElemType::FUNCTION },
    { 0x800332E0, 0x800333D8, "",                                   ProgElemType::FUNCTION },
    { 0x800333D8, 0x800333F0, "",                                   ProgElemType::FUNCTION },
    { 0x800333F0, 0x8003350C, "",                                   ProgElemType::FUNCTION },
    { 0x8003352C, 0x80033578, "",                                   ProgElemType::FUNCTION },
    { 0x80033578, 0x8003390C, "",                                   ProgElemType::FUNCTION },
    { 0x8003390C, 0x8003397C, "",                                   ProgElemType::FUNCTION },
    { 0x8003397C, 0x80033AC4, "",                                   ProgElemType::FUNCTION },
    { 0x8003472C, 0x80034A60, "",                                   ProgElemType::FUNCTION }, // TODO: figure out referenced func '80058534' - may have a switch statement jump table
    { 0x80034CB8, 0x80034D14, "",                                   ProgElemType::FUNCTION },
    { 0x80034D14, 0x80034E58, "",                                   ProgElemType::FUNCTION }, // TODO: figure out referenced func '80058534' - may have a switch statement jump table
    { 0x80034E58, 0x80034EA4, "",                                   ProgElemType::FUNCTION },
    { 0x80034EA4, 0x80034F04, "",                                   ProgElemType::FUNCTION },
    { 0x80034F04, 0x80034F54, "",                                   ProgElemType::FUNCTION },
    { 0x80035B24, 0x80035C94, "",                                   ProgElemType::FUNCTION },
    { 0x80038558, 0x80038610, "",                                   ProgElemType::FUNCTION },
    { 0x8003F180, 0x8003F200, "",                                   ProgElemType::FUNCTION },
    { 0x8003F200, 0x8003F234, "",                                   ProgElemType::FUNCTION },
    { 0x8003F234, 0x8003F2F0, "",                                   ProgElemType::FUNCTION },
    { 0x8003F2F0, 0x8003F3AC, "",                                   ProgElemType::FUNCTION },
    { 0x8003F894, 0x8003F8A0, "",                                   ProgElemType::FUNCTION },
    { 0x8003F8A0, 0x8003F8B0, "",                                   ProgElemType::FUNCTION },
    { 0x8003F8B0, 0x8003F98C, "",                                   ProgElemType::FUNCTION },
    { 0x8003F9BC, 0x8003FACC, "",                                   ProgElemType::FUNCTION },
    { 0x8003FACC, 0x8003FB9C, "",                                   ProgElemType::FUNCTION },
    { 0x8003FB9C, 0x8003FBBC, "",                                   ProgElemType::FUNCTION },
    { 0x8003FBBC, 0x8003FCC4, "",                                   ProgElemType::FUNCTION },
    { 0x8003FE20, 0x8003FE58, "",                                   ProgElemType::FUNCTION },
    { 0x8003FE58, 0x8003FEA4, "",                                   ProgElemType::FUNCTION },
    { 0x8003FEA4, 0x800406D4, "",                                   ProgElemType::FUNCTION },
    { 0x800406D4, 0x800407C8, "",                                   ProgElemType::FUNCTION },
    { 0x800407C8, 0x80040830, "",                                   ProgElemType::FUNCTION },
    { 0x80040830, 0x80040838, "empty_func3",                        ProgElemType::FUNCTION },
    { 0x80040FAC, 0x80040FCC, "",                                   ProgElemType::FUNCTION },
    { 0x80040FCC, 0x80041014, "",                                   ProgElemType::FUNCTION },
    { 0x80041014, 0x80041050, "",                                   ProgElemType::FUNCTION },
    { 0x80041098, 0x800410A0, "",                                   ProgElemType::FUNCTION },
    { 0x800410A0, 0x80041118, "",                                   ProgElemType::FUNCTION },
    { 0x80041118, 0x80041318, "",                                   ProgElemType::FUNCTION },
    { 0x800415B4, 0x800415D4, "",                                   ProgElemType::FUNCTION },
    { 0x800415EC, 0x8004172C, "",                                   ProgElemType::FUNCTION },
    { 0x80041E78, 0x80041EA4, "",                                   ProgElemType::FUNCTION },
    { 0x80041EBC, 0x80041ECC, "",                                   ProgElemType::FUNCTION },
    { 0x80041ECC, 0x80041EDC, "",                                   ProgElemType::FUNCTION },
    { 0x80041EDC, 0x80041EEC, "",                                   ProgElemType::FUNCTION },
    { 0x80041EEC, 0x80041F48, "",                                   ProgElemType::FUNCTION },
    { 0x80041F6C, 0x80041F8C, "",                                   ProgElemType::FUNCTION },
    { 0x80041FAC, 0x80042010, "",                                   ProgElemType::FUNCTION },
    { 0x800420AC, 0x800420BC, "",                                   ProgElemType::FUNCTION },
    { 0x800420BC, 0x8004210C, "",                                   ProgElemType::FUNCTION },
    { 0x8004210C, 0x80042218, "",                                   ProgElemType::FUNCTION },
    { 0x80042218, 0x8004224C, "",                                   ProgElemType::FUNCTION },
    { 0x8004224C, 0x800422EC, "",                                   ProgElemType::FUNCTION },
    { 0x800422EC, 0x800430C4, "",                                   ProgElemType::FUNCTION },
    { 0x8004371C, 0x800437F0, "",                                   ProgElemType::FUNCTION },
    { 0x800437F0, 0x8004397C, "",                                   ProgElemType::FUNCTION },
    { 0x8004397C, 0x80043AF8, "",                                   ProgElemType::FUNCTION },
    { 0x80043AF8, 0x80043B18, "",                                   ProgElemType::FUNCTION },
    { 0x80043B20, 0x80043B28, "",                                   ProgElemType::FUNCTION },
    { 0x80043B28, 0x80043B30, "empty_func4",                        ProgElemType::FUNCTION },
    { 0x80043C1C, 0x80043CA8, "",                                   ProgElemType::FUNCTION },
    { 0x80043D20, 0x80043D94, "",                                   ProgElemType::FUNCTION },
    { 0x80043D94, 0x80043DB4, "",                                   ProgElemType::FUNCTION },
    { 0x80043DB4, 0x80043DD4, "",                                   ProgElemType::FUNCTION },
    { 0x80043DF4, 0x80043E14, "",                                   ProgElemType::FUNCTION },
    { 0x80043E14, 0x80043E1C, "",                                   ProgElemType::FUNCTION },
    { 0x80044740, 0x80044778, "",                                   ProgElemType::FUNCTION },
    { 0x80044790, 0x800447BC, "",                                   ProgElemType::FUNCTION },
    { 0x800447BC, 0x80044828, "",                                   ProgElemType::FUNCTION },
    { 0x80044828, 0x8004487C, "",                                   ProgElemType::FUNCTION },
    { 0x8004487C, 0x80045028, "",                                   ProgElemType::FUNCTION },
    { 0x80045028, 0x8004513C, "",                                   ProgElemType::FUNCTION },
    { 0x800451F4, 0x80045298, "",                                   ProgElemType::FUNCTION },
    { 0x80045298, 0x80045328, "",                                   ProgElemType::FUNCTION },
    { 0x80045328, 0x80045408, "",                                   ProgElemType::FUNCTION },
    { 0x80045450, 0x800454FC, "",                                   ProgElemType::FUNCTION }, // TODO: referenced function '80053DA0' contains a switch statement
    { 0x80045540, 0x80045584, "",                                   ProgElemType::FUNCTION }, // TODO: referenced function '80053DA0' contains a switch statement
    { 0x800455CC, 0x8004560C, "",                                   ProgElemType::FUNCTION }, // TODO: referenced function '80053DA0' contains a switch statement
    { 0x80045720, 0x8004577C, "",                                   ProgElemType::FUNCTION },
    { 0x8004577C, 0x8004578C, "",                                   ProgElemType::FUNCTION },
    { 0x8004578C, 0x80045844, "",                                   ProgElemType::FUNCTION },
    { 0x80045868, 0x80045880, "",                                   ProgElemType::FUNCTION },
    { 0x80048EE4, 0x80048FCC, "",                                   ProgElemType::FUNCTION },
    { 0x80048FCC, 0x80048FF8, "",                                   ProgElemType::FUNCTION },
    { 0x80048FF8, 0x8004906C, "",                                   ProgElemType::FUNCTION },
    { 0x8004906C, 0x800493AC, "",                                   ProgElemType::FUNCTION },
    { 0x800493AC, 0x80049454, "",                                   ProgElemType::FUNCTION },
    { 0x80049454, 0x800497D8, "",                                   ProgElemType::FUNCTION },
    { 0x80049838, 0x80049870, "",                                   ProgElemType::FUNCTION },
    { 0x80049870, 0x80049A30, "",                                   ProgElemType::FUNCTION },
    { 0x80049ADC, 0x80049B90, "",                                   ProgElemType::FUNCTION },
    { 0x80049B90, 0x80049C1C, "",                                   ProgElemType::FUNCTION },
    { 0x80049C1C, 0x80049C2C, "LIBAPI_CloseEvent",                  ProgElemType::FUNCTION },
    { 0x80049C2C, 0x80049C3C, "LIBAPI_EnterCriticalSection",        ProgElemType::FUNCTION },
    { 0x80049C3C, 0x80049C4C, "LIBAPI_write",                       ProgElemType::FUNCTION },
    { 0x80049C4C, 0x80049C5C, "LIBAPI_EnableEvent",                 ProgElemType::FUNCTION },
    { 0x80049C5C, 0x80049C6C, "LIBAPI_InitPAD2",                    ProgElemType::FUNCTION },
    { 0x80049C6C, 0x80049D08, "",                                   ProgElemType::FUNCTION },
    { 0x80049D40, 0x80049D70, "",                                   ProgElemType::FUNCTION },
    { 0x80049DDC, 0x80049DEC, "LIBAPI_DisableEvent",                ProgElemType::FUNCTION },
    { 0x80049DEC, 0x80049DFC, "LIBAPI_StartPAD2",                   ProgElemType::FUNCTION },
    { 0x80049DFC, 0x80049E0C, "LIBAPI_ChangeClearPAD",              ProgElemType::FUNCTION },
    { 0x80049E0C, 0x80049E1C, "LIBAPI_OpenEvent",                   ProgElemType::FUNCTION },
    { 0x80049E1C, 0x80049E2C, "LIBAPI_read",                        ProgElemType::FUNCTION },
    { 0x80049E2C, 0x80049E3C, "LIBAPI_TestEvent",                   ProgElemType::FUNCTION },
    { 0x80049E3C, 0x80049E4C, "LIBAPI_ExitCriticalSection",         ProgElemType::FUNCTION },
    { 0x80049E4C, 0x80049E5C, "LIBAPI_open",                        ProgElemType::FUNCTION },
    { 0x8004A7AC, 0x8004A7DC, "",                                   ProgElemType::FUNCTION },
    { 0x8004A7DC, 0x8004A80C, "",                                   ProgElemType::FUNCTION },
    { 0x8004A8E4, 0x8004A9A4, "",                                   ProgElemType::FUNCTION },
    { 0x8004A8E4, 0x8004A9A4, "",                                   ProgElemType::FUNCTION },
    { 0x8004A9A4, 0x8004AB74, "",                                   ProgElemType::FUNCTION },
    { 0x8004AD14, 0x8004AD40, "",                                   ProgElemType::FUNCTION },
    { 0x8004AD40, 0x8004AD50, "LIBAPI_HookEntryInt",                ProgElemType::FUNCTION },
    { 0x8004AD50, 0x8004AD60, "LIBAPI_ResetEntryInt",               ProgElemType::FUNCTION },
    { 0x8004AD60, 0x8004AD70, "LIBAPI_ChangeClearRCnt",             ProgElemType::FUNCTION },
    { 0x8004AD70, 0x8004AD80, "",                                   ProgElemType::FUNCTION },
    { 0x8004AD80, 0x8004AD90, "LIBAPI_ReturnFromException",         ProgElemType::FUNCTION },
    { 0x8004AD90, 0x8004ADD0, "",                                   ProgElemType::FUNCTION }, // TODO: references funnction with switch statements '8004AE50'
    { 0x8004ADD0, 0x8004AE0C, "",                                   ProgElemType::FUNCTION },
    { 0x8004B530, 0x8004B5F0, "",                                   ProgElemType::FUNCTION },
    { 0x8004B5F0, 0x8004B654, "",                                   ProgElemType::FUNCTION },
    { 0x8004B908, 0x8004B934, "",                                   ProgElemType::FUNCTION },
    { 0x8004B934, 0x8004B9AC, "",                                   ProgElemType::FUNCTION },
    { 0x8004BA68, 0x8004BA94, "",                                   ProgElemType::FUNCTION },
    { 0x8004BA94, 0x8004BBDC, "",                                   ProgElemType::FUNCTION },
    { 0x8004BBDC, 0x8004BC78, "",                                   ProgElemType::FUNCTION },
    { 0x8004BC78, 0x8004BCC8, "",                                   ProgElemType::FUNCTION },
    { 0x8004BCC8, 0x8004BEF0, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004C004, 0x8004C070, "",                                   ProgElemType::FUNCTION },
    { 0x8004C198, 0x8004C210, "",                                   ProgElemType::FUNCTION },
    { 0x8004C210, 0x8004C27C, "",                                   ProgElemType::FUNCTION },
    { 0x8004C438, 0x8004C49C, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004C500, 0x8004C5A0, "",                                   ProgElemType::FUNCTION },
    { 0x8004C72C, 0x8004C79C, "",                                   ProgElemType::FUNCTION },
    { 0x8004C79C, 0x8004C860, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004C898, 0x8004CCBC, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004CE54, 0x8004CEAC, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004E884, 0x8004E8B0, "",                                   ProgElemType::FUNCTION },
    { 0x8004E8B0, 0x8004E8C0, "LIBAPI_GPU_cw",                      ProgElemType::FUNCTION },
    { 0x8004E928, 0x8004E9F0, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004E9F0, 0x8004EA08, "",                                   ProgElemType::FUNCTION },
    { 0x8004F09C, 0x8004F0DC, "",                                   ProgElemType::FUNCTION },
    { 0x8004F0DC, 0x8004F180, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004F180, 0x8004F44C, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004F44C, 0x8004F6AC, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004FC28, 0x8004FCB8, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8004FCB8, 0x8004FCF4, "",                                   ProgElemType::FUNCTION },
    { 0x80050100, 0x80050130, "",                                   ProgElemType::FUNCTION },
    { 0x80050190, 0x800501B4, "",                                   ProgElemType::FUNCTION },
    { 0x800502EC, 0x80050304, "",                                   ProgElemType::FUNCTION },
    { 0x80050304, 0x80050310, "",                                   ProgElemType::FUNCTION },
    { 0x80050334, 0x800503B4, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80050714, 0x800507AC, "main",                               ProgElemType::FUNCTION },
    { 0x800507AC, 0x8005081C, "",                                   ProgElemType::FUNCTION }, // TODO: figure out func ptr jump
    { 0x80050884, 0x80050894, "LIBAPI_InitHeap",                    ProgElemType::FUNCTION },
    { 0x80051208, 0x8005171C, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80053D48, 0x80053D58, "LIBAPI_DeliverEvent",                ProgElemType::FUNCTION },
    { 0x80054134, 0x80054164, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054324, 0x80054334, "LIBAPI_WaitEvent",                   ProgElemType::FUNCTION },
    { 0x80054498, 0x80054518, "",                                   ProgElemType::FUNCTION },
    { 0x80054518, 0x80054580, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054580, 0x800545A0, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x800545A0, 0x80054670, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x800546E0, 0x80054788, "",                                   ProgElemType::FUNCTION },
    { 0x80054788, 0x800547DC, "",                                   ProgElemType::FUNCTION },
    { 0x800547DC, 0x80054830, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054830, 0x80054894, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054894, 0x800548F4, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054B00, 0x80054B90, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054C78, 0x80054C98, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054D20, 0x80054D40, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054D40, 0x80054D60, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054D60, 0x80054D78, "",                                   ProgElemType::FUNCTION },
    { 0x80054D78, 0x80054D90, "",                                   ProgElemType::FUNCTION },
    { 0x80054DA8, 0x80054EC0, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80054EC0, 0x80054FCC, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x80055114, 0x80055138, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x8005521C, 0x80055320, "",                                   ProgElemType::FUNCTION },
    { 0x80055320, 0x800553A0, "",                                   ProgElemType::FUNCTION },
    { 0x80057260, 0x80057284, "",                                   ProgElemType::FUNCTION }, // TODO
    { 0x800580B4, 0x800580E0, "",                                   ProgElemType::FUNCTION },
    { 0x80058A18, 0x80058A28, "LIBAPI_SysEnqIntRP",                 ProgElemType::FUNCTION },
    { 0x80058A28, 0x80058A38, "LIBAPI_AddDrv",                      ProgElemType::FUNCTION },
    { 0x80058A38, 0x80058A48, "LIBAPI_DelDrv",                      ProgElemType::FUNCTION },
};

const ProgElem*     gProgramElems_Doom = ELEMS;
const uint32_t      gNumProgramElems_Doom = sizeof(ELEMS) / sizeof(ProgElem);
