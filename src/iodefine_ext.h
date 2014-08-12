/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software.  By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : iodefine_ext.h
* Version      : 1.00
* Device(s)    : R5F10RLC
* Tool-Chain   : GNURL78 v12.03
* Description  : This file defines the Extended SFRs.
* Creation Date: 21/01/2013
***********************************************************************************************************************/


#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_EXT_H
#define IODEFINE_EXT_H

/*
 IO Registers
 */
union un_adm2 {
	unsigned char adm2;
	__BITS8 BIT;
};
union un_pu1 {
	unsigned char pu1;
	__BITS8 BIT;
};
union un_pu3 {
	unsigned char pu3;
	__BITS8 BIT;
};
union un_pu4 {
	unsigned char pu4;
	__BITS8 BIT;
};
union un_pu5 {
	unsigned char pu5;
	__BITS8 BIT;
};
union un_pu7 {
	unsigned char pu7;
	__BITS8 BIT;
};
union un_pu12 {
	unsigned char pu12;
	__BITS8 BIT;
};
union un_pu14 {
	unsigned char pu14;
	__BITS8 BIT;
};
union un_pim1 {
	unsigned char pim1;
	__BITS8 BIT;
};
union un_pom1 {
	unsigned char pom1;
	__BITS8 BIT;
};
union un_pmc1 {
	unsigned char pmc1;
	__BITS8 BIT;
};
union un_pmc4 {
	unsigned char pmc4;
	__BITS8 BIT;
};
union un_pmc12 {
	unsigned char pmc12;
	__BITS8 BIT;
};
union un_pmc14 {
	unsigned char pmc14;
	__BITS8 BIT;
};
union un_nfen0 {
	unsigned char nfen0;
	__BITS8 BIT;
};
union un_nfen1 {
	unsigned char nfen1;
	__BITS8 BIT;
};
union un_isc {
	unsigned char isc;
	__BITS8 BIT;
};
union un_tos {
	unsigned char tos;
	__BITS8 BIT;
};
union un_dflctl {
	unsigned char dflctl;
	__BITS8 BIT;
};
union un_bectl {
	unsigned char bectl;
	__BITS8 BIT;
};
union un_fsse {
	unsigned char fsse;
	__BITS8 BIT;
};
union un_pfs {
	unsigned char pfs;
	__BITS8 BIT;
};
union un_mduc {
	unsigned char mduc;
	__BITS8 BIT;
};
union un_per0 {
	unsigned char per0;
	__BITS8 BIT;
};
union un_rmc {
	unsigned char rmc;
	__BITS8 BIT;
};
union un_rpectl {
	unsigned char rpectl;
	__BITS8 BIT;
};
union un_se0l {
	unsigned char se0l;
	__BITS8 BIT;
};
union un_ss0l {
	unsigned char ss0l;
	__BITS8 BIT;
};
union un_st0l {
	unsigned char st0l;
	__BITS8 BIT;
};
union un_soe0l {
	unsigned char soe0l;
	__BITS8 BIT;
};
union un_te0l {
	unsigned char te0l;
	__BITS8 BIT;
};
union un_ts0l {
	unsigned char ts0l;
	__BITS8 BIT;
};
union un_tt0l {
	unsigned char tt0l;
	__BITS8 BIT;
};
union un_toe0l {
	unsigned char toe0l;
	__BITS8 BIT;
};
union un_iicctl00 {
	unsigned char iicctl00;
	__BITS8 BIT;
};
union un_iicctl01 {
	unsigned char iicctl01;
	__BITS8 BIT;
};
union un_crc0ctl {
	unsigned char crc0ctl;
	__BITS8 BIT;
};
union un_pfseg0 {
	unsigned char pfseg0;
	__BITS8 BIT;
};
union un_pfseg1 {
	unsigned char pfseg1;
	__BITS8 BIT;
};
union un_pfseg2 {
	unsigned char pfseg2;
	__BITS8 BIT;
};
union un_pfseg3 {
	unsigned char pfseg3;
	__BITS8 BIT;
};
union un_pfseg4 {
	unsigned char pfseg4;
	__BITS8 BIT;
};
union un_isclcd {
	unsigned char isclcd;
	__BITS8 BIT;
};

#define ADM2 (*(volatile union un_adm2 *)0xF0010).adm2
#define ADM2_bit (*(volatile union un_adm2 *)0xF0010).BIT
#define ADUL (*(volatile unsigned char *)0xF0011)
#define ADLL (*(volatile unsigned char *)0xF0012)
#define ADTES (*(volatile unsigned char *)0xF0013)
#define PU1 (*(volatile union un_pu1 *)0xF0031).pu1
#define PU1_bit (*(volatile union un_pu1 *)0xF0031).BIT
#define PU3 (*(volatile union un_pu3 *)0xF0033).pu3
#define PU3_bit (*(volatile union un_pu3 *)0xF0033).BIT
#define PU4 (*(volatile union un_pu4 *)0xF0034).pu4
#define PU4_bit (*(volatile union un_pu4 *)0xF0034).BIT
#define PU5 (*(volatile union un_pu5 *)0xF0035).pu5
#define PU5_bit (*(volatile union un_pu5 *)0xF0035).BIT
#define PU7 (*(volatile union un_pu7 *)0xF0037).pu7
#define PU7_bit (*(volatile union un_pu7 *)0xF0037).BIT
#define PU12 (*(volatile union un_pu12 *)0xF003C).pu12
#define PU12_bit (*(volatile union un_pu12 *)0xF003C).BIT
#define PU14 (*(volatile union un_pu14 *)0xF003E).pu14
#define PU14_bit (*(volatile union un_pu14 *)0xF003E).BIT
#define PIM1 (*(volatile union un_pim1 *)0xF0041).pim1
#define PIM1_bit (*(volatile union un_pim1 *)0xF0041).BIT
#define POM1 (*(volatile union un_pom1 *)0xF0051).pom1
#define POM1_bit (*(volatile union un_pom1 *)0xF0051).BIT
#define PMC1 (*(volatile union un_pmc1 *)0xF0061).pmc1
#define PMC1_bit (*(volatile union un_pmc1 *)0xF0061).BIT
#define PMC4 (*(volatile union un_pmc4 *)0xF0064).pmc4
#define PMC4_bit (*(volatile union un_pmc4 *)0xF0064).BIT
#define PMC12 (*(volatile union un_pmc12 *)0xF006C).pmc12
#define PMC12_bit (*(volatile union un_pmc12 *)0xF006C).BIT
#define PMC14 (*(volatile union un_pmc14 *)0xF006E).pmc14
#define PMC14_bit (*(volatile union un_pmc14 *)0xF006E).BIT
#define NFEN0 (*(volatile union un_nfen0 *)0xF0070).nfen0
#define NFEN0_bit (*(volatile union un_nfen0 *)0xF0070).BIT
#define NFEN1 (*(volatile union un_nfen1 *)0xF0071).nfen1
#define NFEN1_bit (*(volatile union un_nfen1 *)0xF0071).BIT
#define ISC (*(volatile union un_isc *)0xF0073).isc
#define ISC_bit (*(volatile union un_isc *)0xF0073).BIT
#define TIS0 (*(volatile unsigned char *)0xF0074)
#define ADPC (*(volatile unsigned char *)0xF0076)
#define PIOR (*(volatile unsigned char *)0xF0077)
#define IAWCTL (*(volatile unsigned char *)0xF0078)
#define TOS (*(volatile union un_tos *)0xF0079).tos
#define TOS_bit (*(volatile union un_tos *)0xF0079).BIT
#define PRDSEL (*(volatile unsigned short *)0xF007E)
#define TOOLEN (*(volatile unsigned char *)0xF0080)
#define BPAL0 (*(volatile unsigned char *)0xF0081)
#define BPAH0 (*(volatile unsigned char *)0xF0082)
#define BPAS0 (*(volatile unsigned char *)0xF0083)
#define BACDVL0 (*(volatile unsigned char *)0xF0084)
#define BACDVH0 (*(volatile unsigned char *)0xF0085)
#define BACDML0 (*(volatile unsigned char *)0xF0086)
#define BACDMH0 (*(volatile unsigned char *)0xF0087)
#define MONMOD (*(volatile unsigned char *)0xF0088)
#define DFLCTL (*(volatile union un_dflctl *)0xF0090).dflctl
#define DFLCTL_bit (*(volatile union un_dflctl *)0xF0090).BIT
#define HIOTRM (*(volatile unsigned char *)0xF00A0)
#define BECTL (*(volatile union un_bectl *)0xF00A1).bectl
#define BECTL_bit (*(volatile union un_bectl *)0xF00A1).BIT
#define HOCODIV (*(volatile unsigned char *)0xF00A8)
#define TEMPCAL0 (*(volatile unsigned char *)0xF00AC)
#define TEMPCAL1 (*(volatile unsigned char *)0xF00AD)
#define TEMPCAL2 (*(volatile unsigned char *)0xF00AE)
#define TEMPCAL3 (*(volatile unsigned char *)0xF00AF)
#define FLSEC (*(volatile unsigned short *)0xF00B0)
#define FLFSWS (*(volatile unsigned short *)0xF00B2)
#define FLFSWE (*(volatile unsigned short *)0xF00B4)
#define FSSET (*(volatile unsigned char *)0xF00B6)
#define FSSE (*(volatile union un_fsse *)0xF00B7).fsse
#define FSSE_bit (*(volatile union un_fsse *)0xF00B7).BIT
#define FLFADL (*(volatile unsigned short *)0xF00B8)
#define FLFADH (*(volatile unsigned char *)0xF00BA)
#define PFCMD (*(volatile unsigned char *)0xF00C0)
#define PFS (*(volatile union un_pfs *)0xF00C1).pfs
#define PFS_bit (*(volatile union un_pfs *)0xF00C1).BIT
#define FLRL (*(volatile unsigned short *)0xF00C2)
#define FLRH (*(volatile unsigned short *)0xF00C4)
#define FLWE (*(volatile unsigned char *)0xF00C6)
#define FLRE (*(volatile unsigned char *)0xF00C7)
#define FLTMS (*(volatile unsigned short *)0xF00C8)
#define DFLMC (*(volatile unsigned short *)0xF00CA)
#define FLMCL (*(volatile unsigned short *)0xF00CC)
#define FLMCH (*(volatile unsigned char *)0xF00CE)
#define FSCTL (*(volatile unsigned char *)0xF00CF)
#define ICEADR (*(volatile unsigned short *)0xF00D0)
#define ICEDAT (*(volatile unsigned short *)0xF00D2)
#define MDCL (*(volatile unsigned short *)0xF00E0)
#define MDCH (*(volatile unsigned short *)0xF00E2)
#define MDUC (*(volatile union un_mduc *)0xF00E8).mduc
#define MDUC_bit (*(volatile union un_mduc *)0xF00E8).BIT
#define PER0 (*(volatile union un_per0 *)0xF00F0).per0
#define PER0_bit (*(volatile union un_per0 *)0xF00F0).BIT
#define OSMC (*(volatile unsigned char *)0xF00F3)
#define RMC (*(volatile union un_rmc *)0xF00F4).rmc
#define RMC_bit (*(volatile union un_rmc *)0xF00F4).BIT
#define RPECTL (*(volatile union un_rpectl *)0xF00F5).rpectl
#define RPECTL_bit (*(volatile union un_rpectl *)0xF00F5).BIT
#define BCDADJ (*(volatile unsigned char *)0xF00FE)
#define VECTCTRL (*(volatile unsigned char *)0xF00FF)
#define SSR00 (*(volatile unsigned short *)0xF0100)
#define SSR00L (*(volatile unsigned char *)0xF0100)
#define SSR01 (*(volatile unsigned short *)0xF0102)
#define SSR01L (*(volatile unsigned char *)0xF0102)
#define SIR00 (*(volatile unsigned short *)0xF0108)
#define SIR00L (*(volatile unsigned char *)0xF0108)
#define SIR01 (*(volatile unsigned short *)0xF010A)
#define SIR01L (*(volatile unsigned char *)0xF010A)
#define SMR00 (*(volatile unsigned short *)0xF0110)
#define SMR01 (*(volatile unsigned short *)0xF0112)
#define SCR00 (*(volatile unsigned short *)0xF0118)
#define SCR01 (*(volatile unsigned short *)0xF011A)
#define SE0 (*(volatile unsigned short *)0xF0120)
#define SE0L (*(volatile union un_se0l *)0xF0120).se0l
#define SE0L_bit (*(volatile union un_se0l *)0xF0120).BIT
#define SS0 (*(volatile unsigned short *)0xF0122)
#define SS0L (*(volatile union un_ss0l *)0xF0122).ss0l
#define SS0L_bit (*(volatile union un_ss0l *)0xF0122).BIT
#define ST0 (*(volatile unsigned short *)0xF0124)
#define ST0L (*(volatile union un_st0l *)0xF0124).st0l
#define ST0L_bit (*(volatile union un_st0l *)0xF0124).BIT
#define SPS0 (*(volatile unsigned short *)0xF0126)
#define SPS0L (*(volatile unsigned char *)0xF0126)
#define SO0 (*(volatile unsigned short *)0xF0128)
#define SOE0 (*(volatile unsigned short *)0xF012A)
#define SOE0L (*(volatile union un_soe0l *)0xF012A).soe0l
#define SOE0L_bit (*(volatile union un_soe0l *)0xF012A).BIT
#define EDR00 (*(volatile unsigned short *)0xF012C)
#define EDR00L (*(volatile unsigned char *)0xF012C)
#define EDR01 (*(volatile unsigned short *)0xF012E)
#define EDR01L (*(volatile unsigned char *)0xF012E)
#define SOL0 (*(volatile unsigned short *)0xF0134)
#define SOL0L (*(volatile unsigned char *)0xF0134)
#define SSC0 (*(volatile unsigned short *)0xF0138)
#define SSC0L (*(volatile unsigned char *)0xF0138)
#define TCR00 (*(volatile unsigned short *)0xF0180)
#define TCR01 (*(volatile unsigned short *)0xF0182)
#define TCR02 (*(volatile unsigned short *)0xF0184)
#define TCR03 (*(volatile unsigned short *)0xF0186)
#define TCR04 (*(volatile unsigned short *)0xF0188)
#define TCR05 (*(volatile unsigned short *)0xF018A)
#define TCR06 (*(volatile unsigned short *)0xF018C)
#define TCR07 (*(volatile unsigned short *)0xF018E)
#define TMR00 (*(volatile unsigned short *)0xF0190)
#define TMR01 (*(volatile unsigned short *)0xF0192)
#define TMR02 (*(volatile unsigned short *)0xF0194)
#define TMR03 (*(volatile unsigned short *)0xF0196)
#define TMR04 (*(volatile unsigned short *)0xF0198)
#define TMR05 (*(volatile unsigned short *)0xF019A)
#define TMR06 (*(volatile unsigned short *)0xF019C)
#define TMR07 (*(volatile unsigned short *)0xF019E)
#define TSR00 (*(volatile unsigned short *)0xF01A0)
#define TSR00L (*(volatile unsigned char *)0xF01A0)
#define TSR01 (*(volatile unsigned short *)0xF01A2)
#define TSR01L (*(volatile unsigned char *)0xF01A2)
#define TSR02 (*(volatile unsigned short *)0xF01A4)
#define TSR02L (*(volatile unsigned char *)0xF01A4)
#define TSR03 (*(volatile unsigned short *)0xF01A6)
#define TSR03L (*(volatile unsigned char *)0xF01A6)
#define TSR04 (*(volatile unsigned short *)0xF01A8)
#define TSR04L (*(volatile unsigned char *)0xF01A8)
#define TSR05 (*(volatile unsigned short *)0xF01AA)
#define TSR05L (*(volatile unsigned char *)0xF01AA)
#define TSR06 (*(volatile unsigned short *)0xF01AC)
#define TSR06L (*(volatile unsigned char *)0xF01AC)
#define TSR07 (*(volatile unsigned short *)0xF01AE)
#define TSR07L (*(volatile unsigned char *)0xF01AE)
#define TE0 (*(volatile unsigned short *)0xF01B0)
#define TE0L (*(volatile union un_te0l *)0xF01B0).te0l
#define TE0L_bit (*(volatile union un_te0l *)0xF01B0).BIT
#define TS0 (*(volatile unsigned short *)0xF01B2)
#define TS0L (*(volatile union un_ts0l *)0xF01B2).ts0l
#define TS0L_bit (*(volatile union un_ts0l *)0xF01B2).BIT
#define TT0 (*(volatile unsigned short *)0xF01B4)
#define TT0L (*(volatile union un_tt0l *)0xF01B4).tt0l
#define TT0L_bit (*(volatile union un_tt0l *)0xF01B4).BIT
#define TPS0 (*(volatile unsigned short *)0xF01B6)
#define TO0 (*(volatile unsigned short *)0xF01B8)
#define TO0L (*(volatile unsigned char *)0xF01B8)
#define TOE0 (*(volatile unsigned short *)0xF01BA)
#define TOE0L (*(volatile union un_toe0l *)0xF01BA).toe0l
#define TOE0L_bit (*(volatile union un_toe0l *)0xF01BA).BIT
#define TOL0 (*(volatile unsigned short *)0xF01BC)
#define TOL0L (*(volatile unsigned char *)0xF01BC)
#define TOM0 (*(volatile unsigned short *)0xF01BE)
#define TOM0L (*(volatile unsigned char *)0xF01BE)
#define IICCTL00 (*(volatile union un_iicctl00 *)0xF0230).iicctl00
#define IICCTL00_bit (*(volatile union un_iicctl00 *)0xF0230).BIT
#define IICCTL01 (*(volatile union un_iicctl01 *)0xF0231).iicctl01
#define IICCTL01_bit (*(volatile union un_iicctl01 *)0xF0231).BIT
#define IICWL0 (*(volatile unsigned char *)0xF0232)
#define IICWH0 (*(volatile unsigned char *)0xF0233)
#define SVA0 (*(volatile unsigned char *)0xF0234)
#define IICSE0 (*(volatile unsigned char *)0xF0235)
#define CRC0CTL (*(volatile union un_crc0ctl *)0xF02F0).crc0ctl
#define CRC0CTL_bit (*(volatile union un_crc0ctl *)0xF02F0).BIT
#define PGCRCL (*(volatile unsigned short *)0xF02F2)
#define CRCD (*(volatile unsigned short *)0xF02FA)
#define PFSEG0 (*(volatile union un_pfseg0 *)0xF0300).pfseg0
#define PFSEG0_bit (*(volatile union un_pfseg0 *)0xF0300).BIT
#define PFSEG1 (*(volatile union un_pfseg1 *)0xF0301).pfseg1
#define PFSEG1_bit (*(volatile union un_pfseg1 *)0xF0301).BIT
#define PFSEG2 (*(volatile union un_pfseg2 *)0xF0302).pfseg2
#define PFSEG2_bit (*(volatile union un_pfseg2 *)0xF0302).BIT
#define PFSEG3 (*(volatile union un_pfseg3 *)0xF0303).pfseg3
#define PFSEG3_bit (*(volatile union un_pfseg3 *)0xF0303).BIT
#define PFSEG4 (*(volatile union un_pfseg4 *)0xF0304).pfseg4
#define PFSEG4_bit (*(volatile union un_pfseg4 *)0xF0304).BIT
#define ISCLCD (*(volatile union un_isclcd *)0xF0308).isclcd
#define ISCLCD_bit (*(volatile union un_isclcd *)0xF0308).BIT
#define SEG0 (*(volatile unsigned char *)0xF0400)
#define SEG1 (*(volatile unsigned char *)0xF0401)
#define SEG2 (*(volatile unsigned char *)0xF0402)
#define SEG3 (*(volatile unsigned char *)0xF0403)
#define SEG4 (*(volatile unsigned char *)0xF0404)
#define SEG5 (*(volatile unsigned char *)0xF0405)
#define SEG6 (*(volatile unsigned char *)0xF0406)
#define SEG7 (*(volatile unsigned char *)0xF0407)
#define SEG8 (*(volatile unsigned char *)0xF0408)
#define SEG9 (*(volatile unsigned char *)0xF0409)
#define SEG10 (*(volatile unsigned char *)0xF040A)
#define SEG11 (*(volatile unsigned char *)0xF040B)
#define SEG12 (*(volatile unsigned char *)0xF040C)
#define SEG13 (*(volatile unsigned char *)0xF040D)
#define SEG14 (*(volatile unsigned char *)0xF040E)
#define SEG15 (*(volatile unsigned char *)0xF040F)
#define SEG16 (*(volatile unsigned char *)0xF0410)
#define SEG17 (*(volatile unsigned char *)0xF0411)
#define SEG18 (*(volatile unsigned char *)0xF0412)
#define SEG19 (*(volatile unsigned char *)0xF0413)
#define SEG20 (*(volatile unsigned char *)0xF0414)
#define SEG21 (*(volatile unsigned char *)0xF0415)
#define SEG22 (*(volatile unsigned char *)0xF0416)
#define SEG23 (*(volatile unsigned char *)0xF0417)
#define SEG24 (*(volatile unsigned char *)0xF0418)
#define SEG25 (*(volatile unsigned char *)0xF0419)
#define SEG26 (*(volatile unsigned char *)0xF041A)
#define SEG27 (*(volatile unsigned char *)0xF041B)
#define SEG28 (*(volatile unsigned char *)0xF041C)
#define SEG29 (*(volatile unsigned char *)0xF041D)
#define SEG30 (*(volatile unsigned char *)0xF041E)
#define SEG31 (*(volatile unsigned char *)0xF041F)
#define SEG32 (*(volatile unsigned char *)0xF0420)
#define SEG33 (*(volatile unsigned char *)0xF0421)
#define SEG34 (*(volatile unsigned char *)0xF0422)
#define SEG35 (*(volatile unsigned char *)0xF0423)
#define SEG36 (*(volatile unsigned char *)0xF0424)
#define SEG37 (*(volatile unsigned char *)0xF0425)
#define SEG38 (*(volatile unsigned char *)0xF0426)

/*
 Sfr bits
 */
#define ADTYP ADM2_bit.no0
#define AWC ADM2_bit.no2
#define ADRCK ADM2_bit.no3
#define TOS0 TOS_bit.no0
#define DFLEN DFLCTL_bit.no0
#define BRSAM BECTL_bit.no0
#define ESQST FSSE_bit.no7
#define DIVST MDUC_bit.no0
#define MACSF MDUC_bit.no1
#define MACOF MDUC_bit.no2
#define MDSM MDUC_bit.no3
#define MACMODE MDUC_bit.no6
#define DIVMODE MDUC_bit.no7
#define TAU0EN PER0_bit.no0
#define SAU0EN PER0_bit.no2
#define IICA0EN PER0_bit.no4
#define ADCEN PER0_bit.no5
#define RTCEN PER0_bit.no7
#define PAENB RMC_bit.no0
#define WDVOL RMC_bit.no7
#define RPEF RPECTL_bit.no0
#define RPERDIS RPECTL_bit.no7
#define SPT0 IICCTL00_bit.no0
#define STT0 IICCTL00_bit.no1
#define ACKE0 IICCTL00_bit.no2
#define WTIM0 IICCTL00_bit.no3
#define SPIE0 IICCTL00_bit.no4
#define WREL0 IICCTL00_bit.no5
#define LREL0 IICCTL00_bit.no6
#define IICE0 IICCTL00_bit.no7
#define PRS0 IICCTL01_bit.no0
#define DFC0 IICCTL01_bit.no2
#define SMC0 IICCTL01_bit.no3
#define DAD0 IICCTL01_bit.no4
#define CLD0 IICCTL01_bit.no5
#define WUP0 IICCTL01_bit.no7
#define CRC0EN CRC0CTL_bit.no7

/*
 Interrupt vector addresses
 */
#endif
