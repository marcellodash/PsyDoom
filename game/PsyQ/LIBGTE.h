#pragma once

#include <cstdint>

// Represents a basic transform matrix encoding a 3D rotation and translation
struct MATRIX {
    int16_t m[3][3];    // Rotation matrix: 3x3
    int32_t t[3];       // Translation
};

static_assert(sizeof(MATRIX) == 32);

void LIBGTE_MulMatrix() noexcept;
void LIBGTE_MulMatrix2() noexcept;
void LIBGTE_ApplyMatrix() noexcept;
void LIBGTE_ApplyMatrixSV() noexcept;
void LIBGTE_TransMatrix() noexcept;
void LIBGTE_ScaleMatrix() noexcept;

void LIBGTE_SetRotMatrix(const MATRIX& m) noexcept;
void _thunk_LIBGTE_SetRotMatrix() noexcept;

void LIBGTE_SetLightMatrix() noexcept;
void LIBGTE_SetColorMatrix() noexcept;
void LIBGTE_SetTransMatrix(const MATRIX& m) noexcept;
void LIBGTE_SetVertex0() noexcept;
void LIBGTE_SetVertex1() noexcept;
void LIBGTE_SetVertex2() noexcept;
void LIBGTE_SetVertexTri() noexcept;
void LIBGTE_SetRGBfifo() noexcept;
void LIBGTE_SetIR123() noexcept;
void LIBGTE_SetIR0() noexcept;
void LIBGTE_SetBackColor() noexcept;
void LIBGTE_SetFarColor() noexcept;
void LIBGTE_SetSZfifo3() noexcept;
void LIBGTE_SetSZfifo4() noexcept;
void LIBGTE_SetSXSYfifo() noexcept;
void LIBGTE_SetRii() noexcept;
void LIBGTE_SetMAC123() noexcept;
void LIBGTE_SetData32() noexcept;
void LIBGTE_SetGeomOffset() noexcept;
void LIBGTE_SetGeomScreen() noexcept;
void LIBGTE_SetDQA() noexcept;
void LIBGTE_SetDQB() noexcept;
void LIBGTE_InitGeom() noexcept;
void LIBGTE__patch_gte() noexcept;
void LIBGTE_RotTransPers() noexcept;
void LIBGTE_RotTransPers3() noexcept;
void LIBGTE_RotTrans() noexcept;
void LIBGTE_LocalLight() noexcept;
void LIBGTE_DpqColor() noexcept;
void LIBGTE_NormalColor() noexcept;
void LIBGTE_NormalColor3() noexcept;
void LIBGTE_NormalColorDpq() noexcept;
void LIBGTE_NormalColorDpq3() noexcept;
void LIBGTE_NormalColorCol() noexcept;
void LIBGTE_NormalColorCol3() noexcept;
void LIBGTE_ColorDpq() noexcept;
void LIBGTE_ColorCol() noexcept;
void LIBGTE_NormalClip() noexcept;
void LIBGTE_NormalClipS() noexcept;
void LIBGTE_AverageSZ3() noexcept;
void LIBGTE_AverageSZ4() noexcept;
