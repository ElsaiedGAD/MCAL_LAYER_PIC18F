/* 
 * File:   mcal_std_types.h
 * Author: Elsaied_Ahmed Gad 
 * 
 * Created on 10. September 2023, 12:37
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H    

/*Section : includes !!!! */

#include "std_libraries.h"
#include "compiler.h" 

/*Section : Macros Declaration !!!! */

#define STD_HIGH                  0X01
#define STD_LOW                   0X00
#define STD_ON                    0X01
#define STD_OFF                   0X00
#define STD_ACTIVE                0X01
#define STD_IDEL                  0X00


#define E_OK      (STD_ReturnType) 0X01
#define E_NOT_OK  (STD_ReturnType) 0X00

#define CPU_TYPE_8                  8
#define CPU_TYPE_16                 16
#define CPU_TYPE_32                 32
#define CPU_TYPE_64                 64

#define CPU_TYPE    (CPU_TYPE_8)


/*Section : Macros Functions !!!! */


/*Section : Data TYPES Declaration !!!! */

#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char  boolean ;
typedef unsigned char  uint_8  ;
typedef unsigned short uint_16 ;
typedef unsigned int   uint_32 ;
typedef unsigned long long  uint_64 ;

typedef signed char  sint_8  ;
typedef signed short sint_16 ;
typedef signed int   sint_32 ;
typedef signed long long  sint_64 ;

typedef float  float_32 ;
typedef double float_64 ;
#endif 

#if (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char  boolean ;
typedef unsigned char  uint_8  ;
typedef unsigned short uint_16 ;
typedef unsigned long   uint_32 ;
typedef unsigned long long  uint_64 ;

typedef signed char  sint_8  ;
typedef signed short sint_16 ;
typedef signed long   sint_32 ;
typedef signed long long  sint_64 ;

typedef float  float_32 ;
typedef double float_64 ;
#endif

#if (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char  boolean ;
typedef unsigned char  uint_8  ;
typedef unsigned short uint_16 ;
typedef unsigned long   uint_32 ;
typedef unsigned long long  uint_64 ;

typedef signed char  sint_8  ;
typedef signed short sint_16 ;
typedef signed long   sint_32 ;
typedef signed long long  sint_64 ;

typedef float  float_32 ;
typedef double float_64 ;
#endif

#if (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char  boolean ;
typedef unsigned char  uint_8  ;
typedef unsigned short uint_16 ;
typedef unsigned int   uint_32 ;
typedef unsigned long   uint_64 ;

typedef signed char  sint_8  ;
typedef signed short sint_16 ;
typedef signed int   sint_32 ;
typedef signed long   sint_64 ;

typedef float  float_32 ;
typedef double float_64 ;
#endif

typedef uint_8   STD_ReturnType ;

/*Section : Function Declaration !!!! */







#endif	/* MCAL_STD_TYPES_H */

