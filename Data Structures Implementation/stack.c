#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack.\n", value);
}

void pop(void) {
    if (top == -1) {
        printf("Stack Underflow.\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top--]);
}

void search(int value) {
    for (int i = top; i >= 0; i--) {
        if (stack[i] == value) {
            printf("%d found at stack position %d.\n", value, i + 1);
            return;
        }
    }

    printf("%d not found.\n", value);
}

void display(void) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n===== STACK =====\n");
        printf("1. Push\n2. Pop\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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
