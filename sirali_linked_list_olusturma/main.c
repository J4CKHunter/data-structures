#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
}n;

n* sirali_ekle(n* node,int x){

    // ilk eleman boþsa,yani listede eleman yoksa
    if(node==NULL){

        node=(n*)malloc(sizeof(n));
        node->next=NULL;
        node->data=x;
        return node;

    }

    // ilk eleman,girilen deðerden büyükse;root deðiþmeli yeni deðer root olmalý.
    if(node->data > x){

        n* temp=(n*)malloc(sizeof(n));
        temp->next=node;
        temp->data=x;
        return temp;

    }

    // listede herhangi iki sayýnýn arasýndaysa ve girilen değer ilk elemandan büyükse
    n* iter=node;
    while(iter->next!=NULL && iter->next->data < x){
       iter=iter->next;
    }
    n* temp=(n*)malloc(sizeof(n));
    temp->data=x;
    temp->next=iter->next;
    iter->next=temp;
    return node;

}

void print_linkedlist(n* node){

    printf("Listeniz: ");

    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }

}

int main()
{
    n* root=NULL;

    root=sirali_ekle(root,10);
    root=sirali_ekle(root,20);
    root=sirali_ekle(root,30);

    print_linkedlist(root);
    printf("\n\n%d",root->next->next->next);
}
