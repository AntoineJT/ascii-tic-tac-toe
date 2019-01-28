/*
    boolean.h
    boolean header of the ASCII TicTacToe
    Written by Antoine James Tournepiche
    01/24/2019 13:21
*/

#ifndef _H_BOOLEAN_
	#define _H_BOOLEAN_
	typedef unsigned char boolean;
	#ifndef __cplusplus
		#undef true
		#undef false
		#define true    1
		#define false   0
	#endif
#endif
