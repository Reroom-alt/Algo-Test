#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This Code was writen by Lasbet Ahmed Lamin from G3
//The Goal From this Exercise is to look for a node and
//identify it by its value and free it


typedef struct Node
{
    int val;
    struct Node *next;
} Node; //Implementing a container for our nodes

Node* createNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("\nDynamc Allocation Failed!");
        return NULL; // A message in case dynamic allocation fail or memory is occupied
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

// Function to delete a node by its value
void deleteNode(Node** head, int value)
{
    if (*head == NULL)
    {
        printf("\nList is empty! Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // If the head node contains the value
    if (temp != NULL && temp->val == value)
    {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Traverse to find the node
    while (temp != NULL && temp->val != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink and free the node
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

int main(void)
{
    Node* head = NULL;
    int i = 1;
    char input[30];

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

    // Deleting a node by value
    int deleteValue;
    printf("\nEnter the value of the node to delete: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    deleteValue = atoi(input);

    deleteNode(&head, deleteValue); // Delete the node with the given value

    printf("Linked List After Deleting : ");
    display(head); // Display the linked list again after deletion

    freeList(head); // Free the allocated memory for the list
    return 0;
}
