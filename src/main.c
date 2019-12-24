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
    Last update : December 24th 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe
  
    Main file of the ASCII TicTacToe
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "equals.h"
#include "buffer.h"
#include "cmd_title.h"
#include "ttt_game/board.h"
#include "ttt_game/player.h"
#include "ttt_game/input.h"
#include "ttt_game/game.h"

#define LAST_UPDATE "December 24th 2019"

static void ttt_refresh_grid(ttt_board* board)
{
    for (int i = 0; i < 9; i++)
    {
        switch ((*board).cell_owner[i])
        {
        case PLAYER_NULL: (*board).grid[i] = ' ';
            break;
        case PLAYER_CROSS: (*board).grid[i] = 'X';
            break;
        case PLAYER_CIRCLE: (*board).grid[i] = 'O';
            break;
        default: return;
        }
    }
}

static void ttt_print_grid(ttt_board* board)
{
    ttt_refresh_grid(board);
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
           (*board).grid[0], (*board).grid[1], (*board).grid[2],
           (*board).grid[3], (*board).grid[4], (*board).grid[5],
           (*board).grid[6], (*board).grid[7], (*board).grid[8]);
}

// Stack is corrupted here : need to check!
static bool input_bool(const char* str)
{
    bool valid;
    char choice;
    do
    {
        printf("%s [Y/N]\n", str);
        flush_buffer();
        valid = scanf("%[YyNn]", &choice);
        if (!valid)
        {
            puts("Invalid choice!");
        }
    }
    while (!valid);
    return (choice == 'Y' || choice == 'y');
}

int main(void)
{
    CMD_TITLE("ASCII Tic Tac Toe - made by Antoine James Tournepiche")
    puts("ASCII Tic Tac Toe" "\n"
        "made by Antoine James Tournepiche" "\n"
        "October 21st 2018 - " LAST_UPDATE "\n");

    ttt_board* board = ttt_create_board();

    ttt_initialize_cells(board);

    ttt_player player = PLAYER_CROSS; // First player to play
    ttt_player winner = PLAYER_NULL;
    unsigned int cell_number;

    while (1)
    {
        // main loop
        ttt_print_grid(board);

        if (winner == PLAYER_NULL)
        {
            printf("It's the turn of the %s player.\n", ttt_get_player_name(player));
            ttt_input_cell(board, player, &cell_number);
            winner = ttt_get_winner(*board);
        }
        else
        {
            if (winner == PLAYER_UNDEFINED)
            {
                puts("Equality !");
            }
            else
            {
                player = ttt_get_opponent(player);
                // Here is a fix to print the correct winner : here we don't want to print the next player to play, but the last player which has played : the winner
                printf("The player %s has WIN!\n", ttt_get_player_name(player));
            }

            // reset code
            if (input_bool("Do you want to restart a game ?"))
            {
                ttt_initialize_cells(board);
                winner = PLAYER_NULL;
                cell_number = -1;
            }
            else
            {
                return EXIT_SUCCESS;
            }
        }
        player = ttt_get_opponent(player);
    }
}
