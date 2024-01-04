#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void push(Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int main() {
    Stack stack;
    stack.top = -1;  // Initialize stack

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack));  // Prints: 3
    printf("%d\n", pop(&stack));  // Prints: 2
    printf("%d\n", pop(&stack));  // Prints: 1

    return 0;
}