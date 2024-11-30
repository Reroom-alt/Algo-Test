#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This Code was written by Lasbet Ahmed Lamin from G3
// The Goal of this Exercise is to Initialize a linked list, allow the user to add elements,
// and provide functionality to find the kth largest number.

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

// Function to find the kth largest element in the linked list
int findKthLargest(Node* head, int k)
{
    if (head == NULL || k <= 0)
    {
        printf("Invalid input.\n");
        return -1; // Return an invalid number if the input is incorrect
    }

    // Count the total number of elements in the list
    Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    if (k > count)
    {
        printf("k is larger than the size of the list.\n");
        return -1;
    }

    // Find the (k)-th largest element by using two-pass method
    int largest[k]; // Array to hold the k largest elements
    for (int i = 0; i < k; i++)
    {
        largest[i] = -2147483648; // Initialize with a very small value (min integer)
    }

    current = head;
    while (current != NULL)
    {
        for (int i = 0; i < k; i++)
        {
            if (current->val > largest[i])
            {
                // Shift smaller elements down to make room for the new value
                for (int j = k - 1; j > i; j--)
                {
                    largest[j] = largest[j - 1];
                }
                largest[i] = current->val;
                break;
            }
        }
        current = current->next;
    }

    return largest[k - 1]; // The k-th largest value is the last in the array
}

int main(void)
{
    Node* head = NULL;
    int i = 1;
    int k;
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

    // Ask the user for the value of k (k-th largest number)
    printf("\nEnter the value of k: ");
    fgets(input, sizeof(input), stdin);
    k = atoi(input); // Convert the input to an integer

    // Display the linked list
    printf("Linked List: \n");
    display(head);

    // Find the kth largest element in the list
    int kthLargest = findKthLargest(head, k);
    if (kthLargest != -1)
    {
        printf("The %d-th largest number in the linked list is: %d\n", k, kthLargest);
    }

    freeList(head); // Free the allocated memory for the list
    return 0;
}
