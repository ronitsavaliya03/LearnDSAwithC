#include <stdio.h>
#include <string.h> 

int main() {
    char ch;
    const char *vowels = "aeiouAEIOU";

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (strchr(vowels, ch) != NULL) {
        printf("%c is a vowel.\n", ch);
    } else {
        printf("%c is not a vowel.\n", ch);
    }

    return 0;
}
