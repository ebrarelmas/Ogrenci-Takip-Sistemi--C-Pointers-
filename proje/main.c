/* 
* @file main.c 
* @description fonksiyonları çağırılır ve test edilir.
* @assignment proje 1
* @date 09.12.2023
* @author Ebrar Elmas Yıldız- ebrarelmas.yildiz@stu.fsm.edu.tr
*/
//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Proje1.h"
//#include "Proje1.c"

int main(int argc, char *argv[])
{   
        if (argc != 2) {
            fprintf(stderr, "Kullanim: %s <dosya_adi>\n", argv[0]);
            return 1;
        }
        
    // Örnek derslerin ve ogrencilerin oluşturulması
    Ders ders1 = yeniDers("Matematik", 3, 60);
    Ders ders2 = yeniDers("Fizik", 4, 40);
    Ders ders3 = yeniDers("Kimya", 4, 75);
    Ders ogrenci1Dersleri[10] = {ders1, ders2, ders3};
    Ogrenci ogrenci1 = yeniOgrenci("Ebrar", "Yildiz", "Bilgisayar", ogrenci1Dersleri);

    Ders ders4 = yeniDers("Matematik", 3, 30);
    Ders ders5 = yeniDers("Fizik", 4, 60);
    Ders ders8 = yeniDers("Kimya", 4, 70);
    Ders ogrenci2Dersleri[10] = {ders4, ders5,ders8};
    Ogrenci ogrenci2 = yeniOgrenci("Akgun", "Gokalp", "Insaat", ogrenci2Dersleri);

    Ders ders6 = yeniDers("Matematik", 3, 80);
    Ders ders7 = yeniDers("Fizik", 3, 20);
    Ders ders9= yeniDers("Kimya", 4, 40);
    Ders ogrenci3Dersleri[10] = {ders6, ders7,ders9};
    Ogrenci ogrenci3 = yeniOgrenci("Yagmur", "Kara", "Elektrik", ogrenci3Dersleri);

    Ogrenci ogrencilers[] = {ogrenci1, ogrenci2, ogrenci3};
    int boyut = sizeof(ogrencilers) / sizeof(ogrencilers[0]);//dizide kaç eleman olduğunu bulma
 
   /*
    
     // 3. soru: Parametre olarak Ogrenci türünden değişken alıp bilgilerini yazdıran.
    ogrenciBilgisiYazdir(ogrenci1);
    printf("\n");
    ogrenciBilgisiYazdir(ogrenci2);
    printf("\n");
    ogrenciBilgisiYazdir(ogrenci3);
    printf("\n");

    // 4. soru: Parametre olarak Ogrenci türünden dinamik bir dizi alıp bilgilerini yazdıran.
    ogrenciDizisiYazdir(ogrencilers, boyut);

    char fizik[] = "Fizik";
    char matematik[] = "Matematik";
    char Kimya[]="Kimya";


    // 5. soru: Parametre olarak aldığı dersAdi değerine göre bir dersin aritmetik ortalamasını hesaplayan.
    printf("%s Dersi Ortalamasi: %.2f\n", fizik, dersOrtalama(ogrencilers, boyut, fizik));
    printf("%s Dersi Ortalamasi: %.2f\n", matematik, dersOrtalama(ogrencilers, boyut, matematik));
    printf("*******************************\n");


    //6.soru:Parametre olarak aldığı dersAdi değerine göre bir dersin standart sapması
    printf("%s Dersi Standart Sapmasi: %.2f\n",fizik,dersStandartSapma(ogrencilers, boyut, fizik));
    printf("%s Dersi Standart Sapmasi: %.2f\n",matematik,dersStandartSapma(ogrencilers, boyut, matematik));
    printf("*******************************\n");


    // 7.soru:Parametre olarak aldığı Ders türünden iki dersin kovaryansını hesaplayan
    printf("%s ve %s derslerinin kovaryansi: %.2f\n",ders1.dersAdi,ders2.dersAdi, dersKovaryans(ders1, ders2,ogrencilers,boyut));
    printf("*******************************\n");

 
   //8. Belirli bir dersin ortalama puanından yüksek not alan öğrencileri listeleme
    printf("%s dersinden ortalama uzerinde not alan ogrenciler:",matematik);
    yuksekNotAlanOgrencileriListele(ogrencilers, boyut, matematik);
  */
 

    // 9. soru: Tüm öğrenci bilgilerini bir dosyaya yazan.
    writeOgrenciToFile(argv[1], ogrencilers, boyut);

    //10. soru: Tüm öğrenci bilgilerini bir dosyaya yazan.
    Ogrenci *ogrenciArray = readOgrenciFromFile(argv[1], &boyut);
    ogrenciDizisiRead(ogrenciArray, boyut);
    
    

    for (int i = 0; i < boyut; i++)
    {
        free(ogrenciArray[i].ogrAdi);
        free(ogrenciArray[i].ogrSoyAdi);
        free(ogrenciArray[i].bolumu);
    }
    free(ogrenciArray);

  
    return 0;
}
