/* 
* @file Proje1.h
* @description fonksiyonların prototipleri tanımlanır.
* @assignment proje 1
* @date 09.12.2023
* @author Ebrar Elmas Yıldız- ebrarelmas.yildiz@stu.fsm.edu.tr
*/

// Proje1.h
#ifndef PROJE1_H
#define PROJE1_H

typedef struct {
    char* dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
}Ders;

typedef struct {
    char* ogrAdi;
    char* ogrSoyAdi;
    char* bolumu;
    float ortalama;
    Ders* aldigiDersler;
}Ogrenci;

Ders yeniDers(char* dersAdi, unsigned short int kredi, unsigned short int puan);
Ogrenci yeniOgrenci(char* ogrAdi, char* ogrSoyAdi, char* bolumu,  Ders* aldigiDersler);
void ogrenciBilgisiYazdir( Ogrenci ogrenci);
void ogrenciBilgisiRead(Ogrenci ogrenci);
void ogrenciDizisiYazdir( Ogrenci* ogrenciler, int ogrenciSayisi);
void ogrenciDizisiRead(Ogrenci *ogrenciler, int ogrenciSayisi);
float dersOrtalama( Ogrenci* ogrenciler, int ogrenciSayisi, char* dersAdi);
float dersStandartSapma( Ogrenci* ogrenciler, int ogrenciSayisi, char *dersAdi);
float dersKovaryans( Ders ders1,  Ders ders2, Ogrenci* ogrenciler, int ogrenciSayisi);
void yuksekNotAlanOgrencileriListele( Ogrenci* ogrenciler, int ogrenciSayisi, char* dersAdi);
void writeOgrenciToFile(char* dosyaAdi, Ogrenci* ogrenciler, int ogrenciSayisi) ;
Ogrenci* readOgrenciFromFile(char *dosyaAdi, int *size);
void bellekIadeOgrenci(Ogrenci* ogrenciler);
void bellekIadeDers(Ders* ders);
#endif
