#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100
int stack[SIZE], top = -1;

// NOTE: only for single digit expression, for double digit expression you have to take space separated input


void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int evaluatePrefix(char* exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int a = pop();
            int b = pop();
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
    printf("Enter prefix expression: ");
    scanf("%s", expr);
    printf("Result = %d\n", evaluatePrefix(expr));
    return 0;
}
