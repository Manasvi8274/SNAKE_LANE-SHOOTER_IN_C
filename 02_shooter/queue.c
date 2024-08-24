#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int x;
    int y;
    struct queue *next;
};

typedef struct queue queue;
queue *head = NULL;
queue *curr = NULL;
int n = 0;

// queue *get_head(){
//     queue *x = head;
//     return x;
// }

void push(int x, int y)
{
    if (n == 0)
    {
        // printf("in push %d\n", value);
        queue *new1 = (queue *)malloc(sizeof(queue));
        new1->x = x;
        new1->y = y;
        new1->next = NULL;
        head = new1;
        curr = head;
        n++;
        // printf("in push %d\n", value);
        return;
    }
    else
    {
        // printf("in push %d\n", value);
        queue *new1 = (queue *)malloc(sizeof(queue));
        new1->x = x;
        new1->y = y;
        new1->next = NULL;
        curr->next = new1;
        curr = new1;
        n++;
        return;
    }
}

// void iterate()
// {
//     queue *itr = head;
//     while (itr)
//     {
//         printf("%d\t%d\n", itr->x, itr->y);
//         itr = itr->next;
//     }
// }

int pop()
{
    queue *n = head;
    head = head->next;
    free(n);
}