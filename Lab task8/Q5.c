#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

 struct Stack { int top; int capacity; int* array; };

 struct Stack* createStack(int capacity)
{ struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
 stack->capacity = capacity; stack->top = -1; stack->array = (int*)malloc(stack->capacity * sizeof(int));
 return stack; }

int isEmpty(struct Stack* stack)
{ return stack->top == -1; }

 void push(struct Stack* stack, int item)
{ stack->array[++stack->top] = item; }

 int pop(struct Stack* stack) { if (isEmpty(stack)) { printf("Stack underflow\n");
                                                     exit(EXIT_FAILURE); } return stack->array[stack->top--]; }

int evaluatePostfix(char* expression) { struct Stack* stack = createStack(100);

for (int i = 0; expression[i] != '\0'; i++) {
    if (isdigit(expression[i])) {
        push(stack, expression[i] - '0'); // Convert char to int
    } else {
        int val2 = pop(stack);
        int val1 = pop(stack);
        
        switch (expression[i]) {
            case '+': push(stack, val1 + val2); break;
            case '-': push(stack, val1 - val2); break;
            case '*': push(stack, val1 * val2); break;
            case '/': push(stack, val1 / val2); break;
            case '^': push(stack, pow(val1, val2)); break;
            default: printf("Invalid operator\n"); exit(EXIT_FAILURE);
        }
    }
}
int result = pop(stack);
free(stack->array);
free(stack);
return result;

}

int main() {
  char expression[] = "231*+9-";
  printf("Postfix evaluation result: %d\n", evaluatePostfix(expression));
  return 0; }
