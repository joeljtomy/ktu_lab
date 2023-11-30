// 12. Apply stack to perform Infix to postfix conversion and Postfix evaluation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100
int top = -1;
int stack[SIZE];

void push(int item) {
    if (top != SIZE - 1)
        stack[++top] = item;
}

int pop() {
    if (top != -1) return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    return 0;
}

void invalid() {
    printf("Invalid infix expression!");
    exit(0);
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char ch, prevch, nextch;

    for (i = j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        nextch = infix[i+1];

        if (isalnum(ch)) {
            if (prevch && isalnum(prevch)) invalid();
            else postfix[j++] = ch;
        } else if (ch == '(') {
            if (prevch && !isOperator(prevch) && prevch != '(') invalid();
            else push(ch);
        } else if (ch == ')') {
            if (nextch && !isOperator(nextch) && nextch != ')') invalid();
            else {
                while (top != -1 && stack[top] != '(')
                    postfix[j++] = pop();
                if (top == -1) invalid();
                else pop();
            }
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(ch) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(ch);
        }
        prevch = ch;
    }

    while (top != -1){
        ch = pop();
        if (ch == '(') invalid();
        else postfix[j++] = ch;
    }
    postfix[j] = '\0';
}

int postfixEvaluation(char postfix[]) {
    int i, j, l = 0, operand1, operand2, result;
    char ch;
    struct term {
        char ch;
        int value;
    };
    struct term variables[SIZE];

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isalnum(ch)) {
            if (isalpha(ch)) {
                for (j = 0; j < l; j++) {
                    if (variables[j].ch == ch) {
                        push(variables[j].value);
                        break;
                    }
                }
                if (j == l) {
                    printf("Enter value for variable %c: ", ch);
                    scanf("%d", &variables[l].value);
                    variables[l].ch = ch;
                    push(variables[l++].value);
                }
            }
            else push(ch - '0');
        }
        else if (isOperator(ch)) {
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
    char infix[SIZE], postfix[SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);

    int result = postfixEvaluation(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}

/*Algorithm
Step 1: Start.

*/
