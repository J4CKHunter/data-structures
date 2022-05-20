#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int boyut;
    int* dizi;

}stack;

stack* stackOlustur(int boyut){
    printf("%d Boyutlu stack olusturuldu.\n",boyut);
    stack* x=(stack*)malloc(sizeof(stack));
    x->boyut=boyut;
    x->top=-1;
    x->dizi=(int*)malloc(x->boyut*sizeof(int));
    return x;
}

stack* stackOlustur_default(){
    printf("Default stack olusturuldu.\n");
    stack* x=(stack*)malloc(sizeof(stack));
    x->boyut=2;
    x->top=-1;
    x->dizi=(int*)malloc(x->boyut * sizeof(int));
    return x;
}

int dolu_mu(stack* x){

    if(x->boyut-1 == x->top)
        return 1;
    else
        return 0;

}

int bos_mu(stack* x){
    if(x->top==-1)
        return 1;
    else
        return 0;

}

void push(stack* x,int d){

    if(dolu_mu(x)){
        printf("Stack dolu.Stack boyutu arttiriliyor.\n");
        x->boyut=x->boyut*2;
        int *dizi2=(int*)malloc(x->boyut *sizeof(int));
        for(int i=0; i <= x->top ;i++){
            dizi2[i]=x->dizi[i];
        }
        free(x->dizi);
        x->dizi=dizi2;
    }
    printf("Veri ekleniyor.\n");
    x->dizi[++x->top]=d;
    printf("%d Veri eklendi.\n",d);
}

int pop(stack* x){
    if(bos_mu(x))
        return -2147483648;
    if(x->top <= (x->boyut)/4 && x->boyut > 2){
        printf("Boyut azaltiliyor.\n");
        int *dizi2=(int*)malloc(x->boyut/2 *sizeof(int));
        for(int i=0; i <= x->top ;i++){
            dizi2[i]=x->dizi[i];
        }
        free(x->dizi);
        x->dizi=dizi2;
        x->boyut/=2;
        printf("Boyut azaltildi.Yeni boyut = %d\n",x->boyut);
    }
    printf("%d Veri cikarildi.",x->dizi[x->top--]);
    return x->dizi[x->top];

}

void print_stack_ozellik(stack* x){
    printf("\nStack ozellikleri :\n");
    printf("Boyut = %d\n",x->boyut);
    printf("Eleman sayisi = %d\n",x->top+1);
    if(x->top==-1)
        printf("Top = \n");
    else
        printf("Top = %d\n",x->dizi[x->top]);
    printf("Elemanlar = ");
    for(int i=0;i <= x->top ;i++){
        printf("%d ",x->dizi[i]);
    }
    printf("\n\n");

}

int main()
{
    stack* yigin=stackOlustur_default();
    print_stack_ozellik(yigin);

    for(int i=0;i<16;i++){
        push(yigin,i*5+3);
        print_stack_ozellik(yigin);
    }
    for(int i=0;i<16;i++){
        pop(yigin);
        print_stack_ozellik(yigin);
    }

}
