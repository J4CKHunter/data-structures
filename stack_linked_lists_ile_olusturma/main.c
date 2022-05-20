#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct n{
    int data;
    struct n* next;
}n;

n* push(n* node,int x){

    if(node==NULL){
        printf("Stack bos (PUSH).Stack olusturuluyor.\n");
        node=(n*)malloc(sizeof(n));
        node->data=x;
        node->next=NULL;
        printf("%d Pushlanan veri.\n",node->data);
        return node;
    }

    n* iter=node;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    n* temp=(n*)malloc(sizeof(n));
    temp->data=x;
    temp->next=NULL;
    iter->next=temp;
    printf("%d Pushlanan veri.\n",temp->data);
    return node;

}

int pop(n* node){

    if(node==NULL){
        printf("Stack bos.(POP)\n");
        return -1;
    }

    n* iter=node;

    if(iter->next==NULL){
        if(iter->data==INT_MIN){
            return INT_MIN;
        }
        int popped_value=node->data;
        node->data=INT_MIN;
        printf("%d popped veri.\n",popped_value);
        return popped_value;
    }
    while(iter->next->next != NULL){
        iter=iter->next;
    }
    n* temp=iter->next;
    int popped_value=temp->data;
    iter->next=NULL;
    free(temp);
    printf("%d popped veri.\n",popped_value);
    return popped_value;

}

void print_stack(n* node){

    if(node==NULL)
        printf("Stack = Stack bos.\n");


    else if(node->data == INT_MIN)
        printf("Stack = \n");

    else{
        printf("Stack =");
        while(node!=NULL){
            printf("%d ",node->data);
            node=node->next;
        }
        printf("\n");
    }
}

int main()
{
    n* root=NULL;

    pop(root);
    print_stack(root);

    for(int i=0;i<10;i++){
        root=push(root,i+1);
        print_stack(root);
    }

    for(int i=0;i<15;i++){
        pop(root);
        print_stack(root);
    }


}
