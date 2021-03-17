#include <stdio.h>


#define NO_SOLUTION 1000000000

int min (int x, int y) {
    if (x < y) return x;
    return y;
}

// Returns the minimum number of steps to transform x into y, or
// 1000000000 to indicate no solution.
int minSteps(int x, int y) {
    // when x > y
    if (x > y)
        return NO_SOLUTION;
    while (min(2 * x, y) != y) {
        if (y % 2 == 1)
            return 2 + minSteps(x, y / 2);
        else
            return 1 + minSteps(x, y / 2);
    }
    return 0;
}   

int main() {
    int x, y;
    scanf("%d%d", &x, &y);

    int total = minSteps(x, y);
    printf("%d", total);

    return 0;
}