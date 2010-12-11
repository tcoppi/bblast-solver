#include <stdio.h>
#include <stdlib.h>

#include "bblast.h"

int main(void) {

	bblast_square board[BBSIZE_X][BBSIZE_Y];
	bblast_touch *touches;

	//populate board


	//solve the board
	touches = bblast_solve(board, 5);

	if(touches) {
		printf("Board is solveable!\n");
		return 0;
	}

	printf("Board isn't solvable with given parameters.\n");

	return -1;
}
