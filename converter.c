#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char item = infix[i];

        if (isOperand(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            char temp = pop();
            if (temp == -1) { 
                printf("Error: Mismatched parentheses (Extra closing bracket)\n");
                return 1;
            }
            while (temp != '(') {
                postfix[j++] = temp;
                temp = pop();
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        char temp = pop();
        if (temp == '(') {
            printf("Error: Mismatched parentheses (Missing closing bracket)\n");
            return 1;
        }
        postfix[j++] = temp;
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
