#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces and newlines
        if (exp[i] == ' ' || exp[i] == '\n') {
            i++;
            continue;
        }

        // If digit → build full number
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        // If operator
        else {
            int op2 = pop();
            int op1 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
                case '^': push((int)pow(op1, op2)); break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    exit(1);
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (use spaces): ");
    fgets(exp, MAX, stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}