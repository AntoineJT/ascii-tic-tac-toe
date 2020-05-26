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
     Name : input.c
     Author : Antoine James Tournepiche
     Creation Date : December 24th 2019
     Project : ASCII Tic Tac Toe
     Project sources : https://github.com/AntoineJT/ascii-tic-tac-toe

     One utility file from ASCII Tic Tac Toe
 */

#include <stdio.h>
#include "boolean.h"
#include "buffer.h"

static bool is_yes_char(const char c)
{
    return c == 'Y' || c == 'y';
}

static bool is_no_char(const char c)
{
    return c == 'N' || c == 'n';
}

static bool is_yes_or_no_char(const char c)
{
    return is_yes_char(c) || is_no_char(c);
}

bool input_bool(const char* label)
{
    bool is_not_valid;
    char choice;

    do
    {
        printf("%s [Y/N]\n", label);
        flush_buffer();

        choice = (char) getchar();
        is_not_valid = !is_yes_or_no_char(choice);

        if (is_not_valid)
        {
            puts("Invalid choice!");
        }
    } while (is_not_valid);

    return is_yes_char(choice);
}

static bool is_digit(const unsigned int number)
{
    return number <= 9;
}

unsigned int input_digit(const char* label, const char* error_label)
{
    const char* message = label != NULL ?  label : "Input a digit : ";
    const char* error_message = error_label != NULL ? error_label : "Invalid input : not a digit!";

    unsigned int input;
    bool is_not_valid;

    do
    {
        printf("%s", message);

        is_not_valid = !scanf("%u", &input) || !is_digit(input);
        if (is_not_valid)
        {
            puts(error_message);
        }
    } while (is_not_valid);

    return input;
}
