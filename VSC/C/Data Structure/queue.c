#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int arr[MAX] = {0}, front = -1, back = -1;

void inQue(int arr[], int data) {
    if (back > MAX - 1) {
        printf("queue is full");
        return;
    }

    if (front == -1) {
        front = 0;
    }
    arr[++back] = data;
}

int deQue(int arr[]) {
    if (back < front || back == -1) {
        printf("queue is empty");
        exit(1);
    }

    int result = arr[front];
    arr[front++] = 0;
    return result;
}

void printQue(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    inQue(arr, 1);
    inQue(arr, 2);
    inQue(arr, 3);

    printQue(arr);

    deQue(arr);
    deQue(arr);

    printQue(arr);

    return 0;
}