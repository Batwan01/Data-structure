#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    struct List* next;
    struct List* prev;
    char* name;
} List;

// Function to add a new node to the circular linked list
void Add_Linked_List(List** head, char* name) {
    List* new_node = (List*)malloc(sizeof(List));
    new_node->name = name;
    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else {
        List* last = (*head)->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *head;
        (*head)->prev = new_node;
    }
}

int main(void) {
    List* head = NULL; // Declare head variable of type List*
    int n; // Variable to store the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    char name[10]; // Array to store the entered name
    printf("Enter names of students (enter '0' to finish):\n");
    while (true) {
        scanf("%s", name);
        if (name[0] == '0') {
            break;
        }
        Add_Linked_List(&head, name); // Call the function and add the linked list
    }

    List* current = head; // Initialize the current node to the head of the list
    printf("Elimination order:\n");
    while (current->next != current) { // Continue until only one person is left
        for (int i = 1; i < n; i++) { // Move to the nth person in clockwise direction
            current = current->next;
        }
        printf("Removed: %s\n", current->name); // Output the name of the removed person
        current->prev->next = current->next; // Remove the current node from the list
        current->next->prev = current->prev;
        List* temp = current; // Store the current node in a temporary variable
        current = current->next; // Move to the next person in the list
        free(temp); // Free the memory occupied by the removed node
    }

    printf("Remaining student: %s\n", current->name); // Output the name of the last remaining person

    return 0;
}