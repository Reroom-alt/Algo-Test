#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This Code was written by Lasbet Ahmed Lamin from G3
// The Goal of this Exercise is to Initialize a linked list, allow the user to add elements,
// and provide functionality to remove duplicates.

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
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
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

// Function to remove duplicates from a sorted linked list
void removeDuplicates(Node* head)
{
    if (head == NULL) return;

    Node* current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            Node* temp = current->next;
            current->next = current->next->next; // Skip the duplicate node
            free(temp); // Free the memory of the duplicate node
        }
        else
        {
            current = current->next; // Move to the next node if no duplicate
        }
    }
}

// Function to sort the linked list using bubble sort (for simplicity)
void sortList(Node* head)
{
    if (head == NULL)
        return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            {
                // Swap the values
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main(void)
{
    Node* head = NULL;
    int i = 1;
    char input[30];

    // Get input from user and populate linked list
    printf("\nEnter Elements For your Linked List: ");
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

    // Display the list before sorting and removing duplicates
    printf("Linked List Before Removing Duplicates: \n");
    display(head);

    // Sort the list to ensure duplicates are adjacent
    sortList(head);
    printf("Sorted Linked List: \n");
    display(head);

    // Remove duplicates from the list
    removeDuplicates(head);
    printf("Linked List After Removing Duplicates: \n");
    display(head); // Display the list after removing duplicates

    freeList(head); // Free the allocated memory for the list
    return 0;
}
