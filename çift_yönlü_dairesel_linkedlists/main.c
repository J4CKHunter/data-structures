#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
    struct n* prev;

}n;

void yazdir(n* node){
    if(node==NULL){
        printf("Listede eleman yoktur.");
    }
    else{
        printf("Listeniz: %d",node->data);
        n* iter=node->next;
        while(iter!=node){
            printf(" %d",iter->data);
            iter=iter->next;
        }
        printf("\n");
    }
}

n* sona_ekle(n* node,int x){
    if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->next=node;
        node->prev=node;
        node->data=x;
        return node;
    }

    n* iter=node;
    while(iter->next!=node){
        iter=iter->next;
    }
    n* temp=(n*)malloc(sizeof(n));
    temp->data=x;
    temp->next=iter->next;
    temp->prev=iter;
    iter->next->prev=temp;
    iter->next=temp;

    return node;

}

n* sirali_ekle(n* node,int x){

    if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->next=node;
        node->prev=node;
        node->data=x;
        return node;
    }

    if(node->data > x){

        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=node;
        temp->prev=node->prev;
        node->prev->next=temp;
        node->prev=temp;
        return temp;
    }

    n* iter=node;
    while(iter->next!=node && iter->next->data < x ){
        iter=iter->next;
    }
    n* temp=(n*)malloc(sizeof(n));
    temp->data=x;
    temp->prev=iter;
    temp->next=iter->next;
    iter->next->prev=temp;
    iter->next=temp;
    return node;
}

n* sil(n* node,int x){

    if(node->data == x ){
        n* iter=node->next;
        if(iter==node){
            free(node);
            free(iter);
            return NULL;
        }
        iter->prev=node->prev;
        node->prev->next=iter;
        free(node);
        return iter;
    }

    n* iter=node;
    while(iter->next!=node && iter->next->data!=x){
        iter=iter->next;
    }
    if(iter->next==node){
        printf("sayi %d listede bulunamamamistir.\n",x);
        return node;
    }
    n* temp=iter->next;
    iter->next=iter->next->next;
    iter->next->prev=iter;
    free(temp);
    return node;

}

int main()
{
    n* root=NULL;
    root=sona_ekle(root,1);
    root=sona_ekle(root,2);
    root=sona_ekle(root,3);
    root=sona_ekle(root,4);
    root=sona_ekle(root,5);

    yazdir(root);

    n* root2=NULL;
    root2=sirali_ekle(root2,30);
    root2=sirali_ekle(root2,40);
    root2=sirali_ekle(root2,10);
    root2=sirali_ekle(root2,10);
    root2=sirali_ekle(root2,96);
    root2=sirali_ekle(root2,60);
    root2=sirali_ekle(root2,0);

    yazdir(root2);

    root2=sil(root2,0);
    root2=sil(root2,10);
    root2=sil(root2,96);
    root2=sil(root2,150);
    root2=sil(root2,40);
    root2=sil(root2,10);
    root2=sil(root2,30);

    yazdir(root2);

    root2=sil(root2,60);

    yazdir(root2);

}
