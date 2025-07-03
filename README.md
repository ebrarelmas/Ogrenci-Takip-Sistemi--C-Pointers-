Bu projede, C programlama dilinde yapılar(struct), işaretçiler(pointers) ve dinamik bellek kullanarak problem çözme becerinizi geliştirmeniz 
beklenmektedir. Projeyi çalıştırabilmek için terminali açıp "make" yazacaksınız sonrasında "./Proje1 ornek.txt" yazacaksınız ve böylelikle 
öğrenci ilgileri ilgili txt dosyasına kaydedilecek

Ders veri yapısı, “dersAdi” adında char türünden dinamik bir dizi (boyutu 
256) ve "kredi” ve “puan” adında unsigned short int türünden veriler 
içermektedir.  
Ogrenci veri yapısı “ogrAdi”, “ogrSoyAdi” ve “bolumu” adlarında char türünden 
dinamik birer dizi (boyutu 256), ortalama adında float tipinden bir veri ve 
Ders veri yapısı tipinden “aldigiDersler” adında dinamik bir dizi (boyutu 
10) içermektedir. 
Fonksiyonlar ve yapılar harici dosyalarda tutulmalıdır. Bunları “Proje1.h” 
ve “Proje1.c” dosyalarına uygun şekilde ayırarak yerleştirmeniz gereklidir.  
Parametre olarak gönderilen ya da oluşturulan diziler dinamik olarak heap’te 
tutulmalıdır ve gerekli yerlerde alınan bellek alanları iade edilmelidir. 
main fonksiyonunun bulunduğu dosyada, (main.c) sadece veriler oluşturulup 
fonksiyonların testi yapılacaktır. Bu dosya içerisinde yazacağınız bütün 
fonksiyonlar denenmelidir.  
Aşağıda verilen işlemleri yapan fonksiyonları yazınız: 
1. İlgili değerleri alıp bir Ders struct döndüren. 
2. İlgili değerleri alıp bir Ogrenci struct döndüren. 
3. Parametre olarak Ogrenci türünden değişken alıp bilgilerini yazdıran. 
4. Parametre olarak Ogrenci türünden dinamik bir dizi alıp bilgilerini 
yazdıran. 
5. Parametre olarak aldığı dersAdi değerine göre bir dersin aritmetik 
ortalamasını hesaplayan. 
6. Parametre olarak aldığı dersAdi değerine göre bir dersin standart 
sapmasını hesaplayan. 
7. Parametre olarak aldığı Ders türünden iki dersin kovaryansını hesaplayan. 
8. Parametre olarak aldığı dersAdi değerine göre bir dersin ortalama 
puanından daha yüksek not almış öğrencileri listeleyen. 
9. Tüm öğrenci bilgilerini bir dosyaya yazan. 
10. Program başladığında bu dosyayı okumalı ve dosyadaki öğrencileri bir 
Ogrenci dizisine eklemelidir. Dosya adı Command Line Parameter olarak 
gönderilmelidir. Yani programda dosya adı ve konumunu main’de verilen 
argümanlardan okumalısınız. 
İşlemler bitirildikten sonra bir Makefile dosyası hazırlayınız. Bu dosya 
yapmış olduğunuz kod dosyalarını derleyip çalıştırılabilir bir dosya 
oluşturmalıdır.
