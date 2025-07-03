/* 
* @file Proje1.c 
* @description fonksiyonların içerikleri yazılır.
* @assignment proje 1
* @date 09.12.2023
* @author Ebrar Elmas Yıldız- ebrarelmas.yildiz@stu.fsm.edu.tr
*/
// Proje1.c
#include "Proje1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dersayisi 10

Ders yeniDers(char *dersAdi, unsigned short int kredi, unsigned short int puan)
{
    Ders yeniDers;
    yeniDers.dersAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniDers.dersAdi, dersAdi);
    yeniDers.kredi = kredi;
    yeniDers.puan = puan;
    return yeniDers;
    bellekIadeDers(&yeniDers);
}

Ogrenci yeniOgrenci(char *ogrAdi, char *ogrSoyAdi, char *bolumu, Ders *aldigiDersler)
{
    Ogrenci yeniOgrenci;
    yeniOgrenci.ogrAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.ogrAdi, ogrAdi);
    yeniOgrenci.ogrSoyAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.ogrSoyAdi, ogrSoyAdi);
    yeniOgrenci.bolumu = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.bolumu, bolumu);

    yeniOgrenci.aldigiDersler = aldigiDersler;
    return yeniOgrenci;
    bellekIadeOgrenci(&yeniOgrenci);
}

void ogrenciBilgisiYazdir(Ogrenci ogrenci)
{

    printf("Ogrenci Adi: %s %s\n", ogrenci.ogrAdi, ogrenci.ogrSoyAdi);
    printf("Bolumu: %s\n", ogrenci.bolumu);
    int not = 0;
    int toplamkredi = 0;
    for (int i = 0; i < dersayisi; i++)//ogrencinin not ortalamasını kredi puanlarına göre hesaplamak için
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {

            toplamkredi += ogrenci.aldigiDersler[i].kredi;
            not += (ogrenci.aldigiDersler[i].puan * ogrenci.aldigiDersler[i].kredi);
        }
    }
    int ort = not / toplamkredi;
    printf("Ortalama: %d\n", ort);

    for (int i = 0; i < dersayisi; ++i)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {
            printf("%s: Kredi %d, Puan %d\n", ogrenci.aldigiDersler[i].dersAdi,
                   ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
        }
    }
}

void ogrenciDizisiYazdir(Ogrenci *ogrenciler, int ogrenciSayisi)//dizideki ogrencilerin hepsini yazdırmak için
{
    for (int i = 0; i < ogrenciSayisi; ++i)
    {
        ogrenciBilgisiYazdir(ogrenciler[i]);
        printf("\n");
    }
}

void ogrenciBilgisiRead(Ogrenci ogrenci)//dosyadan okuma işlemlerinde kullanılacak olan fonksiyon
{
    printf("\nOgrenci Adi: %s %s\nBolumu:%s\n ", ogrenci.ogrAdi, ogrenci.ogrSoyAdi, ogrenci.bolumu);

    for (int i = 0; i < 3; ++i)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {
            printf("ders adi:%s   ", ogrenci.aldigiDersler[i].dersAdi);
            printf("Kredi: %hd   ", ogrenci.aldigiDersler[i].kredi);
            printf("Puan: %hd\n ", ogrenci.aldigiDersler[i].puan);
        }
        
    }
}

void ogrenciDizisiRead(Ogrenci *ogrenciler, int ogrenciSayisi)//dosyadan okuma işlemlerinde kullanılacak olan fonksiyon,okuma sonrası okunanları terminale yazar
{
    for (int i = 0; i < ogrenciSayisi; ++i)
    {
        ogrenciBilgisiRead(ogrenciler[i]);
        printf("\n");
    }
}

float dersOrtalama(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAd)//tum ogrenciler dizisini dolaşarak bir derse ait ortalamayı hesaplar.
{
    float toplamPuan = 0;
    int ogrenciSayac = 0;

    for (int i = 0; i < ogrenciSayisi; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAd) == 0)
            {

                toplamPuan += ogrenciler[i].aldigiDersler[j].puan;
                ogrenciSayac++;
                break;
            }
        }
    }

    if (ogrenciSayac == 0)
    {
        printf("Belirtilen derse ait veri bulunamadi.\n");
        return -1;
    }

    return toplamPuan / ogrenciSayac;
}

float dersStandartSapma(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi)//bir derse ait standart sapmayı hesaplar.
{
    float ortalama = dersOrtalama(ogrenciler, ogrenciSayisi, dersAdi);
    float toplamKareFark = 0.0;
    int ogrenciSayac = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < ogrenciSayisi; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0)
            {

                float fark = ogrenciler[i].aldigiDersler[j].puan - ortalama;
                toplamKareFark += fark * fark;
                ogrenciSayac++;
                break;
            }
        }
    }

    if (ogrenciSayac == 0)
    {
        return -1; // Standart sapma hesaplanamaz.
    }

    return sqrt(toplamKareFark / ogrenciSayac);
}

float dersKovaryans(Ders ders1, Ders ders2, Ogrenci *ogrenciler, int ogrenciSayisi)//iki dersin kovaryansını hesaplar
{
    float ortDers1 = dersOrtalama(ogrenciler, ogrenciSayisi, ders1.dersAdi);
    float ortDers2 = dersOrtalama(ogrenciler, ogrenciSayisi, ders2.dersAdi);

    float kovaryans = 0.0;
    int ogrenciSayisi1 = 0;
    int ogrenciSayisi2 = 0;
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, ders1.dersAdi) == 0)
            {
                float fark1 = ogrenciler[i].aldigiDersler[j].puan - ortDers1;
                for (int k = 0; k < 10; k++)
                {
                    if (strcmp(ogrenciler[i].aldigiDersler[k].dersAdi, ders2.dersAdi) == 0)
                    {
                        float fark2 = ogrenciler[i].aldigiDersler[k].puan - ortDers2;
                        kovaryans += fark1 * fark2;
                        ogrenciSayisi1++;
                        ogrenciSayisi2++;
                        break;
                    }
                }
                break;
            }
        }
    }
    if (ogrenciSayisi1 == 0 || ogrenciSayisi2 == 0)
    {
        printf("Kovaryans hesaplanamiyor. Yetersiz veri.\n");
        return -1;
    }

    return (kovaryans / (ogrenciSayisi1 - 1));
}

void yuksekNotAlanOgrencileriListele(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi)//bir dersin ortalamasından yüksek alan ogrencileri listeler
{

    float ortalama = dersOrtalama(ogrenciler, ogrenciSayisi, dersAdi);
    if (ortalama == -1)
    {
        return;
    }
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0)
            {
                if (ogrenciler[i].aldigiDersler[j].puan > ortalama)
                {
                    printf("%s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
                }
                break;
            }
        }
    }
}

void writeOgrenciToFile(char *dosyaAdi, Ogrenci *ogrenciler, int ogrenciSayisi)//dosyaya yazdırma işlemini yapar
{
    FILE *dosya = fopen(dosyaAdi, "w");

    if (dosya == NULL)
    {
        printf("Hata: Dosya acilamadi.\n");
        return;
    }

    for (int i = 0; i < ogrenciSayisi; i++)//listedeki öğrencileri dosyaya yazdırmak için ogrenci sayisi kadar döngü kurulur
    {
        fprintf(dosya, "%s %s %s ", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi, ogrenciler[i].bolumu);

        for (int j = 0; j < 10; j++)//max 10 ders olduğu varsayılır
        {
            if (ogrenciler[i].aldigiDersler[j].dersAdi != NULL)//ders adı var boş değilse yazma işlemi devam eder
            {
                fprintf(dosya, "%s %d %d ", ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
            }
        }

        fprintf(dosya, "\n");
    }

    fclose(dosya);
    printf("ogrenci bilgileri yazildi.\n");
}

Ogrenci *readOgrenciFromFile(char *dosyaAdi, int *size)//dosyadan bilgileri okuyan fonksiyon.
{
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL)
    {
        perror("Dosya açma hatasi");
        exit(EXIT_FAILURE);
    }

    // Dosyanın kaç öğrenci içerdiğini öğrenmek için ilk geçiş
    int tempSize = 0;
    char line[1024];
    while (fgets(line, sizeof(line), dosya) != NULL)
    {
        tempSize++;
    }
    rewind(dosya);

    *size = tempSize;

    // Öğrenci dizisi için bellek ayırma
    Ogrenci *ogrenciArray = (Ogrenci *)malloc(tempSize * sizeof(Ogrenci));//gerekli bellek ayırmaları için

    if (ogrenciArray == NULL)
    {
        perror("Bellek ayirma hatasi");
        exit(EXIT_FAILURE);
    }

    // Dosyadan okuma işlemi
    for (int i = 0; i < tempSize; i++)
    {
        ogrenciArray[i].ogrAdi = (char *)malloc(256 * tempSize * sizeof(char));
        ogrenciArray[i].ogrSoyAdi = (char *)malloc(256 * tempSize * sizeof(char));
        ogrenciArray[i].bolumu = (char *)malloc(256 * tempSize * sizeof(char));
        ogrenciArray[i].aldigiDersler = (Ders *)malloc(10 * sizeof(Ders));
        fscanf(dosya, "%s %s %s", ogrenciArray[i].ogrAdi, ogrenciArray[i].ogrSoyAdi, ogrenciArray[i].bolumu);//okuma yapılır

        for (int j = 0; j < 3; j++)
        { 
            ogrenciArray[i].aldigiDersler[j].dersAdi = (char *)malloc(256 * sizeof(char));
           fscanf(dosya, "%s %hd %hd", ogrenciArray[i].aldigiDersler[j].dersAdi, &ogrenciArray[i].aldigiDersler[j].kredi, &ogrenciArray[i].aldigiDersler[j].puan);
            
        }
    }

    fclose(dosya);
    return ogrenciArray;
}

void bellekIadeOgrenci(Ogrenci *ogrenci)
{
    free(ogrenci->aldigiDersler);
    free(ogrenci->ogrAdi);
    free(ogrenci->ogrSoyAdi);
    free(ogrenci->bolumu);
}

void bellekIadeDers(Ders *ders)
{
    free(ders->dersAdi);
}
