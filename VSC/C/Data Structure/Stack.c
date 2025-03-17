#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int arr[MAX],top = -1;

void push(int arr[],int data){
    if(top > MAX){
        printf("stack is full");
        return;
    }
    arr[++top] = data;
}
int pop(int arr[]){
    if(top < 0){
        printf("stack is empty");
        exit(1);
    }
    int result = arr[top];
    arr[top--] = 0;
    printf("poo data is %d \n",result);
    return  result;
}

void printStack(int arr[]){
    for(int i=0; i<MAX; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){

    push(arr,1);
    push(arr,3);
    push(arr,5);
    push(arr,10);

    printStack(arr);

    pop(arr);
    pop(arr);
    pop(arr);

    printStack(arr);
    return 0;
}