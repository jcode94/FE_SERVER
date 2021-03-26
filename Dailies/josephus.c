// Justice Smith
// 2021 03 23
// Description: Given two integers, n and m, where n is the number of elements
//    in a circular sequence and m is the interval, print the numbers from 1 to
//    n in the order in which they will be removed from the sequence, 
//    at m intervals.

#include <stdio.h>
#include <stdlib.h>

typedef struct LL LL;
typedef struct Node Node;

struct LL
{
    Node* tail;
};

struct Node
{
    int data;
    Node* next;
};

LL* createList();
Node* createNode(int data);
void insert(LL* list, int data);
void printList(LL* list);

int main()
{
    int num_elements, interval;

    scanf("%d%d", &num_elements, &interval);
    
    LL* myList = createList();
    
    while (num_elements > 0)
    {
        insert(myList, num_elements--);
        printList(myList);
    }
    
    return 0;
}

LL* createList()
{
    LL* newList = malloc(sizeof(LL));
    newList->tail = NULL;
    return newList;
}

Node* createNode(int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insert(LL* list, int data)
{
    Node* newNode = createNode(data);
    Node* current;
    
    // Empty list
    if (list->tail == NULL)
    {
        list->tail = newNode;
        return;
    }
    
    // At least one node
    newNode->next = list->tail->next;
    list->tail->next = newNode;
    
    return;
}

void printList(LL* list)
{
    Node* current;
    
    if (list->tail == NULL)
        return;
    
    current = list->tail->next;
    
    do {
        printf("%d->", current->data);
        current = current->next;
    } while(current != list->tail->next);
    
    printf("\n");
    
    return;
}
    
