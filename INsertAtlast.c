#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

void Display(struct node* head) {
    printf("The data of the node: ");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n"); // Add a newline for better formatting
}

struct node* insertAtFirst(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) { // Check for malloc failure
        perror("Memory allocation failed");
        exit(1); 
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct node* insertAtLast(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
     if (newNode == NULL) { // Check for malloc failure
        perror("Memory allocation failed");
        exit(1); 
    }
    newNode->data = data;
    newNode->next = NULL; // New node will be the last

    if (head == NULL) { // If the list is empty
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main() {
    struct node* head = NULL; // Initialize head to NULL

    // Add some initial nodes (better way to do this is shown below)
    head = insertAtLast(head, 33);
    insertAtLast(head, 35);
    insertAtLast(head, 33);
    insertAtLast(head, 45);
    insertAtLast(head, 60);

    Display(head);

    int data;
    printf("Enter your inserting data at the beginning: ");
    scanf("%d", &data);
    head = insertAtFirst(head, data);
    Display(head);

    printf("Enter your inserting data at the end: ");
    scanf("%d", &data);
    head = insertAtLast(head, data);
    Display(head);


    // ... (rest of your code)

    return 0;
}