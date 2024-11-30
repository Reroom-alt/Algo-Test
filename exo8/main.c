#include <stdio.h>
#include <stdlib.h>

// This Code was written by Lasbet Ahmed Lamin from G3
// The Goal of this Exercise is to initialize two sorted linked lists and merge them into a single sorted linked list using merge sort.

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

// Append a node to the end of the linked list
void append(Node **head, int val)
{
    Node* newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node
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

// Merge two sorted linked lists into one sorted linked list
Node* merge(Node* first, Node* second)
{
    if (first == NULL) return second;
    if (second == NULL) return first;

    // If first node's value is smaller, merge it first
    if (first->val <= second->val)
    {
        first->next = merge(first->next, second);
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        return second;
    }
}

int main(void)
{
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Initializing two sorted lists manually

    // First sorted list: 1 -> 3 -> 5 -> 7
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);
    append(&list1, 7);

    // Second sorted list: 2 -> 4 -> 6 -> 8
    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);
    append(&list2, 8);

    // Display the two lists before merging
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Merging the two sorted lists
    Node* mergedList = merge(list1, list2);

    // Display the merged sorted list
    printf("Merged List: ");
    display(mergedList);

    // Freeing the allocated memory for the lists
    free(list1);
    free(list2);
    free(mergedList);

    return 0;
}
