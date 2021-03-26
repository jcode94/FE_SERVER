// name: Justice Smith
// date: 2021-03-24
// filename: fold.c
// description: given 2 integer side lengths and 1 integer F representing the 
//      number of folds, calculate the new side lengths after halving the longer
//      side length a number of times equal to F.

#include <stdio.h>

int main()
{
    int s1, s2, folds;
    
    scanf("%d%d%d", &s1, &s2, &folds);
    
    for (int i = 0; i < folds; ++i)
    {
        if (s1 >= s2) s1 /= 2; // halve side 1 bc larger
        else          s2 /= 2; // halve side 2 bc larger
    }
    
    // print larger first
    s1 >= s2 ? printf("%d %d\n", s1, s2) : printf("%d %d\n", s2, s1);
    
    return 0;
}
