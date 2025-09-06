#include<stdio.h>
#define m 10

int hashset[m];

void init(){
    for(int i=0; i<m ; i++){
        hashset[i] = -1;
    }
}

int f(int key){
    return key % m;
}

void add(int key){
    int index = f(key);
    if(hashset[index] == -1){
        hashset[index] = key;
        return;
    }
    else if(hashset[index] == key){
        printf("Key already exists.\n");
        return;
    }
    else{
        // collision
        for(int probe =1; probe < m; probe++){
            int i = (index + probe) % m; //linear probing
            if(hashset[i] == -1){
                hashset[i] = key;
                return;
            }
            if(hashset[i] == key){
                printf("Key already exist.\n");
                return;
            }
        }
        printf("Hashset is full.\n");
    }
}

int conatins(int key){
    int index = f(key);
    if(hashset[index] == -1){
        return -1;
    }
    else if(hashset[index] == key){
        return 1;
    }
    else{
        for(int probe=1 ; probe<m ; probe++){
            int i = (index + probe) % m;
            if(hashset[i] == -1){
                return -1;
            }
            if(hashset[i] == key){
                return 1;
            }
        }
        return -1;
    }
}

void display(){
    printf("\n");
    for(int i=0; i<m ; i++){
        printf("%d    ",hashset[i]);
    }
}

void main(){
    init();
    add(10);
    add(10);
    add(20);
    add(45);
    add(44);
    printf("Hashset has 20? : %d\n", conatins(20));
    printf("Hashset has 45? : %d\n", conatins(45));
    printf("Hashset has 89? : %d\n", conatins(89));
    display();
}