#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

// Stack data structure
typedef struct {
    int top;
    double items[STACK_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, double value);
double pop(Stack *s);
int is_empty(Stack *s);
int is_operator(char c);
int precedence(char c);
void infix_to_postfix(char *infix, char *postfix);
double evaluate_postfix(char *postfix);

int main() {
    char infix[STACK_SIZE], postfix[STACK_SIZE];
    printf("Enter an expression in infix notation: ");
    fgets(infix, STACK_SIZE, stdin);
    infix_to_postfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);
    printf("Result: %f\n", evaluate_postfix(postfix));
    return 0;
}

// Push a value onto the stack
void push(Stack *s, double value) {
    if (s->top == STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

// Pop a value from the stack
double pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Check if a character is an operator
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Determine the precedence of an operator
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert an infix expression to postfix notation
void infix_to_postfix(char *infix, char *postfix) {
    Stack stack = { .top = -1 };
    char *p = infix, *q = postfix;
    while (*p != '\0') {
        if (isdigit(*p) || *p == '.') {
            // If the character is a digit or decimal point, copy it to the output
            while (isdigit(*p) || *p == '.') {
                *q++ = *p++;
            }
            *q++ = ' ';
        } else if (is_operator(*p)) {
            // If the character is an operator, pop operators from the stack until
            // an operator with lower precedence is found, then push the new operator
            while (!is_empty(&stack) && is_operator(stack.items[stack.top]) &&
                   precedence(*p) <= precedence(stack.items[stack.top])) {
                *q++ = pop(&stack);
                *q++ = ' ';
            }
            push(&stack, *p++);
        } else if (*p == '(') {
            // If the character is a left parenthesis, push it onto the stack
            push(&stack, *p++);
        } else if (*p == ')') {
            // If the character is a right parenthesis, pop operators from the stack
            // until a left parenthesis is found (which is discarded)
            while (!is_empty(&stack) && stack.items[stack.top] != '(') {
                *q++ = pop
