/*
	Name : ttt/player.h
	Author : Antoine James Tournepiche
	Creation Date : December 20th 2019
	Last update : December 20th 2019
	Project : ASCII Tic Tac Toe
	Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

	TicTacToe player header
*/

#ifndef _H_TTT_PLAYER_
#define _H_TTT_PLAYER_

typedef enum
{
    PLAYER_CROSS,
    PLAYER_CIRCLE,
    PLAYER_NULL,
    // Used to indicates when no one get a frame or when it has no winner for now
    PLAYER_UNDEFINED // Used to indicates when it has equality
} player;
#endif
