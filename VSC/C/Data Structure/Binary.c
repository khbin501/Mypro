#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int arr[MAX],front = 0, rear = 0, count =0;

void inQue(int arr[],int data){
    if(count == MAX){
        printf("Queue is full\n");
        return;
    }
    arr[rear] = data;
    rear = (rear+1) % MAX;
    count++;
}

int deQue(int arr[]){
    if(count <= 0){
        printf("Queue is empty");
        exit(1);
    }
    int result = arr[front];
    arr[front] = 0;
    front = (front+1) % MAX;
    count--;

    return result;

}


void printQue(int arr[]){
    for(int i=0; i<MAX; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    inQue(arr,1);
    inQue(arr,2);
    inQue(arr,3);
    inQue(arr,4);
    inQue(arr,5);
    
    printQue(arr);

    deQue(arr);
    deQue(arr);

    printQue(arr);

    deQue(arr);
    deQue(arr);

    printQue(arr);

    deQue(arr);

    return 0;
}
