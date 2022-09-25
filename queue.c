#include <stdio.h>
#include <stdlib.h>

struct queue* createEmptyQueue()
{
    struct queue *q = malloc(sizeof(struct queue));

    if(q == NULL)
    {
        printf("Not enough memory to create queue.\n");
        exit(0);
    }

    q -> head = NULL;
    q -> tail = NULL;

    return q;
}

int checkIfQueueEmpty(struct queue *q)
{
    if(q -> head == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void enqueue(struct queue *q, int number)
{
    struct node *new_node = malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("Not enough memory to store more information in queue.\n");
        return;
    }

    new_node -> value = number;
    new_node -> next = NULL;

    if(q -> head == NULL)
    {
        q -> head = new_node;
        q -> tail = new_node;
    }
    else
    {
        q -> tail -> next = new_node;
        q -> tail = new_node;
    }

}

int dequeue(struct queue *q, int *error)
{
    int number = 0;

    if(q -> head == NULL)
    {
        *error = 1;
        return 0;
    }

    struct node *temp = q -> head;

    number = q -> head -> value;
    q -> head = q -> head -> next;

    if(q -> head == NULL)
    {
        q -> tail = NULL;
    }

    free(temp);

    return number;
}

int checkFirstValueOfQueue(struct queue *q, int *error)
{
    int value = 0;

    if(q -> head == NULL)
    {
        *error = 1;
        return 0;
    }

    value = q -> head -> value;

    return value;
}

int findNodeCount(struct queue *q)
{
    int counter = 1;

    if(q -> head == NULL)
    {
        return 0;
    }
    else
    {
        struct node *temp = q -> head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
            counter ++;
        }
    }

    return counter;
}

void destroyQueue(struct queue *q)
{
    struct node *prev = q -> head;
    struct node *cur = q -> head;

    while(cur != NULL)
    {
        prev = cur;
        cur = prev -> next;
        free(prev);
    }
}

void increaseQueue(struct queue *q)
{
    struct node *prev = q -> head;
    struct node *cur = q -> head;

    while(cur != NULL)
    {
        prev = cur;
        cur -> value += 1;
        cur = prev -> next;

    }
}

void printQueue(struct queue *q)
{
    struct node *prev = q -> head;
    struct node *cur = q -> head;

    while(cur != NULL)
    {
        prev = cur;
        printf("%d ", cur -> value);
        cur = prev -> next;
    }
    printf("\n");
}
