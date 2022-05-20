#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n* next;

}n;


int main()
{

    n* root=(n*)malloc(sizeof(n));
    root->data=10;

    root->next=(n*)malloc(sizeof(n));
    root->next->data=20;

    root->next->next=(n*)malloc(sizeof(n));
    root->next->next->data=30;

    printf("%d %d %d\n",root->data,root->next->data,root->next->next->data);

    n* iter=root;
    printf("%d ",iter->data);

    iter=iter->next;
    printf("%d ",iter->data);

    iter=iter->next;
    printf("%d ",iter->data);

}
