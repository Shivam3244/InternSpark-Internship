#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted successfully.\n", value);
}

void deleteNode(int value) {
    struct Node *temp = head;
    struct Node *previous = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("%d deleted successfully.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found.\n", value);
        return;
    }

    previous->next = temp->next;
    free(temp);
    printf("%d deleted successfully.\n", value);
}

void search(int value) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("%d not found.\n", value);
}

void display(void) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n===== LINKED LIST =====\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
