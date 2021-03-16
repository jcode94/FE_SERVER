// Justice Smith 3.15.2021
// For CompSciPrep - FE+ Discord Channel

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int games, points;
    int wins;
    int ties;

    scanf("%d%d", &games, &points);
    
    wins = points / 3;
    ties = points - (3 * wins);

    while (wins >= 0) 
    {
        if (((3 * wins + ties) == points) && (wins + ties) <= games)
            printf("%d-%d-%d\n", wins, ties, games - (wins + ties));

        wins--;
        ties = points - (3 * wins);              
    }

    return 0;
}