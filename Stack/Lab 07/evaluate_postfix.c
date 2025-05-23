#include <stdio.h>
#include <ctype.h>

#define SIZE 100
int stack[SIZE], top = -1;

// NOTE: only for single digit expression, for double digit expression you have to take space separated input


void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i]; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", expr);
    printf("Result = %d\n", evaluatePostfix(expr));
    return 0;
}
