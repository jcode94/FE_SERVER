/**********************************************
 * File Name: fizzbuzz.c
 * Author: Justice Smith
 * Date: 2021-03-15
 * Description: Given two integers x and y and 
 *      and integer upper bound n, for each 
 *      integer 1 to n, print 'Fizz' if x 
 *      divides the integer, 'Buzz' if y 
 *      divides the integer, and 'FizzBuzz' if
 *      both divide the integer.
 * Copyright (c) 2021
 **********************************************/

#include <stdio.h>

int main() {
    int x, y, n;

    scanf("%d%d%d", &x, &y, &n);

    for (int i = 1; i <= n; ++i) {
        if (i % x == 0) {
            printf("Fizz");
        }

        if (i % y == 0) {
            printf("Buzz");
        }

        if (i % x != 0 && i % y != 0) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}