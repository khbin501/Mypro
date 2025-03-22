#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int count = 0;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

// stack_full
// Description: Checks whether the stack has reached its maximum size
// Input: None (uses global count variable)
// Output: -1 if full, 0 otherwise
int stack_full() {
    if (count == MAX) {
        return -1;
    } else
        return 0;
}

// stack_empty
// Description: Checks whether the stack is empty
// Input: None (uses global count variable)
// Output: -1 if empty, 0 otherwise
int stack_empty() {
    if (count == 0) {
        return -1;
    } else
        return 0;
}

// printNode
// Description: Traverses and prints each value in the stack
// Input: None (uses global top pointer)
// Output: None
void printNode() {
    Node *currunt = top;
    while (currunt != NULL) {
        printf("%d ", currunt->data);  
        currunt = currunt->next;
    }
}

// push
// Description: Inserts a value into the stack
// Input: The value to append (stack is a global structure)
// Output: None
int push(int value) {
    Node *newList = (Node *)malloc(sizeof(Node));
    if (newList == NULL || stack_full() == -1) {
        return -1;
    }

    newList->data = value;
    newList->next = top;
    top = newList;
    count++;
    return 0;
}

// pop
// Description: Removes the top value from the stack and returns it
// Input: None (operates on global top)
// Output: The value popped, or -1 if the stack is empty
int pop() {
    if (stack_empty() == -1) {
        return -1;
    }
    Node *tmp = top;
    int popValue = tmp->data;
    top = top->next;
    free(tmp);
    count--;
    return popValue;
}

int main() {
    int x;
    while (1) {
        printf("1.push, 2.pop, 3.exit : ");
        scanf("%d", &x);

        if (x == 1) {
            int value;
            scanf("%d", &value);
            if (push(value) == -1) {
                printf("stack is full\n");
            } else {
                printf("index : ");
                printNode();
                printf("\n");
            }
            printf("\n");
        } else if (x == 2) {
            int popped = pop();
            if (popped == -1) {
                printf("stack is empty\n\n");
            } else {
                printf("pop value is %d\n", popped);
                printf("index : ");
                printNode();
                printf("\n\n");
            }
        } else if (x == 3) {
            break;
        } else {
            break;
        }
    }

    return 0;
}
