#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct n{

    int data;
    struct n* next;

}n;

void enqueue(n* q,int x){

    if(q==NULL){

        printf("Queue bos.Queue olusturuluyor.\n");
        q=(n*)malloc(sizeof(n));
        q->data=x;
        q->next=NULL;
        printf("%d veri eklendi.\n",q->data);

    }
    else{

        n* iter=q;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        n* temp=(n*)malloc(sizeof(n));
        temp->data=x;
        temp->next=NULL;
        iter->next=temp;
        printf("%d data eklendi\n",temp->data);

    }
}

int dequeue(n* q){

    if(q==NULL){
        printf("Queue bos.(dequeue)\n");
        return INT_MIN;
    }
    if(q->next==NULL){
        int rvalue=q->data;
        q=NULL;
        return rvalue;
    }

    n* iter=q;
    q=q->next;
    int rvalue=iter->data;
    free(iter);
    return rvalue;

}

void print_queue(n* q){

    if(q==NULL)
        printf("Queue bos.(print_queue)\n");

    else{

        printf("Queue = ");

        while(q!=NULL){
            printf("%d ",q->data);
            q=q->next;
        }

        printf("\n");

    }
}
int main()
{
    n* q=NULL;

    print_queue(q);
    dequeue(q);

    for(int i=0;i<10;i++){
        enqueue(q,i+1);
        print_queue(q);
    }

    for(int i=0;i<13;i++){
        printf("%d veri dequeued.\n"),dequeue(q);
        print_queue(q);
    }


}
