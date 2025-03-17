#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //set max index

int arr[MAX]={0}, front=-1,rear=-1;


void enqueque(int value){ // enqueue value
    if(front == -1){
        front = 0;
    }
    arr[++rear] = value;

}
int dequeue(){ // dequeue value
    int dequeue_value = arr[front];
    arr[front++] = 0;
    return dequeue_value;
}

int queue_full(){ // check overflow
    if(rear >= MAX-1){
        return -1;
    }
    else return 0;
}

int queue_empty(){ // check underflow
    if(front > rear || rear == -1){ 
        return -1;
    }
    else return 0;
}



int main(){
    int num = 1;
    while(num == 1 || num == 2){ //selection point
        printf("1,enQueue, 2,deQueue 3,exit\n");
        printf("type number : ");
        scanf("%d",&num);

        if(num == 1){
            int check = queue_full(); // check overflow
            if( check == -1){
                printf("queue is full\n");
                continue;
            }
            printf("type enqueue value: "); // start enqueue
            int value;
            scanf("%d",&value);
            enqueque(value);
            printf("queue content : "); // print content
            for(int i=0; i<=rear; i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            printf("\n");
        }
        if(num == 2){
            if(queue_empty() == -1){ // check underflow
                printf("queue is empty\n");
                continue;
            }
            int queue_Value = dequeue(); // start dequue and print dequeue value
            printf("dequeue value is %d \n",queue_Value);

            printf("queue content : "); //print content
            for(int i=0; i<=rear; i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            printf("\n");
        }
        

}

    return 0;
}   