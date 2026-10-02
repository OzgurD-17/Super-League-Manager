#include <fstream>
#include <string>
#include <sstream> // stringstream dosya okuma işlemlerinde belirli veriyi alabilmem için birkaç noktada gerekti
#include <iomanip>
#include <iostream>

using namespace std;

// Takım sınıfı
class Takim {
private:
    
public:

    int takimNO;
    string adi;
    string adresi;
    string telefon;
    int oyuncuSayisi;
    string yoneticiIsmi;

    // Constructor
    Takim() : takimNO(0), adi(""), adresi(""), telefon(""), oyuncuSayisi(0), yoneticiIsmi("")
    {}

    Takim(int no, const string& ad, const string& adres, const string& tel, int oyuncuSay, const string& yonetici)
        : takimNO(no), adi(ad), adresi(adres), telefon(tel), oyuncuSayisi(oyuncuSay), yoneticiIsmi(yonetici) {}

    // Dosyaya yazma fonksiyonu
    void dosyayaYaz(ofstream& dosya) const 
    {
        dosya << takimNO << " " << adi << " " << adresi << " "
        << telefon << " " << oyuncuSayisi << " " << yoneticiIsmi << endl;
    }
    // Dosyayı okuma fonksiyonu
    void dosyayiOku(ifstream& dosya)
    {
        dosya >> takimNO >> adi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;
    }
};

// Futbolcu sınıfı
class Futbolcu {
private:

public:
    int takimNO;
    string TCNO;
    string adi;
    string soyadi;
    string lisansNO;
    string konumu;
    float ucret;
    string dogumTarihi;

    // Constructor
    Futbolcu() : takimNO(0), TCNO(""), adi(""), soyadi(""), lisansNO(""), konumu(""), ucret(0.0), dogumTarihi("")
    {}
    Futbolcu(int tNO,const string& tc, const string& ad, const string& soyad, const string& lisans,
        const string& konum, float ucreti, const string& dogumTarih)
        : takimNO(tNO), TCNO(tc), adi(ad), soyadi(soyad), lisansNO(lisans), konumu(konum), ucret(ucreti), dogumTarihi(dogumTarih) {}

    // Dosyaya yazma fonksiyonu
    void dosyayaYaz(ofstream& dosya) const 
    {
        dosya << takimNO << " " << TCNO << " " << adi << " " << soyadi << " " << lisansNO << " "
        << konumu << " " << ucret << " " << dogumTarihi << endl;
    }
    // Dosyayı okuma fonksiyonu
    bool dosyayiOku(ifstream& dosya)
    {
        if (dosya >> takimNO >> TCNO >> adi >> soyadi >> lisansNO >> konumu >> ucret >> dogumTarihi)
        {
			return true;
		}
        else
        {
			return false;
		}
    }
};

// Fonksiyonlar
void takimOlustur();
void takimSil();
void takimlariListele();
void futbolcuEkle();
void futbolcuSil();
void tumFutbolculariListele();
void takimaGoreFutbolculariListele();
void futbolcuGuncelle();
void futbolOyunuKaydi();
void haftalikKayit();
void haftalikKayitGoruntule();
void haftalikPuanDurumlari();

int main()
{
    setlocale(LC_ALL, "turkish");
    // Ana menü
    int secim;
    do
    {
        cout << "\n---------------------------------------------" << endl
            << "\t SÜPER LİG KONTROL MERKEZİ \t" << endl
            << "---------------------------------------------" << endl << endl
            << "\t     ***-MENÜ-***" << endl << endl
            << "\t1-Takım Oluşturma:" << endl
            << "\t2-Takım Silme:" << endl
            << "\t3-Takımları Listeleme:" << endl
            << "\t4-Takıma Futbolcu Ekleme:" << endl
            << "\t5-Takımdan Futbolcu Silme:" << endl
            << "\t6-Ligdeki Futbolcuları Listeleme:" << endl
            << "\t7-Belirli Bir Takımdaki Futbolcuları Listeleme:" << endl
            << "\t8-Takımdaki Bir Futbolcuyu Güncelleme:" << endl
            << "\t9-Oyuncu Menüsü:" << endl
            << "\t10-Maç Kaydı:" << endl
            << "\t11-Haftalık Lig Kaydı:" << endl
            << "\t12-Haftalık Lig Kaydını Görüntüle:" << endl
            << "\t13-Haftalık Puan Durumları:" << endl
            << "\t0-Çıkış:" << endl << endl
            << "Seçiminiz: ";
        cin >> secim;
        cout << endl;

        switch (secim)
        {
        case 1:
            takimOlustur();
            break;
        case 2:
            takimSil();
            break;
        case 3:
            takimlariListele();
			break;
        case 4:
            futbolcuEkle();
            break;
        case 5:
            futbolcuSil();
            break;
        case 6:
            tumFutbolculariListele();
            break;
        case 7:
            takimaGoreFutbolculariListele();
            break;
        case 8:
            futbolcuGuncelle();
            break;
        case 9:
            // Oyuncu menüsü
            int oyuncuSecim;
            do {
                cout << "Oyuncu Menüsü:\n"
                    << "\t1- Oyuncu Ekleme\n"
                    << "\t2- Oyuncu Silme\n"
                    << "\t3- Oyuncu Güncelleme\n"
                    << "\t4- Oyuncuları Listeleme\n"
                    << "\t0- Ana Menüye Dön\n"
                    << "Seçiminiz: ";
                cin >> oyuncuSecim;
                cout << endl;

                switch (oyuncuSecim)
                {
                case 1:
                    futbolcuEkle();
                    break;
                case 2:
                    futbolcuSil();
                    break;
                case 3:
                    futbolcuGuncelle();
                    break;
                case 4:
                    tumFutbolculariListele();
                    break;
                case 0:
                    break;
                default:
                    cout << "Geçersiz seçim!\n";
                    break;
                }
            } while (oyuncuSecim != 0);
            break;

        case 10:
            futbolOyunuKaydi();
            break;
        case 11:
            haftalikKayit();
            break;
        case 12:
			haftalikKayitGoruntule();
			break;
        case 13:
            haftalikPuanDurumlari();
            break;
        case 0:
            cout << "Programdan çıkılıyor...\n";
            break;
        default:
            cout << "Geçersiz seçim!\n";
            break;
        }
    } while (secim != 0);

    return 0;
}


// Fonksiyonlar

// Takım oluşturma fonksiyonu
void takimOlustur()
{
    // Takım no alma ve kontrol
    Takim T1;
    cout << "Takım no girin: \n";
    cin >> T1.takimNO;
    cout << endl;
    if (T1.takimNO <= 0)
    {
		cout << "Takım no en az 1 olmalı!\n";
		return;
	}

    // Girilen takım no'ya sahip takım zaten var mı kontrol
    Takim T2;
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var mı (oluşturulmuş mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T2.takimNO >> T2.adi >> T2.adresi >> T2.telefon >> T2.oyuncuSayisi >> T2.yoneticiIsmi)
        {
            if (T1.takimNO == T2.takimNO)
            {
                cout << "Bu takım no'ya sahip takım zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();
    
    cout << "Takım adı girin: \n";
    cin >> T1.adi;

    // Girilen takım adına sahip takım zaten var mı kontrol
    Takim T3;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var mı (oluşturulmuş mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T3.takimNO >> T3.adi >> T3.adresi >> T3.telefon >> T3.oyuncuSayisi >> T3.yoneticiIsmi)
        {
            if (T1.adi == T3.adi)
            {
                cout << "Bu takım adına sahip takım zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();

    cout << "Takım adresini girin: \n";
    cin >> T1.adresi;
    cout << "Takım telefon numarasını girin: \n";
    cin >> T1.telefon;
    cout << "Takımdaki oyuncu sayısını girin: \n";
    cin >> T1.oyuncuSayisi;
    cout << "Takım yöneticisinin adını girin: \n";
    cin >> T1.yoneticiIsmi;

    ofstream dosyaYaz;
    dosyaYaz.open("takimlar.txt", ios::app);
    //dosyaYaz.write(reinterpret_cast<char*>(&T1), sizeof(T1));
    T1.dosyayaYaz(dosyaYaz);
    dosyaYaz.close();
}
// Takım silme fonksiyonu
void takimSil()
{
    Takim T;
    int silinecekTakimNo;
    cout << "Silinecek Takım Numarası: ";
    cin >> silinecekTakimNo;
    cout << endl;

    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Dosya açıldı mı kontrol
    {
		cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
		return;
	}

    takimKontrol.seekg(0, ios::beg);
    bool takimBulundu = false;
    // Girilen takım no'ya sahip takım var mı kontrol
    while (takimKontrol >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (silinecekTakimNo == T.takimNO)
        {
            takimBulundu = true;
			break;
		}
	}
    takimKontrol.close();
    if (!takimBulundu) // Takım bulunamadıysa hata ver
    {
        cout << "Girilen takım no'ya sahip takım bulunamadı.\n";
        return;
    }

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    ofstream geciciDosya;
    geciciDosya.open("gecici.txt");
    takimDosyaOku.seekg(0, ios::beg);
    geciciDosya.seekp(0, ios::beg);

    if (takimDosyaOku.is_open() && geciciDosya.is_open()) // Dosyalar açıldıysa devam et
    {   // Dosya içeriği okunurken koşula göre geçici dosyaya kaydet
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {   
            //takimDosyaOku.read(reinterpret_cast<char*>(&T), sizeof(T));
            if (T.takimNO != silinecekTakimNo) // Takım bulunmadıkça kaydet
            {
                T.dosyayaYaz(geciciDosya);
				//geciciDosya.write(reinterpret_cast<char*>(&T), sizeof(T));
			}
		}
        takimDosyaOku.close();
        geciciDosya.close();

        remove("takimlar.txt");
        if (rename("gecici.txt", "takimlar.txt")) // Dosya adı değiştirildi mi
        {
            cout << "Takım silme başarısız." << endl;

		}
        else
        {
            cout << "Takım başarıyla silindi." << endl;
		}
    }
    // Dosyalar veya dosya açılmadıysa hata ver
    else {
        cerr << "Dosya açma hatası!" << endl;
    }
}
// Takımları listeleme fonksiyonu
void takimlariListele()
{
    ifstream takimDosyaOku;
	takimDosyaOku.open("takimlar.txt", ios::in);

    if (!takimDosyaOku.is_open()) // Dosya açıldı mı kontrol
    {
        cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
        return;
    }

    string satir;
    int takimSayisi = 0;
    // Takım sayısını alma
    while (getline(takimDosyaOku, satir))
    {
        takimSayisi += 1;
    }
    takimDosyaOku.close();
    //takimSayisi -= 1; // Son satır boş olduğu için 1 azaltma (ama gerek kalmıyor neden?)
    takimDosyaOku.open("takimlar.txt");
	Takim T;
	takimDosyaOku.seekg(0, ios::beg);
    if (takimDosyaOku.is_open()) // Dosya açıldı mı kontrol
    {
        cout << "Takımlar (toplam " << takimSayisi << " adet):" << endl
            << "-----------------------------" << endl;
        // Takımları ekrana yazdırma
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {
			cout << "Takım No: " << T.takimNO << endl;
			cout << "Takım Adı: " << T.adi << endl;
			cout << "Takım Adresi: " << T.adresi << endl;
			cout << "Takım Telefonu: " << T.telefon << endl;
			cout << "Takımdaki Oyuncu Sayısı: " << T.oyuncuSayisi << endl;
			cout << "Takım Yöneticisi: " << T.yoneticiIsmi << endl;
			cout << "-----------------------------" << endl;
		}
		takimDosyaOku.close();
	}
    else
    {
		cerr << "Dosya açma hatası!" << endl;
	}

}
// Takıma futbolcu ekleme fonksiyonu
void futbolcuEkle()
{
    Futbolcu F;
    cout << "Futbolcunun Ekleneceği Takımın TakımNo'su: ";
    cin >> F.takimNO;

    // Girilen takım no'ya sahip takım var mı kontrol
    Takim T5;
    ifstream takimKontrol("takimlar.txt");
    bool takimBulundu = false;
    if (takimKontrol.is_open()) // Dosya var mı (oluşturulmuş mu) kontrol
    {
        takimKontrol.seekg(0, ios::beg);
        while (takimKontrol >> T5.takimNO >> T5.adi >> T5.adresi >> T5.telefon >> T5.oyuncuSayisi >> T5.yoneticiIsmi)
        {
            if (F.takimNO == T5.takimNO)
            {
                takimBulundu = true;
                break;
            }
        }
	}
    else
    {
        cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
        return;
    }
    takimKontrol.close();
    if (!takimBulundu) // Takım bulunamadıysa hata ver
    {
        cout << "Girilen takım no'suna sahip takım bulunamadı.\n";
        return;
    }

    cout << "Futbolcunun TC Kimlik No'su: ";
    cin >> F.TCNO;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme
    // Temizlemeyince ve sayı atama sonrası string atama işlemi yapınca atama eksik/hatalı oluyor

    // Girilen TC kimlik no'ya sahip başka bir oyuncu var mı kontrol
    Futbolcu F2;
    ifstream tcKontrol("futbolcular.txt");
    if (tcKontrol.is_open()) // Dosya var mı (oluşturulmuş mu) kontrol
    {
		tcKontrol.seekg(0, ios::beg);
        while (tcKontrol >> F2.takimNO >> F2.TCNO >> F2.adi >> F2.soyadi >> F2.lisansNO >> F2.konumu >> F2.ucret >> F2.dogumTarihi)
        {
            if (F.TCNO == F2.TCNO)
            {
				cout << "Bu TC kimlik no'ya sahip oyuncu zaten var!\n";
				return;
			}
		}
	}
    tcKontrol.close();

    cout << "Futbolcunun Adı: ";
    getline(cin, F.adi);

    cout << "Futbolcunun Soyadı: ";
    getline(cin, F.soyadi);

    cout << "Lisans No'su: ";
    getline(cin, F.lisansNO);

    // Girilen lisans no'ya sahip başka bir oyuncu var mı kontrol
    Futbolcu F3;
    ifstream lisansKontrol("futbolcular.txt");
    if (lisansKontrol.is_open()) // Dosya var mı (oluşturulmuş mu) kontrol
    {
		lisansKontrol.seekg(0, ios::beg);
        while (lisansKontrol >> F3.takimNO >> F3.TCNO >> F3.adi >> F3.soyadi >> F3.lisansNO >> F3.konumu >> F3.ucret >> F3.dogumTarihi)
        {
            if (F.lisansNO == F3.lisansNO)
            {
				cout << "Bu lisans no'ya sahip oyuncu zaten var!\n";
				return;
			}
		}
	}
    lisansKontrol.close();

    cout << "Oyundaki Konumu: ";
    getline(cin, F.konumu);

    cout << "Ücreti: ";
    cin >> F.ucret;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

    cout << "Doğum Tarihi: ";
    getline(cin, F.dogumTarihi);

    ofstream futbolcuYaz;
    futbolcuYaz.open("futbolcular.txt", ios::app);
    F.dosyayaYaz(futbolcuYaz);

    // Takım dosyasını güncelleme
    Takim T;
    ifstream dosyaOku("takimlar.txt");
    ofstream tempYaz;
    tempYaz.open("temp.txt");

    dosyaOku.seekg(0, ios::beg);
    tempYaz.seekp(0, ios::beg);

    if (!dosyaOku.is_open() || !tempYaz.is_open()) // Dosyalar açıldı mı kontrol
    {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    takimBulundu = false;
    // Takımı bulma ve oyuncu sayısını arttırma
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (F.takimNO == T.takimNO) // Takım bulunduysa oyuncu sayısını arttır
        {
            takimBulundu = true;
            T.oyuncuSayisi += 1;
        }
        T.dosyayaYaz(tempYaz);
    }

    dosyaOku.close();
    tempYaz.close();

    if (takimBulundu) // Takım dosya içinde varsa devam et
    {
        remove("takimlar.txt");
        if (rename("temp.txt", "takimlar.txt"))
        {
            cout << "Oyuncu ekleme başarısız." << endl;
        }
        else
        {
            cout << "Oyuncu başarıyla eklendi." << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "Takım bulunamadı." << endl;
        return;
    }
}
// Takımdan futbolcu silme fonksiyonu
void futbolcuSil()
{
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Takımlar var mı (oluşturulmuş mu) kontrol
    {
        cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
        return;
    }
    takimKontrol.close();

    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var mı (oluşturulmuş mu) kontrol
    {
        cerr << "Dosya açma hatası! Önce futbolcu eklemeyi deneyin." << endl;
        return;
    }
    futbolcuKontrol.close();

    int takimno = 0;
    cout << "Oyuncusu silinecek takımın no'su: ";
    cin >> takimno;
    cout << endl;

    // Girilen takım no'ya sahip takım var mı kontrol
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    Takim T5;
    bool takimBulundu = false;
    if (takimDosyaOku.is_open()) // Dosya açıldı mı kontrol
    {
		takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T5.takimNO >> T5.adi >> T5.adresi >> T5.telefon >> T5.oyuncuSayisi >> T5.yoneticiIsmi)
        {
            if (takimno == T5.takimNO)
            {
				takimBulundu = true;
				break;
			}
		}
	}
    takimDosyaOku.close();
    if (!takimBulundu) // Takım bulunamadıysa hata ver
    {
        cerr << "Girilen takım no'ya sahip takım bulunamadı.\n";
        return;
    }

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No'sunu kullanarak silmek için '1'i, Lisans No'su ile silmek için '2'yi tuşlayın\n";
    cin >> answer;
    cout << endl;
    if (answer == 1)
    {
		string silinecektcno;
		cout << "Silinecek futbolcunun TC kimlik no'su: ";
		cin >> silinecektcno;
		cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var mı kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
		{
			tcKontrol.seekg(0, ios::beg);
			while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
			{
                if (silinecektcno == F.TCNO && takimno == F.takimNO) // Girilen TC kimlik no'ya sahip oyuncu varsa sil ama aynı takımda olmalı
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
		tcKontrol.close();
        if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadı.\n";
            return;
        }

		ifstream futbolcudosyaoku("futbolcular.txt");
		ofstream gecicidosya("gecici_futbolcu.txt");
		// Dosyalar açıldı mı kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
			Futbolcu F;
			// Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.TCNO != silinecektcno) // Oyuncu TC'si silinecek TC'ye eşit değilse kaydet
                {
					F.dosyayaYaz(gecicidosya);
				}
			}
			futbolcudosyaoku.close();
			gecicidosya.close();
        }

        remove("futbolcular.txt");
        if (rename("gecici_futbolcu.txt", "futbolcular.txt"))
        {
            cout << "Futbolcu silme işlemi başarısız oldu." << endl;
        }
        else
        {
            cout << "Futbolcu başarıyla silindi." << endl;
        }
    }
    else if (answer == 2)
    {
        string silineceklisansno;
        cout << "Silinecek futbolcunun lisans no'su: ";
        cin >> silineceklisansno;
        
        // Girilen lisans no'ya sahip oyuncu var mı kontrol
        Futbolcu F;
        ifstream lisansKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (lisansKontrol.is_open()) // Dosya açıldı mı kontrol
		{
			lisansKontrol.seekg(0, ios::beg);
            while (lisansKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (silineceklisansno == F.lisansNO && takimno == F.takimNO) // Girilen lisans no'ya sahip oyuncu varsa sil ama aynı takımda olmalı
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamadı.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açıldı mı kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.lisansNO != silineceklisansno) // Oyuncu LisansNo'su silinecek LisansNo'ya eşit değilse kaydet
                {
                    F.dosyayaYaz(gecicidosya);
                }
            }
            futbolcudosyaoku.close();
            gecicidosya.close();
        }

        remove("futbolcular.txt");
        if (rename("gecici_futbolcu.txt", "futbolcular.txt"))
        {
            cout << "Futbolcu silme işlemi başarısız oldu." << endl;
        }
        else
        {
            cout << "Futbolcu başarıyla silindi." << endl;
        }
    }
    else
	{
		cout << "Geçersiz seçim!\n";
		return;
	}


    ifstream dosyaOku("takimlar.txt");
    ofstream tempeYaz("temp.txt");
    Takim T;
    // Takım dosyasını güncelleme
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Takım bulunduysa oyuncu sayısını 1 azalt
        {
            T.oyuncuSayisi -= 1;
        }
        T.dosyayaYaz(tempeYaz);
    }
    dosyaOku.close();
    tempeYaz.close();

    remove("takimlar.txt");
    if (rename("temp.txt", "takimlar.txt")) // Dosya adı değiştirildi mi kontrol
    {
        cout << "Takım güncelleme başarısız." << endl;
    }
    else
    {
        cout << "Takım başarıyla güncellendi." << endl;
    }
}
// Tüm futbolcuları listeleme fonksiyonu
void tumFutbolculariListele()
 {
    ifstream futbolcudosyaoku;
    futbolcudosyaoku.open("futbolcular.txt");
    if (!futbolcudosyaoku.is_open()) // Futbolcu var mı kontrol
	{
		cerr << "Dosya açma hatası! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}

    string satir;
    int futbolcuSayisi = 0;
    futbolcudosyaoku.seekg(0, ios::beg);
    // Futbolcu sayısını bulma
    while (getline(futbolcudosyaoku, satir))
    {
        futbolcuSayisi += 1;
    }
    futbolcudosyaoku.close();
    //futbolcuSayisi -= 1; // Son satır boş olduğu için 1 azalt (azaltmaya gerek kalmadan doğru sayıyor ama neden?)
    futbolcudosyaoku.open("futbolcular.txt");
    if (futbolcudosyaoku.is_open()) // Dosya açıldı mı kontrol
    {
		 Futbolcu F;
         cout << "Futbolcular (toplam "<< futbolcuSayisi << " adet):" << endl;
         cout << "-----------------------------" << endl;
         // Futbolcuları ekrana yazdırma
         while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
         {
			 cout << "Takım No: " << F.takimNO << endl;
			 cout << "TC Kimlik No: " << F.TCNO << endl;
			 cout << "Adı: " << F.adi << endl;
			 cout << "Soyadı: " << F.soyadi << endl;
			 cout << "Lisans No: " << F.lisansNO << endl;
			 cout << "Oyundaki Konumu: " << F.konumu << endl;
			 cout << "Ücreti: " << F.ucret << endl;
			 cout << "Doğum Tarihi: " << F.dogumTarihi << endl;
			 cout << "-----------------------------" << endl;
		 }
		 futbolcudosyaoku.close();
	}
    else
    {
		 cerr << "Dosya açma hatası!" << endl;
	}
 
}
// Takıma göre futbolcuları listeleme fonksiyonu
void takimaGoreFutbolculariListele()
{
    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Takım var mı kontrol
    {
        cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
        return;
    }
    takimKontrol.close();

    int takimno = 0;
    cout << "Futbolcuları Listelenecek Takımın TakımNo'su: ";
    cin >> takimno;
    cout << endl;

    ifstream takimOku("takimlar.txt");
    Takim T;
    bool takimBulundu = false;
    // Böyle bir takım var mı yok mu kontrol
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Takım bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku.close();

    if (!takimBulundu) // Takım bulunamadıysa dönüt
    {
        cout << "Girilen takımNo'suna sahip takım bulunamadı.\n";
        return;
    }

    ifstream futbolcudosyaoku("futbolcular.txt");

    if (!futbolcudosyaoku.is_open()) // Futbolcu var mı kontrol
	{
		cerr << "Dosya açma hatası! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    else if (futbolcudosyaoku.is_open())
    {
        Futbolcu F;
        cout << takimno << " No'lu Takımın Futbolcuları:" << endl;
        cout << "-----------------------------" << endl;
        // Takıma ait futbolcuları ekrana yazdırma
        while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
        {
            if (F.takimNO == takimno) // Takım bulunduysa ekrana yazdır
            {
                cout << "Takım No: " << F.takimNO << endl;
                cout << "TC Kimlik No: " << F.TCNO << endl;
                cout << "Adı: " << F.adi << endl;
                cout << "Soyadı: " << F.soyadi << endl;
                cout << "Lisans No: " << F.lisansNO << endl;
                cout << "Oyundaki Konumu: " << F.konumu << endl;
                cout << "Ücreti: " << F.ucret << endl;
                cout << "Doğum Tarihi: " << F.dogumTarihi << endl;
                cout << "-----------------------------" << endl;
            }
        }
        futbolcudosyaoku.close();
    }
    else
    {
        cerr << "Dosya açma hatası!" << endl;
    }
}
// Futbolcu güncelleme fonksiyonu
void futbolcuGuncelle()
{
    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var mı (oluşturulmuş mu) kontrol
    {
		cerr << "Dosya açma hatası! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    futbolcuKontrol.close();

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No ile güncellemek için '1'i, Lisans No ile güncellemek için '2'yi tuşlayın\n";
    cin >> answer;
    cout << endl;

    if (answer != 1 && answer != 2)
    {
        cout << "Hatalı seçim!\n";
        return;
    }

    if (answer == 1)
    {
        string guncellenecektcno;
        cout << "Güncellenecek Futbolcunun TC kimlik No Bilgisi: ";
        cin >> guncellenecektcno;
        cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var mı kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        string guncelleneceklisansno;
        if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
        {
            tcKontrol.seekg(0, ios::beg);
            while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (guncellenecektcno == F.TCNO) // Oyuncu bulunduysa lisans no'sunu da kaydet
                {
                    futbolcuBulundu = true;
                    guncelleneceklisansno = F.lisansNO;
                    break;
                }
            }
        }
        tcKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
        {
			cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadı.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açıldı mı kontrolü
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // Eğer oyuncu bulunmadıysa direkt dosyaya yaz
                if (F.TCNO != guncellenecektcno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // Güncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Takım No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    // Girilen TC kimlik no'ya sahip başka bir oyuncu var mı kontrol
                    Futbolcu F2;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
                    {
						tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F2.takimNO >> F2.TCNO >> F2.adi >> F2.soyadi >> F2.lisansNO >> F2.konumu >> F2.ucret >> F2.dogumTarihi)
                        {
                            if (guncellenecektcno == F2.TCNO) // Kendi TC'si hariç aynı TC'ye sahip başka bir oyuncu var mı kontrol et
                            {
                                continue;
                            }

                            if (F.TCNO == F2.TCNO) // Girilen TC kimlik no'ya sahip başka bir oyuncu var mı kontrol et
                            {
								cout << "Bu TC kimlik no'ya sahip bir oyuncu zaten var!\n";
								return;
							}
						}
					}

                    cout << "Yeni Adı: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyadı: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip başka bir oyuncu var mı kontrol
                    Futbolcu F3;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya açıldı mı kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F3.takimNO >> F3.TCNO >> F3.adi >> F3.soyadi >> F3.lisansNO >> F3.konumu >> F3.ucret >> F3.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F3.lisansNO) // Kendi Lisans No'su hariç aynı Lisans No'ya sahip oyuncu var mı kontrol et
                            {
                                continue;
                            }

                            if (F.lisansNO == F3.lisansNO) // Girilen lisans no'ya sahip başka bir oyuncu var mı kontrol et
                            {
								cout << "Bu lisans no'ya sahip oyuncu zaten var!\n";
								return;
							}
						}
                    }

                    cout << "Yeni Oyundaki Konumu: ";
                    getline(cin, F.konumu);

                    cout << "Yeni Ücreti: ";
                    cin >> F.ucret;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    cout << "Yeni Doğum Tarihi: ";
                    getline(cin, F.dogumTarihi);

                    F.dosyayaYaz(gecicidosya);
                }
            }

            futbolcudosyaoku.close();
            gecicidosya.close();
        }
	}
    else if (answer == 2)
    {
        string guncelleneceklisansno;
        cout << "Güncellenecek futbolcunun lisans no'su: ";
        cin >> guncelleneceklisansno;
        cout << endl;

        Futbolcu F;
        ifstream lisansKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        string guncellenecektcno;
        // Girilen lisans no'ya sahip bir oyuncu var mı kontrol
        if (lisansKontrol.is_open()) // Dosya açıldı mı kontrol
        {
            lisansKontrol.seekg(0, ios::beg);
            while (lisansKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (guncelleneceklisansno == F.lisansNO) // Oyuncu bulunduysa TC kimlik no'sunu da kaydet
                {
                    futbolcuBulundu = true;
                    guncellenecektcno = F.TCNO;
                    break;
                }
            }
        }
        else
        {
			cerr << "Dosya açma hatası! Futbolcu eklemeyi deneyin." << endl;
			return;
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamadı.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açıldı mı kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // Eğer oyuncu bulunmadıysa direkt dosyaya yaz
                if (F.lisansNO != guncelleneceklisansno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // Güncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Takım No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme


                    // Girilen TC kimlik no'ya sahip başka bir oyuncu var mı kontrol
                    Futbolcu F6;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
                    {
                        tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F6.takimNO >> F6.TCNO >> F6.adi >> F6.soyadi >> F6.lisansNO >> F6.konumu >> F6.ucret >> F6.dogumTarihi)
                        {
                            if (guncellenecektcno == F6.TCNO) // Kendi TC'si hariç aynı TC'ye sahip oyuncu var mı kontrol et
                            {
                                continue;
                            }

                            if (F.TCNO == F6.TCNO)
                            {
                                cout << "Bu TC kimlik no'ya sahip bir oyuncu zaten var!\n";
                                return;
                            }
                        }
                    }

                    cout << "Yeni Adı: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyadı: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip oyuncu var mı kontrol
                    Futbolcu F7;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya açıldı mı kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F7.takimNO >> F7.TCNO >> F7.adi >> F7.soyadi >> F7.lisansNO >> F7.konumu >> F7.ucret >> F7.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F7.lisansNO) // Kendi LisansNo'su hariç aynı LisansNo'ya sahip oyuncu var mı kontrol et
                            {
                                continue;
                            }

                            if (F.lisansNO == F7.lisansNO)
                            {
                                cout << "Bu lisans no'ya sahip oyuncu zaten var!\n";
                                return;
                            }
                        }
                    }

                    cout << "Yeni Oyundaki Konumu: ";
                    getline(cin, F.konumu);

                    cout << "Yeni Ücreti: ";
                    cin >> F.ucret;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    cout << "Yeni Doğum Tarihi: ";
                    getline(cin, F.dogumTarihi);

                    F.dosyayaYaz(gecicidosya);
                }
            }
            futbolcudosyaoku.close();
            gecicidosya.close();
        }
    }

	remove("futbolcular.txt");
    // Dosya adı değiştirildi mi kontrol
    if (rename("gecici_futbolcu.txt", "futbolcular.txt"))
    {
        cout << "Futbolcu güncelleneme işlemi başarısız." << endl;
	}
    else
    {
        cout << "Futbolcu başarıyla güncellendi." << endl;
    }
}
// Maç kaydı alma fonksiyonu
void futbolOyunuKaydi()
{
    // Takım kontrolü
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Takımlar var mı (oluşturulmuş mu) kontrol
    {
		cerr << "Dosya açma hatası! Önce takım oluşturmayı deneyin." << endl;
		return;
	}
    takimKontrol.close();

    string evSahibi;
    cout << "Ev sahibi takımın adını girin: ";
    cin.ignore(); // Sayısal giriş aldıktan sonra metinsel giriş alıyosak gerekiyor
    getline(cin, evSahibi);                  // Önceki girişlerin tamamını temizler
    cout << endl;

    // Böyle bir takım var mı yok mu kontrol
    Takim T;
    ifstream takimOku("takimlar.txt");
    bool takimBulundu = false;
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (evSahibi == T.adi) // Takım bulundu mu kontrol
        {
			takimBulundu = true;
			break;
		}
	}
    takimOku.close();
    if (!takimBulundu) // Takım bulunamadıysa dönüt
    {
        cerr << "Girilen takım bulunamadı.\n";
        return;
    }

    string rakipTakim;
    cout << "Karşılaşılan takımın adını girin: ";
    getline(cin, rakipTakim);
    cout << endl;

    // Böyle bir takım var mı yok mu kontrol
    ifstream takimOku2("takimlar.txt");
    takimOku2.seekg(0, ios::beg);
    takimBulundu = false;
    while (takimOku2 >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (rakipTakim == T.adi) // Takım bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku2.close();
    if (!takimBulundu) // Takım bulunamadıysa dönüt
    {
		cerr << "Girilen takım bulunamadı.\n";
		return;
	}

    int skorEv = 0, skorMisafir = 0;
    cout << "Ev sahibi takım skoru: ";
    cin >> skorEv;
    if (skorEv < 0) // Skor negatif olamaz
    {
		cout << "Skor negatif olamaz!\n";
		return;
	}

    cout << "Misafir takım skoru: ";
    cin >> skorMisafir;
    if (skorMisafir < 0) // Skor negatif olamaz
    {
        cout << "Skor negatif olamaz!\n";
        return;
    }

    string tarih;
    cout << "Maç Tarihi: ";
    cin.ignore();
    getline(cin, tarih);

    int hafta = 0;
    cout << "Kaçıncı hafta: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sıfır olamaz
    {
		cout << "Hafta negatif veya sıfır olamaz!\n";
		return;
	}

    ofstream maclarDosyaYaz;
    maclarDosyaYaz.open("maclar.txt", ios::app);
    maclarDosyaYaz << "\t" << evSahibi << " vs " << rakipTakim << endl;
    maclarDosyaYaz << hafta << ". Hafta Karşılaşması Kaydı\n";
    maclarDosyaYaz << "##############################" << endl;
    maclarDosyaYaz << "Tarih: " << tarih << endl;
    maclarDosyaYaz << "Skor: " << skorEv << " - " << skorMisafir << endl;

    int toplamGolAtanOyuncu = 0;
    cout << "Toplam kaç farklı oyuncu gol attı: ";
    cin >> toplamGolAtanOyuncu;
    if (toplamGolAtanOyuncu < 0)
    {
		cout << "Gol atan oyuncu sayısı negatif olamaz!\n";
		return;
	}

    string golAtan;
    int gol = 0;
    // Gol yoksa terminale gereksiz yazma
    if (toplamGolAtanOyuncu > 0)
    {
        cout << "Gol Atan Oyuncular:\n";
    }
    
    maclarDosyaYaz << "Gol Atan Farklı Oyuncu Sayısı: " << toplamGolAtanOyuncu << endl;
    maclarDosyaYaz << "Gol Atan Oyuncular:\n";
    
    for (int i = 1; i <= toplamGolAtanOyuncu; i++)
    {
        cout << "Gol Atan Oyuncunun TC'si: ";
        cin >> golAtan;

        // Girilen TC kimlik no'ya sahip oyuncu var mı kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
        {
			tcKontrol.seekg(0, ios::beg);
            while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (golAtan == F.TCNO)
                {
					futbolcuBulundu = true;
					break;
				}
			}
		}
        tcKontrol.close();
        if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadı.\n";
            return;
        }


        cout << "Attığı Gol Sayısı: ";
        cin >> gol;
        if (gol < 0) // Gol negatif olamaz
        {
            cout << "Gol sayısı negatif olamaz!\n";
            return;
        }

        maclarDosyaYaz << golAtan << ": " << gol << " Gol\n";
    }
    maclarDosyaYaz << "-------------------------------" << endl;

    // Maçta oynayan oyuncuları kaydetme

    int oyuncuSayisi;
    cout << "Maçta oynayan oyuncu sayısı: ";
    cin >> oyuncuSayisi;
    if (oyuncuSayisi <= 21) // Oyuncu sayısı 22 den küçük olamaz
    {
		cout << "Oyuncu sayısı 22 den küçük olamaz!\n";
		return;
	}

    char answer = 'h';
    cout << "Maçta oynayan oyuncuların TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (" << oyuncuSayisi << " adet kayıt gerekli)\n";
    cin >> answer;
    if (answer == 'e' || answer == 'E') // Giriş kontrolü
    {
        maclarDosyaYaz << "Maçta Oynayan Oyuncu Sayısı: " << oyuncuSayisi << endl;
        maclarDosyaYaz << "Maçta Oynayan Oyuncular: \n";
        maclarDosyaYaz << "-------------------------------" << endl;
        // Her bir oyuncuyu kaydetmek için döngü
        for (int i = 1; i <= oyuncuSayisi; i++)
        {
            string oyuncuTC;
            cout << i << ". Oyuncunun TC Kimlik Numarası: ";
            cin >> oyuncuTC;

            // Girilen TC kimlik no'ya sahip oyuncu var mı kontrol
            Futbolcu F;
            ifstream tcKontrol("futbolcular.txt");
            bool futbolcuBulundu = false;
            if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
            {
				tcKontrol.seekg(0, ios::beg);
                while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
                {
                    if (oyuncuTC == F.TCNO)
                    {
						futbolcuBulundu = true;
						break;
					}
				}
			}
            tcKontrol.close();
            if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
            {
				cout << "Girilen TC Kimlik No'ya sahip oyuncu bulunamadı.\n";
				return;
			}
            maclarDosyaYaz << i << ". Oynayan Oyuncu: " << oyuncuTC << endl;
        } 
    }
    else
    {
        cout << "Sadece oynayan oyuncuların sayı bilgisi kaydedildi.\n";
        maclarDosyaYaz << "Maçta Oynayan Oyuncu Sayısı: " << oyuncuSayisi << endl;
    }

    // Oyuncu değişikliklerini kaydetme

    int degisiklikSayisi;
    cout << "Maç sırasında kaç oyuncu değişikliği oldu: ";
    cin >> degisiklikSayisi;
    if (degisiklikSayisi < 0) // Değişiklik sayısı negatif olamaz
    {
        cout << "Değişiklik sayısı negatif olamaz!\n";
        return;
    }
    if (degisiklikSayisi > 10) // Değişiklik sayısı 10'dan fazla olamaz
    {
		cout << "Değişiklik sayısı 10'dan fazla olamaz!\n";
		return;
	}
    if (degisiklikSayisi > 0) // Değişiklik varsa
    {
        answer = 'h';
        cout << "Maçta giren-çıkan oyuncuların TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (toplam " << degisiklikSayisi << " kadar kayıt gerekli)\n";
        cin >> answer;
        if (answer == 'e' || answer == 'E') // Giriş kontrolü
        {
            maclarDosyaYaz << "Maçta Yapılan Değişiklik Sayısı: " << degisiklikSayisi << endl;
            // Değişiklikleri kaydetmek için döngü
            for (int i = 1; i <= degisiklikSayisi; ++i)
            {
                string degisenOyuncuTC, girenOyuncuTC;
                cout << i << ". Çıkan Oyuncunun TC Kimlik Numarası: ";
                cin >> degisenOyuncuTC;

                // Değişen oyuncunun TC kimlik no kontrolü (tc kimlik hiçbir futbolcuda yoksa hata ver)
                Futbolcu F;
                ifstream tcKontrol("futbolcular.txt");
                bool futbolcuBulundu = false;
                if (tcKontrol.is_open()) // Dosya açıldı mı kontrol
                {
                    while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
                    {
                        if (degisenOyuncuTC == F.TCNO)
                        {
                            futbolcuBulundu = true;
                            break;
                        }
                    }
                }
                tcKontrol.close();
                if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadı.\n";
                    return;
                }

                maclarDosyaYaz << i << ". Çıkan Oyuncu: " << degisenOyuncuTC << endl;
                cout << i << ". Giren Oyuncunun TC Kimlik Numarası: ";
                cin >> girenOyuncuTC;

                // Giren oyuncunun TC kimlik no kontrolü (tc kimlik hiçbir futbolcuda yoksa hata ver)
                Futbolcu F2;
                ifstream tcKontrol2("futbolcular.txt");
                futbolcuBulundu = false;
                if (tcKontrol2.is_open()) // Dosya açıldı mı kontrol
                {
                    while (tcKontrol2 >> F2.takimNO >> F2.TCNO >> F2.adi >> F2.soyadi >> F2.lisansNO >> F2.konumu >> F2.ucret >> F2.dogumTarihi)
                    {
                        if (girenOyuncuTC == F2.TCNO)
                        {
                            futbolcuBulundu = true;
                            break;
                        }
                    }
                }
                tcKontrol2.close();
                if (!futbolcuBulundu) // Futbolcu bulunamadıysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadı.\n";
                    return;
                }
                maclarDosyaYaz << i << ". Giren Oyuncu: " << girenOyuncuTC << endl;
            }
        }
        else
        {
            cout << "Sadece yapılan değişiklik sayısı kaydedildi\n";
            maclarDosyaYaz << "Maçta Yapılan Değişiklik Sayısı: " << degisiklikSayisi << endl;
        }
    }
    else // Değişiklik 0 ise
    {
        maclarDosyaYaz << "Maçta Yapılan Değişiklik Sayısı: " << degisiklikSayisi << endl;
    }
    maclarDosyaYaz << "------------------------------" << endl;
    maclarDosyaYaz.close();

    cout << "Maç kaydı başarıyla oluşturuldu." << endl;
}
// Haftalık kayıt alma fonksiyonu
void haftalikKayit()
{
    // Maçlar kontrolü
    ifstream maclarKontrol("maclar.txt");
    if (!maclarKontrol.is_open()) // Maçlar var mı (oluşturulmuş mu) kontrol
    {
        cerr << "Dosya açma hatası! Önce maç kaydı oluşturmayı deneyin." << endl;
        return;
    }

    int istekHafta = 0;
    cout << "Kaçıncı haftanın kaydı yapılacak: ";
    cin >> istekHafta;
    if (istekHafta <= 0) // Hafta negatif veya sıfır olamaz
    {
		cout << "Hafta negatif veya sıfır olamaz!\n";
		return;
	}

    // İstenilen haftaya kadar kayıt yapmak için döngü (ama tam çalışmıyor sadece girilen haftayı yapıyor)
    for (int i = 1; i <= istekHafta; i++)
    {
        string kayit = to_string(istekHafta) + ". hafta_kayit.txt";
        ofstream maclarDosyasi(kayit);
        ifstream maclarOku("maclar.txt");
        if (maclarDosyasi.is_open() && maclarOku.is_open()) // Dosyalar açıldı mı kontrol
        {
            cout << to_string(i) << ". Hafta oynanan maçlar kaydediliyor..." << endl;
            string satir;
            maclarOku.seekg(0);
            maclarDosyasi.seekp(0);
            string haftaBilgisi = to_string(istekHafta) + ". Hafta Karşılaşması Kaydı";
            bool istekHaftaBasladi = false;
            string oncekiSatir;
            int a = 1;

            // Tüm maçların kaydedildiği dosyadan haftaya göre maç seçmek için döngü
            while (getline(maclarOku, satir))
            {
                // İstenilen haftayı bulma kontrolü
                if (satir.find(haftaBilgisi) != string::npos)
                {
                    istekHaftaBasladi = true;
                }
                else
                {
                    istekHaftaBasladi = false;
                }

                // Hafta bulunduysa yapılacak işlemler
                if (istekHaftaBasladi)
                {
                    if (a) // Maçı yapan takımları yazdırmak için döngüde tek sefer çalışan koşul
                    {
                        maclarDosyasi << oncekiSatir << endl;
                        a = 0;
                    }
                    // Bulunan haftanın bilgilerini almak için döngü
                    while (getline(maclarOku, satir))
                    {
                        // Tarihi kaydetme
                        if (satir.find("Tarih") != string::npos)
                        {
                            maclarDosyasi << satir << endl;
                        }
                        // Skoru kaydetme
                        else if (satir.find("Skor") != string::npos)
                        {
                            maclarDosyasi << satir << endl;
                        }
                        // Goller ile ilgili satırları alma
                        else if (satir.find("Gol") != string::npos)
                        {
                            maclarDosyasi << satir << endl;
                        }
                        // Maç kaydının ilk parçası bitti ise 2. parçayı
                       // atlayıp diğer maç kaydına geçme
                        else if (satir.find("---") != string::npos)
                        {
                            a = 1;
                            getline(maclarOku, satir); // Gereksiz satırı atlama
                            getline(maclarOku, satir); // Gereksiz satırı atlama
                            getline(maclarOku, satir); // Gereksiz satırı atlama
                            maclarDosyasi << satir << endl; //araya "-----" için
                            //getline(maclarOku, satir); // Gereksiz satırı atlama

                            break;
                        }
                    }
                }
                oncekiSatir = satir; // Maçı yapan takımları alma
                // (maclar dosyasında hafta bilgisinden hemen önce yer alıyorlar)
            }
            maclarDosyasi.close();
            maclarOku.close();
            cout << "Haftanın kaydı başarıyla tamamlandı.\n";
        }
        else // Dosyalar açılmadıysa oynanmamış haftalar için de kayıt istenmiştir veya küçük ihtimal dosya açılamamıştır
        {
            cerr << "Dosya açma hatası! Haftası oynanmamış maçlar için de kayıt istemiş olabilirsiniz. Maç kaydı yapmayı deneyin." << endl;
            break;
        }
	}
}
// Haftalık kayıt görüntüleme fonksiyonu
void haftalikKayitGoruntule()
{
	int hafta = 0;
	cout << "Kaydı görüntülenecek haftayı girin: ";
	cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sıfır olamaz
    {
		cout << "Hafta negatif veya sıfır olamaz!\n";
		return;
	}
    // Dosyayı okuma
	string haftaBilgisi = to_string(hafta) + ". hafta_kayit.txt";
	ifstream dosya(haftaBilgisi);
    if (dosya.is_open()) // Dosya açıldı mı kontrol
    {
		string satir;
        while (getline(dosya, satir))
        {
			cout << satir << endl;
		}
		dosya.close();
	}
    else
    {
		cerr << "Dosya açma hatası! Dosya var olmayabilir, haftalık kayıt oluşturmayı deneyin." << endl;
        return;
	}
}
// Haftalık puan durumu görüntüleme fonksiyonu
void haftalikPuanDurumlari()
{
    int hafta = 0;
    cout << "Puan durumu gösterilecek haftayı girin: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sıfır olamaz
    {
        cout << "Hafta negatif veya sıfır olamaz!\n";
        return;
    }
    const int takimSayisi = 21; // Aslında 20 takım var ama 0. indis boş kalıyor çünkü takımlar dosyası 1. değerden başlıyor
    
    string takimlar[takimSayisi]{}; // Takımların isimlerini tutacak dizi
    int takimPuanlari[takimSayisi] = { 0 }; // Takımların puanlarını tutacak dizi
    int takimOynadigiMacSayisi[takimSayisi] = { 0 }; // Takımların oynadığı maç sayısını tutacak dizi
    int takimAttigiGolSayisi[takimSayisi] = { 0 }; // Takımların attığı gol sayısını tutacak dizi
    int takimYedigiGolSayisi[takimSayisi] = { 0 }; // Takımların yediği gol sayısını tutacak dizi
    int takimAveraj[takimSayisi] = { 0 }; // Takımların averajını tutacak dizi
    int takimGalibiyetSayisi[takimSayisi] = { 0 }; // Takımların galibiyet sayısını tutacak dizi
    int takimBeraberlikSayisi[takimSayisi] = { 0 }; // Takımların beraberlik sayısını tutacak dizi
    int takimMaglubiyetSayisi[takimSayisi] = { 0 }; // Takımların mağlubiyet sayısını tutacak dizi
    
    Takim T;

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt", ios::in);
    takimDosyaOku.seekg(0, ios::beg);
    // Takımların isimlerini alma
    while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        takimlar[T.takimNO] = T.adi;
    }
    takimDosyaOku.close();

    // Her bir hafta kaydından verileri alma
    for (int i = 1; i <= hafta; i++)
    {
        string haftaBilgisi = to_string(i) + ". hafta_kayit.txt";
        ifstream dosya(haftaBilgisi);
        if (dosya.is_open()) // Dosya açıldı mı kontrol
        {
            string satir;
            // Dosya içeriğini satır satır okuma
            while (getline(dosya, satir))
            {
                // Takımların isimlerini almak için koşul (bununla o takımın takımNO bilgisini alıyoruz)
                if (satir.find("vs") != string::npos)
                {
                    string evTakim, vs, misafirTakim;
                    stringstream ss(satir);
                    ss >> evTakim >> vs >> misafirTakim;

                    ifstream takimBul;
                    takimBul.open("takimlar.txt");
                    takimBul.seekg(0, ios::beg);
                    Takim T1;
                    int takimEvNo = 0, takimMisafirNo = 0;
                    // Takımlar dosyasından takım isimlerine göre takımNO bilgilerini almak için döngü
                    while (takimBul >> T1.takimNO >> T1.adi >> T1.adresi >> T1.telefon >> T1.oyuncuSayisi >> T1.yoneticiIsmi)
                    {
                        if (T1.adi == evTakim) // Ev sahibi takımın takımNO bilgisini almak için koşul
                        {
							takimEvNo = T1.takimNO;
						}
                        else if (T1.adi == misafirTakim) // Misafir takımın takımNO bilgisini almak için koşul
                        {
                            takimMisafirNo = T1.takimNO;
                        }
                    }
                    takimBul.close();
                    if (takimEvNo == 0 && takimMisafirNo == 0) // Takımlar dosyasında takım isimlerine göre takımNO bulunamadıysa
                    {
                        cerr << "Takım bulunamadı! Takım eklemesi yapmayı deneyin.\n";
                        return;
                    }

                    int evSkor = 0, misafirSkor = 0;
                    string skor, tire; // Skor satırındaki gereksiz bilgileri atlamak için atama
                    getline(dosya, satir); // Tarih satırını atla
                    getline(dosya, satir); // Skor satırını oku

                    if (satir.find("Skor") != string::npos) // Skor satırı bulunduysa
                    {
						stringstream(satir) >> skor >> evSkor >> tire >> misafirSkor;
					}
                    else
                    {
						cerr << "Skor satırı bulunamadı!\n";
						return;
					}
                    // Puan ve diğer hesaplar için koşullar
                    if (evSkor > misafirSkor) // Ev sahibi kazandı, misafir kaybetti
                    {
                        takimPuanlari[takimEvNo] += 3;
                        takimPuanlari[takimMisafirNo] += 0;
                        takimGalibiyetSayisi[takimEvNo] += 1;
                        takimMaglubiyetSayisi[takimMisafirNo] += 1;
                        takimAttigiGolSayisi[takimEvNo] += evSkor;
                        takimYedigiGolSayisi[takimMisafirNo] += evSkor;
                        takimAttigiGolSayisi[takimMisafirNo] += misafirSkor;
                        takimYedigiGolSayisi[takimEvNo] += misafirSkor;
                        
                    }
                    else if (evSkor < misafirSkor) // Misafir kazandı, ev sahibi kaybetti
                    {
                        takimPuanlari[takimEvNo] += 0;
                        takimPuanlari[takimMisafirNo] += 3;
                        takimGalibiyetSayisi[takimMisafirNo] += 1;
                        takimMaglubiyetSayisi[takimEvNo] += 1;
                        takimAttigiGolSayisi[takimEvNo] += evSkor;
                        takimYedigiGolSayisi[takimMisafirNo] += evSkor;
                        takimAttigiGolSayisi[takimMisafirNo] += misafirSkor;
                        takimYedigiGolSayisi[takimEvNo] += misafirSkor;
                    }
                    else if (evSkor == misafirSkor) // Beraberlik durumu
                    {
                        takimPuanlari[takimEvNo] += 1; 
                        takimPuanlari[takimMisafirNo] += 1;
                        takimBeraberlikSayisi[takimEvNo] += 1;
                        takimBeraberlikSayisi[takimMisafirNo] += 1;
                        takimAttigiGolSayisi[takimEvNo] += evSkor;
                        takimYedigiGolSayisi[takimMisafirNo] += evSkor;
                        takimAttigiGolSayisi[takimMisafirNo] += misafirSkor;
                        takimYedigiGolSayisi[takimEvNo] += misafirSkor;
                    }
                }
            }
            dosya.close();  
        }
        else // Dosya açılmadıysa oynanmamış haftalar için de kayıt istenmiştir veya küçük ihtimal dosya açılamamıştır
        {
            cerr << "Dosya açma hatası! Önce oynanmış tüm maçların hafta kayıtlarını alın." << endl;
            break;
        }
    }

    // Takımları puanlarına göre sıralama işlemi
    for (int i = 1; i < takimSayisi; i++)
    {
        int enBuyukPuan = takimPuanlari[i];
        int enBuyukPuaninIndisi = i;

        // Dizi içinde en büyük puanı bulma
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[j] > enBuyukPuan) // Sonraki indisteki değer bir önceki indisteki değerden büyükse
            {
                enBuyukPuan = takimPuanlari[j];
                enBuyukPuaninIndisi = j;
            }
        }

        // Takımları puanlarına göre büyükten küçüğe sıralama
        if (enBuyukPuaninIndisi != i)
        {
            // Takımların tüm değerlerinin yerini değiştirme
            swap(takimlar[i], takimlar[enBuyukPuaninIndisi]); // 1. sıraya en büyük puana sahip takımı getir
            swap(takimPuanlari[i], takimPuanlari[enBuyukPuaninIndisi]); // 1. sıraya en büyük puanı getir vs...
            swap(takimOynadigiMacSayisi[i], takimOynadigiMacSayisi[enBuyukPuaninIndisi]);
            swap(takimAttigiGolSayisi[i], takimAttigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimYedigiGolSayisi[i], takimYedigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimAveraj[i], takimAveraj[enBuyukPuaninIndisi]);
            swap(takimGalibiyetSayisi[i], takimGalibiyetSayisi[enBuyukPuaninIndisi]);
            swap(takimBeraberlikSayisi[i], takimBeraberlikSayisi[enBuyukPuaninIndisi]);
            swap(takimMaglubiyetSayisi[i], takimMaglubiyetSayisi[enBuyukPuaninIndisi]);
        }
    }

    // Puanlar eşitse Averaj durumuna göre sıralama
    for (int i = 0; i < takimSayisi; i++)
    {
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[i] == takimPuanlari[j]) // Puanların eşit olduğu durumda
            {
                if (takimAveraj[i] < takimAveraj[j]) // Averajı küçükse yerlerini değiştir
                {
                    // Takımların yerini değiştirme
                    swap(takimlar[i], takimlar[j]); // 1. sıraya en büyük averaja sahip takımı getirdik
                    swap(takimPuanlari[i], takimPuanlari[j]); // 1. sıraya en büyük averajı getirdik
                    swap(takimOynadigiMacSayisi[i], takimOynadigiMacSayisi[j]);
                    swap(takimAttigiGolSayisi[i], takimAttigiGolSayisi[j]);
                    swap(takimYedigiGolSayisi[i], takimYedigiGolSayisi[j]);
                    swap(takimAveraj[i], takimAveraj[j]);
                    swap(takimGalibiyetSayisi[i], takimGalibiyetSayisi[j]);
                    swap(takimBeraberlikSayisi[i], takimBeraberlikSayisi[j]);
                    swap(takimMaglubiyetSayisi[i], takimMaglubiyetSayisi[j]);
                }
            }
		}
    }
    // Dosyaya tabloyu yazdırma
    ofstream puanDosyaYaz;
    puanDosyaYaz.open("SLTablo.txt");
    puanDosyaYaz << "Süper Lig Puan Durumu" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    puanDosyaYaz << "Takım\t\t  |\tPuan\t|\tO\t|\tG\t|\tM\t|\tB\t|\t+/-\t|\tA\t|" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    // Her bir takımın bilgilerini dosyaya yazdırma
    for (int i = 1; i < 21; i++)
    {
        takimOynadigiMacSayisi[i] = takimGalibiyetSayisi[i] + takimBeraberlikSayisi[i] + takimMaglubiyetSayisi[i];

        takimAveraj[i] = takimAttigiGolSayisi[i] - takimYedigiGolSayisi[i];
        string sira = to_string(i) + ".";
		puanDosyaYaz << left << setw(3) << sira << left << setw(15) << takimlar[i] << "|\t" << takimPuanlari[i] << "\t|\t"
         << takimOynadigiMacSayisi[i] << "\t|\t" << takimGalibiyetSayisi[i] << "\t|\t" << takimMaglubiyetSayisi[i] << "\t|\t" << takimBeraberlikSayisi[i] 
         << "\t|\t" << takimAttigiGolSayisi[i] << "/" << takimYedigiGolSayisi[i] 
         << "\t|\t" << takimAveraj[i] << "\t|\t" << endl;
        puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
    puanDosyaYaz.close();
	cout << "Lig tablosu başarıyla oluşturuldu." << endl;
}
