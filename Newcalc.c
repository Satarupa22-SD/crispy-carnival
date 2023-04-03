#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infix_to_postfix(char *infix_expression, char *postfix_expression) {
    int i, j, top = -1;
    char stack[MAX_EXPRESSION_LENGTH];
    char c;

    for (i = 0, j = 0; infix_expression[i] != '\0'; i++) {
        c = infix_expression[i];
        if (isdigit(c) || c == '.') {
            postfix_expression[j] = c;
            j++;
        }
        else if (is_operator(c)) {
            while (top >= 0 && stack[top] != '(' && precedence(stack[top]) >= precedence(c)) {
                postfix_expression[j] = stack[top];
                top--;
                j++;
            }
            top++;
            stack[top] = c;
        }
        else if (c == '(') {
            top++;
            stack[top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix_expression[j] = stack[top];
                top--;
                j++;
            }
            top--;
        }
    }

    while (top >= 0) {
        postfix_expression[j] = stack[top];
        top--;
        j++;
    }

    postfix_expression[j] = '\0';
}

double evaluate_postfix(char *postfix_expression) {
    int i, top = -1;
    double stack[MAX_EXPRESSION_LENGTH];
    char c;
    double operand1, operand2;

    for (i = 0; postfix_expression[i] != '\0'; i++) {
        c = postfix_expression[i];
        if (isdigit(c)) {
            top++;
            stack[top] = atof(&postfix_expression[i]);
            while (isdigit(postfix_expression[i]) || postfix_expression[i] == '.') {
                i++;
            }
            i--;
        }
        else if (is_operator(c)) {
            operand2 = stack[top];
            top--;
            operand1 = stack[top];
            top--;
            switch (c) {
                case '+':
                    top++;
                    stack[top] = operand1 + operand2;
                    break;
                case '-':
                    top++;
                    stack[top] = operand1 - operand2;
                    break;
                case '*':
                    top++;
                    stack[top] = operand1 * operand2;
                    break;
                case '/':
                    top++;
                    stack[top] = operand1 / operand2;
                    break;
            }
        }
    }

    return stack[top];
}

int main() {
    char infix_expression[MAX_EXPRESSION_LENGTH];
    char postfix_expression[MAX_EXPRESSION_LENGTH];
    double result;

    printf("Enter an expression in infix notation: ");
    fgets(infix_expression, MAX_EXPRESSION_LENGTH, stdin);
    infix_expression[strcspn(infix_expression, "\n")] = '\0';

    infix_to_postfix(infix_expression, postfix_expression);
    printf("The expression in postfix notation is: %s\n", postfix_expression);

    result = evaluate_postfix(postfix_expression);
    printf("The result of the expression is: %f\n", result);

    return 0;
}
