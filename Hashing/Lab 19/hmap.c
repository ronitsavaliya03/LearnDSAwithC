#include<stdio.h>
#include<string.h>
#define m 10

struct pair{
    char key[10];
    int value;
};

struct pair hashmap[m];

int f(char key[]){ 
    int index = 0;
    for(int i=0; i<strlen(key); i++){
        index = index + key[i];
    }

    printf("Hash function called for key: %s, Index: %d\n", key, index);
    return index % m;
}

void add(char k[], int v){
    int index = f(k);
    if(hashmap[index].key[0] == '\0'){
        //hashmap[index].key = k;
        strcpy(hashmap[index].key, k);
        hashmap[index].value = v;
        return;
    }
    else if(strcmp(hashmap[index].key,k) == 0){
        hashmap[index].value = v;
        return;
    }
    else{
        //collision
        for(int probe=1 ; probe<m ; probe++){
            int i = (index + probe)%m;
            if(hashmap[i].key[0] == '\0'){
                strcpy(hashmap[i].key, k);
                hashmap[i].value = v;
                return;
            }
            if(strcmp(hashmap[i].key, k)==0){
                hashmap[i].value = v;
                return;
            }

        }
        printf("Hashmap is full.\n");
    }
}

int get (char key[]){
    int index = f(key);
    if(strcmp(hashmap[index].key, key) == 0){
        return hashmap[index].value;
    }
    else if(hashmap[index].key[0] == '\0'){
        return -1;
    }
    else{
        for(int probe=1 ; probe<m ; probe++){
            int i = (index + probe)%m;
            if(strcmp(hashmap[i].key, key) == 0){
                return hashmap[i].value;
            }
            if(hashmap[i].key[0] == '\0'){
                return -1;
            }
        }
        return -1;
    } 
}

void main(){
    add("i1",10);
    add("i2",20);
    add("i3",10);
    add("i1",100);
    printf("Value of i1 : %d\n",get("i1"));
    printf("Value of i2 : %d\n",get("i2"));
}

