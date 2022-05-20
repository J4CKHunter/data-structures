#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    int height;
    struct n* sag;
    struct n* sol;

}n;

int height(n* node){

    if(node == NULL)
        return 0;
    return node->height;
}

int max(int a,int b){
    return (a > b) ? a : b; // a > b ise a yı döndür , değilse b yi döndür
}


/*

y (sol taraf) veya x (sað taraf) pivotlarý ile döndürülecek
alt aðaçlar T1, T2 ve T3'dür.

     y                  x
    / \                / \
   x   T3    =>       T1  y
  / \                    /  \
 T1 T2                  T2  T3

*/
n* sagaDondur(n* y){

    n* x=y->sol;
    n* t2=x->sag;

    x->sag=y;
    y->sol=t2;

    y->height=max(height(y->sol),height(y->sag))+1;
    x->height=max(height(x->sol),height(x->sag))+1;

    return x;

}

/*
y (sol taraf) veya x (sað taraf) pivotlarý ile döndürülecek
alt aðaçlar T1, T2 ve T3'dür.

    y              x
   / \            / \
  x   T3    <=   T1  y
 / \                / \
T1  T2             T2  T3

*/

n* solaDondur(n* x){

    n* y=x->sag;
    n* t2=y->sol;

    y->sol=x;
    x->sag=t2;

    x->height=max(height(x->sol),height(x->sag))+1;
    y->height=max(height(y->sol),height(y->sag))+1;

    return y;
}

int dengeFaktoru(n* node){

    if(node == NULL)
        return 0;
    return height(node->sol) - height(node->sag);
}

n* ekle(n* node,int x){

    if(node == NULL){

        n* node=(n*)malloc(sizeof(n));

        node->data=x;
        node->sol=NULL;
        node->sag=NULL;
        node->height=1;

        return node;

    }

    if(x < node->data){
        node->sol=ekle(node->sol,x);
    }

    else if(x > node->data){

        node->sag=ekle(node->sag,x);
    }

    else
        return node;

    node->height=max(height(node->sol),height(node->sag))+1;

    int denge=dengeFaktoru(node);

    if(denge > 1 && x < node->sol->data)
        return sagaDondur(node);

    if(denge < -1 && x > node->sag->data)
        return solaDondur(node);

    if(denge > 1 && x > node->sol->data){
        node->sol=solaDondur(node->sol);
        return sagaDondur(node);
    }

    if(denge < -1 && x < node->sag->data){
        node->sag=sagaDondur(node->sag);
        return solaDondur(node);
    }

    return node;

}

void bastir(n* node){
    if(node != NULL){
        printf("%d ",node->data);
        bastir(node->sol);
        bastir(node->sag);
    }
}

int main()
{
    n* root=NULL;

    root=ekle(root,10);
    root=ekle(root,20);
    root=ekle(root,30);
    root=ekle(root,40);
    root=ekle(root,50);
    root=ekle(root,25);

    bastir(root);
    printf("\n%d",root->height);
}
