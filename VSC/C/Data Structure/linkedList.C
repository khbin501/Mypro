#include <stdio.h>
#include <stdlib.h>


// ?? ??? ??
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ??? ?? ??
Node* creatNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(!newNode){
        printf("??? ?? ??\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ??? ?? ?? ??
void appendNode(Node** head, int data){
    Node* newNode = creatNode(data);

    //??? ??? ??
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    //???? ??
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}    

//???? ?? ??
void insertNode(Node** head, int newKey){
    int fail = -1;
    Node* prve = NULL;
    Node* temp = *head;

    Node* newNode = creatNode(newKey);

    while(temp){
        if(temp->data == newKey){
            printf("?? ?? ??\n");
            break;
        }

        if(temp->data < newKey){
            prve = temp;
            temp = temp->next;
        }
        else{
            prve->next = newNode;
            newNode->next = temp;
            printf("? ?? ??\n");
            break;
        }
    }
}


// ?? ?? ?? ??
void deleteNode(Node** head, int key){
    Node* temp = *head;
    Node* prve = NULL;

    // ??? ??? ? ?? ??? ??
    if(!temp && temp->data == key){
        *head = temp->next;
        free(temp);
    }

    // ??? ??? ??
    while(temp != NULL && temp->data != key){
        prve = temp;
        temp = temp->next;
    }


    // ??? ???? ?? ??
    if(temp == NULL) return;

    // ?? ??
    prve->next = temp->next;
    free(temp); 
}

//?? ??
void searchNode(Node** head, int key){
    int found=0;
    Node* temp = *head;
    while(temp){
        if(temp->data==key){
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 1){
        printf("??? ???\n");
    }
    else printf("??? ????\n");
}



// ??? ??

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


// ??? ??

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    

Node* head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    
    printf("?? ???: ");
    printList(head);

    searchNode(&head,20);
    insertNode(&head,25);
    printList(head);
    freeList(head);
    return 0;
}