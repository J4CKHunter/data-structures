#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
}n;

void print_linkedlist(n* node){

    printf("Listeniz: ");
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

n* sirali_ekle(n* node,int x){



    if(node==NULL){
        node=(n*)malloc(sizeof(n));
        node->data=x;
        node->next=NULL;
        return node;
    }

    int var_mi=0;
    n* iter=node;

    while(iter!=NULL){

        if(iter->data == x){
            printf("%d veri listede var ekleyemezsiniz.\n",x);
            var_mi=1;
        }
        iter=iter->next;

    }


    if(var_mi==0){

        if(node->data > x){
        n* temp=(n*)malloc(sizeof(n));
                temp->data=x;
            temp->next=node;
            return temp;
        }
//10 20 30
        iter=node;
        while(iter->next!=NULL && iter->next->data < x ){
            iter=iter->next;
        }

        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=iter->next;
        iter->next=temp;
        return node;
    }

    return node;

}
//10 20 30 40
n* eleman_sil(n* node,int x){

        n* iter=node;

        if(node->data==x){
            node=node->next;
            free(iter);
            return node;
        }
        else{

            while(iter->next!=NULL && iter->next->data!=x){
                iter=iter->next;
            }
            if(iter->next==NULL){
                printf("sayi %d Listede bulunamadi.\n",x);
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


    root=sirali_ekle(root,10);
    root=sirali_ekle(root,5);
    root=sirali_ekle(root,7);
    root=sirali_ekle(root,15);
    root=sirali_ekle(root,-4);
    root=sirali_ekle(root,10);


    print_linkedlist(root);


    root=eleman_sil(root,15);
    root=eleman_sil(root,-4);
    root=eleman_sil(root,7);
    root=eleman_sil(root,55);
    root=eleman_sil(root,198);

    print_linkedlist(root);

}
