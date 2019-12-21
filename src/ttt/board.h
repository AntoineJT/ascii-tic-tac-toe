/*
	Name : ttt/board.h
	Author : Antoine James Tournepiche
	Creation Date : December 20th 2019
	Last update : December 21st 2019
	Project : ASCII Tic Tac Toe
	Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

	TicTacToe board header
*/

#ifndef _H_TTT_BOARD_
	#define _H_TTT_BOARD_
	#include "player.h"

	typedef struct ttt_board {
		player cell_owner[9];
		char grid[9];
	} ttt_board;

	ttt_board* ttt_create_board(void);
	void ttt_destroy_board(ttt_board* board);
#endif
