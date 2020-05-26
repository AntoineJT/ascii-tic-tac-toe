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
     Name : game/ttt_grid.c
     Author : Antoine James Tournepiche
     Creation Date : December 25th 2019
     Last update : December 27th 2019
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     TicTacToe grid source code file
 */

#include <stdio.h>
#include "ttt_board.h"

void ttt_refresh_grid(ttt_board* board)
{
    for (int i = 0; i < 9; i++)
    {
        switch (board->cell_owner[i])
        {
        case PLAYER_NULL: board->grid[i] = ' ';
            break;
        case PLAYER_CROSS: board->grid[i] = 'X';
            break;
        case PLAYER_CIRCLE: board->grid[i] = 'O';
            break;
        default: return;
        }
    }
}

static void only_print_grid(const ttt_board board)
{
    printf(" _________________ " "\n"
        "|**0**|**1**|**2**|" "\n"
        "|  %c  |  %c  |  %c  |" "\n"
        "|_____|_____|_____|" "\n"
        "|**3**|**4**|**5**|" "\n"
        "|  %c  |  %c  |  %c  |" "\n"
        "|_____|_____|_____|" "\n"
        "|**6**|**7**|**8**|" "\n"
        "|  %c  |  %c  |  %c  |" "\n"
        "|_____|_____|_____|" "\n",
        board.grid[0], board.grid[1], board.grid[2],
        board.grid[3], board.grid[4], board.grid[5],
        board.grid[6], board.grid[7], board.grid[8]);
}

void ttt_print_grid(ttt_board* board)
{
    ttt_refresh_grid(board);
    only_print_grid(*board);
}
