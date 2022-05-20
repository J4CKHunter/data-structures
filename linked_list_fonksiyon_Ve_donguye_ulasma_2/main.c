#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;

}n;

void print_linkedlist(n* node){

    while(node!=NULL){

        printf("%d ",node->data);
        node=node->next;
    }
}

int main()
{
    // en sonki versiyonda yaparsak iter nulla kadar gider.
    // eleman eklememiz için nulldan önceki nodeda durup onun nextine yeni bir node açmalıyız.
    // bunun kontrolünün yapmak için şöyle bir yol izliyoruz :

    n* root=(n*)malloc(sizeof(n));
    root->data=15;

    root->next=(n*)malloc(sizeof(n));
    root->next->data=25;

    root->next->next=(n*)malloc(sizeof(n));
    root->next->next->data=35;

    root->next->next->next=NULL;// sonuncusunun nexti belki ramde dolu bir yeri gösterir
    // o yüzden biz elle null atýyoruz ki bittiðini belirtelim.

    n* iter=root;


    while(iter->next!=NULL){

        iter=iter->next;
        // while(iter!=NULL) yaparsak iter nullda kalır.
        // burada nulldan bir öncekine kadar gidiyoruz ki onun nextine yeni bir tane node ekleyebilelim.

    }

    int sayi;
    printf("kac elemanli linked list eklemek istersiniz? :");
    scanf("%d",&sayi);


    for(int i=0;i<sayi;i++){

        iter->next=(n*)malloc(sizeof(n));
        iter=iter->next;
        iter->data=i*10;
        iter->next=NULL;

        // en son pointerın başında kalmıştık.onun sonunda da null vardı.
        // burada o pointerın null değerine yeni bir node açtık.
        // sonra iteri o nodea ilerlettik ve içindeki datayı koyduk.nextini de nulladık.

    }

    print_linkedlist(root);
}
