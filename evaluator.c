#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i = 0, val1, val2, result;

    printf("Enter postfix expression (e.g., 53+ for 5+3): ");
    scanf("%s", postfix);

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } 
        else {
            val2 = pop(); // Second operand
            val1 = pop(); // First operand

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(result);
        }
        i++;
    }

    printf("Evaluation Result: %d\n", pop());
    return 0;
}
