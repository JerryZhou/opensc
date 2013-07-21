/* [SCE CONFIDENTIAL DOCUMENT]
 * $PSLibId$
 *                Copyright (C) 2006 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __QUICKSORT_SPU_H__
#define __QUICKSORT_SPU_H__

#include "Physics/Base/SortCommon.h"

//	�n���ꂽ�o�b�t�@��4�������ė��p���邽�߁A
//	4�Ŋ���؂�鐔��numPrefetch�Ɏw�肷�邱��
void quickSortSPU(uint32_t start_ea,uint32_t end_ea,int numPrefetch);

#endif /* __QUICKSORT_SPU_H__ */
