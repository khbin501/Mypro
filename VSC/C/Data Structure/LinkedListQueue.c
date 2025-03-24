#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
int count = 0;

// enqueue
// Description: Inserts a value into the queue
// Input: The value to enqueue (queue is a global structure)
// Output: -1 if memory allocation fails or queue is full, 0 otherwise
int enqueue(int value) {
    if (count == MAX) {
        return -1;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
    return 0;
}

// dequeue
// Description: Removes the front value from the queue and returns it
// Input: None (operates on global front/rear)
// Output: The value dequeued, or -1 if the queue is empty
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    Node *tmp = front;
    int dequeueValue = tmp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(tmp);
    count--;
    return dequeueValue;
}

// printQueue
// Description: Prints all elements in the queue from front to rear
// Input: None (uses global front pointer)
// Output: None
void printQueue() {
    Node *curr = front;
    while (curr != NULL) {
        printf("%d ", curr->data);  
        curr = curr->next;
    }
}

int main() {
    int cmd;

    while (1) {
        printf("1.enqueue, 2.dequeue, 3.exit : ");
        scanf("%d", &cmd);

        if (cmd == 1) {
            int val;
            scanf("%d", &val);
            if (enqueue(val) == -1) {
                printf("fail\n");
            } else {
                printf("queue : ");
                printQueue();
                printf("\n");
            }
        } else if (cmd == 2) {
            int result = dequeue();
            if (result == -1) {
                printf("fail\n");
            } else {
                printf("dequeue value is %d\n", result);
                printf("queue : ");
                printQueue();
                printf("\n");
            }
        } else if (cmd == 3) {
            break;
        } else {
            printf("invalid command\n");
        }
    }

    return 0;
}
