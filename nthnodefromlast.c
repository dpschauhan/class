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
};

// return middle node using bunny and turtle technique
void bunnyandturtle(struct Node* head){
    printf("PRINTING middle node using bunny and turtle technique\n");
    struct Node* s=head;
    struct Node* temp=head;
    while (s->address!=NULL && s!=NULL && s->address->address!=NULL)
    {
        temp=temp->address;
        s=s->address->address;
    }
    printf("%d\n",temp->data);
    
}
// return middle node using counter
void middle(struct Node* head){
    printf("PRINTING middle node using counter\n");
    int c=0;
    struct Node* s=head;
    while (s->address!=NULL)
    {
        c++;
        s=s->address;
    }
    int mi=c/2;
    s=head;
    if (c&1==0){
        mi-=1;
    }
    while (mi>0)
    {
        s=s->address;
        mi--;
    }
    printf("%d",s->data);
    
}
// return n from last of linked list
void returnnfromlinkedlist(struct Node* head, int n_from_last){
    printf("PRINTING Nth node from last\n");
    struct Node* s=head;
    struct Node* temp=head;
    while(n_from_last > 0){
        s=s->address;
        n_from_last--;
    }
    while (s!=NULL)
    {
        temp=temp->address;
        s=s->address;
    }
    printf("%d\n",temp->data);
    
}


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
    insertionattail(headptr, 40);
    insertionattail(headptr, 60);
    insertionattail(headptr, 70);
    insertionattail(headptr, 80);
    insertionattail(headptr, 90);
    printLL(headptr);
    returnnfromlinkedlist(headptr,3);
    bunnyandturtle(headptr);
    middle(headptr);

}