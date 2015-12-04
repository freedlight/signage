/* alpha.h - defines for Alpha display signs */

/* sign types */
#define	S_ALL			'Z'		/* broadcast */
#define	S_PING		'!'		/* visual response to broadcast */
#define	S_215C		'f'		/* 215C specific */
#define	S_ONE			'1'		/* 1 line signs */
#define	S_TWO			'2'		/* 2 line signs */

/* sign commands */
#define	CMD_WRTEXT	'A'		/* write text file */
#define	CMD_RDTEXT	'B'		/* read text file */
#define	CMD_WRSPEC	'E'		/* write special function */
#define	CMD_RDSPEC	'F'		/* read special function */
#define	CMD_WRSTRG	'G'		/* write string file */
#define	CMD_RDSTRG	'H'		/* read string file */
#define	CMD_WRDOTS	'I'		/* write dots file */
#define	CMD_RDDOTS	'J'		/* read dots file */

/* sign control codes */
#define	CTL_FLASH	0x07
#define	CTL_STRING	0x10		/* call string file */
#define	CTL_WIDEOFF	0x11
#define	CTL_WIDEON	0x12
#define	CTL_TIME		0x13		/* call time */
#define	CTL_DOTS		0x14		/* call dots file */
#define	CTL_SPEED1	0x15
#define	CTL_SPEED2	0x16
#define	CTL_SPEED3	0x17
#define	CTL_SPEED4	0x18
#define	CTL_SPEED5	0x19
#define	CTL_FONT		0x1A		/* set font */
#define	CTL_POSIT	0x1B		/* set position/mode */
#define	CTL_COLOR	0x1C		/* set color */
#define	CTL_PROPOR	0x1E		/* proportional on/off */

#define	POS_NORM	0x20	/* middle, full height */

/* sign modes */
#define	MOD_ROTATE	'a'
#define	MOD_HOLD		'b'
#define	MOD_FLASH	'c'
#define	MOD_ROLLUP	'e'
#define	MOD_ROLLDN	'f'
#define	MOD_ROLLLF	'g'
#define	MOD_ROLLRT	'h'
#define	MOD_WIPEUP	'i'
#define	MOD_WIPEDN	'j'
#define	MOD_WIPELF	'k'
#define	MOD_WIPERT	'l'
#define	MOD_SCROLL	'm'
#define	MOD_SPECIAL	'n'
#define	MOD_AUTO		'o'
#define	MOD_ROLLIN	'p'
#define	MOD_ROLLOUT	'q'
#define	MOD_WIPEIN	'r'
#define	MOD_WIPEOUT	's'
#define	MOD_COMPROT	't'
/* modifiers for MOD_SPECIAL */
#define	MOD_TWINKLE	'0'
#define	MOD_SPARKLE	'1'
#define	MOD_SNOW		'2'
#define	MOD_INTLOCK	'3'
#define	MOD_SWITCH	'4'
#define	MOD_SLIDE	'5'
#define	MOD_SPRAY	'6'
#define	MOD_SBURST	'7'
#define	MOD_WELCOME	'8'
#define	MOD_SLOTMAC	'9'
#define	MOD_THANKU	'S'
#define	MOD_SMOKING	'U'
#define	MOD_DRINK	'V'
#define	MOD_ANIMAL	'W'
#define	MOD_FIREWRK	'X'
#define	MOD_CAR		'Y'
#define	MOD_BOMB		'Z'

/* sign colors */
#define	CLR_BLACK	'0'
#define	CLR_RED		'1'
#define	CLR_GREEN	'2'
#define	CLR_AMBER	'3'
#define	CLR_DIMRED	'4'
#define	CLR_DIMGRN	'5'
#define	CLR_BROWN	'6'
#define	CLR_ORANGE	'7'
#define	CLR_YELLOW	'8'
#define	CLR_RAINBOW	'9'
#define	CLR_RAINBO2	'A'
#define	CLR_MIX		'B'
#define	CLR_RANDOM	'C'

/* sign special functions */
#define	SPC_TIME		0x20		/* R/W, data=HHMM */
#define	SPC_SPEAKER	0x21		/* R/W, 00=on, FF=off */
#define	SPC_GETINFO	0x22		/* Read only */
#define	SPC_MEMPOOL	0x23		/* Read only */
#define	SPC_MEMCONF	0x24		/* R/W, data=LabTypLockSIZECODE */
#define	SPC_MEMDUMP	0x25		/* Read only */
#define	SPC_WEEKDAY	0x26		/* R/W, 1-7=sun-sat */
#define	SPC_TIMEFMT	0x27		/* R/W, S=12, M=24 */
#define	SPC_SOUND	0x28		/* Write, 0=tone, 1=beeps */
#define	SPC_RUNTAB	0x29		/* R/W, LabTIME */
#define	SPC_SERERR	0x2A		/* Read only */
#define	SPC_RESET	0x2C		/* Write only */
#define	SPC_PING		0x2D		/* Read only */
#define	SPC_RUNSEQ	0x2E		/* R/W, CodLockLab */
#define	SPC_DAYTAB	0x32		/* R/W, LabStartStop */
#define	SPC_CLRERR	0x34		/* Write only */
#define	SPC_ADRESS	0x37		/* Write only */

