	TEXT	_sha1block+0(SB),$328

/*
 * wp[off] = x;
 * x += A <<< 5;
 * E += 0xca62c1d6 + x;
 * x = FN(B,C,D);
 * E += x;
 * B >>> 2
 */
#define BODYX(off,FN,V,A,B,C,D,E)\
	FN(B,C,D)\
	ADDU TMP1,E;\
	ADDU V,E;\
	MOVW TMP2,off(WREG);\
	ADDU TMP2,E;\
	SLL $5,A,TMP3;\
	SRL $27,A,TMP4;\
	OR TMP3,TMP4;\
	ADDU TMP4,E;\
	SLL $30,B,TMP4;\
	SRL $2,B;\
	OR TMP4,B

/*
 * x = data[i]
 * BODYX
 */
#define BODY1(off,FN,V,A,B,C,D,E)\
	MOVBU off(DATAREG),TMP2;\
	MOVBU (off+1)(DATAREG),TMP3;\
	MOVBU (off+2)(DATAREG),TMP1;\
	MOVBU (off+3)(DATAREG),TMP4;\
	SLL $24,TMP2;\
	SLL $16,TMP3;\
	OR TMP3,TMP2;\
	SLL $8,TMP1;\
	OR TMP1,TMP2;\
	OR TMP4,TMP2;\
	BODYX(off,FN,V,A,B,C,D,E)

/*
 * x = (wp[off-3] ^ wp[off-8] ^ wp[off-14] ^ wp[off-16]) <<< 1;
 * BODYX
 */
#define BODY(off,FN,V,A,B,C,D,E)\
	MOVW (off-64)(WREG),TMP1;\
	MOVW (off-56)(WREG),TMP2;\
	MOVW (off-32)(WREG),TMP3;\
	MOVW (off-12)(WREG),TMP4;\
	XOR TMP1,TMP2;\
	XOR TMP3,TMP2;\
	XOR TMP4,TMP2;\
	SLL $1,TMP2,TMP1;\
	SRL $31,TMP2;\
	OR TMP1,TMP2;\
	BODYX(off,FN,V,A,B,C,D,E)

/*
 * fn1 = (((C^D)&B)^D);
 */
#define FN1(B,C,D)\
	XOR C,D,TMP1;\
	AND B,TMP1;\
	XOR D,TMP1;

/*
 * fn24 = B ^ C ^ D
 */
#define FN24(B,C,D)\
	XOR B,C,TMP1;\
	XOR D,TMP1;

/*
 * fn3 = ((B ^ C) & (D ^ B)) ^ B
 */
#define FN3(B,C,D)\
	XOR B,C,TMP1;\
	XOR B,D,TMP4;\
	AND TMP4,TMP1;\
	XOR B,TMP1;

/*
 * stack offsets
 * void vtSha1Block(ulong *STATE, uchar *DATA, int LEN)
 */
#define	DATA	0
#define	LEN	4
#define	STATE	8

/*
 * stack offsets for locals
 * ulong w[80];
 * uchar *edata;
 * ulong *w15, *w40, *w60, *w80;
 * register local
 * ulong *wp = BP
 * ulong a = eax, b = ebx, c = ecx, d = edx, e = esi
 * ulong tmp = edi
 */
#define WARRAY	(-4-(80*4))

#define	AREG		R5
#define BREG		R6
#define CREG		R7
#define DREG		R8
#define EREG		R9
#define DATAREG		R1
#define STREG		R11
#define WREG		R12
#define W15REG		R13
#define W60REG		R14
#define W40REG		R15
#define W80REG		R16
#define EDREG		R17
#define VREG		R18

#define TMP1		R10
#define TMP2		R2
#define TMP3		R3
#define TMP4		R4
#define TMP5		R19

	MOVW len+LEN(FP),TMP1
	MOVW state+STATE(FP),STREG
	ADDU DATAREG,TMP1,EDREG

	MOVW 0(STREG),AREG
	MOVW 4(STREG),BREG
	MOVW 8(STREG),CREG
	MOVW 12(STREG),DREG
	MOVW 16(STREG),EREG

	MOVW $warray+WARRAY(SP),WREG
	ADDU $(15*4),WREG,W15REG
	ADDU $(40*4),WREG,W40REG
	ADDU $(60*4),WREG,W60REG
	ADDU $(80*4),WREG,W80REG

mainloop:
	MOVW $warray+WARRAY(SP),WREG

	MOVW $0x5a827999,VREG
loop1:
	BODY1(0,FN1,VREG,AREG,BREG,CREG,DREG,EREG)
	BODY1(4,FN1,VREG,EREG,AREG,BREG,CREG,DREG)
	BODY1(8,FN1,VREG,DREG,EREG,AREG,BREG,CREG)
	BODY1(12,FN1,VREG,CREG,DREG,EREG,AREG,BREG)
	BODY1(16,FN1,VREG,BREG,CREG,DREG,EREG,AREG)

	ADDU $20,DATAREG
	ADDU $20,WREG
	BNE WREG,W15REG,loop1

	BODY1(0,FN1,VREG,AREG,BREG,CREG,DREG,EREG)
	ADDU $4,DATAREG

	BODY(4,FN1,VREG,EREG,AREG,BREG,CREG,DREG)
	BODY(8,FN1,VREG,DREG,EREG,AREG,BREG,CREG)
	BODY(12,FN1,VREG,CREG,DREG,EREG,AREG,BREG)
	BODY(16,FN1,VREG,BREG,CREG,DREG,EREG,AREG)

	ADDU $20,WREG

	MOVW $0x6ed9eba1,VREG
loop2:
	BODY(0,FN24,VREG,AREG,BREG,CREG,DREG,EREG)
	BODY(4,FN24,VREG,EREG,AREG,BREG,CREG,DREG)
	BODY(8,FN24,VREG,DREG,EREG,AREG,BREG,CREG)
	BODY(12,FN24,VREG,CREG,DREG,EREG,AREG,BREG)
	BODY(16,FN24,VREG,BREG,CREG,DREG,EREG,AREG)

	ADDU $20,WREG
	BNE WREG,W40REG,loop2

	MOVW $0x8f1bbcdc,VREG
loop3:
	BODY(0,FN3,VREG,AREG,BREG,CREG,DREG,EREG)
	BODY(4,FN3,VREG,EREG,AREG,BREG,CREG,DREG)
	BODY(8,FN3,VREG,DREG,EREG,AREG,BREG,CREG)
	BODY(12,FN3,VREG,CREG,DREG,EREG,AREG,BREG)
	BODY(16,FN3,VREG,BREG,CREG,DREG,EREG,AREG)

	ADDU $20,WREG
	BNE WREG,W60REG,loop3

	MOVW $0xca62c1d6,VREG
loop4:
	BODY(0,FN24,VREG,AREG,BREG,CREG,DREG,EREG)
	BODY(4,FN24,VREG,EREG,AREG,BREG,CREG,DREG)
	BODY(8,FN24,VREG,DREG,EREG,AREG,BREG,CREG)
	BODY(12,FN24,VREG,CREG,DREG,EREG,AREG,BREG)
	BODY(16,FN24,VREG,BREG,CREG,DREG,EREG,AREG)

	ADDU $20,WREG
	BNE WREG,W80REG,loop4

	MOVW 0(STREG),TMP1
	MOVW 4(STREG),TMP2
	MOVW 8(STREG),TMP3
	MOVW 12(STREG),TMP4
	MOVW 16(STREG),TMP5

	ADDU TMP1,AREG
	ADDU TMP2,BREG
	ADDU TMP3,CREG
	ADDU TMP4,DREG
	ADDU TMP5,EREG

	MOVW AREG,0(STREG)
	MOVW BREG,4(STREG)
	MOVW CREG,8(STREG)
	MOVW DREG,12(STREG)
	MOVW EREG,16(STREG)

	BNE DATAREG,EDREG,mainloop

	RET

	END