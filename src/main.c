/*
    Name : main.c
    Author : Antoine James Tournepiche
    Creation Date : October 21st 2018
    Last update : December 20th 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

    Main file of the ASCII TicTacToe
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define LAST_UPDATE "December 20th 2019"

typedef enum {
    PLAYER_CROSS,
    PLAYER_CIRCLE,
    PLAYER_NULL,      // Used to indicates when no one get a frame or when it has no winner for now
    PLAYER_UNDEFINED  // Used to indicates when it has equality
} player;

typedef unsigned int uint;

typedef struct ttt_board {
    player cell_owner[9];
    char grid[9];
} ttt_board;

static bool int_3_equals(const int a, const int b, const int c) {
    return (a == b) && (b == c);
}

static bool is_cell_line_claimed_by_one_player(ttt_board board, const player a, const player b, const player c) {
    return int_3_equals(board.cell_owner[a], board.cell_owner[b], board.cell_owner[c]);
}

static player get_winner(const ttt_board board){
    if (board.cell_owner[4] != PLAYER_NULL && (
        (is_cell_line_claimed_by_one_player(board, 3, 4, 5))      // HLine 2
        || (is_cell_line_claimed_by_one_player(board, 1, 4, 7))   // VLine 2
        || (is_cell_line_claimed_by_one_player(board, 0, 4, 8))   // DLine '\'
        || (is_cell_line_claimed_by_one_player(board, 2, 4, 6))   // DLine /
    )){
        return board.cell_owner[4];
    } else
    if (board.cell_owner[0] != PLAYER_NULL && (
        (is_cell_line_claimed_by_one_player(board, 0, 1, 2))      // HLine 1
        || (is_cell_line_claimed_by_one_player(board, 0, 3, 6))   // VLine 1
    ))
    {
        return board.cell_owner[0];
    } else
    if (board.cell_owner[8] != PLAYER_NULL && (
        (is_cell_line_claimed_by_one_player(board, 6, 7, 8)) // HLine 3
        || (is_cell_line_claimed_by_one_player(board, 2, 5, 8)) // VLine 3
    )){
        return board.cell_owner[8];
    } else {
        for (uint i = 0; i < 9; i++){
            if (board.cell_owner[i] == PLAYER_NULL){
                return PLAYER_NULL; // No winner for now
            }
        }
        return PLAYER_UNDEFINED; // Equality
    }
}

static char* get_player_name(const player pl){
    switch(pl){
        case PLAYER_CROSS: return "Cross";
        case PLAYER_CIRCLE: return "Circle";
        default: return "ERROR";
    }
}

static bool play_cell(ttt_board *board, const uint cell, const player pl){
    if((*board).cell_owner[cell] != PLAYER_NULL){
        return false;
    }
    (*board).cell_owner[cell] = pl;
    return true;
}

static void print_grid(ttt_board *board){
    for(uint i = 0; i < 9; i++){
        switch((*board).cell_owner[i]){
            case PLAYER_NULL:   (*board).grid[i] = ' '; break;
            case PLAYER_CROSS:  (*board).grid[i] = 'X'; break;
            case PLAYER_CIRCLE: (*board).grid[i] = 'O'; break;
            default: return;
        }
    }
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

#define FLUSH_BUFFER while(getchar() != '\n');

static void input_cell(const ttt_board *board, const player pl, unsigned int *cell){
    bool valid;
    do {
        fputs("Select the cell you want to play : ", stdout);
        valid = scanf("%u", cell) && *cell < 10; // if the input is invalid or out of range, it will ask again to user
        if(!valid){
            FLUSH_BUFFER
            puts("Invalid cell number!");
        } else {
            valid = play_cell(board, *cell, pl);
            if(!valid){
                puts("This Cell is already owned!");
            }
        }
    } while(!valid);
}

// Stack is corrupted here : need to check!
static bool input_bool(const char *str){
    bool valid;
    char choice;
    do {
        printf("%s [Y/N]\n", str);
        FLUSH_BUFFER
        valid = scanf("%[YyNn]", &choice);
        if(!valid){
            puts("Invalid choice!");
        }
    } while(!valid);
    return (choice == 'Y' || choice == 'y');
}

static void initialize_cells(ttt_board *board){
    for (int i = 0; i < 9; i++){
        (*board).cell_owner[i] = PLAYER_NULL;
    }
}

static player ttt_get_opponent(const player pl) {
    switch (pl) {
        case PLAYER_CIRCLE: return PLAYER_CROSS;
        case PLAYER_CROSS: return PLAYER_CIRCLE;
        case PLAYER_NULL:
        case PLAYER_UNDEFINED:
        default:
            return PLAYER_NULL;
    }
}

#ifdef _WIN32
    #include <windows.h>
    #define CMD_TITLE(_TXT_) SetConsoleTitleA(_TXT_);
#elif defined(unix)
    #define CMD_TITLE(_TXT_) printf("%c]0;%s\a", '\033', _TXT_);
#else
    #define CMD_TITLE(_TXT_) // For other platforms than unix and windows
#endif

static ttt_board *create_ttt_board(void) {
    ttt_board* board_ptr = malloc(sizeof(ttt_board));
    if (board_ptr == NULL) {
        return NULL;
    }
    return board_ptr;
}

int main(void)
{
    CMD_TITLE("ASCII Tic Tac Toe - made by Antoine James Tournepiche")
    puts("ASCII Tic Tac Toe" "\n"
         "made by Antoine James Tournepiche" "\n"
         "October 21st 2018 - " LAST_UPDATE "\n");

    ttt_board *board = create_ttt_board();

    initialize_cells(board);

    player pl = PLAYER_CROSS; // First player to play
    player winner = PLAYER_NULL;
    uint cell_number = -1;

    while(1){ // main loop
        print_grid(board);

        if (winner == PLAYER_NULL){
            printf("It's the turn of the %s player.\n", get_player_name(pl));
            input_cell(board, pl, &cell_number);
            winner = get_winner(*board);
        } else {
            if (winner == PLAYER_UNDEFINED){
                puts("Equality !");
            } else {
                pl = ttt_get_opponent(pl); // Here is a fix to print the correct winner : here we don't want to print the next player to play, but the last player which has played : the winner
                printf("The player %s has WIN!\n", get_player_name(pl));
            }

            // reset code
            if(input_bool("Do you want to restart a game ?")){
                initialize_cells(board);
                winner = PLAYER_NULL;
                cell_number = -1;
            } else {
                exit(EXIT_SUCCESS);
            }
        }
        pl = ttt_get_opponent(pl);
    }
    return EXIT_SUCCESS;
}
