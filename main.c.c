#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Zaman bilgilerini saklayan yapý
typedef struct {
    int yil, ay, gun, saat, dakika, saniye;
} TarihSaat;

// Yapý ve epoch zamanýný bir arada tutan birlik (union)
typedef union {
    TarihSaat tarihSaat;
    time_t epoch;
} ZamanDonusturucu;

// Zamaný epoch zamanýna çeviren fonksiyon
time_t epochCevir(const TarihSaat *tarihSaat) {
    struct tm zamanBilgisi = {0};
    zamanBilgisi.tm_year = tarihSaat->yil - 1900;
    zamanBilgisi.tm_mon = tarihSaat->ay - 1;
    zamanBilgisi.tm_mday = tarihSaat->gun;
    zamanBilgisi.tm_hour = tarihSaat->saat;
    zamanBilgisi.tm_min = tarihSaat->dakika;
    zamanBilgisi.tm_sec = tarihSaat->saniye;
    zamanBilgisi.tm_isdst = -1;

    time_t sonuc = mktime(&zamanBilgisi);
    if(sonuc == -1) {
        fprintf(stderr, "Gecersiz tarih/saat girisi!\n");
        exit(EXIT_FAILURE);
    }
    return sonuc;
}

// Koþu süresini hesaplayan fonksiyon
void kosuSuresiHesapla(time_t baslangicZamani) {
    time_t bitisZamani;
    char giris;

    printf("Kosu basladi! Kosu bittiginde 'B' tusuna basin...\n");

    while (1) {
        scanf(" %c", &giris); // Kullanýcýdan giriþ al
        if (giris == 'B' || giris == 'b') {
            bitisZamani = time(NULL); // B tuþuna basýldýðýnda bitiþ zamanýný kaydet
            break;
        } else {
            printf("Gecersiz giris! Lutfen 'B' tusuna basin.\n");
        }
    }

    double gecenSure = difftime(bitisZamani, baslangicZamani); // Geçen süreyi hesapla

    // Süreyi saat, dakika ve saniye cinsine çevir
    int saat = (int)gecenSure / 3600;
    int dakika = ((int)gecenSure % 3600) / 60;
    int saniye = (int)gecenSure % 60;

    printf("Kosu suresi: %02d saat %02d dakika %02d saniye\n", saat, dakika, saniye);
}

int main() {
    ZamanDonusturucu baslangicZamani;

    // Baþlangýç zamanýný kaydet
    baslangicZamani.epoch = time(NULL);

    // Koþu süresini hesapla
    kosuSuresiHesapla(baslangicZamani.epoch);

    return 0;
}
