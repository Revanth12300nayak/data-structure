#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;  
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;

    stack->top = newNode;

    printf("%d pushed to stack\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;  
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;

    stack->top = stack->top->next;

    free(temp);

    return poppedValue;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("%d popped from stack\n", pop(&stack));
    printf("%d popped from stack\n", pop(&stack));

    printf("Top element is %d\n", peek(&stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("%d popped from stack\n", pop(&stack));
    printf("%d popped from stack\n", pop(&stack));

    pop(&stack);

    return 0;
}
