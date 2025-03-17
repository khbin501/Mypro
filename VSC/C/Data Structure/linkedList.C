#include <stdio.h>
#include <stdlib.h>


// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 새로운 노드 생성
Node* creatNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(!newNode){
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트 끝에 노드 추가
void appendNode(Node** head, int data){
    Node* newNode = creatNode(data);

    //첫번째 노드일 경우
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    //일반적인 경우
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}    

//리스트에 노드 삽입
void insertNode(Node** head, int newKey){
    int fail = -1;
    Node* prve = NULL;
    Node* temp = *head;

    Node* newNode = creatNode(newKey);

    while(temp){
        if(temp->data == newKey){
            printf("키가 이미 있음\n");
            break;
        }

        if(temp->data < newKey){
            prve = temp;
            temp = temp->next;
        }
        else{
            prve->next = newNode;
            newNode->next = temp;
            printf("키 삽입 완료\n");
            break;
        }
    }
}


// 특정 값의 노드 삭제
void deleteNode(Node** head, int key){
    Node* temp = *head;
    Node* prve = NULL;

    // 삭제할 노드가 첫 번째 노드인 경우
    if(!temp && temp->data == key){
        *head = temp->next;
        free(temp);
    }

    // 삭제할 노드를 찾기
    while(temp != NULL && temp->data != key){
        prve = temp;
        temp = temp->next;
    }


    // 노드가 존재하지 않는 경우
    if(temp == NULL) return;

    // 노드 삭제
    prve->next = temp->next;
    free(temp); 
}

//노드 검색
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
        printf("키값을 찾았음\n");
    }
    else printf("키값을 찾지못함\n");
}



// 리스트 출력

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


// 메모리 해제

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
    
    printf("연결 리스트: ");
    printList(head);

    searchNode(&head,20);
    insertNode(&head,25);
    printList(head);
    freeList(head);
    return 0;
}
