#include <stdio.h>
#include <stdlib.h>


//This Code was written by lasbet Ahmed Lamin from G3
//The Goal From this Exercise is to Initialize A linked list with five Elements



typedef struct Node
{
    int val;
    struct Node *next;
}Node; //Implementing a container for our nodes



Node* createNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("\nDynamic Allocation Failed!");
        return 0; //A message in case dynamic allocation fail or memory is occupied
    }
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int val)
{
    Node* newNode = createNode(val);
    if(*head == NULL)
    {
        *head = newNode;
        return; // Assigning The New Node address to The head and terminate the function
    }
    Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next; //Traversing Through The linked list until we reach the the last node
    }
    temp->next = newNode;
}


void display(Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        printf("%d -> ",current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head)
{
        Node* current = head;
        while(current != NULL)
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
}



int main(void)
{
    Node* head = NULL;
    append(&head, 10);
    append(&head, 23);
    append(&head, 62);
    append(&head, 13);
    append(&head, 74);
    printf("Linked List : \n");
    display(head);
    freeList(head);
    return 0;
}
