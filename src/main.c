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
    Name : main.c
    Author : Antoine James Tournepiche
    Creation Date : October 21st 2018
    Last update : January 25th 2020
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe
    
    Main file of the ASCII TicTacToe
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cmd_title.h"
#include "input.h"
#include "game/ttt_input.h"
#include "game/ttt_game.h"
#include "game/ttt_grid.h"

#define LAST_UPDATE "January 25th 2020"

static bool is_game_draw(const ttt_player winner)
{
    return winner == PLAYER_UNDEFINED;
}

static bool has_no_winner_yet(const ttt_player winner)
{
    return winner == PLAYER_NULL;
}

// this is called restart_game and not reset_game because it does not reset the first player to play
static void restart_game(ttt_board* board, ttt_player* winner, unsigned int* cell_number)
{
    ttt_reset_cells(board);
    *winner = PLAYER_NULL;
    *cell_number = -1;
}

int main(void)
{
    CMD_TITLE("ASCII Tic Tac Toe - made by Antoine James Tournepiche")
    puts("ASCII Tic Tac Toe" "\n"
        "made by Antoine James Tournepiche" "\n"
        "October 21st 2018 - " LAST_UPDATE "\n");

    ttt_board* board = ttt_create_board();
    ttt_player player = PLAYER_CROSS; // First player to play
    ttt_player winner = PLAYER_NULL;
    unsigned int cell_number;

    while (1)
    {
        ttt_print_grid(board);

        if (has_no_winner_yet(winner))
        {
            printf("It's the turn of the %s player.\n", ttt_get_player_name(player));
            ttt_input_and_play_cell(board, player);
            winner = ttt_get_winner(*board);
        }
        else
        {
            if (is_game_draw(winner))
            {
                puts("Equality !");
            }
            else
            {
                printf("The player %s has WIN!\n", ttt_get_player_name(winner));
            }

            if (input_bool("Do you want to restart a game ?"))
            {
                restart_game(board, &winner, &cell_number);
            }
            else
            {
                return EXIT_SUCCESS;
            }
        }
        player = ttt_get_opponent(player);
    }
}
