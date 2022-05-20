#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n* sol;
    struct n* sag;
}n;

n* ekle(n* agac,int x){

    if(agac==NULL){
        agac=(n*)malloc(sizeof(n));
        agac->sag=NULL;
        agac->sol=NULL;
        agac->data=x;
        return agac;
    }

    if(x > agac->data){
        agac->sag=ekle(agac->sag,x);
        return agac;
    }

    else{
        agac->sol=ekle(agac->sol,x);
        return agac;
    }


}

n* sil(n* agac,int x){

    if(agac==NULL)
        return NULL;

    if(agac->data == x){

        if(agac->sol==NULL && agac->sag==NULL){
            return NULL;
        }

        if(agac->sag!=NULL){

            agac->data=min_bul(agac->sag);
            agac->sag=sil(agac->sag,min_bul(agac->sag));
            return agac;

        }

        if(agac->sol!=NULL){

            agac->data=max_bul(agac->sol);
            agac->sol=sil(agac->sol,max_bul(agac->sol));
            return agac;

        }

    }

    if(x > agac->data){
        agac->sag=sil(agac->sag,x);
        return agac;

    }

    if(x < agac->data){
        agac->sol=sil(agac->sol,x);
        return agac;
    }

}

void dolas(n* agac){

    if(agac==NULL)
        return;
    // LNR

    dolas(agac->sol);
    printf("%d ",agac->data);
    dolas(agac->sag);



    // bunlarýn yerlerini degistirerek olusturuyoruz
    // lnr rnl rln lrn nlr nrl hepsini ,bu kadar

}

int var_mi(n* agac,int x){
    if(agac==NULL)
        return -1;

    if(agac->data==x)
        return 1;

    if(var_mi(agac->sol,x)==1)
        return 1;

    if(var_mi(agac->sag,x)==1)
        return 1;

    return -1;


}

int min_bul(n* agac){

    while(agac->sol!=NULL)
        agac=agac->sol;

    return agac->data;

}

int max_bul(n* agac){

    while(agac->sag != NULL)
        agac=agac->sag;

    return agac->data;


}
int main()
{

    n* agac=NULL;

    dolas(agac);

    agac=ekle(agac,56);
    agac=ekle(agac,200);
    agac=ekle(agac,26);
    agac=ekle(agac,190);
    agac=ekle(agac,213);
    agac=ekle(agac,18);
    agac=ekle(agac,28);
    agac=ekle(agac,12);
    agac=ekle(agac,24);
    agac=ekle(agac,27);


    dolas(agac);
    printf("\n10 var mi = %d",var_mi(agac,10));
    printf("\n24 var mi = %d",var_mi(agac,24));
    printf("\nmax= %d   min= %d",min_bul(agac),max_bul(agac));

    printf("\n");
    agac=sil(agac,56);
    dolas(agac);

    printf("\n");
    agac=sil(agac,213);
    dolas(agac);

    printf("\n");
    agac=sil(agac,27);
    dolas(agac);


}
