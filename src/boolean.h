/*
    Name : boolean.h
    Author : Antoine James Tournepiche
    Creation date : January 24th 2019
    Last update : March 28th 2019
    Project : ASCII Tic Tac Toe
    Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

    boolean header of the ASCII TicTacToe
*/

#ifndef _H_BOOLEAN_
	#define _H_BOOLEAN_
	typedef unsigned char boolean;
	#ifndef __cplusplus
		#undef true
		#undef false
		#define true 1
		#define false 0
	#endif
#endif
