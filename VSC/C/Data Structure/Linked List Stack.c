#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;
int count = MAX;


void push(int value){
    Node *newList = (Node *)malloc(sizeof(Node));
    if (newList == NULL){
        printf("Creating newList Fail\n");
        return;
    }

    newList->data = value;
    newList->next = top;
    top = newList;
    count++;

}

int pop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    
    Node *tmp = top;
    int popData = tmp->data;
    top = top->next;
    free(tmp);
    count--;

    return popData;
}

int stack_full(){
    if(count == MAX ){
        return -1;
    }
    else return 0;
}

int stack_empty(){
    if(count == 0){
        return -1;
    }
    else return 0;
}

void stackPrint(){
    if(top == NULL){
        printf("end");
        return;
    }
    Node *currunt = top;
    printf("stack index : ");
    while(currunt != NULL){
        printf("%d ",currunt->data);
        currunt = currunt->next;
    }
    printf("\n");

}



int main(){

    push(20);
    push(33);
    push(55);
    
    stackPrint();

    pop();
    pop();

    stackPrint();


    return 0;
}