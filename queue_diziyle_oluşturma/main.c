#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue{

    int* dizi;
    int bas;
    int son;

}queue;

queue* dequeue(queue* q){

    if(q->son==0){
        printf("dequeued data = %d\n",q->dizi[q->bas]);
        q->dizi[q->bas]=INT_MIN;
        return q;
    }
    else{
    int j=0,i=q->bas+1,*dizi2=(int*)malloc(( q->son - q->bas +1 -1 )* sizeof(int));
    printf("dequeued data = %d\n",q->dizi[q->bas]);

    for(i;i <= q->son ;i++){
        dizi2[j]=q->dizi[i];
        j++;
    }
    free(q->dizi);
    q->dizi=dizi2;
    if(q->son == 0)
        return q;
    q->son--;
    return q;
    }
}

queue* enqueue(queue* q,int x){

    if(q==NULL){
        printf("Queue bos.Queue olusturuluyor.\n");
        q=(queue*)malloc(sizeof(queue));
        q->bas=0;
        q->son=0;
        q->dizi=(int*)malloc(sizeof(int));
        q->dizi[q->bas]=x;
        printf("Queue basariyla olusturuldu.\n");
        return q;
    }

    int i=0,*dizi2=(int*)malloc(((q->son)+2) * sizeof(int));
    for(i;i <= q->son ;i++){
        dizi2[i] = q->dizi[i];
    }
    dizi2[i]=x;
    free(q->dizi);
    q->dizi=dizi2;
    q->son=i;

    return q;

}


void print_queue_ozellikler(queue* q){


    if(q->dizi[q->bas]==INT_MIN){
        printf("queue Boyut = 0\n");
        printf("queue bas = %d bastaki eleman = %d\n",q->bas,q->dizi[q->bas]);
        printf("queue son = %d sondaki eleman = %d\n",q->son,q->dizi[q->son]);
        printf("queue = ");
    }
    else{
    printf("queue Boyut = %d\n",q->son-q->bas+1);
    printf("queue bas = %d bastaki eleman = %d\n",q->bas,q->dizi[q->bas]);
    printf("queue son = %d sondaki eleman = %d\n",q->son,q->dizi[q->son]);
    printf("queue = ");
    for(int i=q->bas ; i <= q->son ; i++)
        printf("%d ",q->dizi[i]);
    printf("\n\n");
    }
}

int main()
{
    queue* q = NULL;

    for(int i=0;i<10;i++){
        q=enqueue(q,i+1);
        print_queue_ozellikler(q);
    }

    for(int i=0;i<10;i++){
        q=dequeue(q);
        print_queue_ozellikler(q);
    }
}
