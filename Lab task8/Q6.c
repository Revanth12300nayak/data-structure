#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Stack { int top; int capacity; char* array; };

 struct Stack* createStack(int capacity) { struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity; stack->top = -1;
  stack->array = (char*)malloc(stack->capacity * sizeof(char));
   return stack; }

 int isEmpty(struct Stack* stack) { return stack->top == -1; }

 void push(struct Stack* stack, char item) { stack->array[++stack->top] = item; }

 char pop(struct Stack* stack) { if (isEmpty(stack)) return '#'; // Return a dummy character return stack->array[stack->top--]; }

int isBalanced(char* expression) { struct Stack* stack = createStack(strlen(expression));

for (int i = 0; expression[i] != '\0'; i++) {
    if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
        push(stack, expression[i]);
    } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
        char top = pop(stack);
        if ((expression[i] == ')' && top != '(') ||
            (expression[i] == '}' && top != '{') ||
            (expression[i] == ']' && top != '[')) {
            free(stack->array);
            free(stack);
            return 0; // Not balanced
        }
    }
}
int balanced = isEmpty(stack);
free(stack->array);
free(stack);
return balanced;

}

 int main() { char expression[] = "{[()]}";
  if (isBalanced(expression))
  { printf("Parentheses are balanced.\n"); }
  else { printf("Parentheses are not balanced.\n"); }
    return 0; }
