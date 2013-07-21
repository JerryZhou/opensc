/* [SCE CONFIDENTIAL DOCUMENT]
 * $PSLibId$
 *                Copyright (C) 2006 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __HEIGHTFLUID_UTILITY_H__
#define __HEIGHTFLUID_UTILITY_H__

#include "Physics/HeightFluid/HeightFluidSurface.h"

namespace HeightFluidUtil {

///////////////////////////////////////////////////////////////////////////////
// ���ʃ��[�e�B���e�B�֐�

// ���ʃT�[�t�F�X�̍쐬
void createHeightFluidSurface(HeightFluidSurface &surface,int numWidth,int numDepth);

// ���ʃT�[�t�F�X�̔j��
void releaseHeightFluidSurface(HeightFluidSurface &surface);

} // namespace HeightFluidUtil

#endif /* __HEIGHTFLUID_UTILITY_H__ */
