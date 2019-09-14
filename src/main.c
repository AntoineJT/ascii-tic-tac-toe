/*
    Name : main.c
    Author : Antoine James Tournepiche
    Creation Date : October 21st 2018
    Last update : September 14th 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

    Main file of the ASCII TicTacToe
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef enum {
    PLAYER_CROSS = 0,
    PLAYER_CIRCLE = 1,
    PLAYER_NULL,      // Used to indicates when no one get a frame or when it has no winner for now
    PLAYER_UNDEFINED  // Used to indicates when it has equality
} player;

player plycells[9];
char grid[9];

static player getWinner(void){
    if (plycells[4] != PLAYER_NULL && (
        (plycells[3] == plycells[4] && plycells[4] == plycells[5])      // HLine 2
        || (plycells[1] == plycells[4] && plycells[4] == plycells[7])   // VLine 2
        || (plycells[0] == plycells[4] && plycells[4] == plycells[8])   // DLine '\'
        || (plycells[2] == plycells[4] && plycells[4] == plycells[6])   // DLine /
    )){
        return plycells[4];
    } else
    if (plycells[0] != PLAYER_NULL && (
        (plycells[0] == plycells[1] && plycells[1] == plycells[2])      // HLine 1
        || (plycells[0] == plycells[3] && plycells[3] == plycells[6])   // VLine 1
    ))
    {
        return plycells[0];
    } else
    if (plycells[8] != PLAYER_NULL && (
        (plycells[6] == plycells[7] && plycells[7] == plycells[8]) // HLine 3
        || (plycells[2] == plycells[5] && plycells[5] == plycells[8]) // VLine 3
    )){
        return plycells[8];
    } else {
        for (register unsigned int i = 0; i < 9; i++){
            if (plycells[i] == PLAYER_NULL){
                return PLAYER_NULL; // No winner for now
            }
        }
        return PLAYER_UNDEFINED; // Equality
    }
}

static char* getPlayerName(const player pl){
    switch(pl){
        case PLAYER_CROSS: return "Cross";
        case PLAYER_CIRCLE: return "Circle";
        default: return "ERROR";
    }
}

static bool playCell(const unsigned int cell, const player pl){
    if(plycells[cell] != PLAYER_NULL){
        return false;
    }
    plycells[cell] = pl;
    return true;
}

static void printGrid(void){
    for(unsigned int i = 0; i < 9; i++){
        switch(plycells[i]){
            case PLAYER_NULL:   grid[i] = ' '; break;
            case PLAYER_CROSS:  grid[i] = 'X'; break;
            case PLAYER_CIRCLE: grid[i] = 'O'; break;
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
                grid[0], grid[1], grid[2],
                grid[3], grid[4], grid[5],
                grid[6], grid[7], grid[8]);
}

static void input_cell(const player pl, unsigned int *cell){
    bool valid;
    do {
        fputs("Select the cell you want to play : ", stdout);
        valid = scanf("%u", cell) && *cell < 10; // if the input is invalid or out of range, it will ask again to user
        if(!valid){
            while(getchar() != '\n');
            puts("Invalid cell number!");
        } else {
            valid = playCell(*cell, pl);
            if(!valid){
                puts("This Cell is already owned!");
            }
        }
    } while(!valid);
}

static bool input_bool(const char *str){
    bool valid;
    char choice;
    do {
        printf("%s [Y/N]\n", str);
        while(getchar() != '\n');
        valid = scanf("%[YyNn]", &choice);
        if(!valid){
            puts("Invalid choice!");
        }
    } while(!valid);
    return (choice == 'Y' || choice == 'y');
}

static inline void init(void){
    for (int i = 0; i < 9; i++){
        plycells[i] = PLAYER_NULL;
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
#define LAST_UPDATE "09/14/2019 15:45"
int main(void)
{
    CMD_TITLE("ASCII Tic Tac Toe - made by Antoine James Tournepiche")
    puts("ASCII Tic Tac Toe" "\n"
         "made by Antoine James Tournepiche" "\n"
         "10/21/2018 - " LAST_UPDATE "\n");
    init();
    player pl = PLAYER_CROSS; // First player to play
    unsigned int i = PLAYER_NULL; // Winner, or Cell number (2 usages)
    while(1){ // main loop
        printGrid();
        if (i == PLAYER_NULL){
            printf("It's the turn of the %s player.\n", getPlayerName(pl));
            input_cell(pl, &i);
            i = getWinner();
        } else {
            if (i == PLAYER_UNDEFINED){
                puts("Equality !");
            } else {
                pl = !pl; // Here is a fix to print the correct winner : here we don't want to print the next player to play, but the last player which has played : the winner
                printf("The player %s has WIN!\n", getPlayerName(pl));
            }
            // reset code
            if(input_bool("Do you want to restart a game ?")){
                init();
            } else {
                exit(EXIT_SUCCESS);
            }
            i = PLAYER_NULL;
        }
        pl = !pl; // Switch from CIRCLE to CROSS, or from CROSS to CIRCLE
    }
    return EXIT_SUCCESS;
}
