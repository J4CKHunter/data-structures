#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n* next;
}n;

// linked list squential eri�im->dizinin bir eleman�na eri�mek i�in ondan �ncekine eri�memiz gerekir.
// diziler random eri�im->dizinin istedi�imiz eleman�na eri�ebiliriz

int main()
{
    n* root=(n*)malloc(sizeof(n));
    root->data=15;

    root->next=(n*)malloc(sizeof(n));
    root->next->data=25;

    root->next->next=(n*)malloc(sizeof(n));
    root->next->next->data=35;

    root->next->next->next=NULL;// sonuncusunun nexti belki ramde dolu bir yeri g�sterir
    // o y�zden biz elle null at�yoruz ki bitti�ini belirtelim.

    n* iter=root;

    int i=0;
    while(iter!=NULL){

        printf("%d.eleman=%d\n",i,iter->data);
        iter=iter->next;
        i++;

        }

    }


