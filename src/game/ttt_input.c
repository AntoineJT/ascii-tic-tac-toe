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
     Name : game/ttt_input.c
     Author : Antoine James Tournepiche
     Creation Date : December 24th 2019
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     TicTacToe input source code file
 */

#include <stdio.h>
#include <stdbool.h>
#include "ttt_board.h"
#include "ttt_player.h"
#include "ttt_game.h"
#include "../input.h"

void ttt_input_and_play_cell(ttt_board* board, const ttt_player player)
{
    bool is_not_playable;

    do
    {
        const unsigned int cell_number = input_digit("Select the cell you want to play : ", "Invalid cell number!");
        is_not_playable = !ttt_play_cell(board, cell_number, player);
        if (is_not_playable)
        {
            puts("This Cell is already owned!");
        }
    } while (is_not_playable);
}
