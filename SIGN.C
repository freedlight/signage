
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>
#include <comm.h>
#include <ctrlch.h>
#include "alpha.h"

//----------------------------------------------------------------
//		compile-time defines
//----------------------------------------------------------------

#define DEBUG		0

// change these and recompile to change comm port
#define COMPORT	COM1
#define COMBAUD	9600
#define COMBITS	7
#define COMPART	EVENPARITY
#define COMDELAY	2
#define COMTOUT	2

//----------------------------------------------------------------
//		sign graphics characters
//----------------------------------------------------------------

#include "katakana.c"

//----------------------------------------------------------------
//		comm subroutines
//----------------------------------------------------------------

//
// output a character to comm port
//
void putcomm(BYTE ch)
{
	commputc(ch);
}

//
// output a string to comm port
//
void putcomms(char *s)
{
	while (*s)
		commputc(*s++);
}

//
// beginning of sign packet
//
void sendbegin(void)
{
	short i;

	delay(50);
	for (i=0; i<8; i++)
		putcomm(NUL);
	putcomm(SOH);
	putcomm(S_ALL);		// all signs
	putcomms("00");		// broadcast
	putcomm(STX);
}

//
// end of sign packet
//
void sendend(void)
{
	putcomm(EOT);
	delay(50);
}

//
// string to set color on sign
//
void callcolor(short color)
{
	putcomm(CTL_COLOR);
	putcomm(color);
}

//
// output custom char
//
void calldots(short addr)
{
	putcomm(CTL_DOTS);
	putcomm(addr);
}

//
// send japanese message to sign
//
void sendjapmsg(void)
{
	sendbegin();
	putcomm(CMD_WRTEXT);
	putcomm(TXT_MSG1);
	putcomm(CTL_POSIT);
	putcomm(POS_NORM);
	putcomm(MOD_ROTATE);
	callcolor(CLR_RED);
	calldots(DOT_JD6);
	calldots(DOT_JB3);
	calldots(DOT_JBA);
	calldots(DOT_JBF);
	calldots(DOT_JB1);
	calldots(DOT_JC4);
	calldots(DOT_JD7);
	calldots(DOT_JDD);
	calldots(DOT_JC0);
	calldots(DOT_JCD);
	putcomm('!');
	putcomm(' ');
	putcomm(' ');
	calldots(DOT_JB2);
	calldots(DOT_JDD);
	calldots(DOT_JC3);
	calldots(DOT_JD8);
	calldots(DOT_JBC);
	calldots(DOT_JDE);
	calldots(DOT_JAA);
	calldots(DOT_JDD);
	calldots(DOT_JC4);
	putcomm(' ');
	putcomm(' ');
	calldots(DOT_JCD);
	calldots(DOT_JDE);
	calldots(DOT_JDD);
	calldots(DOT_JC3);
	calldots(DOT_JDE);
	calldots(DOT_JA8);
	calldots(DOT_JDD);
	calldots(DOT_JB8);
	calldots(DOT_JDE);
	calldots(DOT_JA6);
	putcomm(' ');
	putcomm(' ');
	calldots(DOT_JB5);
	calldots(DOT_JC0);
	calldots(DOT_JD2);
	calldots(DOT_JBC);
	calldots(DOT_JB8);
	calldots(DOT_JC0);
	calldots(DOT_JDE);
	calldots(DOT_JBB);
	calldots(DOT_JB2);
	calldots(DOT_JA1);
	putcomm('\r');
	callcolor(CLR_MIX);
	putcomm(CTL_TIME);
	sendend();
}

//
// send english message to sign
//
void sendengmsg(void)
{
	sendbegin();
	putcomm(CMD_WRTEXT);
	putcomm(TXT_MSG1);
	putcomm(CTL_POSIT);
	putcomm(POS_NORM);
	putcomm(MOD_ROTATE);
	callcolor(CLR_AMBER);
	putcomms("Welcome to Atlanta");
	callcolor(CLR_RED);
	putcomms(" ! ");
	callcolor(CLR_GREEN);
	putcomms("Intelligent Vending has all the answers.\r");
	callcolor(CLR_MIX);
	putcomm(CTL_TIME);
	sendend();
}

//
// send graphics data string
//
void senddots(short idx)
{
	short i;
	char **dat;

	sendbegin();
	putcomm(CMD_WRDOTS);
	putcomm(idx);
	switch (idx)
	{
		case DOT_JA1: dat = dotsA1; break;
		case DOT_JA6: dat = dotsA6; break;
		case DOT_JA8: dat = dotsA8; break;
		case DOT_JAA: dat = dotsAA; break;
		case DOT_JB1: dat = dotsB1; break;
		case DOT_JB2: dat = dotsB2; break;
		case DOT_JB3: dat = dotsB3; break;
		case DOT_JB5: dat = dotsB5; break;
		case DOT_JB8: dat = dotsB8; break;
		case DOT_JBA: dat = dotsBA; break;
		case DOT_JBB: dat = dotsBB; break;
		case DOT_JBC: dat = dotsBC; break;
		case DOT_JBF: dat = dotsBF; break;
		case DOT_JC0: dat = dotsC0; break;
		case DOT_JC3: dat = dotsC3; break;
		case DOT_JC4: dat = dotsC4; break;
		case DOT_JCD: dat = dotsCD; break;
		case DOT_JD2: dat = dotsD2; break;
		case DOT_JD6: dat = dotsD6; break;
		case DOT_JD7: dat = dotsD7; break;
		case DOT_JD8: dat = dotsD8; break;
		case DOT_JDD: dat = dotsDD; break;
		case DOT_JDE: dat = dotsDE; break;
	}
	for (i=0; i<8; i++)
		putcomms(dat[i]);
	sendend();
}

//
// send memory allocation string
//
void sendalloc(void)
{
	sendbegin();
	putcomm(CMD_WRSPEC);		// send
	putcomm(SPC_MEMCONF);	// memory configuration
	putcomm(TXT_MSG1);
	putcomms("AU0400FF00");
	putcomm(DOT_JA1);
	putcomms("DU07061000");
	putcomm(DOT_JA6);
	putcomms("DU07061000");
	putcomm(DOT_JA8);
	putcomms("DU07061000");
	putcomm(DOT_JAA);
	putcomms("DU07061000");
	putcomm(DOT_JB1);
	putcomms("DU07061000");
	putcomm(DOT_JB2);
	putcomms("DU07061000");
	putcomm(DOT_JB3);
	putcomms("DU07061000");
	putcomm(DOT_JB5);
	putcomms("DU07061000");
	putcomm(DOT_JB8);
	putcomms("DU07061000");
	putcomm(DOT_JBA);
	putcomms("DU07061000");
	putcomm(DOT_JBB);
	putcomms("DU07061000");
	putcomm(DOT_JBC);
	putcomms("DU07061000");
	putcomm(DOT_JBF);
	putcomms("DU07061000");
	putcomm(DOT_JC0);
	putcomms("DU07061000");
	putcomm(DOT_JC3);
	putcomms("DU07061000");
	putcomm(DOT_JC4);
	putcomms("DU07061000");
	putcomm(DOT_JCD);
	putcomms("DU07061000");
	putcomm(DOT_JD2);
	putcomms("DU07061000");
	putcomm(DOT_JD6);
	putcomms("DU07061000");
	putcomm(DOT_JD7);
	putcomms("DU07061000");
	putcomm(DOT_JD8);
	putcomms("DU07061000");
	putcomm(DOT_JDD);
	putcomms("DU07061000");
	putcomm(DOT_JDE);
	putcomms("DU07061000");
	sendend();
}

//
// send string to set time to match computer
//
void sendtime(void)
{
	struct dostime_t tm;

	_dos_gettime(&tm);
	sendbegin();
	putcomm(CMD_WRSPEC);		// send
	putcomm(SPC_TIME);		// set time
	putcomm((tm.hour / 10) + '0');
	putcomm((tm.hour % 10) + '0');
	putcomm((tm.minute / 10) + '0');
	putcomm((tm.minute % 10) + '0');
	sendend();
}

//
// send strings to initialize sign
//
void sendinit(void)
{
	sendalloc();
	senddots(DOT_JA1);
	senddots(DOT_JA6);
	senddots(DOT_JA8);
	senddots(DOT_JAA);
	senddots(DOT_JB1);
	senddots(DOT_JB2);
	senddots(DOT_JB3);
	senddots(DOT_JB5);
	senddots(DOT_JB8);
	senddots(DOT_JBA);
	senddots(DOT_JBB);
	senddots(DOT_JBC);
	senddots(DOT_JBF);
	senddots(DOT_JC0);
	senddots(DOT_JC3);
	senddots(DOT_JC4);
	senddots(DOT_JCD);
	senddots(DOT_JD2);
	senddots(DOT_JD6);
	senddots(DOT_JD7);
	senddots(DOT_JD8);
	senddots(DOT_JDD);
	senddots(DOT_JDE);
	sendtime();
}

//----------------------------------------------------------------
//		main routine
//----------------------------------------------------------------

/*
void main(short argc, char *argv[])
{
	char *arg;

	if (argc < 2)
	{
		printf("Signload - no command\n");
		return;
	}
	arg = argv[1];
	setchan(COMPORT);
	commopen(COMBAUD, COMBITS, COMPART);
	commdelay(COMDELAY);
	commtime(COMTOUT);
	if (*arg == 'I' || *arg == 'i')
		sendinit();
	if (*arg == 'E' || *arg == 'e')
		sendengmsg();
	if (*arg == 'J' || *arg == 'j')
		sendjapmsg();
	commclose();
}
*/
