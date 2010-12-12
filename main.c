#include <stdio.h>
#include <stdlib.h>

#include "bblast.h"
#include "mtwist.h"

mt_state s;

void reset_board(bblast_square *board[BBSIZE_X][BBSIZE_Y]) {
	//populate board

	/* 2-1
	board[0][0]->life = 3;
	board[0][1]->life = 0;
	board[0][2]->life = 1;
	board[0][3]->life = 4;
	board[0][4]->life = 2;
	board[0][5]->life = 2;

	board[1][0]->life = 3;
	board[1][1]->life = 3;
	board[1][2]->life = 4;
	board[1][3]->life = 2;
	board[1][4]->life = 2;
	board[1][5]->life = 2;

	board[2][0]->life = 2;
	board[2][1]->life = 0;
	board[2][2]->life = 1;
	board[2][3]->life = 2;
	board[2][4]->life = 1;
	board[2][5]->life = 3;

	board[3][0]->life = 0;
	board[3][1]->life = 2;
	board[3][2]->life = 2;
	board[3][3]->life = 1;
	board[3][4]->life = 1;
	board[3][5]->life = 0;

	board[4][0]->life = 3;
	board[4][1]->life = 3;
	board[4][2]->life = 1;
	board[4][3]->life = 2;
	board[4][4]->life = 3;
	board[4][5]->life = 2;
	*/

	/* 2-2
	board[0][0]->life = 4;
	board[0][1]->life = 0;
	board[0][2]->life = 0;
	board[0][3]->life = 4;
	board[0][4]->life = 3;
	board[0][5]->life = 2;

	board[1][0]->life = 3;
	board[1][1]->life = 4;
	board[1][2]->life = 1;
	board[1][3]->life = 0;
	board[1][4]->life = 2;
	board[1][5]->life = 4;

	board[2][0]->life = 1;
	board[2][1]->life = 2;
	board[2][2]->life = 0;
	board[2][3]->life = 1;
	board[2][4]->life = 3;
	board[2][5]->life = 4;

	board[3][0]->life = 4;
	board[3][1]->life = 1;
	board[3][2]->life = 1;
	board[3][3]->life = 1;
	board[3][4]->life = 2;
	board[3][5]->life = 0;

	board[4][0]->life = 2;
	board[4][1]->life = 2;
	board[4][2]->life = 3;
	board[4][3]->life = 1;
	board[4][4]->life = 1;
	board[4][5]->life = 3;
	*/

	/* 2-3
	board[0][0]->life = 1;
	board[0][1]->life = 4;
	board[0][2]->life = 1;
	board[0][3]->life = 1;
	board[0][4]->life = 3;
	board[0][5]->life = 2;

	board[1][0]->life = 4;
	board[1][1]->life = 1;
	board[1][2]->life = 4;
	board[1][3]->life = 1;
	board[1][4]->life = 0;
	board[1][5]->life = 4;

	board[2][0]->life = 1;
	board[2][1]->life = 0;
	board[2][2]->life = 2;
	board[2][3]->life = 2;
	board[2][4]->life = 3;
	board[2][5]->life = 1;

	board[3][0]->life = 3;
	board[3][1]->life = 0;
	board[3][2]->life = 0;
	board[3][3]->life = 2;
	board[3][4]->life = 4;
	board[3][5]->life = 0;

	board[4][0]->life = 2;
	board[4][1]->life = 4;
	board[4][2]->life = 1;
	board[4][3]->life = 4;
	board[4][4]->life = 4;
	board[4][5]->life = 1;
	*/

	/* 2-4
	board[0][0]->life = 0;
	board[0][1]->life = 4;
	board[0][2]->life = 2;
	board[0][3]->life = 4;
	board[0][4]->life = 3;
	board[0][5]->life = 2;

	board[1][0]->life = 0;
	board[1][1]->life = 1;
	board[1][2]->life = 2;
	board[1][3]->life = 1;
	board[1][4]->life = 1;
	board[1][5]->life = 1;

	board[2][0]->life = 2;
	board[2][1]->life = 4;
	board[2][2]->life = 3;
	board[2][3]->life = 1;
	board[2][4]->life = 4;
	board[2][5]->life = 4;

	board[3][0]->life = 4;
	board[3][1]->life = 1;
	board[3][2]->life = 2;
	board[3][3]->life = 0;
	board[3][4]->life = 3;
	board[3][5]->life = 2;

	board[4][0]->life = 4;
	board[4][1]->life = 3;
	board[4][2]->life = 0;
	board[4][3]->life = 3;
	board[4][4]->life = 3;
	board[4][5]->life = 0;
	*/

	/* 2-14
	board[0][0]->life = 0;
	board[0][1]->life = 1;
	board[0][2]->life = 0;
	board[0][3]->life = 4;
	board[0][4]->life = 1;
	board[0][5]->life = 1;

	board[1][0]->life = 0;
	board[1][1]->life = 1;
	board[1][2]->life = 2;
	board[1][3]->life = 2;
	board[1][4]->life = 2;
	board[1][5]->life = 0;

	board[2][0]->life = 1;
	board[2][1]->life = 3;
	board[2][2]->life = 3;
	board[2][3]->life = 1;
	board[2][4]->life = 4;
	board[2][5]->life = 1;

	board[3][0]->life = 3;
	board[3][1]->life = 0;
	board[3][2]->life = 4;
	board[3][3]->life = 4;
	board[3][4]->life = 2;
	board[3][5]->life = 3;

	board[4][0]->life = 3;
	board[4][1]->life = 1;
	board[4][2]->life = 1;
	board[4][3]->life = 3;
	board[4][4]->life = 2;
	board[4][5]->life = 0;
	*/

	/* 2-16 */
	board[0][0]->life = 1;
	board[0][1]->life = 3;
	board[0][2]->life = 1;
	board[0][3]->life = 4;
	board[0][4]->life = 2;
	board[0][5]->life = 4;

	board[1][0]->life = 3;
	board[1][1]->life = 0;
	board[1][2]->life = 2;
	board[1][3]->life = 1;
	board[1][4]->life = 1;
	board[1][5]->life = 4;

	board[2][0]->life = 2;
	board[2][1]->life = 3;
	board[2][2]->life = 0;
	board[2][3]->life = 1;
	board[2][4]->life = 2;
	board[2][5]->life = 1;

	board[3][0]->life = 4;
	board[3][1]->life = 3;
	board[3][2]->life = 2;
	board[3][3]->life = 0;
	board[3][4]->life = 0;
	board[3][5]->life = 3;

	board[4][0]->life = 1;
	board[4][1]->life = 4;
	board[4][2]->life = 3;
	board[4][3]->life = 4;
	board[4][4]->life = 2;
	board[4][5]->life = 0;
}

int main(void) {

	bblast_square *board[BBSIZE_X][BBSIZE_Y];
	bblast_touch *touches;
	uint32_t i,j;

	mts_seed(&s);

	for(i=0;i<BBSIZE_X;i++) {
		for(j=0;j<BBSIZE_Y;j++) {
			board[i][j] = malloc(sizeof(bblast_square));
		}
	}

/*
	board = malloc(sizeof(bblast_square) * BBSIZE_X+1);

	for(i=0;i<BBSIZE_X;i++) {
		board[i] = malloc(sizeof(bblast_square) * BBSIZE_Y+1);
	}
*/

	reset_board(board);

	print_board(board);

	//solve the board
	touches = bblast_solve(board, 4);

	if(touches) {
		printf("Board is solveable!\n");

		print_board(board);

		printf("x: %d y: %d\n", touches[0].x, touches[0].y);
		printf("x: %d y: %d\n", touches[1].x, touches[1].y);
		printf("x: %d y: %d\n", touches[2].x, touches[2].y);
		printf("x: %d y: %d\n", touches[3].x, touches[3].y);

		return 0;
	}


	printf("Board isn't solvable with given parameters.\n");

	return -1;
}
