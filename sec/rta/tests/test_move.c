/* Copyright 2008-2013 Freescale Semiconductor, Inc. */

#include <stdio.h>
#include "flib/rta.h"
#include "test_common.h"

enum rta_sec_era rta_sec_era;
unsigned prg_buff[1000];

unsigned test_move_op(uint32_t *buff)
{
	struct program prg;
	struct program *program = &prg;
	int len = 16;
	uint16_t label1 = 24;

	PROGRAM_CNTXT_INIT(buff, 0);
	/* MOVE from Class 1 Context */
	MOVE(CONTEXT1, 19, CONTEXT1, 0, IMM(len), 0);
	MOVE(CONTEXT1, 21, CONTEXT2, 0, IMM(len), 0);
	MOVE(CONTEXT1, 20, OFIFO, 0, IMM(len), 0);
	MOVE(CONTEXT1, 0, DESCBUF, 17, IMM(len), 0);
	MOVE(CONTEXT1, 16, DESCBUF, 18, IMM(len), 0);
	MOVE(CONTEXT1, 32, DESCBUF, 19, IMM(len), 0);
	MOVE(CONTEXT1, 48, DESCBUF, label1, IMM(len), 0);
	MOVE(CONTEXT1, 1, MATH0, 0, IMM(len), 0);
	MOVE(CONTEXT1, 2, MATH1, 0, IMM(len), 0);
	MOVE(CONTEXT1, 3, MATH2, 0, IMM(len), 0);
	MOVE(CONTEXT1, 5, MATH3, 0, IMM(len), 0);
	MOVE(CONTEXT1, 21, IFIFOAB1, 0, IMM(len), 0);
	MOVE(CONTEXT1, 22, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(CONTEXT1, 23, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(CONTEXT1, 25, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(CONTEXT1, 26, IFIFOAB2, 0, IMM(len), 0);
	MOVE(CONTEXT1, 27, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(CONTEXT1, 29, IFIFO, 0, IMM(len), 0);
	MOVE(CONTEXT1, 1, PKA, 0, IMM(len), 0);
	MOVE(CONTEXT1, 2, KEY1, 0, IMM(len), 0);
	MOVE(CONTEXT1, 0, KEY1, 3, IMM(len), 0);
	MOVE(CONTEXT1, 5, KEY2, 0, IMM(len), 0);
	MOVE(CONTEXT1, 0, KEY2, 6, IMM(len), 0);
	MOVE(CONTEXT1, 4, ALTSOURCE, 0, IMM(len), 0);

	/* MOVE from Class 2 Context */
	MOVE(CONTEXT2, 5, CONTEXT1, 0, IMM(8), 0);
	MOVE(CONTEXT2, 6, CONTEXT1, 0, IMM(len), WITH(WAITCOMP));
	MOVE(CONTEXT2, 7, CONTEXT2, 0, IMM(len), 0);
	MOVE(CONTEXT2, 9, CONTEXT2, 0, IMM(len), WITH(WAITCOMP));
	MOVE(CONTEXT2, 4, OFIFO, 0, IMM(len), 0);
	MOVE(CONTEXT2, 0, DESCBUF, 33, IMM(len), 0);
	MOVE(CONTEXT2, 16, DESCBUF, 34, IMM(len), 0);
	MOVE(CONTEXT2, 32, DESCBUF, 35, IMM(len), 0);
	MOVE(CONTEXT2, 48, DESCBUF, 37, IMM(len), 0);
	MOVE(CONTEXT2, 1, MATH0, 0, IMM(len), 0);
	MOVE(CONTEXT2, 2, MATH1, 0, IMM(len), 0);
	MOVE(CONTEXT2, 3, MATH2, 0, IMM(len), 0);
	MOVE(CONTEXT2, 5, MATH3, 0, IMM(len), 0);
	MOVE(CONTEXT2, 1, IFIFOAB1, 0, IMM(len), 0);
	MOVE(CONTEXT2, 2, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(CONTEXT2, 3, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(CONTEXT2, 5, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(CONTEXT2, 6, IFIFOAB2, 0, IMM(len), 0);
	MOVE(CONTEXT2, 7, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(CONTEXT2, 9, IFIFO, 0, IMM(len), 0);
	MOVE(CONTEXT2, 10, PKA, 0, IMM(len), 0);
	MOVE(CONTEXT2, 11, KEY1, 0, IMM(len), 0);
	MOVE(CONTEXT2, 0, KEY1, 13, IMM(len), 0);
	MOVE(CONTEXT2, 14, KEY2, 0, IMM(len), 0);
	MOVE(CONTEXT2, 0, KEY2, 15, IMM(len), 0);
	MOVE(CONTEXT2, 4, ALTSOURCE, 0, IMM(len), 0);

	/* MOVE from Output Data FIFO */
	MOVE(OFIFO, 0, CONTEXT1, 1, IMM(len), 0);
	MOVE(OFIFO, 0, CONTEXT2, 2, IMM(len), 0);
	MOVE(OFIFO, 0, DESCBUF, 3, IMM(len), 0);
	MOVE(OFIFO, 0, MATH0, 1, IMM(len), 0);
	MOVE(OFIFO, 0, MATH1, 2, IMM(len), 0);
	MOVE(OFIFO, 0, MATH2, 3, IMM(len), 0);
	MOVE(OFIFO, 0, MATH3, 5, IMM(len), 0);
	MOVE(OFIFO, 0, IFIFOAB1, 0, IMM(len), 0);
	MOVE(OFIFO, 0, IFIFOAB1, 0, IMM(16), 0);
	MOVE(OFIFO, 0, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(OFIFO, 0, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(OFIFO, 0, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(OFIFO, 0, IFIFOAB2, 0, IMM(len), 0);
	MOVE(OFIFO, 0, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(OFIFO, 0, IFIFO, 0, IMM(len), 0);
	MOVE(OFIFO, 0, PKA, 0, IMM(len), 0);
	MOVE(OFIFO, 0, KEY1, 9, IMM(len), 0);
	MOVE(OFIFO, 0, KEY2, 11, IMM(len), 0);
	MOVE(OFIFO, 0, ALTSOURCE, 0, IMM(len), 0);

	/* MOVE from Descriptor Buffer */
	MOVE(DESCBUF, 17, CONTEXT1, 0, IMM(8), 0);
	MOVE(DESCBUF, 18, CONTEXT1, 16, IMM(8), 0);
	MOVE(DESCBUF, 19, CONTEXT1, 32, IMM(8), 0);
	MOVE(DESCBUF, label1, CONTEXT1, 48, IMM(8), 0);
	MOVE(DESCBUF, 17, CONTEXT2, 0, IMM(8), 0);
	MOVE(DESCBUF, 18, CONTEXT2, 16, IMM(8), 0);
	MOVE(DESCBUF, 19, CONTEXT2, 32, IMM(8), 0);
	MOVE(DESCBUF, 21, CONTEXT2, 48, IMM(8), 0);
	MOVE(DESCBUF, 4, OFIFO, 0, IMM(8), 0);
	MOVE(DESCBUF, 1, MATH0, 0, IMM(3), 0);
	MOVE(DESCBUF, 2, MATH1, 0, IMM(3), 0);
	MOVE(DESCBUF, 3, MATH2, 0, IMM(3), 0);
	MOVE(DESCBUF, 1, MATH3, 0, IMM(3), 0);
	MOVE(DESCBUF, 5, MATH3, 0, IMM(8), 0);
	MOVE(DESCBUF, 11, IFIFOAB1, 0, IMM(len), 0);
	MOVE(DESCBUF, 13, IFIFOAB1, 0, IMM(len), 0);
	MOVE(DESCBUF, 14, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(DESCBUF, 15, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(DESCBUF, 17, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(DESCBUF, 18, IFIFOAB2, 0, IMM(len), 0);
	MOVE(DESCBUF, 19, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(DESCBUF, 21, IFIFO, 0, IMM(len), 0);
	MOVE(DESCBUF, 22, PKA, 0, IMM(8), 0);
	MOVE(DESCBUF, 23, KEY1, 0, IMM(8), 0);
	MOVE(DESCBUF, 25, KEY2, 0, IMM(8), 0);
	MOVE(DESCBUF, 4, ALTSOURCE, 0, IMM(8), 0);

	/* MOVE from Math 0 */
	MOVE(MATH0, 0, CONTEXT1, 1, IMM(8), 0);
	MOVE(MATH0, 0, CONTEXT2, 2, IMM(8), 0);
	MOVE(MATH0, 4, OFIFO, 0, IMM(8), 0);
	MOVE(MATH0, 0, DESCBUF, 3, IMM(8), 0);
	MOVE(MATH0, 0, MATH0, 1, IMM(8), 0);
	MOVE(MATH0, 0, MATH1, 2, IMM(6), 0);
	MOVE(MATH0, 0, MATH2, 3, IMM(8), 0);
	MOVE(MATH0, 0, MATH3, 5, IMM(8), 0);
	MOVE(MATH0, 11, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH0, 13, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH0, 14, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(MATH0, 15, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(MATH0, 17, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(MATH0, 18, IFIFOAB2, 0, IMM(len), 0);
	MOVE(MATH0, 19, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(MATH0, 1, IFIFO, 0, IMM(len), 0);
	MOVE(MATH0, 11, PKA, 0, IMM(8), 0);
	MOVE(MATH0, 0, KEY1, 3, IMM(8), 0);
	MOVE(MATH0, 0, KEY2, 5, IMM(8), 0);
	MOVE(MATH0, 4, ALTSOURCE, 0, IMM(8), 0);

	/* MOVE from Math 1 */
	MOVE(MATH1, 0, CONTEXT1, 1, IMM(8), 0);
	MOVE(MATH1, 0, CONTEXT2, 2, IMM(8), 0);
	MOVE(MATH1, 4, OFIFO, 0, IMM(8), 0);
	MOVE(MATH1, 0, DESCBUF, 3, IMM(8), 0);
	MOVE(MATH1, 0, MATH0, 1, IMM(8), 0);
	MOVE(MATH1, 0, MATH1, 2, IMM(6), 0);
	MOVE(MATH1, 0, MATH2, 3, IMM(8), 0);
	MOVE(MATH1, 0, MATH3, 5, IMM(8), 0);
	MOVE(MATH1, 11, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH1, 13, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH1, 14, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(MATH1, 15, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(MATH1, 17, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(MATH1, 18, IFIFOAB2, 0, IMM(len), 0);
	MOVE(MATH1, 19, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(MATH1, 1, IFIFO, 0, IMM(len), 0);
	MOVE(MATH1, 11, PKA, 0, IMM(8), 0);
	MOVE(MATH1, 0, KEY1, 3, IMM(8), 0);
	MOVE(MATH1, 0, KEY2, 5, IMM(8), 0);
	MOVE(MATH1, 4, ALTSOURCE, 0, IMM(8), 0);

	/* MOVE from Math 2 */
	MOVE(MATH2, 0, CONTEXT1, 1, IMM(8), 0);
	MOVE(MATH2, 0, CONTEXT2, 2, IMM(8), 0);
	MOVE(MATH2, 4, OFIFO, 0, IMM(8), 0);
	MOVE(MATH2, 0, DESCBUF, 3, IMM(8), 0);
	MOVE(MATH2, 0, MATH0, 1, IMM(8), 0);
	MOVE(MATH2, 0, MATH1, 2, IMM(6), 0);
	MOVE(MATH2, 0, MATH2, 3, IMM(8), 0);
	MOVE(MATH2, 0, MATH3, 5, IMM(8), 0);
	MOVE(MATH2, 11, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH2, 13, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH2, 14, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(MATH2, 15, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(MATH2, 17, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(MATH2, 18, IFIFOAB2, 0, IMM(len), 0);
	MOVE(MATH2, 19, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(MATH2, 1, IFIFO, 0, IMM(len), 0);
	MOVE(MATH2, 11, PKA, 0, IMM(8), 0);
	MOVE(MATH2, 0, KEY1, 3, IMM(8), 0);
	MOVE(MATH2, 0, KEY2, 5, IMM(8), 0);
	MOVE(MATH2, 4, ALTSOURCE, 0, IMM(8), 0);

	/* MOVE from Math 3 */
	MOVE(MATH3, 0, CONTEXT1, 1, IMM(8), 0);
	MOVE(MATH3, 0, CONTEXT2, 2, IMM(8), 0);
	MOVE(MATH3, 4, OFIFO, 0, IMM(8), 0);
	MOVE(MATH3, 0, DESCBUF, 3, IMM(8), 0);
	MOVE(MATH3, 0, MATH0, 1, IMM(8), 0);
	MOVE(MATH3, 0, MATH1, 2, IMM(6), 0);
	MOVE(MATH3, 0, MATH2, 3, IMM(8), 0);
	MOVE(MATH3, 0, MATH3, 5, IMM(8), 0);
	MOVE(MATH3, 11, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH3, 13, IFIFOAB1, 0, IMM(len), 0);
	MOVE(MATH3, 14, IFIFOAB1, 0, IMM(len), WITH(FLUSH1));
	MOVE(MATH3, 15, IFIFOAB1, 0, IMM(len), WITH(LAST1));
	MOVE(MATH3, 17, IFIFOAB1, 0, IMM(len), WITH(LAST1 | FLUSH1));
	MOVE(MATH3, 18, IFIFOAB2, 0, IMM(len), 0);
	MOVE(MATH3, 19, IFIFOAB2, 0, IMM(len), WITH(LAST2));
	MOVE(MATH3, 1, IFIFO, 0, IMM(len), 0);
	MOVE(MATH3, 11, PKA, 0, IMM(8), 0);
	MOVE(MATH3, 0, KEY1, 3, IMM(8), 0);
	MOVE(MATH3, 0, KEY2, 5, IMM(8), 0);
	MOVE(MATH3, 4, ALTSOURCE, 0, IMM(8), 0);

	/* MOVE from IFIFO via DECO Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(IFIFOABD, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(IFIFOABD, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(IFIFOABD, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(IFIFOABD, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(IFIFOABD, 0, MATH0, 4, IMM(8), 0);
	MOVE(IFIFOABD, 0, MATH1, 8, IMM(6), 0);
	MOVE(IFIFOABD, 0, MATH2, 12, IMM(8), 0);
	MOVE(IFIFOABD, 0, MATH3, 16, IMM(8), 0);
	MOVE(IFIFOABD, 0, KEY1, 4, IMM(8), 0);
	MOVE(IFIFOABD, 0, KEY2, 8, IMM(8), 0);

	/* MOVE from IFIFO via Class 1 Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(IFIFOAB1, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(IFIFOAB1, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(IFIFOAB1, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(IFIFOAB1, 0, OFIFO, 0, IMM(5128), WITH(FLUSH1));
	MOVE(IFIFOAB1, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(IFIFOAB1, 0, MATH0, 4, IMM(8), 0);
	MOVE(IFIFOAB1, 0, MATH1, 8, IMM(6), 0);
	MOVE(IFIFOAB1, 0, MATH2, 12, IMM(8), 0);
	MOVE(IFIFOAB1, 0, MATH3, 16, IMM(8), 0);
	MOVE(IFIFOAB1, 0, KEY1, 4, IMM(8), 0);
	MOVE(IFIFOAB1, 0, KEY2, 8, IMM(8), 0);

	/* MOVE from IFIFO via Class 2 Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(IFIFOAB2, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(IFIFOAB2, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(IFIFOAB2, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(IFIFOAB2, 0, OFIFO, 0, IMM(5128), WITH(FLUSH2));
	MOVE(IFIFOAB2, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(IFIFOAB2, 0, MATH0, 4, IMM(8), 0);
	MOVE(IFIFOAB2, 0, MATH1, 8, IMM(6), 0);
	MOVE(IFIFOAB2, 0, MATH2, 12, IMM(8), 0);
	MOVE(IFIFOAB2, 0, MATH3, 16, IMM(8), 0);
	MOVE(IFIFOAB2, 0, KEY1, 4, IMM(8), 0);
	MOVE(IFIFOAB2, 0, KEY2, 8, IMM(8), 0);

	/* MOVE from DECO Align Block (no auto-info-fifo-entry)  */
	MOVE(ABD, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(ABD, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(ABD, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(ABD, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(ABD, 0, MATH0, 4, IMM(8), 0);
	MOVE(ABD, 0, MATH1, 8, IMM(6), 0);
	MOVE(ABD, 0, MATH2, 12, IMM(8), 0);
	MOVE(ABD, 0, MATH3, 16, IMM(8), 0);
	MOVE(ABD, 0, KEY1, 4, IMM(8), 0);
	MOVE(ABD, 0, KEY2, 8, IMM(8), 0);

	/* MOVE from Class 1 Align Block (no auto-info-fifo-entry)  */
	MOVE(AB1, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(AB1, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(AB1, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(AB1, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(AB1, 0, MATH0, 4, IMM(8), 0);
	MOVE(AB1, 0, MATH1, 8, IMM(6), 0);
	MOVE(AB1, 0, MATH2, 12, IMM(8), 0);
	MOVE(AB1, 0, MATH3, 16, IMM(8), 0);
	MOVE(AB1, 0, KEY1, 4, IMM(8), 0);
	MOVE(AB1, 0, KEY2, 8, IMM(8), 0);

	/* MOVE from Class 2 Align Block (no auto-info-fifo-entry)  */
	MOVE(AB2, 0, CONTEXT1, 4, IMM(8), 0);
	MOVE(AB2, 0, CONTEXT2, 8, IMM(8), 0);
	MOVE(AB2, 0, OFIFO, 0, IMM(5128), 0);
	MOVE(AB2, 0, DESCBUF, 16, IMM(8), 0);
	MOVE(AB2, 0, MATH0, 4, IMM(8), 0);
	MOVE(AB2, 0, MATH1, 8, IMM(6), 0);
	MOVE(AB2, 0, MATH2, 12, IMM(8), 0);
	MOVE(AB2, 0, MATH3, 16, IMM(8), 0);
	MOVE(AB2, 0, KEY1, 4, IMM(8), 0);
	MOVE(AB2, 0, KEY2, 8, IMM(8), 0);

	MOVE(CONTEXT1, 13, CONTEXT1, 0, MATH0, WITH(WAITCOMP));
	MOVE(CONTEXT1, 9, CONTEXT1, 0, MATH1, 0);
	MOVE(CONTEXT1, 47, CONTEXT1, 0, MATH2, 0);

	MOVE(AB2, 0, OFIFO, 0, MATH3, 0);

	return PROGRAM_FINALIZE();
}

int main(int argc, char **argv)
{
	unsigned size;

	pr_debug("MOVE program\n");
	rta_set_sec_era(RTA_SEC_ERA_4);
	size = test_move_op(prg_buff);
	pr_debug("size = %d\n", size);
	print_prog(prg_buff, size);

	return 0;
}
