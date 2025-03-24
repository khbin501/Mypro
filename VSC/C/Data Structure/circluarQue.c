#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int arr[MAX], front = 0, rear = 0, count = 0;

// inQue
// Description: Inserts a value into the circular queue
// Input: The value to insert (queue is a global structure)
// Output: -1 if queue is full, 0 otherwise
int inQue(int data) {
    if (count == MAX) {
        return -1;
    }
    arr[rear] = data;
    rear = (rear + 1) % MAX;
    count++;
    return 0;
}

// deQue
// Description: Removes the front value from the circular queue
// Input: None (queue is a global structure)
// Output: The value dequeued, or -1 if the queue is empty
int deQue() {
    if (count <= 0) {
        return -1;
    }
    int result = arr[front];
    arr[front] = 0;
    front = (front + 1) % MAX;
    count--;
    return result;
}

// printQue
// Description: Prints all values in the queue array
// Input: None (uses global array)
// Output: None
void printQue() {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);  // main에서 호출되므로 출력 유지
    }
    printf("\n");
}

int main() {
    int cmd;
    while (1) {
        printf("1.enqueue, 2.dequeue, 3.exit : ");
        scanf("%d", &cmd);

        if (cmd == 1) {
            int val;
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            if (inQue(val) == -1) {
                printf("queue is full\n");
            } else {
                printf("queue : ");
                printQue();
            }
        } else if (cmd == 2) {
            int result = deQue();
            if (result == -1) {
                printf("queue is empty\n");
            } else {
                printf("dequeue value is %d\n", result);
                printf("queue : ");
                printQue();
            }
        } else if (cmd == 3) {
            break;
        } else {
            printf("invalid command\n");
        }
    }

    return 0;
}
