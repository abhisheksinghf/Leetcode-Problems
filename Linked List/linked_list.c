#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
    printf("%d->",ptr->data);
    ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    traverseLinkedList(head);
}