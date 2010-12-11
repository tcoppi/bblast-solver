#ifndef BBLAST_H_
#define BBLAST_H_

#include <stdint.h>

/* In the Bubble Blast 2 game the board is 4x6, but it can really be any size. */
#define BBSIZE_X 4
#define BBSIZE_Y 6

/**
 * A square has a integer life value, with 0 meaning it is "dead".
 * It is a struct because this may need to be expanded later.
 */
struct _bblast_square {
	uint32_t life;
};

typedef struct _bblast_square bblast_square;

/**
 * Moves in bubble blast are called "touches", defined by an x,y coordinate
 * that reduces the corresponding square's life by one.
 */

struct _bblast_touch {
	uint32_t x;
	uint32_t y;
};

typedef struct _bblast_touch bblast_touch;

/**
 * The goal of a game of bubble blast is to make all squares have 0 life.
 * Returns an array of touches that will solve the board.
 */
bblast_touch *bblast_solve(bblast_square **board, uint64_t max_touches);

#endif
