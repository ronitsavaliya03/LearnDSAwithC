#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++)
        push(str[i]);
    
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    for (int i = start; i < len; i++) {
        if (pop() != str[i])
            return 0;
    }
    return 1;
}

int main() {
    char str[SIZE];
    printf("Enter string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("Valid string (palindrome).\n");
    else
        printf("Invalid string.\n");

    return 0;
}
