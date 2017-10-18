#include <stdio.h>
#include <stdlib.h>
struct dugum{
int icerik;
struct dugum *sol;
struct dugum *sag;
};

struct ikiliAramaAgaci{
    struct dugum *kok;
};

void ikiliAramaAgaciOlustur(struct ikiliAramaAgaci **agac){
    *agac=(struct ikiliAramaAgaci*)malloc(sizeof(struct ikiliAramaAgaci));
    if(*agac==NULL){
        printf("yer ayrilamadi...");
        exit(1);
    }
    else
        (*agac)->kok=NULL;
}

int ikiliAgacBosmu(struct ikiliAramaAgaci *agac){
    if(agac->kok==NULL)
        return 1;
    else
        return 0;
}

struct dugum *dugumOlustur(int icerik){
    struct dugum *d=(struct dugum*)malloc(sizeof(struct dugum));
    if(d==NULL)
        printf("yer ayrilamadi...\n");
    else
        d->icerik=icerik;
        d->sol=d->sag=NULL;
        return d;
};
void ekle(struct ikiliAramaAgaci *agac,int icerik){
    struct dugum *d;
    struct dugum *geri;
    struct dugum *dugum;

    d=agac->kok;
    while(d!=NULL){
        geri=d;
        if(icerik<d->icerik)
            d=d->sol;
        else if(icerik>d->icerik)
            d=d->sag;
        else
            return;
    }
    dugum=dugumOlustur(icerik);
    if(agac->kok==NULL){
        agac->kok=dugum;
        return;
    }if(icerik<geri->icerik)
        geri->sol=dugum;
    else
        geri->sag=dugum;

}

void ineorderYardimci(struct dugum *kok){
    if(kok==NULL)
        return;
    ineorderYardimci(kok->sol);
    printf("%d ",kok->icerik);
    ineorderYardimci(kok->sag);
}

void ineorder(struct ikiliAramaAgaci *agac){
if(agac==NULL)
    return;
ineorderYardimci(agac->kok);
printf("\n");
}


int main()
{
    struct ikiliAramaAgaci *agac=NULL;
    ikiliAramaAgaciOlustur(&agac);

    ekle(agac,15);
    ekle(agac,28);
    ekle(agac,31);
    ekle(agac,2);
    ekle(agac,500);
    ekle(agac,87);

    ineorder(agac);

    return 0;
}
