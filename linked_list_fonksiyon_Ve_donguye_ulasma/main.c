#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n* next;
}n;

// linked list squential eriþim->dizinin bir elemanýna eriþmek için ondan öncekine eriþmemiz gerekir.
// diziler random eriþim->dizinin istediðimiz elemanýna eriþebiliriz

int main()
{
    n* root=(n*)malloc(sizeof(n));
    root->data=15;

    root->next=(n*)malloc(sizeof(n));
    root->next->data=25;

    root->next->next=(n*)malloc(sizeof(n));
    root->next->next->data=35;

    root->next->next->next=NULL;// sonuncusunun nexti belki ramde dolu bir yeri gösterir
    // o yüzden biz elle null atýyoruz ki bittiðini belirtelim.

    n* iter=root;

    int i=0;
    while(iter!=NULL){

        printf("%d.eleman=%d\n",i,iter->data);
        iter=iter->next;
        i++;

        }

    }


