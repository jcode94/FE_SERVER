/***********************************************
* @author: Justice Smith
* @filename: matrix.c
* @date: 2021-03-25
* @description: output the minimum number of 
*     swaps necessary to move an element to the
*     center of a 5x5 matrix.
***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define M_WIDTH 5
#define M_HEIGHT 5

int stepConverter(int pos) {
    int vert = 0;
    int horiz = 0;
    
    vert += pos / 5;
    horiz += pos % 5;
    
    return abs(2 - vert) + abs(2 - horiz);
}

int main() {

    int in, pos = -1;
    
    do {
        scanf("%d", &in);
        pos++;
    } while (in != 1);
    
    printf("%d", stepConverter(pos));
    
    return 0;   
}

// printf("%d", abs(2 - (pos/5)) + abs(2 - (pos % 5)));
// we out here golfin bro
    
