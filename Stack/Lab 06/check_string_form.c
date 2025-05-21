#include <stdio.h>
#include <string.h>

#define SIZE 100

int stack[SIZE];  
int top = -1;     

void push(int value) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        return -1; 
    } else {
        return stack[top--];
    }
}

int isEmpty() {
    return top == -1;
}

int main() {
    char str[SIZE];
    int i = 0, valid = 1;

    printf("Enter the string (like aaabbb): ");
    scanf("%s", str);

    while (str[i] != '\0'){
        if(str[i] == 'a'){
            push(1);
            i++;
        }
        else if(str[i] == 'b'){
            if(isEmpty()){
                valid = 0;
                break;
            }
            pop();
            i++;
        }
    }

    if (!isEmpty() || str[i] != '\0') {
        valid = 0;
    }

    if (valid)
        printf("Valid String (a^i b^i)\n");
    else
        printf("Invalid String\n");

    return 0;
}
