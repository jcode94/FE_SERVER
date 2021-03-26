// Justice Smith
// 2021 03 23
// Filename: bulk.c
// Description: Given the number of items a customer has purchased
//    and the price for one item, compute the total cost for the customer.

#include <stdio.h>

#define DISCOUNT 2

int main()
{
    int num_items, cost_per_item;
    
    scanf("%d%d", &num_items, &cost_per_item);
    
    if (num_items == 1)
    {
        printf("%d", cost_per_item);
        return 0;
    }
    
    printf("%d", (num_items * cost_per_item) - (DISCOUNT * (num_items - 1)));
    
    return 0;
    
}
       
