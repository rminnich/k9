#define nil		((void*)0)
typedef	unsigned short	ushort;
typedef	unsigned char	uchar;
typedef unsigned long	ulong;
typedef unsigned int	uint;
typedef   signed char	schar;
typedef	long long	vlong;
typedef	unsigned long long uvlong;
typedef unsigned long long uintptr;
typedef unsigned long	usize;
typedef	uint		Rune;
typedef union FPdbleword FPdbleword;
typedef uvlong		jmp_buf[2];
#define	JMPBUFSP	0
#define	JMPBUFPC	1
#define	JMPBUFDPC	0
typedef unsigned int	mpdigit;	/* for /sys/include/mp.h */
typedef unsigned char	u8int;
typedef unsigned short	u16int;
typedef unsigned int	u32int;
typedef unsigned long long u64int;

/* MXCSR */
/* fcr */
#define	FPFTZ	(1<<15)	/* amd64 */
#define	FPINEX	(1<<12)
#define	FPUNFL	(1<<11)
#define	FPOVFL	(1<<10)
#define	FPZDIV	(1<<9)
#define	FPDNRM	(1<<8)	/* amd64 */
#define	FPINVAL	(1<<7)
#define	FPDAZ	(1<<6)	/* amd64 */
#define	FPRNR	(0<<13)
#define	FPRZ	(3<<13)
#define	FPRPINF	(2<<13)
#define	FPRNINF	(1<<13)
#define	FPRMASK	(3<<13)
#define	FPPEXT	0
#define	FPPSGL	0
#define	FPPDBL	0
#define	FPPMASK	0
/* fsr */
#define	FPAINEX	(1<<5)
#define	FPAUNFL	(1<<4)
#define	FPAOVFL	(1<<3)
#define	FPAZDIV	(1<<2)
#define	FPADNRM	(1<<1)	/* not in plan 9 */
#define	FPAINVAL	(1<<0)
union FPdbleword
{
	double	x;
	struct {	/* little endian */
		uint lo;
		uint hi;
	};
};

