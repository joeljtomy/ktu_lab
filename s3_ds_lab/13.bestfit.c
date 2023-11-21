//13. Simulate first fit, best fit and worst fit memory allocation strategies using linked list.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

int empty() {
    return top == -1;
}

int full() {
    return top == MAX_SIZE - 1;
}

void push(char item) {
    if (!full()) stack[++top] = item;
}

int pop() {
    if (!empty()) return stack[top--];
    else return -1;
}

int peek() {
    if (!empty()) return stack[top];
    else return -1;
}

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j;
    char ch;

    for (i = j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) postfix[j++] = ch;
        else if (ch == '(') push(ch);
        else if (ch == ')') {
            while (peek() != '(' && !empty()) {
                postfix[j++] = pop();
            }
            pop();
        } else if (is_operator(ch)) {
            while (!empty() && precedence(ch) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!empty()) postfix[j++] = pop();
    postfix[j] = '\0';
}

int postfix_evaluation(char postfix[]) {
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch))  push(ch - '0');
        else if (is_operator(ch)) {
            operand2 = pop();
            operand1 = pop();

            switch (ch) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
            }
        }
    }

    result = pop();
    return result;
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);

    int result = postfix_evaluation(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}


/*Algorithm
Step 1: Start.

*/
