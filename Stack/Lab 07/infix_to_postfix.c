#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Stack Precedence (G)
int G(char ch) {
    switch(ch) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1; // initial stack bottom
        default: return 8; 
    }
}

// Input Precedence (F)
int F(char ch) {
    switch(ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7; 
    }
}

// Rank Function
int rank(char ch) {
    if (isalnum(ch)) return 1;
    else return -1;
}

// Stack operations
void push(char ch) {
    stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}

void infixToPostfix(char infix[]) {
    char postfix[SIZE] = "";
    int r = 0; 
    push('#');  // Initial bottom marker
    for (int i = 0; infix[i] != '\0'; i++) {
        char sym = infix[i];

        while (G(peek()) > F(sym)) {
            char temp = pop();
            strncat(postfix, &temp, 1);
            r += rank(temp);
            if (r < 1) {
                printf("INVALID\n");
                return;
            }
        }

        if (G(peek()) != F(sym)) {
            push(sym);
        } else {
            pop(); 
        }
    }

    while (peek() != '#') {
        char temp = pop();
        strncat(postfix, &temp, 1);
        r += rank(temp);
        if (r < 1) {
            printf("INVALID\n");
            return;
        }
    }

    if (r != 1) printf("INVALID\n");
    else printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
