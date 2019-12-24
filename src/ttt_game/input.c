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
     Name : ttt_game/input.c
     Author : Antoine James Tournepiche
     Creation Date : December 24th 2019
     Last update : December 24th 2019
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     TicTacToe input source code file
 */

#include <stdio.h>
#include "../boolean.h"
#include "../buffer.h"
#include "board.h"
#include "player.h"
#include "game.h"

void ttt_input_cell(ttt_board* board, const ttt_player player, unsigned int* cell)
{
    bool valid;
    do
    {
        fputs("Select the cell you want to play : ", stdout);
        valid = scanf("%u", cell) && *cell < 10; // if the input is invalid or out of range, it will ask again to user
        if (!valid)
        {
            flush_buffer();
            puts("Invalid cell number!");
        }
        else
        {
            valid = ttt_play_cell(board, *cell, player);
            if (!valid)
            {
                puts("This Cell is already owned!");
            }
        }
    } while (!valid);
}
