#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
}n;

void print_dairesel_linkedlist(n* node){

    printf("Listeniz: ");

    if(node==NULL){
        printf("listede eleman yoktur.\n");
    }

    else{
        n* iter=node;
        printf("%d ",iter->data);
        iter=iter->next;

        while(iter!=node){
            printf("%d ",iter->data);
            iter=iter->next;
        }
        printf("\n");
    }

}

n* dairesel_sona_ekle(n* node,int x){

    if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->data=x;
        node->next=node;
        return node;
    }
    else{
        n* iter=node;
        iter=iter->next;

        while(iter->next!=node){
            iter=iter->next;
        }
        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=node;
        iter->next=temp;
        return node;
        }
}
//10 20 30 40 50
n* dairesel_sirali_ekle(n* node,int x){

    n* iter=node;

    if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->data=x;
        node->next=node;
        return node;
    }
    else if(node->data > x){
        while(iter->next!=node){
            iter=iter->next;
        }
        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=node;
        iter->next=temp;
        return temp;
    }
    else{

        while(iter->next!=node && iter->next->data < x){
            iter=iter->next;
        }
        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=iter->next;
        iter->next=temp;
        return node;
    }
}

n* dairesel_silme(n* node,int x){

    if(node->data==x){
        n* iter=node;
        n* temp;
        if(node->next==node){
            free(node);
            return NULL;
        }
        while(iter->next!=node){
            iter=iter->next;
        }
        iter->next=iter->next->next;
        temp=node->next;
        free(node);
        return temp;
    }
    else{
        n* iter=node;
        while(iter->next!=node && iter->next->data!=x){
            iter=iter->next;
        }
        if(iter->next==node){
            printf("%d sayi bulunamadi\n",x);
            return node;
        }
        n* temp=iter->next;
        iter->next=iter->next->next;
        free(temp);
        return node;
    }

}
int main()
{
    n* root=NULL;
    n* root2=NULL;

    root=dairesel_sona_ekle(root,98);
    root=dairesel_sona_ekle(root,15);
    root=dairesel_sona_ekle(root,5);

    print_dairesel_linkedlist(root);

    printf("\n");

    root2=dairesel_sirali_ekle(root2,10);
    root2=dairesel_sirali_ekle(root2,-5);
    root2=dairesel_sirali_ekle(root2,0);
    root2=dairesel_sirali_ekle(root2,-15);
    root2=dairesel_sirali_ekle(root2,15);
    root2=dairesel_sirali_ekle(root2,5);
    root2=dairesel_sirali_ekle(root2,-10);

    print_dairesel_linkedlist(root2);


    root2=dairesel_silme(root2,120);
    root2=dairesel_silme(root2,15);
    root2=dairesel_silme(root2,-10);
    root2=dairesel_silme(root2,15);
    root2=dairesel_silme(root2,0);
    root2=dairesel_silme(root2,98);
    print_dairesel_linkedlist(root2);

    printf("\n");

    n* root3=NULL;

    root3=dairesel_sirali_ekle(root3,15);
    print_dairesel_linkedlist(root3);

    root3=dairesel_silme(root3,15);
    print_dairesel_linkedlist(root3);
}
