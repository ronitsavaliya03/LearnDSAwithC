#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        case '#': return -1;
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

// Rank function
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

// Reverse a string
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

// Swap brackets in a string
void swapBrackets(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

// Infix to Prefix conversion
void infixToPrefix(char infix[]) {
    char prefix[SIZE] = "";
    int r = 0;
    top = -1;
    push('#');

    reverse(infix);
    swapBrackets(infix);

    for (int i = 0; infix[i]; i++) {
        char sym = infix[i];

        while (G(peek()) > F(sym)) {
            char temp = pop();
            strncat(prefix, &temp, 1);
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
        strncat(prefix, &temp, 1);
        r += rank(temp);
        if (r < 1) {
            printf("INVALID\n");
            return;
        }
    }

    if (r != 1) {
        printf("INVALID\n");
    } else {
        reverse(prefix);
        printf("Prefix: %s\n", prefix);
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    return 0;
}
