#include<stdio.h>

struct priority_q{
    int data;
    int priority;
};

struct priority_q queue[5];

int front = -1;
int rear = -1;

void enqueue(int x, int y){
    if(rear == 4){
        printf("Queue Overflow");
        return;
    }
    rear++;
    queue[rear].data = x;
    queue[rear].priority = y;
    if(front == -1){
        front = 0;
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue Underflow");
        return;
    }
    int max_i = front;
    for(int i = front+1 ; i <= rear ; i++){
        if(queue[i].priority > queue[max_i].priority){
            max_i = i;
        }
    }
    printf("Deleted Element is: { %d : %d }\n", queue[max_i].data, queue[max_i].priority);
    for(int i = max_i; i<=rear ; i++){
        queue[i] = queue[i+1];
    }
    rear--;
}

void display(){
    if(front == -1){
        printf("Queue is Empty");
        return;
    }
    for(int i = front ; i <= rear ; i++){
        printf("{%d : %d}\n", queue[i].data, queue[i].priority);
    }
}

void main(){
    enqueue(10, 5);
    enqueue(20, 3);
    enqueue(30, 7);
    enqueue(20,7);
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
}