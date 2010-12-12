#include <stdio.h>
#include <stdlib.h>

#include "bblast.h"
#include "mtwist.h"

extern mt_state s;

void do_touch(bblast_square *board[BBSIZE_X][BBSIZE_Y], bblast_touch *touch);

bblast_touch *new_touch(uint32_t x, uint32_t y) {
	bblast_touch *ntouch = malloc(sizeof(bblast_touch));

	ntouch->x = x;
	ntouch->y = y;

	return ntouch;
}

/* helper for do_touch */
uint32_t check_and_do_touch(bblast_square *board[BBSIZE_X][BBSIZE_Y], uint32_t x, uint32_t y) {
	bblast_touch *ntouch = NULL;

	if(board[x][y]->life > 0) {
		ntouch = new_touch(x, y);

		do_touch(board, ntouch);

		free(ntouch);

		return 1;
	}

	return 0;
}

/**
 * Subtract the touched square's life by one. If it reaches zero, then
 * it "dies" and shoots out four touches in each direction(up, down,
 * left, right) that execute do_touch on the first nonzero life square
 * they run into.
 */
void do_touch(bblast_square *board[BBSIZE_X][BBSIZE_Y], bblast_touch *touch) {
	int i;

	if(board[touch->x][touch->y]->life == 0) {
		// this shouldn't ever happen
		fprintf(stderr, "ERROR\n");
		return;
		exit(-1);
	}

	// subtract and see if the square is dead
	if((--((board[touch->x][touch->y])->life)) == 0) {

//		printf("%d,%d is dead\n\n", touch->x, touch->y);

//		print_board(board);

		//XXX FIXME the way this works in a serial way may not be
		//correct. might need to use pthreads and parallelize it, or
		//use some method of simulating it

		//move bubble upwards
		for(i=(touch->y)-1;i>=0;i--) {
//			printf("checking %d, %d\n", touch->x, i);
			if(check_and_do_touch(board, touch->x, i))
				break;
		}

		//move bubble downwards
		for(i=(touch->y)+1;i<BBSIZE_Y;i++) {
//			printf("checking %d, %d\n", touch->x, i);
			if(check_and_do_touch(board, touch->x, i))
				break;
		}

		//move bubble to the right
		for(i=(touch->x)+1;i<BBSIZE_X;i++) {
//			printf("checking %d, %d\n", i, touch->y);
			if(check_and_do_touch(board, i, touch->y))
				break;
		}

		//move bubble to the left
		for(i=(touch->x)-1;i>=0;i--) {
//			printf("checking %d, %d\n", i, touch->y);
			if(check_and_do_touch(board, i, touch->y))
				break;
		}
	}

}

uint32_t check_if_dead(bblast_square *board[BBSIZE_X][BBSIZE_Y]) {
	uint32_t x, y;

	for(x=0;x<BBSIZE_X;x++) {
		for(y=0;y<BBSIZE_Y;y++) {
			if(board[x][y]->life != 0) {
				return 0;
			}
		}
	}

	return 1;
}

bblast_touch *select_touch() {
	uint32_t x = mts_lrand(&s) % (BBSIZE_X);
	uint32_t y = mts_lrand(&s) % (BBSIZE_Y);

	return new_touch(x, y);
}


/**
 * Tries random combinations of touches.
 */
bblast_touch *bblast_solve(bblast_square *board[BBSIZE_X][BBSIZE_Y], uint64_t max_touches) {
	bblast_touch *touches = malloc(sizeof(bblast_touch) * max_touches);
	uint32_t x, y;
	uint64_t i, tries;

	i = 0;

	while(1) {
		// select new touch and add it to list, then do it
		touches[i] = *select_touch();
	//	touches[i] = *new_touch(2,4);

		printf("trying %d,%d\n", touches[i].x, touches[i].y);

		do_touch(board, &touches[i]);

		// check if board is dead
		if(check_if_dead(board) == 1) {
			// correct solution

			printf("tries: %d\n", tries);

			return touches;
		}
		else if(++i >= max_touches) {
//			print_board(board);
			i = 0;
			reset_board(board);
			printf("reset\n");
		}

		tries++;
	}
	return NULL;
}

void print_board(bblast_square *board[BBSIZE_X][BBSIZE_Y]) {
	uint32_t i,j;

	for(i=0;i<BBSIZE_Y;i++) {
		for(j=0;j<BBSIZE_X;j++) {
			printf("%d ", board[j][i]->life);
		}

		puts("");
	}
}
