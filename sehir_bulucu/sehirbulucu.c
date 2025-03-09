#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *sehirDosya, *kodDosya;
    int sehir_sayisi = 7;  // Şehir sayısını değişken olarak tanımlıyoruz
    int max_uzunluk = 50;  // Maksimum karakter uzunluğu
    char sehirler[7][50];  // 7 şehir için dizi
    int trafikKodlari[7];  // 7 trafik kodu için dizi
    int i, girilenKod, bulundu = 0;

    // Dosyaları aç
    sehirDosya = fopen("sehirler.txt", "r");
    kodDosya = fopen("trafik_kodlari.txt", "r");

    if (sehirDosya == NULL || kodDosya == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }

    if (sehirDosya == NULL || kodDosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // Dosyalardan verileri oku
    for (i = 0; i < sehir_sayisi; i++) {
        fscanf(sehirDosya, "%s", sehirler[i]);
        fscanf(kodDosya, "%d", &trafikKodlari[i]);
    }

    fclose(sehirDosya);
    fclose(kodDosya);

    // Kullanıcıdan trafik kodu al
    printf("Trafik kodunu girin: ");
    scanf("%d", &girilenKod);

    // Girilen kodu listede ara
    for (i = 0; i < sehir_sayisi; i++) {
        if (trafikKodlari[i] == girilenKod) {
            printf("%s", sehirler[i]);
            bulundu = 1;
            printf(" Dogu karadeniz bolgesinde yer alir.");
            break;
        }
    }

    // Eğer kod bulunamazsa
    if (!bulundu) {
        printf("Gecersiz trafik kodu!\n");
    }
    return 0;
}