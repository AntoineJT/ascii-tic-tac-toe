/*
    main.c
    Unique file of the ASCII TicTacToe
    Written by Antoine James Tournepiche
    10/21/2018 - 11/03/2018 13:19
*/

#include <stdio.h>
#include <stdlib.h>

// Boolean
typedef unsigned char boolean;
#define BFALSE 0
#define BTRUE 1

typedef unsigned int player; // Possible micro-optimization : check if unsigned char is faster / as fast as unsigned int to reduce RAM consumption (not very useful because this is just a tic tac toe in ASCII and the optimization will not be visible at all)
#define PLAYER_NULL 2 // Used to indicates when no one get a frame or when it has no winner for now
#define PLAYER_CROSS 0
#define PLAYER_CIRCLE 1
#define PLAYER_UNDEFINED 3 // Used to indicates when it has equality

player plycells[9];

player getWinner(){
    if (plycells[4]!=PLAYER_NULL&&(
        (plycells[3]==plycells[4]&&plycells[4]==plycells[5])|| // HLine 2
        (plycells[1]==plycells[4]&&plycells[4]==plycells[7])|| // VLine 2
        (plycells[0]==plycells[4]&&plycells[4]==plycells[8])|| // DLine '\'
        (plycells[2]==plycells[4]&&plycells[4]==plycells[6]) // DLine /
    )){
        return plycells[4];
    } else if (plycells[0]!=PLAYER_NULL&&(
        (plycells[0]==plycells[1]&&plycells[1]==plycells[2])|| // HLine 1
        (plycells[0]==plycells[3]&&plycells[3]==plycells[6]) // VLine 1
    )){
        return plycells[0];
    } else if (plycells[8]!=PLAYER_NULL&&(
        (plycells[6]==plycells[7]&&plycells[7]==plycells[8])|| // HLine 3
        (plycells[2]==plycells[5]&&plycells[5]==plycells[8]) // VLine 3
    )){
        return plycells[8];
    } else {
        for (int i=0;i<9;i++)
            if (plycells[i]==PLAYER_NULL)
                return PLAYER_NULL; // No winner for now
        return PLAYER_UNDEFINED; // Equality
    }
}

char* getPlayerName(const player pl){
    if (pl==PLAYER_CROSS)
        return "Cross";
    else if (pl==PLAYER_CIRCLE)
        return "Circle";
    else
        return "ERROR";
}

boolean playCell(const unsigned int cell,const player pl){
    if (plycells[cell]==PLAYER_NULL){
        plycells[cell]=pl;
        return BTRUE;
    } else
        return BFALSE;
}

char grid[9];
// PRINTGRID was a void function before, but I think it's better optimize to change it to a macro
#define PRINTGRID \
    for (int i=0;i<9;i++) \
        if (plycells[i]==PLAYER_NULL) \
            grid[i]=' '; \
        else if (plycells[i]==PLAYER_CROSS) \
            grid[i]='X'; \
        else if (plycells[i]==PLAYER_CIRCLE) \
            grid[i]='O'; \
    printf(" _________________ \n|**0**|**1**|**2**|\n|  %c  |  %c  |  %c  |\n|_____|_____|_____|\n|**3**|**4**|**5**|\n|  %c  |  %c  |  %c  |\n|_____|_____|_____|\n|**6**|**7**|**8**|\n|  %c  |  %c  |  %c  |\n|_____|_____|_____|\n",grid[0],grid[1],grid[2],grid[3],grid[4],grid[5],grid[6],grid[7],grid[8]);

#define INIT \
	for (int i=0;i<9;i++) \
        plycells[i]=PLAYER_NULL;

#define RESET \
    printf("Do you want to restart a game ? (type 1 to accept)\n"); \
    int i_=scanf("%d",&i); \
    if (i==1&&i_) \
        INIT \
    else \
        stay=BFALSE; \
    \
    i=PLAYER_NULL;

/* This macro allows to do secure scanf */
#define SCANF(_FORMAT_,_POINTER_) \
	if (!scanf(_FORMAT_,_POINTER_)){ \
		fprintf(stderr,"You have entered an invalid value and the program has crashed!"); \
		exit(EXIT_FAILURE); \
	}

#ifdef _WIN32
    #include <windows.h>
    #define CMD_TITLE(_TXT_) SetConsoleTitleA(_TXT_);
#elif defined(unix)
    #define CMD_TITLE(_TXT_) printf("%c]0;%s\a",'\033',_TXT_);
#else
    #define CMD_TITLE(_TXT_) // For other platforms than unix and windows
#endif
int main(void)
{
    CMD_TITLE("ASCII Tic Tac Toe - made by Antoine James Tournepiche");
    printf("ASCII Tic Tac Toe\nmade by Antoine James Tournepiche\n10/21/2018 - 11/03/2018 13:19\n\n");
    INIT // Here I use a macro just because it's clearer
    boolean stay=BTRUE;
    player pl=PLAYER_CROSS; // First player to play
    player i=PLAYER_NULL; // Winner, or Cell number (2 usages)
    while(stay){
        PRINTGRID
        if (i==PLAYER_NULL){
            printf("It's the turn of the %s player.\n",getPlayerName(pl));
            do {
                printf("Select the cell you want to play : ");
                SCANF("%d",&i)
                if (i>8)
                    printf("Invalid Cell Number!\n");
                else if (!playCell(i,pl)){
                    printf("This Cell is already owned!\n");
                    i=9;
                }
            } while (i>8);
            i=getWinner();
        } else if (i==PLAYER_UNDEFINED){
            printf("Equality !\n");
            RESET
        } else {
            pl=!pl; // Here is a fix to print the correct winner : here we don't want to print the next player to play, but the last player which has played : the winner
            printf("The player %s has WIN!\n",getPlayerName(pl));
            RESET
        }
        pl=!pl; // Switch from CIRCLE to CROSS, or from CROSS to CIRCLE
    }
    return EXIT_SUCCESS;
}

#undef BTRUE
#undef BFALSE
#undef PLAYER_NULL
#undef PLAYER_CROSS
#undef PLAYER_CIRCLE
#undef PLAYER_UNDEFINED
#undef PRINTGRID
#undef INIT
#undef RESET
#undef SCANF
