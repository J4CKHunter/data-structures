#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
}n;

void print_linkedlist(n* node){
    printf("Linked Listiniz: ");
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

void sona_ekle(n* node){

    int sayi,girdi_sayisi;

    printf("sona kac sayi eklemek istersiniz?\n");
    scanf("%d",&girdi_sayisi);
    printf("sirayla sayilari girin\n");

    for(int i=0;i<girdi_sayisi;i++){
        scanf("%d",&sayi);
        while(node->next!=NULL){
            node=node->next;
        }

        node->next=(n*)malloc(sizeof(n));
        node=node->next;
        node->data=sayi;
        node->next=NULL;
    }
}

n* araya_ekle(n* node){
// FONKSÝYONUN TÝPÝNÝ N* YAPTIK KÝ ROOT DEÐÝÞÝRSE,MAÝNE YOLLAYIP GÜNCELLEYELÝM
    int sira,sayi;

    printf("kacinci siraya ekleme yapmak istersiniz?\n");
    scanf("%d",&sira);

    printf("hangi sayiyi eklemek istiyorsunuz?\n");
    scanf("%d",&sayi);

    if(sira==1){
        n* temp=(n*)malloc(sizeof(n));
        temp->data=sayi;
        temp->next=node;
        return temp;
        //BURADA EN BAÞA EKLEDÝK.ROOT DEÐÝÞTÝ.ROOT ARTIK TEMPÝ GÖSTERÝYOR.TEMPÝN NEXTÝ ROOTU.
        //ROOT DEÐÝÞTÝÐÝ ÝÇÝN MAÝNDE GÜNCELLEMEMÝZ LAZIM.VOÝD YAPARSAK MAÝNDE HALA BAÞTAKÝ ROOTUN ADRESÝ TUTULUR.
    }

    else{
        n* iter=node;
        //BURADA DA NODE=NODE->NEXT DÝYEREK NODEU ÝLERLETÝYORUZ ÝSTEDÝÐÝMÝZ YERE ERÝÞMEK ÝÇÝN.
        //EGER RETURN NODE DERSEK KALDIÐI YERÝ ROOT OLARAK KABUL EDER BAÞTAKÝ BÝLGÝLER KAYBOLUR BELLEKTE.
        for(int i=0;i<sira-2;i++){
            iter=iter->next;
        }
        n* temp=(n*)malloc(sizeof(n));
        temp->next=iter->next;
        iter->next=temp;
        temp->data=sayi;

        return node;
    }

}
int main()
{
    n* root=(n*)malloc(sizeof(n));
    root->data=500;
    root->next=NULL;

    sona_ekle(root);
    print_linkedlist(root);

    sona_ekle(root);
    print_linkedlist(root);

    root=araya_ekle(root);
    print_linkedlist(root);

}
