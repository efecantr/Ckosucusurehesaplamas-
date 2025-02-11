# Ckosucusurehesaplaması
C dilinde, bir koşucunun her gün sabit bir rotada koştuğu mesafeyi ne kadar sürede tamamladığını hesaplayan ve koşucunun gelişimini takip etmesine yardımcı olan programım.

Değişken İsimleri ve Açıklamaları:
ZamanDonusturucu: TimeConverter yerine kullanıldı.
TarihSaat ve epoch zamanını bir arada tutar.

epochCevir: convertToEpoch yerine kullanıldı. 
Tarih bilgisini epoch zamanına çevirir.

kosuSuresiHesapla: calculateRunDuration yerine kullanıldı. 
Koşu süresini hesaplar ve ekrana yazdırır.

baslangicZamani: startTime yerine kullanıldı. Koşunun başlangıç zamanını tutar.

bitisZamani: endTime yerine kullanıldı. Koşunun bitiş zamanını tutar.

gecenSure: duration yerine kullanıldı. Geçen süreyi tutar.



Programın Çalışma Mantığı:


Program başladığında, baslangicZamani.epoch değişkenine mevcut zaman kaydedilir.

Kullanıcıdan "B" tuşuna basması beklenir.

Kullanıcı "B" tuşuna bastığında, bitisZamani kaydedilir ve başlangıç zamanı ile arasındaki fark hesaplanır.

Geçen süre saat, dakika ve saniye cinsinden ekrana yazdırılır.
