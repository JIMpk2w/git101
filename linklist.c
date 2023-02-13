#include <stdio.h>
#include <stdlib.h>

struct Node__{
    int value;
    struct Node__* next;
};

typedef struct Node__ Node;
typedef Node* NodePtr;

void printList(NodePtr start){
    NodePtr current = start;
    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("\n");
}

void addFirst(NodePtr* startPtr, int value){
    NodePtr temp = (NodePtr) malloc(sizeof(Node));
    temp -> value = value;

    // if didnt typedef will be 
    // Node* tmp = (Node*)malloc(sizeof(Node__));

    if(*startPtr == NULL){
        temp->next = NULL;
    }else{
        temp->next = *startPtr;
    }

    *startPtr = temp;
}

void addLast(NodePtr* startPtr, int value){

    NodePtr temp = (NodePtr) malloc(sizeof(Node));
    temp -> value = value;
    temp -> next = NULL;

    if(*startPtr == NULL){
        *startPtr = temp;
    }else{
        NodePtr current = *startPtr;
        while(current->next != NULL){
            current = current -> next;
        }
        current->next = temp;
    }
}
int main(){
    NodePtr startPtr;
    startPtr = NULL;

    addLast(&startPtr, 0);   
    addFirst(&startPtr, 10);
    addFirst(&startPtr, 20);
    addFirst(&startPtr, 30);
    addLast(&startPtr, 100);
    addLast(&startPtr, 200);

    printList(startPtr);
    return 0;
}