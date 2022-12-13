#include <stdio.h>
#include <stdlib.h>
// Code to make a note of a linkedlist.
struct Node
{
    int data;
    struct Node *address;
};

// Printing a linked list
void printLL(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->address;
    }
    printf("NULL\n");
}

// Insert at tail of a linked list
void insertionattail(struct Node *head, int data)
{
    printf("Before Insertion at tail \n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    struct Node *s = head;
    while (s->address != NULL)
    {
        s = s->address;
    }
    s->address = temp;
    printf("After Insertion at tail \n");
    printLL(head);
};
// Insert at position before of a linked list
void insertion(struct Node *head, int data, int posafter)
{
    printf("Before Insertion in between\n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;
    struct Node *s = head;
    while (s->address->data != posafter)
    {
        s = s->address;
    }
    struct Node *a = s->address;
    s->address = temp;
    temp->address = a;
    printf("After Insertion in between\n");
    printLL(head);
};

// Insert at head of a linked list
struct Node *insertionathead(struct Node *head, int data)
{
    printf("Before Insertion at head \n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;
    struct Node *s = head;
    head = temp;
    head->address = s;
    printf("After Insertion at head \n");
    printLL(head);
    return (head);
};

// deletion at tail
void deletetail(struct Node *head)
{
    printf("Before deletion at tail \n");
    printLL(head);
    struct Node *s = head;
    while (s->address->address != NULL)
    {
        s = s->address;
    }
    struct Node *temp = s->address;
    s->address = NULL;
    free(temp);
    printf("after deletion at tail \n");
    printLL(head);
}
// deletion at head
struct Node* deletehead(struct Node *head)
{
    printf("Before deletion at head \n");
    printLL(head);
    struct Node *temp = head;
    head=head->address;
    free(temp);
    printf("after deletion at head \n");
    printLL(head);
    return (head);
}


// deletion at before data
void deletebefore(struct Node *head,int data)
{
    printf("Before deletion at before data \n");
    printLL(head);
    struct Node *s = head;
    while (s->address->address->data != data)
    {
        s = s->address;
    }
    struct Node *temp = s->address;
    s->address=s->address->address;
    free(temp);
    printf("after deletion at before data \n");
    printLL(head);
}

// Making nodes of a linked list.
void main()
{
    struct Node *headptr = NULL;
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 10;
    if (headptr == NULL)
    {
        headptr = first;
    }
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 20;
    second->address = NULL;
    first->address = second;
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->data = 30;
    third->address = NULL;
    second->address = third;
    printLL(headptr);
    printf(".................................................................................\n");
    insertionattail(headptr, 40);
    printf(".................................................................................\n");
    headptr = insertionathead(headptr, 5);
    printf(".................................................................................\n");
    insertion(headptr, 35, 30);
    printf(".................................................................................\n");
    deletetail(headptr);
    printf(".................................................................................\n");
    headptr = deletehead(headptr);
    printf(".................................................................................\n"); 
    deletebefore(headptr,30);
    printf(".................................................................................\n");         

}