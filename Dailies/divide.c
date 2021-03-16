/**********************************************
 * File Name: divide.c
 * Author: Justice Smith
 * Date: 2021-03-15
 * Description: Program to compute the earnings
 *      of multiple problem-completing students.
 * Copyright (c) 2021
 **********************************************/

#include <stdio.h>

int main() {
    int num_students, dollars, num_problems = 0;
    scanf("%d%d", &num_students, &dollars);
    int problems_solved[num_students];

    for (int i = 0; i < num_students; i++) {
        scanf("%d", &problems_solved[i]);
        num_problems += problems_solved[i];
    }

    for (int i = 0; i < num_students; i++) {
        printf("%d\n", (dollars / num_problems) * problems_solved[i]);
    }

    return 0;
}