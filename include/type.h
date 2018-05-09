/******************************************************************************/
/* @F_NAME:           type.h                                                  */
/* @F_PURPOSE:        Definition of basic types and define                    */
/* @F_CREATED_BY:     Vincent RIOUAL                                          */
/* @F_MODIFIED_BY:    John Vegezzi                                            */
/* @F_CREATION_DATE:  21/12/2000                                              */
/* @F_MOD_DATE:  		 23/12/2010                                              */
/* @F_MPROC_TYPE:     NEC_V850 (little endian)                                */
/************************************** (C) Copyright 2000 Magneti Marelli ****/

/*_____ I N C L U D E - F I L E S ____________________________________________*/
#ifndef TYPE_H_NAME
#define TYPE_H_NAME

//#include "device.h"
#include "Platform_Types.h"


/*_____ G L O B A L - D E F I N E ____________________________________________*/
//#define FSLLIB_COMPILER_NEC
#ifdef FSLLIB_COMPILER_NEC
	#pragma ioreg
#else  // GHS
	#define GREEN_HILLS
#endif
#define DEFPORT8(addr)  (*((volatile unsigned char *)addr))   /* 8-bit port */
#define DEFPORT16(addr)  (*((volatile unsigned short *)addr)) /* 16-bit port*/
#define DEFPORT32(addr)  (*((volatile unsigned int *)addr))   /* 32-bit port*/

#define _USED_      1
#define _NOT_USED_  0

#ifndef NULL
#define NULL ((void*)0)
#endif

#define DISABLE ((uint8) 0)
#define ENABLE  ((uint8) 1)

#define NO  ((uint8) 0)
#define YES ((uint8) 1)
#ifdef DIAG_FIAT
#define NOK   ((sint8)  1)
#define OK    ((sint8)  0)
#define ERROR ((sint8) -1)
#else
#define NOK   ((sbyte)  1)
#define OK    ((sbyte)  0)
#define ERROR ((sbyte) -1)
#endif

// Custom macros for CUSW program
#define USE_MM_OPT_MACROS

#define __BITFIELD_LSB_FIRST__
#define BOOL_EVAL(C)		((C) ? 1 :0)  // macro for ternary operator
///////////////////////////////////////////////////////////////////////////////
// from obsolete targ.h file
#define TARG_WRITE8(ADDR, VALUE)   *((volatile uint8*)(ADDR)) = (VALUE)
#define TARG_READ8(ADDR)           *((volatile uint8*)((ADDR)))
#define TARG_WRITE16(ADDR, VALUE)  *((volatile uint16*)(ADDR)) = (VALUE)
#define TARG_READ16(ADDR)          *((volatile uint16*)((ADDR)))
#define TARG_WRITE32(ADDR, VALUE)  *((volatile uint32*)(ADDR)) = (VALUE)
#define TARG_READ32(ADDR)          *((volatile uint32*)((ADDR)))
#define TARG_WRITE1(REG, PINNUMBER, VALUE)                                     \
        *((volatile uint32*)(REG))=((VALUE << PINNUMBER) |                      \
         (*((volatile uint32*)((REG))) & (0xFFFFFFFF - (1 << PINNUMBER))))
#define TARG_READ1(REG, PINNUMBER) (*((volatile uint32*)(REG)) &                \
        (1 << PinNumber)) >> PinNumber
#define TARG_ReadLong(REG)						\
	*((volatile uint32*)(REG))
///////////////////////////////////////////////////////////////////////////////

// Application flag stored in EEPROM
#define EOL_MODE_FLAG	0x23232323
#define DV_MODE_FLAG		0xA5A5A5A5
#define IL_MODE_FLAG		0xB4B4B4B4
#define IM_MODE_FLAG		0x11111111

/*_____ G L O B A L - T Y P E S ______________________________________________*/

/* new basic type definitions */
//typedef unsigned char uint8;            // 1 byte
//typedef signed char sint8;              // 1 byte
//typedef unsigned short int uint16;      // 2 bytes
//typedef signed short int sint16;        // 2 bytes
//typedef unsigned long int uint32;       // 4 bytes
//typedef signed int sint32;              // 4 bytes

/* MISRA non standard definition */
#ifdef MISRA_ON
	typedef unsigned long int uint64;  // 4 bytes
	typedef signed  long int sint64;   // 4 bytes
	#define BF_t int
	#define BF8_t int
	#error "INCORRECT UINT64 TYPE!!!!!"
#else
	typedef unsigned long long int uint64;  // 8 bytes
	typedef signed long long int sint64;    // 8 bytes
	#define BF_t uint32
	#define BF8_t uint8
#endif
/* end MISRA */


//#define uint32 unsigned int
/* boolean type definition */
#ifndef FALSE
  #define FALSE 0
#endif
#ifndef TRUE
  #define TRUE  1
#endif
#ifdef FSLLIB_COMPILER_NEC
	#define bool_t _Bool
#else
	typedef uint8  bool_t;
#endif
typedef uint32 hz_t;     // hertz
typedef uint8  percent_t; // 0-100%
typedef uint32 ee_atom_t; // smallest integer to use in EEPROM

#ifndef MISRA_ON
typedef struct
	{
		volatile uint8  bit0 : 1;
		volatile uint8  bit1 : 1;
		volatile uint8  bit2 : 1;
		volatile uint8  bit3 : 1;

		volatile uint8  bit4 : 1;
		volatile uint8  bit5 : 1;
		volatile uint8  bit6 : 1;
		volatile uint8  bit7 : 1;
} u8BitAccess;

typedef struct
{
	volatile uint16  bit0  : 1;
	volatile uint16  bit1  : 1;
	volatile uint16  bit2  : 1;
	volatile uint16  bit3  : 1;

	volatile uint16  bit4  : 1;
	volatile uint16  bit5  : 1;
	volatile uint16  bit6  : 1;
	volatile uint16  bit7  : 1;

	volatile uint16  bit8  : 1;
	volatile uint16  bit9  : 1;
	volatile uint16  bit10 : 1;
	volatile uint16  bit11 : 1;

	volatile uint16  bit12 : 1;
	volatile uint16  bit13 : 1;
	volatile uint16  bit14 : 1;
	volatile uint16  bit15 : 1;
} u16BitAccess;
#else
typedef struct
	{
		volatile int  bit0 : 1;
		volatile int  bit1 : 1;
		volatile int  bit2 : 1;
		volatile int  bit3 : 1;

		volatile int  bit4 : 1;
		volatile int  bit5 : 1;
		volatile int  bit6 : 1;
		volatile int  bit7 : 1;
} u8BitAccess;

typedef struct
{
	volatile int  bit0  : 1;
	volatile int  bit1  : 1;
	volatile int  bit2  : 1;
	volatile int  bit3  : 1;

	volatile int  bit4  : 1;
	volatile int  bit5  : 1;
	volatile int  bit6  : 1;
	volatile int  bit7  : 1;

	volatile int  bit8  : 1;
	volatile int  bit9  : 1;
	volatile int  bit10 : 1;
	volatile int  bit11 : 1;

	volatile int  bit12 : 1;
	volatile int  bit13 : 1;
	volatile int  bit14 : 1;
	volatile int  bit15 : 1;
} u16BitAccess;
#endif  // MISRA_ON

// CSIG Definitions
//typedef enum
//{
//    CSIG0	= 0,
//    CSIG1	= 1,
//    CSIG2	= 2
//} SPID_ChannelNumber_t;

//#define OSTM0				0

//***** Definitions *****

// CLKS Definitions
//typedef enum { CLKS_HSROSC = 0, CLKS_MOSC, CLKS_SOSC, CLKS_PLL0, CLKS_PLL1, CLKS_PLL2, CLKS_LSROSC, CLKS_NUM_CLK_SRCS } CLKS_ClkSources_t;
//typedef enum { PWRD_AWO, PWRD_ISO0, PWRD_ISO1 } CLKS_PwrDomains_t;
#define CLKS_MAX_FREQ			120000000

// CPU Definitions
#define CPU_PWRD				PWRD_ISO0
#define CPU_CLKD				0
#define CLKD_CPU				CPU_PWRD, CPU_CLKD

// BRAM Definitions
#define BRAM_PWRD				PWRD_AWO
#define BRAM_CLKD				5
#define CLKD_BRAM				BRAM_PWRD, BRAM_CLKD

// FOUT Definitions
#define FOUT_PWRD				PWRD_AWO
#define FOUT_CLKD				6
#define CLKD_FOUT				FOUT_PWRD, FOUT_CLKD

// INTP Definitions
#define INTP_MAX_INSTS		(11 + 1)	// max number of external interrupts (11 + NMI)

#define REGISTER_UNLOCK_CODE ((unsigned char)0xA5)

// function prototype definition
typedef void ( *function_ptr_T ) (void);		// pointer to a function with no parameters returns nothing
typedef void ( *function_ptr_P1_T) (uint16);	// pointer to a function with one (uint8) parameter returns nothing


#ifdef MISRA_ON
typedef union
{
	struct
	{
		int BIT0 :1;	/* lsb */
		int BIT1 :1;
		int BIT2 :1;
		int BIT3 :1;
		int BIT4 :1;
		int BIT5 :1;
		int BIT6 :1;
		int BIT7 :1;	/* msb */
	} _bit; /* for bit  acces */
	uint8 _byte; /* for byte acces */
} bitfield_byte_t;

/* Type definition for short, byte and bit acces */
typedef union
{
	struct
	{
		int BIT0 :1;	/* lsb */
		int BIT1 :1;
		int BIT2 :1;
		int BIT3 :1;
		int BIT4 :1;
		int BIT5 :1;
		int BIT6 :1;
		int BIT7 :1;
		int BIT8 :1;
		int BIT9 :1;
		int BIT10 :1;
		int BIT11 :1;
		int BIT12 :1;
		int BIT13 :1;
		int BIT14 :1;
		int BIT15 :1;	/* msb */
	} _bit; /* for bit  acces */

	struct
	{
		/* little indian format (Intel) */
		uint8 low;
		uint8 high;
	} _byte; /* for byte access */

	uint16 _short; /* for word access */
} bitfield_short_t;

#else
typedef union
{
	struct
	{
		uint8 BIT0 :1;	/* lsb */
		uint8 BIT1 :1;
		uint8 BIT2 :1;
		uint8 BIT3 :1;
		uint8 BIT4 :1;
		uint8 BIT5 :1;
		uint8 BIT6 :1;
		uint8 BIT7 :1;	/* msb */
	} _bit; /* for bit  acces */
	uint8 _byte; /* for byte acces */
} bitfield_byte_t;

/* Type definition for short, byte and bit acces */
typedef union
{
	struct
	{
		uint16 BIT0 :1;	/* lsb */
		uint16 BIT1 :1;
		uint16 BIT2 :1;
		uint16 BIT3 :1;
		uint16 BIT4 :1;
		uint16 BIT5 :1;
		uint16 BIT6 :1;
		uint16 BIT7 :1;
		uint16 BIT8 :1;
		uint16 BIT9 :1;
		uint16 BIT10 :1;
		uint16 BIT11 :1;
		uint16 BIT12 :1;
		uint16 BIT13 :1;
		uint16 BIT14 :1;
		uint16 BIT15 :1;	/* msb */
	} _bit; /* for bit  acces */

	struct
	{
		/* little indian format (Intel) */
		uint8 low;
		uint8 high;
	} _byte; /* for byte access */

	uint16 _short; /* for word access */
} bitfield_short_t;
#endif


/* FROM TARG.H file */
#define TARG_WRITE8(ADDR, VALUE)   *((volatile uint8*)(ADDR)) = (VALUE)
#define TARG_READ8(ADDR)           *((volatile uint8*)((ADDR)))
#define TARG_WRITE16(ADDR, VALUE)  *((volatile uint16*)(ADDR)) = (VALUE)
#define TARG_READ16(ADDR)          *((volatile uint16*)((ADDR)))
#define TARG_WRITE32(ADDR, VALUE)  *((volatile uint32*)(ADDR)) = (VALUE)
#define TARG_READ32(ADDR)          *((volatile uint32*)((ADDR)))
#define TARG_WRITE1(REG, PINNUMBER, VALUE)                                     \
        *((volatile uint32*)(REG))=((VALUE << PINNUMBER) |                      \
         (*((volatile uint32*)((REG))) & (0xFFFFFFFF - (1 << PINNUMBER))))
#define TARG_READ1(REG, PINNUMBER) (*((volatile uint32*)(REG)) &                \
        (1 << PinNumber)) >> PinNumber
/* end targ.h file */

#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

#define UINT16_MAX 65535

#define INT32_MIN (-INT_MAX-1)
#define INT32_MAX 2147483647

#define UINT32_MAX 4294967295U

#define ULONG_MAX 4294967295UL

#define PERIODIC_SINGLE_PASS_RATE 10	// rate in milliseconds at which tasks are run

#define VFD_FB_OFFSET	34	// offset into framebuffer per Chrysler
#define VFD_IMAGE_SIZE 44*17

typedef enum color_t {BLACK=0, RED=1, GRN=2, BLUE=3, RGBCOLOR=4, WHITE=0xFF} color_t;

#define TASK_RATE 10


typedef enum
{
	Stage_0_Deinitalized,
	Stage_1_TurDEN_AND_DI,
	Stage_2_TurnGRB_AND_STNDBY,
	Stage_3_WaitForMemInitToComplete,
	Stage_4_TurnAVDD,
	Stage_5_TurnVGL_L,
	Stage_6_TurnVGL_H,
	Stage_7_TurnBKLEN,
	Stage_8_TFTActivated
}TFTP_ActivativationStage;

typedef uint16 ErrCnt_t;


/*_____ E N D _____ (type.h) _________________________________________________*/


#endif
