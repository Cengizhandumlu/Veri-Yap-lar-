#include <stdio.h>
#include <stdlib.h>

struct hucre{
    int icerik;
    struct hucre *sonraki;
};

struct hucre *hucreolustur(int icerik){
    struct hucre *a;
    a=(struct hucre*)malloc(sizeof(struct hucre));
        if(a==NULL){
            printf("hesap alaninda yer ayrilamadi...\n");
            exit(1);
        }
        a->icerik=icerik;
        a->sonraki=NULL;
        return a;
    }
void listebasinaekle(int icerik,struct hucre **listebasi){
    struct hucre *a=hucreolustur(icerik);
    a->sonraki=*listebasi;
    *listebasi=a;
}

void listeyazdir(struct hucre *listebasi){
    while(listebasi!=NULL){
        printf("%4d",listebasi->icerik);
        listebasi=listebasi->sonraki;
    }
    printf("\n");
}

void listeyi_yok_et(struct hucre **listebasi){
    struct hucre *simdiki;
    while(*listebasi!=NULL){
        simdiki=(*listebasi);
        (*listebasi)=(*listebasi)->sonraki;
        free(simdiki);
    }


}

int main()
{
    struct hucre *liste1=NULL;

    listebasinaekle(20,&liste1);
    listebasinaekle(40,&liste1);
    listebasinaekle(60,&liste1);
    listebasinaekle(80,&liste1);
    listebasinaekle(100,&liste1);

    listeyazdir(liste1);

    listeyi_yok_et(&liste1);

    printf("--------------\n");

    listeyazdir(liste1);


    return 0;
}
