#include <stdio.h>

#define MAX 5

int stack[MAX];  
int top = -1; 

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } else {
        stack[++top] = val;
        printf("Pushed %d\n", val);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("Popped %d\n", stack[top--]);
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int size() {
    return top + 1;
}

int main() {
    printf("=== Stack Implementation using Array ===\n\n");
    
    printf("Pushing elements: 10, 20, 30, 40, 50\n");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    printf("\nStack size: %d\n", size());
    display();
    
    printf("\nTop element (peek): %d\n", peek());
    
    printf("\nAttempting to push 60 (should fail - stack full):\n");
    push(60);
    
    printf("\nPopping 2 elements:\n");
    pop();
    pop();
    
    printf("\nStack after popping:\n");
    display();
    printf("Stack size: %d\n", size());
    
    printf("\nPopping remaining elements:\n");
    pop();
    pop();
    pop();
    
    printf("\nAttempting to pop from empty stack:\n");
    pop();
    
    return 0;
}
