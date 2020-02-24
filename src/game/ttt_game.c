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
     Last update : January 25th 2020
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     TicTacToe game logic source code file
 */

#include <assert.h>
#include <stdbool.h>
#include "../equals.h"
#include "ttt_board.h"
#include "ttt_player.h"

static bool are_cells_claimed_by_same_player(ttt_board board, const unsigned int a, const unsigned int b, const unsigned int c)
{
    assert(a > 0 && a < 10);
    assert(b > 0 && b < 10);
    assert(c > 0 && c < 10);
    return int_3_equals(board.cell_owner[a - 1], board.cell_owner[b - 1], board.cell_owner[c - 1]);
}

static bool is_cell_owned(const ttt_board board, const unsigned int cell_number)
{
    assert(cell_number < 9);
    return board.cell_owner[cell_number] != PLAYER_NULL;
}

static void set_cell_owner(ttt_board* board, const ttt_player player, const unsigned int cell_number)
{
    assert(cell_number < 9);
    (*board).cell_owner[cell_number] = player;
}

bool ttt_play_cell(ttt_board* board, const unsigned int cell_number, const ttt_player player)
{
    assert(cell_number < 9);
    if (is_cell_owned(*board, cell_number))
    {
        return false;
    }
    set_cell_owner(board, player, cell_number);
    return true;
}

/*
 *  hline -> horizontal line
 *  vline -> vertical line
 *  dline -> diagonal line
 *  lr -> left to right, from top to bottom
 *  rl -> right to left, from top to bottom
 */
static bool is_left_hline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 1, 2, 3);
}

static bool is_middle_hline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 4, 5, 6);
}

static bool is_right_hline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 7, 8, 9);
}

static bool is_left_vline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 1, 4, 7);
}

static bool is_middle_vline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 2, 5, 8);
}

static bool is_right_vline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 3, 6, 9);
}

static bool is_lr_dline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 1, 5, 9);
}

static bool is_rl_dline_claimed_by_one_player(const ttt_board board)
{
    return are_cells_claimed_by_same_player(board, 3, 5, 7);
}

ttt_player ttt_get_winner(const ttt_board board)
{
    if (board.cell_owner[4] != PLAYER_NULL && (
        is_middle_hline_claimed_by_one_player(board) // HLine 2
        || is_middle_vline_claimed_by_one_player(board) // VLine 2
        || is_lr_dline_claimed_by_one_player(board) // DLine '\'
        || is_rl_dline_claimed_by_one_player(board) // DLine '/'
        ))
    {
        return board.cell_owner[4];
    }
    if (board.cell_owner[0] != PLAYER_NULL && (
        is_left_hline_claimed_by_one_player(board) // HLine 1
        || is_left_vline_claimed_by_one_player(board) // VLine 1
    ))
    {
        return board.cell_owner[0];
    }
    if (board.cell_owner[8] != PLAYER_NULL && (
        is_right_hline_claimed_by_one_player(board) // HLine 3
        || is_right_vline_claimed_by_one_player(board) // VLine 3
    ))
    {
        return board.cell_owner[8];
    }

    for (int cell_number = 0; cell_number < 9; cell_number++)
    {
        if (!is_cell_owned(board, cell_number))
        {
            return PLAYER_NULL; // No winner for now
        }
    }
    return PLAYER_UNDEFINED; // Equality
}
