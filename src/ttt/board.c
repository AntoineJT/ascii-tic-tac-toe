/*
	Name : ttt/board.c
	Author : Antoine James Tournepiche
	Creation Date : December 20th 2019
	Last update : December 20th 2019
	Project : ASCII Tic Tac Toe
	Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

	TicTacToe board source file
*/

#include <stdlib.h>
#include "board.h"

ttt_board* create_ttt_board(void) {
	ttt_board* board_ptr = malloc(sizeof(ttt_board));
	if (board_ptr == NULL) {
		return NULL;
	}
	return board_ptr;
}
