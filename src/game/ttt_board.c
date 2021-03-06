/*
 *  MIT License
 *
 *  Copyright (c) 2018 Antoine James Tournepiche
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/*
    Name : game/ttt_board.c
    Author : Antoine James Tournepiche
    Creation Date : December 20th 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe
    
    TicTacToe board source file
*/

#include <stdlib.h>
#include "ttt_board.h"

ttt_board* ttt_create_board(void)
{
    ttt_board* board_ptr = malloc(sizeof(ttt_board));
    if (board_ptr == NULL)
    {
        return NULL;
    }
    ttt_reset_cells(board_ptr);
    return board_ptr;
}

void ttt_reset_cells(ttt_board* board)
{
    for (int i = 0; i < 9; i++)
    {
        board->cell_owner[i] = PLAYER_NULL;
    }
}

void ttt_destroy_board(ttt_board* board)
{
    free(board);
}
