#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void create(struct Node *head, int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    // Traverse to the end of the list
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;  // Add the new node at the end
}

void display(struct Node *head) {
    if (head->next == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head->next;  // Skip the dummy head node
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // End of the list
}

int main() {
    int choice, data;

    // Dummy head node
    struct Node head = {0, NULL};

    while (1) {
        printf("\n1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                create(&head, data);
                break;
            case 2:
                printf("Linked List: ");
                display(&head);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
