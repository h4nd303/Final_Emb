/*********************************************************************************************************//**
 * @file    ht32_dependency.h
 * @version $Rev:: 5246         $
 * @date    $Date:: 2021-02-04 #$
 * @brief   The header file of dependency check.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif


#if 0 // Version setting example for module

/* Dependency check ----------------------------------------------------------------------------------------*/
#define MIN_HT32_FWLIB_VER              (005)
#define MIN_HT32_FWLIB_SVN              (2200)
#include "ht32_dependency.h" // Not exist means the the version of HT32 Firmwar Library is older than the module required.

#endif


#if 0 // Enable for test
#undef HT32_FWLIB_VER
#undef HT32_FWLIB_SVN
#define HT32_FWLIB_VER                  (004)
#define HT32_FWLIB_SVN                  (1074)
#endif


// Check "ht32fxxxxx_lib.h" for the version of HT32 Firmwar Library

#if HT32_FWLIB_VER < MIN_HT32_FWLIB_VER
  #error !!! The version of HT32 Firmwar Library is older than the module required. Please update HT32 Firmwar Library.
#endif

#if HT32_FWLIB_SVN < MIN_HT32_FWLIB_SVN
  #error !!! The version of HT32 Firmwar Library is older than the module required. Please update HT32 Firmwar Library.
#endif


// Un-defined for next module of the .C include .C case
#undef MIN_HT32_FWLIB_VER
#undef MIN_HT32_FWLIB_SVN


#ifdef __cplusplus
}
#endif

//#endif
