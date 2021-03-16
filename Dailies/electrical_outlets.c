/**********************************************
 * File Name: electrical_outlets.c
 * Author: Justice Smith
 * Date: 2021-03-15
 * Description: Computes the maximum number of 
 *      appliances that can be powered given the
 *      number of power strips and the number of
 *      outlets in each power strip
 * Copyright (c) 2021
 **********************************************/

#include <stdio.h>

void get_total_outlets() {
    int num_strips, num_outlets, total_outlets = 0;

    scanf("%d", &num_strips);

    // n - 1 outlets per strip because one outlet from each
    // strip is used to power the subsequent strip
    for (int j = 0; j < num_strips - 1; ++j) {
        scanf("%d", &num_outlets);
        total_outlets += (num_outlets - 1);
    }
    // last outlet is completely free
    scanf("%d", &num_outlets);
    total_outlets += num_outlets;

    printf("%d\n", total_outlets);
}

int main() {
    int num_test_cases;

    scanf("%d", &num_test_cases);

    for (int i = 0; i < num_test_cases; ++i) {
        get_total_outlets();
    }

    return 0;
}