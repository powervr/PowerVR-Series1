/**************************************************************************
 * Name         : sgl_init.c
 * Title        : SGL intialisation
 * Author       : Simon James Fenney
 * Created      : 22 May 1995
 *
 * Copyright : 1995-2022 Imagination Technologies (c)
 * License	 : MIT
 *
 * Description  : Global Vars/ Routines to initialise SGL. This contains a 
 *				  global variable which can be used to test if the system has
 *				  been initialised, and then a routine can be called to actually
 *				  get it flying.
 *
 * Platform     : ANSI 
 *
 * Modifications:-
 * $Log: sgl_init.c,v $
 * Revision 1.91  1997/11/21  12:03:47  sxy
 * made DebugInit() available to TIMING build.
 *
 * Revision 1.90  1997/09/25  11:46:59  sxy
 * changed debug level to MESSAGE for DEBUGDEV, and added some DPFDEV messages.
 *
 * Revision 1.89  1997/09/24  14:41:47  gdc
 * made sgl read in settings work same as new priority ini file reads
 *
 * Revision 1.88  1997/09/24  09:25:49  sxy
 * Made DebugInit() available to DEBUGDEV.
 *
 * Revision 1.87  1997/07/24  17:14:00  gdc
 * removed unneeded windows.h
 *
 * Revision 1.86  1997/07/14  09:58:53  gdc
 * tried to turn off windows include file warnings and failed
 *
 * Revision 1.85  1997/07/11  16:21:15  gdc
 * added two new functions to get ini file stuff in a manner controlled
 * by us
 *
 * Revision 1.84  1997/06/04  15:30:16  gdc
 * removed compiler warnings
 *
 * Revision 1.83  1997/06/02  02:48:24  jop
 * Removed no longer need ed mem file stuff
 *
 * Revision 1.82  1997/05/20  13:58:08  gdc
 * removed thread priority code
 *
 * Revision 1.81  1997/05/14  03:41:26  jop
 * Hacked about
 *
 * Revision 1.80  1997/05/02  16:35:55  jop
 * Killed off InitTextureInterface
 *
 * Revision 1.79  1997/05/01  16:47:30  mjg
 * Replaced a UINT32 and added a call to initialise the TEXAPI.
 *
 * Revision 1.78  1997/04/30  19:21:38  jop
 * Put Ed's changes back to how they were
 *
 * Revision 1.77  1997/04/29  14:51:24  erf
 * Added new PVROS API function call mechanism.
 *
 * Revision 1.76  1997/04/25  21:24:49  mjg
 * Changed non-Windows defines.
 *
 * Revision 1.75  1997/04/25  17:36:01  mjg
 * Removed more texturing functions.
 *
 * Revision 1.74  1997/04/25  11:24:24  gdc
 * removed tex heap initialisation that mjg had removed from sgllite
 *
 * Revision 1.73  1997/04/25  09:46:41  gdc
 * hardware and buffer initailisation removed for win32 builds - now
 * done in pvros upon physical/virtual device creation
 * NOTE: TexParamSize hard coded - this stuff should soon move to texapi
 * hopefully
 *
 * Revision 1.72  1997/04/23  18:22:11  gdc
 * chnages for multi context
 *
 * Revision 1.71  1997/04/22  17:40:46  mjg
 * Removed brdsetup.h include and changed a ghTexHeap pointer
 *
 * Revision 1.70  1997/04/21  18:43:56  sxy
 * Added a global variable ghTexHeap for texture heap.
 *
 * Revision 1.69  1997/04/21  15:30:05  mjg
 * Replaced ParamBufferInfo with PVRParamBuffs.
 *
 * Revision 1.68  1997/04/16  10:02:01  gdc
 * added a version.h file which is auto generated by the new make process
 * this contains the VER_LIB_XXX defines
 *
 * Revision 1.67  1997/04/15  13:12:10  mjg
 * Moved HWSetupBunchOfBRIDGERegs into ISPTSP brackets and removed the call
 * to RnInitialise (replaced with InitRegionDataL() and for now, until the
 * VxD will do it, set the Sabre and Texas BufferIds.
 *
 * Revision 1.66  1997/04/08  11:54:02  jop
 * Set default trace output level to warning rather than message
 *
 * Revision 1.65  1997/04/07  14:59:16  gdc
 * RnSetupDefaultCamera now call in with pointer to default camera
 *
 * Revision 1.64  1997/04/04  13:05:41  jop
 * Simplified debug initialisation - now generic
 *
 * Revision 1.63  1997/04/03  17:55:46  mjg
 * Added an include.
 *
 * Revision 1.62  1997/04/03  13:13:55  mjg
 * Included 'hwregs.h'
 *
 * Revision 1.61  1997/04/02  21:29:41  mjg
 * Updated calling conventions.
 *
 * Revision 1.60  1997/04/01  19:17:41  mjg
 * Changed notprintf to PVROSPrintf.
 *
 * Revision 1.59  1997/03/31  23:57:02  mlj
 * Fixed brdsetup.c include
 *
 * Revision 1.58  1997/03/31  23:41:10  mlj
 * Fixes to get DSO32 driver to build
 *
 * Revision 1.57  1997/03/31  22:09:58  jop
 * Sorted out WIN32/DOS32 issues
 *
 * Revision 1.56  1997/03/13  11:44:25  sxy
 * Added a global MemoryRoot, and pass it to InitTextureMemory().
 *
 * Revision 1.55  1997/02/04  12:27:24  gdc
 * reworked sgl_init somewhat so that a separate sgl_lite only dll could be
 * built, this mainly meant having some globals defined in rnglobal.c and
 * instanced here by externs, and putting calls to InitStateStack and
 * RnSetupDefaultCamera here instaed of RnInitialise
 *
 * Revision 1.54  1996/12/10  23:39:17  erf
 * Changed compile switches:
 * 1. PCX1 to PCX1 || PCX2.
 * 2. MIDASPC1 to ISPTSP.
 * 3. Include "pcx2\brdsetup.h" for PCX2.
 * 4. Removed defined from ICC and ICL.
 *
 * Revision 1.53  1996/11/07  19:58:07  jop
 * Sorted dodgy include
 *
 * Revision 1.52  1996/10/29  10:34:05  gdc
 * forgot about midas3 when doing texparamsize
 *
 * Revision 1.51  1996/10/28  12:55:11  gdc
 * added facility to changed amount of texture memory used
 * by ISP andTSP prameter buffers via an ini file setting
 * called TSPParamSize in kb
 *
 * Revision 1.50  1996/09/27  10:28:14  mjg
 * move a line inside a #if WIN32
 *
 * Revision 1.49  1996/09/19  11:58:49  gdc
 * added code to read a value from the sglhw.ini file to control
 * how long the render takes to timeout. Ini file entry is
 * RenderTimeout and is an integer in tenths of a second, default is 2
 *
 * Revision 1.48  1996/08/30  14:03:50  pdl
 * put back the translucent pixel init
 *
 * Revision 1.47  1996/08/02  18:06:54  jop
 * Removed FPU init - was breaking D3D
 *
 * Revision 1.46  1996/07/19  19:34:44  jop
 * Added createwhitetexture from NTT support
 *
 * Revision 1.45  1996/07/17  13:59:36  sjf
 * Twiddling call now conditional on it being a SIMUALTOR build.
 *
 * Revision 1.44  1996/07/10  10:44:53  pdl
 * shuffled around an inittexturememory call.
 *
 * Revision 1.43  1996/07/08  04:51:27  sjf
 * Added macto so mem logging can be built into release versions.
 *
 * Revision 1.41  1996/06/28  09:49:05  mal
 * Added the HighPriority and DefaultPriority global variables
 *
 * Revision 1.38  1996/06/26  09:55:58  mal
 * Added Thread Priority Read from sglhw.ini.
 *
 * Revision 1.37  1996/06/19  08:59:19  mal
 * Added PCX1 Texture Memory Size Detection
 *
 * Revision 1.36  1996/06/03  16:41:54  jop
 * Now calls exit() if the board init fails
 *
 * Revision 1.35  1996/06/03  16:29:02  jop
 * WIN32 builds now carry out board and VxD init in sgl_init
 *
 * Revision 1.34  1996/05/30  20:33:37  sjf
 *  Added texture caching.
 *
 * Revision 1.33  1996/05/09  17:35:17  jop
 * Commented out non-tex translucency stuff
 *
 * Revision 1.32  1996/04/26  16:55:28  pdl
 * changed MIDASPC1 to WIN32.
 *
 * Revision 1.31  1996/04/26  14:32:27  pdl
 * changed a const to a #define
 *
 * Revision 1.30  1996/04/15  11:42:38  pdl
 * added some PCX1 support
 *
 * Revision 1.29  1996/04/02  16:25:11  jop
 * Added ICL support
 *
 * Revision 1.28  1996/03/19  17:10:47  pdl
 * included WIN32 into the condition for memory logging.
 *
 * Revision 1.27  1996/03/01  13:54:03  jrc
 * 1. Removed redundant CheckVersion function and VersionString.
 * 2. Added sgl_get_versions().
 *
 * Revision 1.26  1996/02/26  15:38:14  sjf
 * Added memory use logging.
 *
 * Revision 1.25  1995/11/02  16:55:31  jop
 * Added quality default flags init from ini file
 *
 * Revision 1.24  1995/11/02  13:37:47  jop
 * Added optional memory test
 *
 * Revision 1.23  1995/10/29  14:20:05  jop
 * Set base priority to enable normal desktop activity to take
 * place, just!
 *
 * Revision 1.22  1995/10/27  18:13:10  sjf
 * Added version printing.
 *
 * Revision 1.21  1995/10/27  10:15:08  sjf
 * Added printout of version information to help prevent confusion
 * debug releases.
 *
 * Revision 1.20  1995/10/27  10:04:30  pdl
 * added the variable texture memory.
 *
 * Revision 1.19  1995/10/20  20:19:42  pdl
 * added some register setup calls.
 *
 * Revision 1.18  1995/10/04  10:39:57  jop
 * Added SetupFPU command for WIN32, ICC builds on PCs
 *
 * Revision 1.17  1995/09/04  13:18:22  jop
 * Added fast square root lookup initialisation
 *
 * Revision 1.16  1995/08/25  10:30:47  pdl
 * nothing.
 *
 * Revision 1.15  1995/08/09  12:25:09  pdl
 * added the call to SetupTransPixel.
 *
 * Revision 1.14  1995/08/07  12:14:08  jop
 * Added init-time mesh initialisation
 *
 * Revision 1.13  1995/08/02  13:23:45  pdl
 * removed the volatile.
 *
 * Revision 1.12  1995/08/01  11:48:57  pdl
 * removed TexasSetDim
 *
 * Revision 1.11  1995/07/30  19:00:09  pdl
 * added version checking.
 *
 * Revision 1.10  1995/07/28  11:29:37  sjf
 * Conditionally initialises debug.
 *
 * Revision 1.9  1995/07/27  10:58:08  sjf
 * Initialised debug levels for UNIX versions.
 *
 * Revision 1.8  1995/07/26  17:37:09  jop
 * removed simwin init call
 *
 * Revision 1.7  1995/07/26  17:00:55  pdl
 * Corrected the memory size.
 *
 * Revision 1.6  1995/07/26  16:58:44  pdl
 * Added some texas initialisation.
 *
 * Revision 1.5  1995/07/25  17:17:54  sjf
 * Added parameter memory initialisation.
 *
 * Revision 1.4  1995/07/25  17:09:58  sjf
 * Added RnInitialise.
 *
 * Revision 1.3  1995/07/23  17:20:49  jop
 * Added windows debug initialisation support - a quick hack really
 *
 * Revision 1.2  1995/05/30  12:29:14  sjf
 * Made function name VL standard.
 *
 * Revision 1.1  1995/05/26  12:39:26  sjf
 * Initial revision
 *
 *
 **************************************************************************/

#define MODULE_ID MODID_SGL_INIT

#include <string.h>
#include <stdio.h>

#include "sgl.h"
#include "sgl_defs.h"
#include "pvrosapi.h"

#include "dlnodes.h"
#include "nm_intf.h"
#include "dlglobal.h"
#include "sgl_init.h"
#include "rnglobal.h"
#include "rnstate.h"
#include "rnmesh.h"
#include "dlothers.h"
#include "dvdevice.h"
#include "rncamera.h"
#include "txmops.h"
#include "pmsabre.h"
#include "dregion.h"
#include "sgl_math.h"
#include "pktsp.h"
#include "texapi.h"
#include "parmbuff.h"


#if WIN32 || DOS32
    #include "version.h"
	#include "hwregs.h" /* For get_texture_memory_size */
	#include "brdcfg.h"
#endif

#if ISPTSP
#include "profile.h"
#endif

#if !WIN32
extern sgl_uint32 TexParamSize;
extern HTEXHEAP ghTexHeap;
#endif

/*
// Variable to decide if we have initialised the system or not
//    0 - UNinitialised, NonZero - Initialised
//
// Set it to indicate that the system is uninitialised.
*/
extern int sglSystemInitialised;
extern int HighPrioritySetting;
extern int DefaultPrioritySetting;

extern int nTimeOutTenths;

/* prototype for function in w32dll.c */
sgl_bool CALL_CONV InitEnvironment(void);

/**************************************************************************
 * Function Name  : sglInitialise
 * Inputs         : None
 * Outputs        : None
 * Returns        : 0 if OK, non zero otherwise.
 * Global Used    : sglSystemInitialised
 * Description    : Initialises the system by calling individual initialisation
 *					routines.
 **************************************************************************/

int CALL_CONV SglInitialise(void)
{
	int result;

	/*
	// Assume success until proven otherwise
	*/
	result = 0;

	/*
	// If we havent initialised the system, do so
	*/
	if(sglSystemInitialised == 0)
	{
		PVROSPrintf("Initialising SGL Ver:%s\n", VER_LIB_TXT);

		#if WIN32 || DOS32
		
			if (!InitEnvironment ())
			{
				exit (1);
			}

		#endif

		#if DEBUG 

			DebugInit (DBGPRIV_WARNING);

		#endif

		#if DEBUGDEV || TIMING

			DebugInit (DBGPRIV_MESSAGE);

		#endif


		#if !WIN32
			/* get the render timeout in tenths of a second */
			nTimeOutTenths = HWRdValFile( "RenderTimeout", 2);

			HWReset(); /* this is a full on reset*/

			#if ISPTSP
				HWSetupBunchOfBRIDGERegs();
			#endif
		
			HWSetupBunchOfISPRegs();

			HWSetupBunchOfTSPRegs();

		#endif

		/*
		// Initialise the display list editing globals etc
		*/
		result = InitDisplayLists();

		/*
		// Initialise the rendering variables
		*/

		/*
		** initialise the default camera - used to be called from within
		** RnInitialise
		*/
		RnSetupDefaultCamera(GetDefaultCamera());

		if(result == 0)
		{
			InitRegionDataL(); /* Previously in a RnInitialise funcion */
			result = InitStateStacks();
		}

#if !WIN32
		if(result == 0)
		{
		  /* read the size for the texture parameter space in 4k pages */
		    TexParamSize = 1024*HWRdValFile( "TSPParamSize", (TEX_PARAM_SIZE/1024));
			result = HWInitParamMem();
		}
#endif
		/* Initialise the bit twiddling table IF SIMULATOR*/
	#if SIMULATOR
		InitTwiddle();
	#endif
		
		/* Initialise the texture memory manager*/

#if DOS32
		InitTextureMemory( 4*1024*1024, ghTexHeap );
#elif !WIN32
		InitTextureMemory(TEXTURE_MEMORY_SIZE*2, ghTexHeap);
#endif

		/*
		// Initialse the texture cache control structure
		*/
		InitCachedTextures();
#if !WIN32

		/* this allocates the overflow area for sabre parameters.
		** It HAS to be done in this position/
		*/

		SetupOverflowArea(TexParamSize);

		/*	the translucent pixel HAS to be set up after the
			texture memory */
	
		TranslucentControlWord=SetupTransPixel();
#endif

		/* Initialise some mesh rendering globals */

		RnMeshOnSglInitialise ();

		/* init fast inverse sqrt lookup table */

		MakeInvSqrtLookupTable ();
		
		if(result == 0)
		{
			sglSystemInitialised = 1;
		}

		/* read default quality flags from ini file */
		
		InitDefaultQualityFlags ();

		
	}/*End if system not initialised*/

	return result;
}


/******************************************************************************
 * Function Name: sgl_get_versions
 *
 * Inputs		: -
 * Outputs		: -
 * Returns		: Pointer to internal versions structure
 * Globals Used	: -
 *
 * Description  : See SGL API document
 *****************************************************************************/
sgl_versions * CALL_CONV sgl_get_versions()
{
	static sgl_versions  versions;

	versions.library = VER_LIB_TXT;
	versions.required_header = SGL_HEADER_VERSION;

	return &versions;
}

/***********************************************************************
**
** New recommended way for apps to get a value which they used
** to read from the local ini file eg StrictLocks
**
**
**
***********************************************************************/


sgl_bool CALL_CONV sgl_get_ini_string(char *ReturnData, int ReturnSize, 
								  char *DefaultDataValue, 
								  char *Section, char *Entry)
{
	sgl_bool bResult = FALSE;

	if(ReturnData==NULL || Section==NULL || Entry==NULL ||
	   DefaultDataValue==NULL || ReturnSize==0)
	{

		SglError(sgl_err_bad_parameter);
		return FALSE;

	}
	else
	{

		strncpy(ReturnData, DefaultDataValue, ReturnSize); 
		bResult = HWRdValFileString (Entry, ReturnData, ReturnSize);
		SglError(sgl_no_err);
		return bResult;
	}
}

sgl_bool CALL_CONV sgl_get_ini_int(sgl_int32 *ReturnData,
									sgl_int32 DefaultValue, 
									char *Section, char *Entry)
{

	if(ReturnData==NULL || Section==NULL || Entry==NULL)
	{

		SglError(sgl_err_bad_parameter);
		return FALSE;

	}
	else
	{
		*ReturnData = (sgl_uint32) HWRdValFileInt (Entry, DefaultValue); 
		SglError(sgl_no_err);
		return TRUE;
	}
}
/*
//  Thats all Folks....
//  END OF FILE
*/
