#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int en_cok_on_numara_sayilar[81];
int on_numara_sanli_sayilar[10][22];
int gecicidizi[81];
int main()
{
    int i,j,a,k,l,c,cr,toplam,puan=0,rastgele,dizi[10],rdizi[23];
    int ongec,ka,ta,ar,degis,gag,pat,deger,at,ot;
    int on_numara_sayici=0;

    printf("==ON NUMARA OYUNUNA HOSGELDINIZ==\n");
    baslangic:
    for(i=0; i<10; i++)
    {
        printf("%d. sayiyi giriniz: ",i+1);
        scanf("%d",&dizi[i]);
        if(0<=dizi[i] && dizi[i]<=80)
        {

        }
        else
        {
            printf("Hatali sayi girdiniz!\n");
            goto baslangic;
        }
    }
    k = 0;
    while(k<10)
    {
     if(dizi[k]>dizi[k+1])
     {
         int temp;
         temp = dizi [k];
         dizi[k] = dizi[k+1];
         dizi[k+1] = temp;
         k = 0;
     }
     else
     {
         k=k+1;
     }
    }
    printf("==GIRILEN SAYILAR(KUCUKTEN BUYUGE)==");
    for (int index=0; index<10;index++)
    {
        printf("\n%d. = %d\n",index+1,dizi[index]);
    }
    srand(time(0));
j = 1;
while(j<23)
    {
     int gec,p,esit;
     gec = rand()%80;
     esit = 0;
     for(p=0; p<j; p++)
     {
         if(gec == rdizi[p])
         {
             esit=1;
             break;
         }
         else
         {
             esit=0;
         }
     }
     if(esit==0)
     {
         rdizi[j-1]=gec;
		 j++;
     }

    }
      l = 0;
    while(l<22)
    {
     if(rdizi[l]>rdizi[l+1])
     {
         int tem;
         tem = rdizi [l];
         rdizi[l] = rdizi[l+1];
         rdizi[l+1] = tem;
         l = 0;
     }
     else
     {
         l=l+1;
     }
    }

    for(a=0; a<22; a++)
    {
        on_numara_sanli_sayilar[on_numara_sayici][a]=rdizi[a];
    }
    on_numara_sayici++;

    for(ta=on_numara_sayici-1; ta<on_numara_sayici; ta++)
        {
            for(ka=0; ka<22; ka++)
            {
                ongec = on_numara_sanli_sayilar[ta][ka];
                en_cok_on_numara_sayilar[ongec]++;
            }
        }
        for(int tr=0; tr<81; tr++)
        {
        gecicidizi[tr]=en_cok_on_numara_sayilar[tr];
        }

   ar= 0;
    while(ar<81)
    {
     if(gecicidizi[ar+1]>gecicidizi[ar])
     {
         degis = gecicidizi [ar];
         gecicidizi[ar] = gecicidizi[ar+1];
         gecicidizi[ar+1] = degis;
         ar = 0;
     }
     else
     {
         ar=ar+1;
     }
    }
    for(at=0; at<81; at++)
    {
        for(int ot=0; ot<81; ot++)
        {
            if(gecicidizi[at] == en_cok_on_numara_sayilar[ot])
            {
              printf("en cok gelen sayi = %d, gelme sayisi = %d\n",ot+1,en_cok_on_numara_sayilar[ot]);
            }
        }
    }
    printf("==SANSLI SAYILAR(KUCUKTEN BUYUGE)==");

     for(int degisgen=0; degisgen<22;degisgen++)
     {
         printf("\n%d. = %d",degisgen+1,rdizi[degisgen]);
     }
     c=0;
     toplam=0;
     while(c<10)
     {
         for(cr=0; cr<22; cr++)
         {
             if(dizi[c]==rdizi[cr])
             {
                 printf("\nTutturulan sayi = %d\n",dizi[c]);
                 toplam++;
             }
         }
         c++;
     }
     printf("\n Tutturulan sayi sayisi : %d",toplam);
     if(toplam==10)
        {
            puan = puan + 256;
        }
    else if(toplam==9)
    {
        puan = puan + 128;
    }
    else if(toplam==8)
    {
        puan = puan + 64;
    }
    else if(toplam==7)
    {
        puan = puan + 32;
    }
    else if(toplam==6)
    {
        puan = puan + 16;
    }
    printf("\nToplam kazanilan puan : %d\n",puan);

    printf("\n\nYeni bir oyun oynamak ister misiniz?\nEvet icin (e) ye basiniz.\nHayir icin (h) ye basiniz.\n");
    char karakter;
    karakter=getche();
    switch(karakter)
    {
    case 'e':
        goto baslangic;
        break;
    case 'E':
        goto baslangic;
        break;
    case 'h':

    break;
    case 'H':

    break;
    default:
        printf("Gecersiz harf!");
    }
    return 0;
}

