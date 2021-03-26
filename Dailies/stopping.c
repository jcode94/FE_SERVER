// Justice Smith
// 2020 03 23
// Description: Given an integer n representing the trip distance, and two 
//    additional integers representing the distances at which the travelers 
//    must stop, print the number of stops for the trip. Coincident stops do 
//    not count twice, and stops that coincide with the trip termination do
//    not count toward the total stop count either.

#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}   

int main()
{

    int total_dist, refuel, eat, total_stops = 0;
    
    scanf("%d%d%d", &total_dist, &refuel, &eat);
    
    // this double counts the intersection
    total_stops += (total_dist / refuel);
    total_stops += total_dist / eat;
    
    // need to subtract the number of values in the intersection of sets    
    total_stops -= total_dist / ((refuel * eat) / gcd(refuel, eat));
    
    // There may still be an extra count upon arrival coincidence
    if (total_dist % refuel == 0 || total_dist % eat == 0)
        total_stops--;
    
    printf("%d\n", total_stops);
    
    return 0;
}
    
