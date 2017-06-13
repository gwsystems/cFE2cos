/*================================================================================*
** File:  ut_osfile_test_platforms.h
** Owner: Tam Ngo
** Date:  September 2013
**================================================================================*/

#ifndef _UT_OSFILE_TEST_PLATFORMS_H_
#define _UT_OSFILE_TEST_PLATFORMS_H_

/*--------------------------------------------------------------------------------*
** Includes
**--------------------------------------------------------------------------------*/

#ifdef _LINUX_OS_
#endif  /* _LINUX_OS_ */

#ifdef OSP_ARINC653
#include "apex_api.h"
#endif  /* OSP_ARINC653 */

/*--------------------------------------------------------------------------------*
** Macros
**--------------------------------------------------------------------------------*/

/*--------------------------------------------*/
#ifdef _LINUX_OS_
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO \
    strncmp(g_readBuff, "UT_os_outputtofile_test", 7) == 0

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO              \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||       \
    (fdProps.IsValid != TRUE) ||                                    \
    (strncmp(fdProps.Path, g_fNames[0], strlen(g_fNames[0])) != 0))

/*--------------------------------------------*/
#endif  /* _LINUX_OS_ */
/*--------------------------------------------*/

/*--------------------------------------------*/
#ifdef _VXWORKS_OS_
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO \
    strncmp(&g_readBuff[1], cmd, strlen(cmd)) == 0

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO              \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||       \
    (fdProps.IsValid != TRUE) ||                                    \
    (strncmp(fdProps.Path, g_fNames[0], strlen(g_fNames[0])) != 0))

/*--------------------------------------------*/
#endif  /* _VXWORKS_OS_ */
/*--------------------------------------------*/

/*--------------------------------------------*/
#if defined(OSP_ARINC653) || defined(_RTEMS_OS_)
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO  1

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO         \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||  \
    (fdProps.IsValid != TRUE) ||                               \
    (strncmp(fdProps.Path, fileName, strlen(fileName)) != 0))

/*--------------------------------------------*/
#endif  /* OSP_ARINC653 */
/*--------------------------------------------*/

#ifdef COMPOSITE_OS

/* Copying VXWORKS defines. */
#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO \
    strncmp(&g_readBuff[1], cmd, strlen(cmd)) == 0

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO              \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||       \
    (fdProps.IsValid != TRUE) ||                                    \
    (strncmp(fdProps.Path, g_fNames[0], strlen(g_fNames[0])) != 0))

#endif
/*--------------------------------------------------------------------------------*
** Data types
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** External global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Function prototypes
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/

#endif  /* _UT_OSFILE_TEST_PLATFORMS_H_ */

/*================================================================================*
** End of File: ut_osfile_test_platforms.h
**================================================================================*/
