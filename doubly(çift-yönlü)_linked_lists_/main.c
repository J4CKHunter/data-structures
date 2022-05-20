#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
    struct n* prev;
}n;

void print_doublyll(n* node){
    printf("Listeniz: ");
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

n* sirali_ekle(n* node,int x){

    int varmi=0;
    n* iter=node;
    while(iter!=NULL){
        if(iter->data == x)
            varmi=1;

        iter=iter->next;
    }
    if(varmi==1){
        printf("%d sayi var listeye ekleyemezsiniz.\n",x);
        return node;
    }


    else{
        if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->next=NULL;
        node->prev=NULL;
        node->data=x;
        return node;
    }
    else if(node->data > x){
        n* temp=(n*)malloc(sizeof(n));
        temp->prev=NULL;
        temp->next=node;
        temp->data=x;
        node->prev=temp;
        return temp;
    }
    else{

        n* iter=node;
        while(iter->next!=NULL && iter->next->data < x){
            iter=iter->next;
        }
        if(iter->next==NULL){
            n* temp=(n*)malloc(sizeof(n));
            temp->prev=iter;
            temp->next=iter->next;
            temp->data=x;
            iter->next=temp;
            return node;
        }
        else{
            n* temp=(n*)malloc(sizeof(n));
            temp->prev=iter;
            temp->next=iter->next;
            temp->data=x;
            iter->next=temp;
            iter->next->prev=temp;
            return node;
        }

    }

    }
}

n* sil(n* node,int x){

    n* iter=node;
    if(node->data==x){
        node=node->next;
        node->prev=NULL;
        free(iter);
        return node;
    }
    while(iter->next!=NULL && iter->next->data!=x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("%d sayi bulunamadi",x);
    }
    n *temp=iter->next;
    iter->next=iter->next->next;//SONDAYSA NULL
    free(temp);
    if(iter->next!=NULL)
        iter->next->prev=iter;
    return node;

}

int main()
{
    n* root=NULL;
    root=sirali_ekle(root,15);
    root=sirali_ekle(root,5);
    root=sirali_ekle(root,10);
    root=sirali_ekle(root,0);
    root=sirali_ekle(root,20);
    root=sirali_ekle(root,10);
    print_doublyll(root);
    root=sil(root,0);
    printf("\n0");
    print_doublyll(root);
    root=sil(root,20);
    printf("\n20");
    print_doublyll(root);
    root=sil(root,10);
    printf("\n10");
    print_doublyll(root);
    root=sil(root,35);
    printf("\n35");
    print_doublyll(root);

}
