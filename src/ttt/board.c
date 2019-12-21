/*
    Name : ttt/board.c
    Author : Antoine James Tournepiche
    Creation Date : December 20th 2019
    Last update : December 21st 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe
    
    TicTacToe board source file
*/

#include <stdlib.h>
#include "board.h"
#include "../boolean.h"

ttt_board* ttt_create_board(void)
{
    ttt_board* board_ptr = malloc(sizeof(ttt_board));
    if (board_ptr == NULL)
    {
        return NULL;
    }
    return board_ptr;
}

void ttt_destroy_board(ttt_board* board)
{
    free(board);
}
