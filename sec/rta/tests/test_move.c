/* Copyright 2008-2013 Freescale Semiconductor, Inc. */

#include <stdio.h>
#include "flib/rta.h"
#include "test_common.h"

enum rta_sec_era rta_sec_era;
unsigned prg_buff[1000];

int test_move_op(uint32_t *buff)
{
	struct program prg;
	struct program *p = &prg;
	int len = 16;
	uint16_t label1 = 24;

	PROGRAM_CNTXT_INIT(p, buff, 0);
	/* MOVE from Class 1 Context */
	MOVE(p, CONTEXT1, 19, CONTEXT1, 0, len, IMMED);
	MOVE(p, CONTEXT1, 21, CONTEXT2, 0, len, IMMED);
	MOVE(p, CONTEXT1, 20, OFIFO, 0, len, IMMED);
	MOVE(p, CONTEXT1, 0, DESCBUF, 17, len, IMMED);
	MOVE(p, CONTEXT1, 16, DESCBUF, 18, len, IMMED);
	MOVE(p, CONTEXT1, 32, DESCBUF, 19, len, IMMED);
	MOVE(p, CONTEXT1, 48, DESCBUF, label1, len, IMMED);
	MOVE(p, CONTEXT1, 1, MATH0, 0, len, IMMED);
	MOVE(p, CONTEXT1, 2, MATH1, 0, len, IMMED);
	MOVE(p, CONTEXT1, 3, MATH2, 0, len, IMMED);
	MOVE(p, CONTEXT1, 5, MATH3, 0, len, IMMED);
	MOVE(p, CONTEXT1, 21, IFIFOAB1, 0, len, IMMED);
	MOVE(p, CONTEXT1, 22, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, CONTEXT1, 23, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, CONTEXT1, 25, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, CONTEXT1, 26, IFIFOAB2, 0, len, IMMED);
	MOVE(p, CONTEXT1, 27, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, CONTEXT1, 29, IFIFO, 0, len, IMMED);
	MOVE(p, CONTEXT1, 1, PKA, 0, len, IMMED);
	MOVE(p, CONTEXT1, 2, KEY1, 0, len, IMMED);
	MOVE(p, CONTEXT1, 0, KEY1, 3, len, IMMED);
	MOVE(p, CONTEXT1, 5, KEY2, 0, len, IMMED);
	MOVE(p, CONTEXT1, 0, KEY2, 6, len, IMMED);
	MOVE(p, CONTEXT1, 4, ALTSOURCE, 0, len, IMMED);

	/* MOVE from Class 2 Context */
	MOVE(p, CONTEXT2, 5, CONTEXT1, 0, 8, IMMED);
	MOVE(p, CONTEXT2, 6, CONTEXT1, 0, len, WAITCOMP | IMMED);
	MOVE(p, CONTEXT2, 7, CONTEXT2, 0, len, IMMED);
	MOVE(p, CONTEXT2, 9, CONTEXT2, 0, len, WAITCOMP | IMMED);
	MOVE(p, CONTEXT2, 4, OFIFO, 0, len, IMMED);
	MOVE(p, CONTEXT2, 0, DESCBUF, 33, len, IMMED);
	MOVE(p, CONTEXT2, 16, DESCBUF, 34, len, IMMED);
	MOVE(p, CONTEXT2, 32, DESCBUF, 35, len, IMMED);
	MOVE(p, CONTEXT2, 48, DESCBUF, 37, len, IMMED);
	MOVE(p, CONTEXT2, 1, MATH0, 0, len, IMMED);
	MOVE(p, CONTEXT2, 2, MATH1, 0, len, IMMED);
	MOVE(p, CONTEXT2, 3, MATH2, 0, len, IMMED);
	MOVE(p, CONTEXT2, 5, MATH3, 0, len, IMMED);
	MOVE(p, CONTEXT2, 1, IFIFOAB1, 0, len, IMMED);
	MOVE(p, CONTEXT2, 2, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, CONTEXT2, 3, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, CONTEXT2, 5, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, CONTEXT2, 6, IFIFOAB2, 0, len, IMMED);
	MOVE(p, CONTEXT2, 7, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, CONTEXT2, 9, IFIFO, 0, len, IMMED);
	MOVE(p, CONTEXT2, 10, PKA, 0, len, IMMED);
	MOVE(p, CONTEXT2, 11, KEY1, 0, len, IMMED);
	MOVE(p, CONTEXT2, 0, KEY1, 13, len, IMMED);
	MOVE(p, CONTEXT2, 14, KEY2, 0, len, IMMED);
	MOVE(p, CONTEXT2, 0, KEY2, 15, len, IMMED);
	MOVE(p, CONTEXT2, 4, ALTSOURCE, 0, len, IMMED);

	/* MOVE from Output Data FIFO */
	MOVE(p, OFIFO, 0, CONTEXT1, 1, len, IMMED);
	MOVE(p, OFIFO, 0, CONTEXT2, 2, len, IMMED);
	MOVE(p, OFIFO, 0, DESCBUF, 3, len, IMMED);
	MOVE(p, OFIFO, 0, MATH0, 1, len, IMMED);
	MOVE(p, OFIFO, 0, MATH1, 2, len, IMMED);
	MOVE(p, OFIFO, 0, MATH2, 3, len, IMMED);
	MOVE(p, OFIFO, 0, MATH3, 5, len, IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB1, 0, len, IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB1, 0, 16, IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB2, 0, len, IMMED);
	MOVE(p, OFIFO, 0, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, OFIFO, 0, IFIFO, 0, len, IMMED);
	MOVE(p, OFIFO, 0, PKA, 0, len, IMMED);
	MOVE(p, OFIFO, 0, KEY1, 9, len, IMMED);
	MOVE(p, OFIFO, 0, KEY2, 11, len, IMMED);
	MOVE(p, OFIFO, 0, ALTSOURCE, 0, len, IMMED);

	/* MOVE from Descriptor Buffer */
	MOVE(p, DESCBUF, 17, CONTEXT1, 0, 8, IMMED);
	MOVE(p, DESCBUF, 18, CONTEXT1, 16, 8, IMMED);
	MOVE(p, DESCBUF, 19, CONTEXT1, 32, 8, IMMED);
	MOVE(p, DESCBUF, label1, CONTEXT1, 48, 8, IMMED);
	MOVE(p, DESCBUF, 17, CONTEXT2, 0, 8, IMMED);
	MOVE(p, DESCBUF, 18, CONTEXT2, 16, 8, IMMED);
	MOVE(p, DESCBUF, 19, CONTEXT2, 32, 8, IMMED);
	MOVE(p, DESCBUF, 21, CONTEXT2, 48, 8, IMMED);
	MOVE(p, DESCBUF, 4, OFIFO, 0, 8, IMMED);
	MOVE(p, DESCBUF, 1, MATH0, 0, 3, IMMED);
	MOVE(p, DESCBUF, 2, MATH1, 0, 3, IMMED);
	MOVE(p, DESCBUF, 3, MATH2, 0, 3, IMMED);
	MOVE(p, DESCBUF, 1, MATH3, 0, 3, IMMED);
	MOVE(p, DESCBUF, 5, MATH3, 0, 8, IMMED);
	MOVE(p, DESCBUF, 11, IFIFOAB1, 0, len, IMMED);
	MOVE(p, DESCBUF, 13, IFIFOAB1, 0, len, IMMED);
	MOVE(p, DESCBUF, 14, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, DESCBUF, 15, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, DESCBUF, 17, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, DESCBUF, 18, IFIFOAB2, 0, len, IMMED);
	MOVE(p, DESCBUF, 19, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, DESCBUF, 21, IFIFO, 0, len, IMMED);
	MOVE(p, DESCBUF, 22, PKA, 0, 8, IMMED);
	MOVE(p, DESCBUF, 23, KEY1, 0, 8, IMMED);
	MOVE(p, DESCBUF, 25, KEY2, 0, 8, IMMED);
	MOVE(p, DESCBUF, 4, ALTSOURCE, 0, 8, IMMED);

	/* MOVE from Math 0 */
	MOVE(p, MATH0, 0, CONTEXT1, 1, 8, IMMED);
	MOVE(p, MATH0, 0, CONTEXT2, 2, 8, IMMED);
	MOVE(p, MATH0, 4, OFIFO, 0, 8, IMMED);
	MOVE(p, MATH0, 0, DESCBUF, 3, 8, IMMED);
	MOVE(p, MATH0, 0, MATH0, 1, 8, IMMED);
	MOVE(p, MATH0, 0, MATH1, 2, 6, IMMED);
	MOVE(p, MATH0, 0, MATH2, 3, 8, IMMED);
	MOVE(p, MATH0, 0, MATH3, 5, 8, IMMED);
	MOVE(p, MATH0, 11, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH0, 13, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH0, 14, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, MATH0, 15, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, MATH0, 17, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, MATH0, 18, IFIFOAB2, 0, len, IMMED);
	MOVE(p, MATH0, 19, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, MATH0, 1, IFIFO, 0, len, IMMED);
	MOVE(p, MATH0, 11, PKA, 0, 8, IMMED);
	MOVE(p, MATH0, 0, KEY1, 3, 8, IMMED);
	MOVE(p, MATH0, 0, KEY2, 5, 8, IMMED);
	MOVE(p, MATH0, 4, ALTSOURCE, 0, 8, IMMED);

	/* MOVE from Math 1 */
	MOVE(p, MATH1, 0, CONTEXT1, 1, 8, IMMED);
	MOVE(p, MATH1, 0, CONTEXT2, 2, 8, IMMED);
	MOVE(p, MATH1, 4, OFIFO, 0, 8, IMMED);
	MOVE(p, MATH1, 0, DESCBUF, 3, 8, IMMED);
	MOVE(p, MATH1, 0, MATH0, 1, 8, IMMED);
	MOVE(p, MATH1, 0, MATH1, 2, 6, IMMED);
	MOVE(p, MATH1, 0, MATH2, 3, 8, IMMED);
	MOVE(p, MATH1, 0, MATH3, 5, 8, IMMED);
	MOVE(p, MATH1, 11, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH1, 13, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH1, 14, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, MATH1, 15, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, MATH1, 17, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, MATH1, 18, IFIFOAB2, 0, len, IMMED);
	MOVE(p, MATH1, 19, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, MATH1, 1, IFIFO, 0, len, IMMED);
	MOVE(p, MATH1, 11, PKA, 0, 8, IMMED);
	MOVE(p, MATH1, 0, KEY1, 3, 8, IMMED);
	MOVE(p, MATH1, 0, KEY2, 5, 8, IMMED);
	MOVE(p, MATH1, 4, ALTSOURCE, 0, 8, IMMED);

	/* MOVE from Math 2 */
	MOVE(p, MATH2, 0, CONTEXT1, 1, 8, IMMED);
	MOVE(p, MATH2, 0, CONTEXT2, 2, 8, IMMED);
	MOVE(p, MATH2, 4, OFIFO, 0, 8, IMMED);
	MOVE(p, MATH2, 0, DESCBUF, 3, 8, IMMED);
	MOVE(p, MATH2, 0, MATH0, 1, 8, IMMED);
	MOVE(p, MATH2, 0, MATH1, 2, 6, IMMED);
	MOVE(p, MATH2, 0, MATH2, 3, 8, IMMED);
	MOVE(p, MATH2, 0, MATH3, 5, 8, IMMED);
	MOVE(p, MATH2, 11, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH2, 13, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH2, 14, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, MATH2, 15, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, MATH2, 17, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, MATH2, 18, IFIFOAB2, 0, len, IMMED);
	MOVE(p, MATH2, 19, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, MATH2, 1, IFIFO, 0, len, IMMED);
	MOVE(p, MATH2, 11, PKA, 0, 8, IMMED);
	MOVE(p, MATH2, 0, KEY1, 3, 8, IMMED);
	MOVE(p, MATH2, 0, KEY2, 5, 8, IMMED);
	MOVE(p, MATH2, 4, ALTSOURCE, 0, 8, IMMED);

	/* MOVE from Math 3 */
	MOVE(p, MATH3, 0, CONTEXT1, 1, 8, IMMED);
	MOVE(p, MATH3, 0, CONTEXT2, 2, 8, IMMED);
	MOVE(p, MATH3, 4, OFIFO, 0, 8, IMMED);
	MOVE(p, MATH3, 0, DESCBUF, 3, 8, IMMED);
	MOVE(p, MATH3, 0, MATH0, 1, 8, IMMED);
	MOVE(p, MATH3, 0, MATH1, 2, 6, IMMED);
	MOVE(p, MATH3, 0, MATH2, 3, 8, IMMED);
	MOVE(p, MATH3, 0, MATH3, 5, 8, IMMED);
	MOVE(p, MATH3, 11, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH3, 13, IFIFOAB1, 0, len, IMMED);
	MOVE(p, MATH3, 14, IFIFOAB1, 0, len, FLUSH1 | IMMED);
	MOVE(p, MATH3, 15, IFIFOAB1, 0, len, LAST1 | IMMED);
	MOVE(p, MATH3, 17, IFIFOAB1, 0, len, LAST1 | FLUSH1 | IMMED);
	MOVE(p, MATH3, 18, IFIFOAB2, 0, len, IMMED);
	MOVE(p, MATH3, 19, IFIFOAB2, 0, len, LAST2 | IMMED);
	MOVE(p, MATH3, 1, IFIFO, 0, len, IMMED);
	MOVE(p, MATH3, 11, PKA, 0, 8, IMMED);
	MOVE(p, MATH3, 0, KEY1, 3, 8, IMMED);
	MOVE(p, MATH3, 0, KEY2, 5, 8, IMMED);
	MOVE(p, MATH3, 4, ALTSOURCE, 0, 8, IMMED);

	/* MOVE from IFIFO via DECO Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(p, IFIFOABD, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, IFIFOABD, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, IFIFOABD, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, IFIFOABD, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, IFIFOABD, 0, MATH0, 4, 8, IMMED);
	MOVE(p, IFIFOABD, 0, MATH1, 8, 6, IMMED);
	MOVE(p, IFIFOABD, 0, MATH2, 12, 8, IMMED);
	MOVE(p, IFIFOABD, 0, MATH3, 16, 8, IMMED);
	MOVE(p, IFIFOABD, 0, KEY1, 4, 8, IMMED);
	MOVE(p, IFIFOABD, 0, KEY2, 8, 8, IMMED);

	/* MOVE from IFIFO via Class 1 Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(p, IFIFOAB1, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, IFIFOAB1, 0, OFIFO, 0, 5128, FLUSH1 | IMMED);
	MOVE(p, IFIFOAB1, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, MATH0, 4, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, MATH1, 8, 6, IMMED);
	MOVE(p, IFIFOAB1, 0, MATH2, 12, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, MATH3, 16, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, KEY1, 4, 8, IMMED);
	MOVE(p, IFIFOAB1, 0, KEY2, 8, 8, IMMED);

	/* MOVE from IFIFO via Class 2 Align Block
	 * (auto-info-fifo-entry created) */
	MOVE(p, IFIFOAB2, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, IFIFOAB2, 0, OFIFO, 0, 5128, FLUSH2 | IMMED);
	MOVE(p, IFIFOAB2, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, MATH0, 4, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, MATH1, 8, 6, IMMED);
	MOVE(p, IFIFOAB2, 0, MATH2, 12, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, MATH3, 16, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, KEY1, 4, 8, IMMED);
	MOVE(p, IFIFOAB2, 0, KEY2, 8, 8, IMMED);

	/* MOVE from DECO Align Block (no auto-info-fifo-entry)  */
	MOVE(p, ABD, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, ABD, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, ABD, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, ABD, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, ABD, 0, MATH0, 4, 8, IMMED);
	MOVE(p, ABD, 0, MATH1, 8, 6, IMMED);
	MOVE(p, ABD, 0, MATH2, 12, 8, IMMED);
	MOVE(p, ABD, 0, MATH3, 16, 8, IMMED);
	MOVE(p, ABD, 0, KEY1, 4, 8, IMMED);
	MOVE(p, ABD, 0, KEY2, 8, 8, IMMED);

	/* MOVE from Class 1 Align Block (no auto-info-fifo-entry)  */
	MOVE(p, AB1, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, AB1, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, AB1, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, AB1, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, AB1, 0, MATH0, 4, 8, IMMED);
	MOVE(p, AB1, 0, MATH1, 8, 6, IMMED);
	MOVE(p, AB1, 0, MATH2, 12, 8, IMMED);
	MOVE(p, AB1, 0, MATH3, 16, 8, IMMED);
	MOVE(p, AB1, 0, KEY1, 4, 8, IMMED);
	MOVE(p, AB1, 0, KEY2, 8, 8, IMMED);

	/* MOVE from Class 2 Align Block (no auto-info-fifo-entry)  */
	MOVE(p, AB2, 0, CONTEXT1, 4, 8, IMMED);
	MOVE(p, AB2, 0, CONTEXT2, 8, 8, IMMED);
	MOVE(p, AB2, 0, OFIFO, 0, 5128, IMMED);
	MOVE(p, AB2, 0, DESCBUF, 16, 8, IMMED);
	MOVE(p, AB2, 0, MATH0, 4, 8, IMMED);
	MOVE(p, AB2, 0, MATH1, 8, 6, IMMED);
	MOVE(p, AB2, 0, MATH2, 12, 8, IMMED);
	MOVE(p, AB2, 0, MATH3, 16, 8, IMMED);
	MOVE(p, AB2, 0, KEY1, 4, 8, IMMED);
	MOVE(p, AB2, 0, KEY2, 8, 8, IMMED);

	MOVE(p, CONTEXT1, 13, CONTEXT1, 0, MATH0, WAITCOMP);
	MOVE(p, CONTEXT1, 9, CONTEXT1, 0, MATH1, 0);
	MOVE(p, CONTEXT1, 47, CONTEXT1, 0, MATH2, 0);

	MOVE(p, AB2, 0, OFIFO, 0, MATH3, 0);

	return PROGRAM_FINALIZE(p);
}

int main(int argc, char **argv)
{
	int size;

	pr_debug("MOVE program\n");
	rta_set_sec_era(RTA_SEC_ERA_4);
	size = test_move_op(prg_buff);
	pr_debug("size = %d\n", size);
	print_prog(prg_buff, size);

	return 0;
}
