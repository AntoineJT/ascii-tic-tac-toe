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
     Name : game/ttt_game.h
     Author : Antoine James Tournepiche
     Creation Date : December 24th 2019
     Last update : December 24th 2019
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     TicTacToe game logic source code file
 */

#include "../boolean.h"
#include "../equals.h"
#include "ttt_board.h"
#include "ttt_player.h"

bool ttt_is_cell_line_claimed_by_one_player(ttt_board board, const ttt_player a, const ttt_player b, const ttt_player c)
{
    return int_3_equals(board.cell_owner[a], board.cell_owner[b], board.cell_owner[c]);
}

bool ttt_play_cell(ttt_board* board, const unsigned int cell, const ttt_player player)
{
    if ((*board).cell_owner[cell] != PLAYER_NULL)
    {
        return false;
    }
    (*board).cell_owner[cell] = player;
    return true;
}

ttt_player ttt_get_winner(const ttt_board board)
{
    if (board.cell_owner[4] != PLAYER_NULL && (
        (ttt_is_cell_line_claimed_by_one_player(board, 3, 4, 5)) // HLine 2
        || (ttt_is_cell_line_claimed_by_one_player(board, 1, 4, 7)) // VLine 2
        || (ttt_is_cell_line_claimed_by_one_player(board, 0, 4, 8)) // DLine '\'
        || (ttt_is_cell_line_claimed_by_one_player(board, 2, 4, 6)) // DLine /
        ))
    {
        return board.cell_owner[4];
    }
    else if (board.cell_owner[0] != PLAYER_NULL && (
        (ttt_is_cell_line_claimed_by_one_player(board, 0, 1, 2)) // HLine 1
        || (ttt_is_cell_line_claimed_by_one_player(board, 0, 3, 6)) // VLine 1
        ))
    {
        return board.cell_owner[0];
    }
    else if (board.cell_owner[8] != PLAYER_NULL && (
        (ttt_is_cell_line_claimed_by_one_player(board, 6, 7, 8)) // HLine 3
        || (ttt_is_cell_line_claimed_by_one_player(board, 2, 5, 8)) // VLine 3
        ))
    {
        return board.cell_owner[8];
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (board.cell_owner[i] == PLAYER_NULL)
            {
                return PLAYER_NULL; // No winner for now
            }
        }
        return PLAYER_UNDEFINED; // Equality
    }
}
