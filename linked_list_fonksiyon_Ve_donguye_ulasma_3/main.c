#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n* next;

}n;

void ekle(n* node,int x){

    while(node->next!=NULL){
        node=node->next;
    }

    node->next=(n*)malloc(sizeof(n));
    node=node->next;
    node->data=x;
    node->next=NULL;

}
void print_linkedlist(n* node){

    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
}
int main()
{
    n* root=(n*)malloc(sizeof(n));
    root->data=500;
    root->next=NULL;

    int sayi;
    printf("kac eleman eklemek istersiniz?:");
    scanf("%d",&sayi);

    for(int i=0;i<sayi;i++){
        ekle(root,i*10);
    }

    print_linkedlist(root);
}
