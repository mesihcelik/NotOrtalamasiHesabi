#include <stdio.h>
#include <conio.h>

float diziort(float istdizi[],int dizi_el_sy);  //diziort fonksiyonunun tanýmlanmasý. Bu sayede fonksiyon main içinde çalýþýr hale gelir.
float tskoru(float sinavort,float sinifort,float stsapma);
float tskorudizi(float ilknot[],float tskorulu[],float dizi_el_sy,float stsapma);
float harfnotu(float al_not);

int main()
{

	int dz_el_sy,cikis;	
	float stdsapma;
	
	printf("Can egrisi hesabi icin standart sapma degerini giriniz.\n");
	scanf("%f",&stdsapma);
	printf("Sinava giren kisi sayisini giriniz.\n");
	scanf("%d",&dz_el_sy);
	
	float notlist[dz_el_sy];
	char isimlist[dz_el_sy][20];
	char soyisimlist[dz_el_sy][20];
	float tskorlist[dz_el_sy];
	
	printf("Artarda sira ve alinan not degerini giriniz.Listenizin sonuna geldiginizde yanlis girilen degeri \nkontrol edip tekrar sira ve alinan notu girerek duzeltme yapabilirsiniz.Butun notlari girditen \nsonra -1 girisi yaparak sonuclara ulasabilirsiniz.\n");
	
	int listsira;
	while(listsira!=-1)
	{
		printf("\n-------------------\n");
		printf("Listede kaydolacagi sirayi giriniz.\n");
		scanf("%d",&listsira);
		if(listsira==-1)
		break;
		printf("Sinava giren kisinin Adi \n");
		scanf("%s",&isimlist[listsira-1]);
		printf("Sinava giren kisinin Soyadi \n");
		scanf("%s",&soyisimlist[listsira-1]);
		fflush(stdin);
		printf("Sinava giren kisinin notu.\n");
		scanf("%f",&notlist[listsira-1]);
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n%d.%s %s   Not: %.2f\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",listsira,isimlist[listsira-1],soyisimlist[listsira-1],notlist[listsira-1]);
	}
	
	float snfort;
	snfort=diziort(notlist,dz_el_sy);
	
	printf("\n_________________________________________________________________________________________________________");
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||    NOT TABLOSU    |||||||||||||||||||||||||||||||||||||||||");
	int i;
	for(i=0;i<dz_el_sy;i++)
	{
		tskorlist[i]=tskoru(notlist[i],snfort,stdsapma);
		printf("\n_________________________________________________________________________________________________________");
		printf("\n\n%3d.%s %s",i+1,isimlist[i],soyisimlist[i]);
		printf("\n\n  ALINAN NOT: %6.2f    HARF NOTU: ",notlist[i]);
		harfnotu(notlist[i]);
		printf("    T-SKORU: %6.2f    CAN EGRiSi HARF NOTU: ",tskorlist[i]);
		harfnotu(tskorlist[i]);                
	}
    printf("\n_________________________________________________________________________________________________________");
	printf("\n|||||||||||||||||||||||||||||||||||    Sinifin Not Ortalamasi : %.2f   |||||||||||||||||||||||||||||||||",snfort);
	printf("\n_________________________________________________________________________________________________________");
	
	getch();
	return 0;
}
float diziort(float istdizi[],int dizi_el_sy) //float cinsinde dizinin elemanlarýnýn ortalamasýný alan fonksiyon.Diziismi,Dizinin eleman sayýsý
{	
	int b;
    float bellek,ort;
	for(b=0;b<dizi_el_sy;b++)
	{
		bellek=istdizi[b]+bellek;
	}
    return bellek/dizi_el_sy;
}
float tskoru(float sinavort,float sinifort,float stsapma)          // T-Skoru Hesabý Fonksiyonu
{
	return (((sinavort-sinifort)/stsapma)*10)+50;
}
float harfnotu(float al_not)
{
		if(al_not<35)
	{
		return printf("FF");
	}else if(al_not<45)
	{
		return printf("DD");
	}else if(al_not<50)
	{
		return printf("DC");
	}else if(al_not<55)
	{
		return printf("CC");
	}else if(al_not<63)
	{
		return printf("CB");
	}else if(al_not<71)
	{
		return printf("BB");
	}else if(al_not<80)
	{
		return printf("BA");
	}else if(al_not>=80)
	{
		return printf("AA");
	}
}

