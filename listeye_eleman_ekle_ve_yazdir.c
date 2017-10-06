#include <stdio.h>
#include <stdlib.h>


struct hucre{
    int icerik;
    struct hucre *sonraki;
};

struct hucre* hucre_olustur(int icerik){
    struct hucre *a;
    a=(struct hucre*)malloc(sizeof(struct hucre));
    if(a==NULL){
        printf("Heap alaninda yer ayrilamadi ...\n");
        exit(1);
    }
    a->icerik=icerik;
    a->sonraki=NULL;
    return a;
}

void liste_basina_ekle(int icerik,struct hucre **liste_basi){
    struct hucre* a=hucre_olustur(icerik);
    a->sonraki=*liste_basi;
    *liste_basi=a;
}

void liste_yaz(struct hucre *liste_basi){
    while(liste_basi!=NULL){
        printf("%4d ",liste_basi->icerik);
        liste_basi=liste_basi->sonraki;
    }
    printf("\n");
}


int main(int argc, char** argv) {

    struct hucre *liste1=NULL;

     liste_basina_ekle(10,&liste1);
     liste_basina_ekle(20,&liste1);
     liste_basina_ekle(30,&liste1);
     liste_basina_ekle(40,&liste1);
     liste_basina_ekle(50,&liste1);
     liste_yaz(liste1);




    return 0;
}

