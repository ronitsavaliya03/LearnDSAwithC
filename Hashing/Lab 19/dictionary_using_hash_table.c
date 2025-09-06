#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct DictEntry {
    char key[20];
    char value[50];
};

struct DictEntry hashTable[SIZE];

int hashFunction(char key[]) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++){
        sum += key[i];
    }
    return sum % SIZE;
}

void insert(char key[], char value[]) {
    int index = hashFunction(key);

    while (strlen(hashTable[index].key) != 0) {
        index = (index + 1) % SIZE;
    }

    strcpy(hashTable[index].key, key);
    strcpy(hashTable[index].value, value);
}

void get(char key[]) {
    int index = hashFunction(key);
    int start = index;

    while (strlen(hashTable[index].key) != 0) {
        if (strcmp(hashTable[index].key, key) == 0) {
            printf("Value for key '%s' is: %s\n", key, hashTable[index].value);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == start){
            break;
        }
    }

    printf("Key '%s' not found in dictionary.\n", key);
}

void display() {
    printf("\nDictionary Entries:\n");
    for (int i = 0; i < SIZE; i++) {
        if (strlen(hashTable[i].key) != 0) {
            printf("Index %d -> Key: %s, Value: %s\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].key[0] = '\0';
        hashTable[i].value[0] = '\0';
    }

    insert("apple", "A fruit");
    insert("book", "A source of knowledge");
    insert("cat", "A domestic animal");
    insert("dog", "Another domestic animal");

    display();

    get("book");
    get("cat");
    get("fan"); 

    return 0;
}
