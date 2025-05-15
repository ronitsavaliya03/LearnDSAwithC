#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int isAnagram(char str1[], char str2[]) {
    char temp1[100], temp2[100];

    strcpy(temp1, str1);
    strcpy(temp2, str2);

    sortString(temp1);
    sortString(temp2);

    if (strcmp(temp1, temp2) == 0)
        return 1;
    else
        return 0;
}

int main() {
    int n, index;
    char words[10][100], input[100];

    printf("Enter number of words (max 10): ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    printf("Enter index (0 to %d) to test anagram: ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid index.\n");
        return 1;
    }

    printf("Make an anagram of the word: %s\n", words[index]);
    scanf("%s", input);

    if (isAnagram(words[index], input)) {
        printf("Correct! It is an anagram.\n");
    } else {
        printf("Wrong! It is not an anagram.\n");
    }

    return 0;
}
