#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This Code was written by Lasbet Ahmed Lamin from G3
// The Goal of this Exercise is to Initialize a linked list, allow the user to add elements,
// and provide functionality to reverse the list.

typedef struct Node
{
    int val;
    struct Node *next;
} Node; // Implementing a container for our nodes

Node* createNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("\nDynamic Allocation Failed!");
        return NULL; // A message in case dynamic allocation fails or memory is occupied
    }
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int val)
{
    Node* newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return; // Assigning The New Node address to The head and terminate the function
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next; // Traversing Through The linked list until we reach the last node
    }
    temp->next = newNode;
}

// Display all elements in the linked list
void display(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Freeing the memory allocated for the linked list
void freeList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to reverse the linked list
void reverse(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Update the head to the new first element
}

int main(void)
{
    Node* head = NULL;
    int i = 1;
    char input[30];

    // Get input from user and populate linked list
    printf("\nEnter Elements For your Linked List : ");
    while (1)
    {
        printf("\nElement %d : ", i);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline from input

        if (strlen(input) == 0) // Stop if user doesn't input anything
            break;

        int val = atoi(input); // Convert the input to an integer
        append(&head, val); // Append value to the list
        i++;
    }

    printf("Linked List : \n");
    display(head); // Display the linked list

    // Reverse the linked list
    reverse(&head);
    printf("Linked List After Reversing: \n");
    display(head); // Display the reversed linked list

    freeList(head); // Free the allocated memory for the list
    return 0;
}
