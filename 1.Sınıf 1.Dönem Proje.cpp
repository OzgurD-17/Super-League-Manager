/****************************************************************************************
**
**
**                        SAKARYA ÜNÝVERSÝTESÝ                                 
**              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                    
**                   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                          
**                     PROGRAMLAMAYA GÝRÝÞ DERSÝ                             
**                                                                       
**       ÖDEV NUMARASI    : 1. Dönem Projesi          TARÝH: 31/12/2023                      
**       ÖÐRENCÝ ADI      : Özgür Demir                         
**       ÖÐRENCÝ NUMARASI : B221210017                       
**       DERS GRUBU       : C                                     
**
**                                                                      
*****************************************************************************************/



#include <fstream>
#include <string>
#include <sstream> // stringstream dosya okuma iþlemlerinde belirli veriyi alabilmem için birkaç noktada gerekti
#include <iomanip>
#include <iostream>

using namespace std;

// Takým sýnýfý
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
    // Dosyayý okuma fonksiyonu
    void dosyayiOku(ifstream& dosya)
    {
        dosya >> takimNO >> adi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;
    }
};

// Futbolcu sýnýfý
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
    // Dosyayý okuma fonksiyonu
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
            << "\t SÜPER LÝG KONTROL MERKEZÝ \t" << endl
            << "---------------------------------------------" << endl << endl
            << "\t     ***-MENÜ-***" << endl << endl
            << "\t1-Takým Oluþturma:" << endl
            << "\t2-Takým Silme:" << endl
            << "\t3-Takýmlarý Listeleme:" << endl
            << "\t4-Takýma Futbolcu Ekleme:" << endl
            << "\t5-Takýmdan Futbolcu Silme:" << endl
            << "\t6-Ligdeki Futbolcularý Listeleme:" << endl
            << "\t7-Belirli Bir Takýmdaki Futbolcularý Listeleme:" << endl
            << "\t8-Takýmdaki Bir Futbolcuyu Güncelleme:" << endl
            << "\t9-Oyuncu Menüsü:" << endl
            << "\t10-Maç Kaydý:" << endl
            << "\t11-Haftalýk Lig Kaydý:" << endl
            << "\t12-Haftalýk Lig Kaydýný Görüntüle:" << endl
            << "\t13-Haftalýk Puan Durumlarý:" << endl
            << "\t0-Çýkýþ:" << endl << endl
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
                    << "\t4- Oyuncularý Listeleme\n"
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
            cout << "Programdan çýkýlýyor...\n";
            break;
        default:
            cout << "Geçersiz seçim!\n";
            break;
        }
    } while (secim != 0);

    return 0;
}


// Fonksiyonlar

// Takým oluþturma fonksiyonu
void takimOlustur()
{
    // Takým no alma ve kontrol
    Takim T1;
    cout << "Takým no girin: \n";
    cin >> T1.takimNO;
    cout << endl;
    if (T1.takimNO <= 0)
    {
		cout << "Takým no en az 1 olmalý!\n";
		return;
	}

    // Girilen takým no'ya sahip takým zaten var mý kontrol
    Takim T2;
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var mý (oluþturulmuþ mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T2.takimNO >> T2.adi >> T2.adresi >> T2.telefon >> T2.oyuncuSayisi >> T2.yoneticiIsmi)
        {
            if (T1.takimNO == T2.takimNO)
            {
                cout << "Bu takým no'ya sahip takým zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();
    
    cout << "Takým adý girin: \n";
    cin >> T1.adi;

    // Girilen takým adýna sahip takým zaten var mý kontrol
    Takim T3;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var mý (oluþturulmuþ mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T3.takimNO >> T3.adi >> T3.adresi >> T3.telefon >> T3.oyuncuSayisi >> T3.yoneticiIsmi)
        {
            if (T1.adi == T3.adi)
            {
                cout << "Bu takým adýna sahip takým zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();

    cout << "Takým adresini girin: \n";
    cin >> T1.adresi;
    cout << "Takým telefon numarasýný girin: \n";
    cin >> T1.telefon;
    cout << "Takýmdaki oyuncu sayýsýný girin: \n";
    cin >> T1.oyuncuSayisi;
    cout << "Takým yöneticisinin adýný girin: \n";
    cin >> T1.yoneticiIsmi;

    ofstream dosyaYaz;
    dosyaYaz.open("takimlar.txt", ios::app);
    //dosyaYaz.write(reinterpret_cast<char*>(&T1), sizeof(T1));
    T1.dosyayaYaz(dosyaYaz);
    dosyaYaz.close();
}
// Takým silme fonksiyonu
void takimSil()
{
    Takim T;
    int silinecekTakimNo;
    cout << "Silinecek Takým Numarasý: ";
    cin >> silinecekTakimNo;
    cout << endl;

    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Dosya açýldý mý kontrol
    {
		cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
		return;
	}

    takimKontrol.seekg(0, ios::beg);
    bool takimBulundu = false;
    // Girilen takým no'ya sahip takým var mý kontrol
    while (takimKontrol >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (silinecekTakimNo == T.takimNO)
        {
            takimBulundu = true;
			break;
		}
	}
    takimKontrol.close();
    if (!takimBulundu) // Takým bulunamadýysa hata ver
    {
        cout << "Girilen takým no'ya sahip takým bulunamadý.\n";
        return;
    }

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    ofstream geciciDosya;
    geciciDosya.open("gecici.txt");
    takimDosyaOku.seekg(0, ios::beg);
    geciciDosya.seekp(0, ios::beg);

    if (takimDosyaOku.is_open() && geciciDosya.is_open()) // Dosyalar açýldýysa devam et
    {   // Dosya içeriði okunurken koþula göre geçici dosyaya kaydet
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {   
            //takimDosyaOku.read(reinterpret_cast<char*>(&T), sizeof(T));
            if (T.takimNO != silinecekTakimNo) // Takým bulunmadýkça kaydet
            {
                T.dosyayaYaz(geciciDosya);
				//geciciDosya.write(reinterpret_cast<char*>(&T), sizeof(T));
			}
		}
        takimDosyaOku.close();
        geciciDosya.close();

        remove("takimlar.txt");
        if (rename("gecici.txt", "takimlar.txt")) // Dosya adý deðiþtirildi mi
        {
            cout << "Takým silme baþarýsýz." << endl;

		}
        else
        {
            cout << "Takým baþarýyla silindi." << endl;
		}
    }
    // Dosyalar veya dosya açýlmadýysa hata ver
    else {
        cerr << "Dosya açma hatasý!" << endl;
    }
}
// Takýmlarý listeleme fonksiyonu
void takimlariListele()
{
    ifstream takimDosyaOku;
	takimDosyaOku.open("takimlar.txt", ios::in);

    if (!takimDosyaOku.is_open()) // Dosya açýldý mý kontrol
    {
        cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
        return;
    }

    string satir;
    int takimSayisi = 0;
    // Takým sayýsýný alma
    while (getline(takimDosyaOku, satir))
    {
        takimSayisi += 1;
    }
    takimDosyaOku.close();
    //takimSayisi -= 1; // Son satýr boþ olduðu için 1 azaltma (ama gerek kalmýyor neden?)
    takimDosyaOku.open("takimlar.txt");
	Takim T;
	takimDosyaOku.seekg(0, ios::beg);
    if (takimDosyaOku.is_open()) // Dosya açýldý mý kontrol
    {
        cout << "Takýmlar (toplam " << takimSayisi << " adet):" << endl
            << "-----------------------------" << endl;
        // Takýmlarý ekrana yazdýrma
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {
			cout << "Takým No: " << T.takimNO << endl;
			cout << "Takým Adý: " << T.adi << endl;
			cout << "Takým Adresi: " << T.adresi << endl;
			cout << "Takým Telefonu: " << T.telefon << endl;
			cout << "Takýmdaki Oyuncu Sayýsý: " << T.oyuncuSayisi << endl;
			cout << "Takým Yöneticisi: " << T.yoneticiIsmi << endl;
			cout << "-----------------------------" << endl;
		}
		takimDosyaOku.close();
	}
    else
    {
		cerr << "Dosya açma hatasý!" << endl;
	}

}
// Takýma futbolcu ekleme fonksiyonu
void futbolcuEkle()
{
    Futbolcu F;
    cout << "Futbolcunun Ekleneceði Takýmýn TakýmNo'su: ";
    cin >> F.takimNO;

    // Girilen takým no'ya sahip takým var mý kontrol
    Takim T5;
    ifstream takimKontrol("takimlar.txt");
    bool takimBulundu = false;
    if (takimKontrol.is_open()) // Dosya var mý (oluþturulmuþ mu) kontrol
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
        cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
        return;
    }
    takimKontrol.close();
    if (!takimBulundu) // Takým bulunamadýysa hata ver
    {
        cout << "Girilen takým no'suna sahip takým bulunamadý.\n";
        return;
    }

    cout << "Futbolcunun TC Kimlik No'su: ";
    cin >> F.TCNO;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme
    // Temizlemeyince ve sayý atama sonrasý string atama iþlemi yapýnca atama eksik/hatalý oluyor

    // Girilen TC kimlik no'ya sahip baþka bir oyuncu var mý kontrol
    Futbolcu F2;
    ifstream tcKontrol("futbolcular.txt");
    if (tcKontrol.is_open()) // Dosya var mý (oluþturulmuþ mu) kontrol
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

    cout << "Futbolcunun Adý: ";
    getline(cin, F.adi);

    cout << "Futbolcunun Soyadý: ";
    getline(cin, F.soyadi);

    cout << "Lisans No'su: ";
    getline(cin, F.lisansNO);

    // Girilen lisans no'ya sahip baþka bir oyuncu var mý kontrol
    Futbolcu F3;
    ifstream lisansKontrol("futbolcular.txt");
    if (lisansKontrol.is_open()) // Dosya var mý (oluþturulmuþ mu) kontrol
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

    cout << "Doðum Tarihi: ";
    getline(cin, F.dogumTarihi);

    ofstream futbolcuYaz;
    futbolcuYaz.open("futbolcular.txt", ios::app);
    F.dosyayaYaz(futbolcuYaz);

    // Takým dosyasýný güncelleme
    Takim T;
    ifstream dosyaOku("takimlar.txt");
    ofstream tempYaz;
    tempYaz.open("temp.txt");

    dosyaOku.seekg(0, ios::beg);
    tempYaz.seekp(0, ios::beg);

    if (!dosyaOku.is_open() || !tempYaz.is_open()) // Dosyalar açýldý mý kontrol
    {
        cerr << "Dosya açýlamadý!" << endl;
        return;
    }

    takimBulundu = false;
    // Takýmý bulma ve oyuncu sayýsýný arttýrma
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (F.takimNO == T.takimNO) // Takým bulunduysa oyuncu sayýsýný arttýr
        {
            takimBulundu = true;
            T.oyuncuSayisi += 1;
        }
        T.dosyayaYaz(tempYaz);
    }

    dosyaOku.close();
    tempYaz.close();

    if (takimBulundu) // Takým dosya içinde varsa devam et
    {
        remove("takimlar.txt");
        if (rename("temp.txt", "takimlar.txt"))
        {
            cout << "Oyuncu ekleme baþarýsýz." << endl;
        }
        else
        {
            cout << "Oyuncu baþarýyla eklendi." << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "Takým bulunamadý." << endl;
        return;
    }
}
// Takýmdan futbolcu silme fonksiyonu
void futbolcuSil()
{
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Takýmlar var mý (oluþturulmuþ mu) kontrol
    {
        cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
        return;
    }
    takimKontrol.close();

    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var mý (oluþturulmuþ mu) kontrol
    {
        cerr << "Dosya açma hatasý! Önce futbolcu eklemeyi deneyin." << endl;
        return;
    }
    futbolcuKontrol.close();

    int takimno = 0;
    cout << "Oyuncusu silinecek takýmýn no'su: ";
    cin >> takimno;
    cout << endl;

    // Girilen takým no'ya sahip takým var mý kontrol
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    Takim T5;
    bool takimBulundu = false;
    if (takimDosyaOku.is_open()) // Dosya açýldý mý kontrol
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
    if (!takimBulundu) // Takým bulunamadýysa hata ver
    {
        cerr << "Girilen takým no'ya sahip takým bulunamadý.\n";
        return;
    }

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No'sunu kullanarak silmek için '1'i, Lisans No'su ile silmek için '2'yi tuþlayýn\n";
    cin >> answer;
    cout << endl;
    if (answer == 1)
    {
		string silinecektcno;
		cout << "Silinecek futbolcunun TC kimlik no'su: ";
		cin >> silinecektcno;
		cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var mý kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
		{
			tcKontrol.seekg(0, ios::beg);
			while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
			{
                if (silinecektcno == F.TCNO && takimno == F.takimNO) // Girilen TC kimlik no'ya sahip oyuncu varsa sil ama ayný takýmda olmalý
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
		tcKontrol.close();
        if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadý.\n";
            return;
        }

		ifstream futbolcudosyaoku("futbolcular.txt");
		ofstream gecicidosya("gecici_futbolcu.txt");
		// Dosyalar açýldý mý kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
			Futbolcu F;
			// Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.TCNO != silinecektcno) // Oyuncu TC'si silinecek TC'ye eþit deðilse kaydet
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
            cout << "Futbolcu silme iþlemi baþarýsýz oldu." << endl;
        }
        else
        {
            cout << "Futbolcu baþarýyla silindi." << endl;
        }
    }
    else if (answer == 2)
    {
        string silineceklisansno;
        cout << "Silinecek futbolcunun lisans no'su: ";
        cin >> silineceklisansno;
        
        // Girilen lisans no'ya sahip oyuncu var mý kontrol
        Futbolcu F;
        ifstream lisansKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (lisansKontrol.is_open()) // Dosya açýldý mý kontrol
		{
			lisansKontrol.seekg(0, ios::beg);
            while (lisansKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (silineceklisansno == F.lisansNO && takimno == F.takimNO) // Girilen lisans no'ya sahip oyuncu varsa sil ama ayný takýmda olmalý
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamadý.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açýldý mý kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.lisansNO != silineceklisansno) // Oyuncu LisansNo'su silinecek LisansNo'ya eþit deðilse kaydet
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
            cout << "Futbolcu silme iþlemi baþarýsýz oldu." << endl;
        }
        else
        {
            cout << "Futbolcu baþarýyla silindi." << endl;
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
    // Takým dosyasýný güncelleme
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Takým bulunduysa oyuncu sayýsýný 1 azalt
        {
            T.oyuncuSayisi -= 1;
        }
        T.dosyayaYaz(tempeYaz);
    }
    dosyaOku.close();
    tempeYaz.close();

    remove("takimlar.txt");
    if (rename("temp.txt", "takimlar.txt")) // Dosya adý deðiþtirildi mi kontrol
    {
        cout << "Takým güncelleme baþarýsýz." << endl;
    }
    else
    {
        cout << "Takým baþarýyla güncellendi." << endl;
    }
}
// Tüm futbolcularý listeleme fonksiyonu
void tumFutbolculariListele()
 {
    ifstream futbolcudosyaoku;
    futbolcudosyaoku.open("futbolcular.txt");
    if (!futbolcudosyaoku.is_open()) // Futbolcu var mý kontrol
	{
		cerr << "Dosya açma hatasý! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}

    string satir;
    int futbolcuSayisi = 0;
    futbolcudosyaoku.seekg(0, ios::beg);
    // Futbolcu sayýsýný bulma
    while (getline(futbolcudosyaoku, satir))
    {
        futbolcuSayisi += 1;
    }
    futbolcudosyaoku.close();
    //futbolcuSayisi -= 1; // Son satýr boþ olduðu için 1 azalt (azaltmaya gerek kalmadan doðru sayýyor ama neden?)
    futbolcudosyaoku.open("futbolcular.txt");
    if (futbolcudosyaoku.is_open()) // Dosya açýldý mý kontrol
    {
		 Futbolcu F;
         cout << "Futbolcular (toplam "<< futbolcuSayisi << " adet):" << endl;
         cout << "-----------------------------" << endl;
         // Futbolcularý ekrana yazdýrma
         while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
         {
			 cout << "Takým No: " << F.takimNO << endl;
			 cout << "TC Kimlik No: " << F.TCNO << endl;
			 cout << "Adý: " << F.adi << endl;
			 cout << "Soyadý: " << F.soyadi << endl;
			 cout << "Lisans No: " << F.lisansNO << endl;
			 cout << "Oyundaki Konumu: " << F.konumu << endl;
			 cout << "Ücreti: " << F.ucret << endl;
			 cout << "Doðum Tarihi: " << F.dogumTarihi << endl;
			 cout << "-----------------------------" << endl;
		 }
		 futbolcudosyaoku.close();
	}
    else
    {
		 cerr << "Dosya açma hatasý!" << endl;
	}
 
}
// Takýma göre futbolcularý listeleme fonksiyonu
void takimaGoreFutbolculariListele()
{
    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Takým var mý kontrol
    {
        cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
        return;
    }
    takimKontrol.close();

    int takimno = 0;
    cout << "Futbolcularý Listelenecek Takýmýn TakýmNo'su: ";
    cin >> takimno;
    cout << endl;

    ifstream takimOku("takimlar.txt");
    Takim T;
    bool takimBulundu = false;
    // Böyle bir takým var mý yok mu kontrol
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Takým bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku.close();

    if (!takimBulundu) // Takým bulunamadýysa dönüt
    {
        cout << "Girilen takýmNo'suna sahip takým bulunamadý.\n";
        return;
    }

    ifstream futbolcudosyaoku("futbolcular.txt");

    if (!futbolcudosyaoku.is_open()) // Futbolcu var mý kontrol
	{
		cerr << "Dosya açma hatasý! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    else if (futbolcudosyaoku.is_open())
    {
        Futbolcu F;
        cout << takimno << " No'lu Takýmýn Futbolcularý:" << endl;
        cout << "-----------------------------" << endl;
        // Takýma ait futbolcularý ekrana yazdýrma
        while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
        {
            if (F.takimNO == takimno) // Takým bulunduysa ekrana yazdýr
            {
                cout << "Takým No: " << F.takimNO << endl;
                cout << "TC Kimlik No: " << F.TCNO << endl;
                cout << "Adý: " << F.adi << endl;
                cout << "Soyadý: " << F.soyadi << endl;
                cout << "Lisans No: " << F.lisansNO << endl;
                cout << "Oyundaki Konumu: " << F.konumu << endl;
                cout << "Ücreti: " << F.ucret << endl;
                cout << "Doðum Tarihi: " << F.dogumTarihi << endl;
                cout << "-----------------------------" << endl;
            }
        }
        futbolcudosyaoku.close();
    }
    else
    {
        cerr << "Dosya açma hatasý!" << endl;
    }
}
// Futbolcu güncelleme fonksiyonu
void futbolcuGuncelle()
{
    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var mý (oluþturulmuþ mu) kontrol
    {
		cerr << "Dosya açma hatasý! Önce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    futbolcuKontrol.close();

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No ile güncellemek için '1'i, Lisans No ile güncellemek için '2'yi tuþlayýn\n";
    cin >> answer;
    cout << endl;

    if (answer != 1 && answer != 2)
    {
        cout << "Hatalý seçim!\n";
        return;
    }

    if (answer == 1)
    {
        string guncellenecektcno;
        cout << "Güncellenecek Futbolcunun TC kimlik No Bilgisi: ";
        cin >> guncellenecektcno;
        cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var mý kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        string guncelleneceklisansno;
        if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
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

        if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
        {
			cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadý.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açýldý mý kontrolü
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // Eðer oyuncu bulunmadýysa direkt dosyaya yaz
                if (F.TCNO != guncellenecektcno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // Güncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Takým No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    // Girilen TC kimlik no'ya sahip baþka bir oyuncu var mý kontrol
                    Futbolcu F2;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
                    {
						tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F2.takimNO >> F2.TCNO >> F2.adi >> F2.soyadi >> F2.lisansNO >> F2.konumu >> F2.ucret >> F2.dogumTarihi)
                        {
                            if (guncellenecektcno == F2.TCNO) // Kendi TC'si hariç ayný TC'ye sahip baþka bir oyuncu var mý kontrol et
                            {
                                continue;
                            }

                            if (F.TCNO == F2.TCNO) // Girilen TC kimlik no'ya sahip baþka bir oyuncu var mý kontrol et
                            {
								cout << "Bu TC kimlik no'ya sahip bir oyuncu zaten var!\n";
								return;
							}
						}
					}

                    cout << "Yeni Adý: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyadý: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip baþka bir oyuncu var mý kontrol
                    Futbolcu F3;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya açýldý mý kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F3.takimNO >> F3.TCNO >> F3.adi >> F3.soyadi >> F3.lisansNO >> F3.konumu >> F3.ucret >> F3.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F3.lisansNO) // Kendi Lisans No'su hariç ayný Lisans No'ya sahip oyuncu var mý kontrol et
                            {
                                continue;
                            }

                            if (F.lisansNO == F3.lisansNO) // Girilen lisans no'ya sahip baþka bir oyuncu var mý kontrol et
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

                    cout << "Yeni Doðum Tarihi: ";
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
        // Girilen lisans no'ya sahip bir oyuncu var mý kontrol
        if (lisansKontrol.is_open()) // Dosya açýldý mý kontrol
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
			cerr << "Dosya açma hatasý! Futbolcu eklemeyi deneyin." << endl;
			return;
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamadý.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar açýldý mý kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Geçici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // Eðer oyuncu bulunmadýysa direkt dosyaya yaz
                if (F.lisansNO != guncelleneceklisansno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // Güncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Takým No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme


                    // Girilen TC kimlik no'ya sahip baþka bir oyuncu var mý kontrol
                    Futbolcu F6;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
                    {
                        tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F6.takimNO >> F6.TCNO >> F6.adi >> F6.soyadi >> F6.lisansNO >> F6.konumu >> F6.ucret >> F6.dogumTarihi)
                        {
                            if (guncellenecektcno == F6.TCNO) // Kendi TC'si hariç ayný TC'ye sahip oyuncu var mý kontrol et
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

                    cout << "Yeni Adý: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyadý: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip oyuncu var mý kontrol
                    Futbolcu F7;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya açýldý mý kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F7.takimNO >> F7.TCNO >> F7.adi >> F7.soyadi >> F7.lisansNO >> F7.konumu >> F7.ucret >> F7.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F7.lisansNO) // Kendi LisansNo'su hariç ayný LisansNo'ya sahip oyuncu var mý kontrol et
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

                    cout << "Yeni Doðum Tarihi: ";
                    getline(cin, F.dogumTarihi);

                    F.dosyayaYaz(gecicidosya);
                }
            }
            futbolcudosyaoku.close();
            gecicidosya.close();
        }
    }

	remove("futbolcular.txt");
    // Dosya adý deðiþtirildi mi kontrol
    if (rename("gecici_futbolcu.txt", "futbolcular.txt"))
    {
        cout << "Futbolcu güncelleneme iþlemi baþarýsýz." << endl;
	}
    else
    {
        cout << "Futbolcu baþarýyla güncellendi." << endl;
    }
}
// Maç kaydý alma fonksiyonu
void futbolOyunuKaydi()
{
    // Takým kontrolü
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Takýmlar var mý (oluþturulmuþ mu) kontrol
    {
		cerr << "Dosya açma hatasý! Önce takým oluþturmayý deneyin." << endl;
		return;
	}
    takimKontrol.close();

    string evSahibi;
    cout << "Ev sahibi takýmýn adýný girin: ";
    cin.ignore(); // Sayýsal giriþ aldýktan sonra metinsel giriþ alýyosak gerekiyor
    getline(cin, evSahibi);                  // Önceki giriþlerin tamamýný temizler
    cout << endl;

    // Böyle bir takým var mý yok mu kontrol
    Takim T;
    ifstream takimOku("takimlar.txt");
    bool takimBulundu = false;
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (evSahibi == T.adi) // Takým bulundu mu kontrol
        {
			takimBulundu = true;
			break;
		}
	}
    takimOku.close();
    if (!takimBulundu) // Takým bulunamadýysa dönüt
    {
        cerr << "Girilen takým bulunamadý.\n";
        return;
    }

    string rakipTakim;
    cout << "Karþýlaþýlan takýmýn adýný girin: ";
    getline(cin, rakipTakim);
    cout << endl;

    // Böyle bir takým var mý yok mu kontrol
    ifstream takimOku2("takimlar.txt");
    takimOku2.seekg(0, ios::beg);
    takimBulundu = false;
    while (takimOku2 >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (rakipTakim == T.adi) // Takým bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku2.close();
    if (!takimBulundu) // Takým bulunamadýysa dönüt
    {
		cerr << "Girilen takým bulunamadý.\n";
		return;
	}

    int skorEv = 0, skorMisafir = 0;
    cout << "Ev sahibi takým skoru: ";
    cin >> skorEv;
    if (skorEv < 0) // Skor negatif olamaz
    {
		cout << "Skor negatif olamaz!\n";
		return;
	}

    cout << "Misafir takým skoru: ";
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
    cout << "Kaçýncý hafta: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sýfýr olamaz
    {
		cout << "Hafta negatif veya sýfýr olamaz!\n";
		return;
	}

    ofstream maclarDosyaYaz;
    maclarDosyaYaz.open("maclar.txt", ios::app);
    maclarDosyaYaz << "\t" << evSahibi << " vs " << rakipTakim << endl;
    maclarDosyaYaz << hafta << ". Hafta Karþýlaþmasý Kaydý\n";
    maclarDosyaYaz << "##############################" << endl;
    maclarDosyaYaz << "Tarih: " << tarih << endl;
    maclarDosyaYaz << "Skor: " << skorEv << " - " << skorMisafir << endl;

    int toplamGolAtanOyuncu = 0;
    cout << "Toplam kaç farklý oyuncu gol attý: ";
    cin >> toplamGolAtanOyuncu;
    if (toplamGolAtanOyuncu < 0)
    {
		cout << "Gol atan oyuncu sayýsý negatif olamaz!\n";
		return;
	}

    string golAtan;
    int gol = 0;
    // Gol yoksa terminale gereksiz yazma
    if (toplamGolAtanOyuncu > 0)
    {
        cout << "Gol Atan Oyuncular:\n";
    }
    
    maclarDosyaYaz << "Gol Atan Farklý Oyuncu Sayýsý: " << toplamGolAtanOyuncu << endl;
    maclarDosyaYaz << "Gol Atan Oyuncular:\n";
    
    for (int i = 1; i <= toplamGolAtanOyuncu; i++)
    {
        cout << "Gol Atan Oyuncunun TC'si: ";
        cin >> golAtan;

        // Girilen TC kimlik no'ya sahip oyuncu var mý kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
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
        if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadý.\n";
            return;
        }


        cout << "Attýðý Gol Sayýsý: ";
        cin >> gol;
        if (gol < 0) // Gol negatif olamaz
        {
            cout << "Gol sayýsý negatif olamaz!\n";
            return;
        }

        maclarDosyaYaz << golAtan << ": " << gol << " Gol\n";
    }
    maclarDosyaYaz << "-------------------------------" << endl;

    // Maçta oynayan oyuncularý kaydetme

    int oyuncuSayisi;
    cout << "Maçta oynayan oyuncu sayýsý: ";
    cin >> oyuncuSayisi;
    if (oyuncuSayisi <= 21) // Oyuncu sayýsý 22 den küçük olamaz
    {
		cout << "Oyuncu sayýsý 22 den küçük olamaz!\n";
		return;
	}

    char answer = 'h';
    cout << "Maçta oynayan oyuncularýn TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (" << oyuncuSayisi << " adet kayýt gerekli)\n";
    cin >> answer;
    if (answer == 'e' || answer == 'E') // Giriþ kontrolü
    {
        maclarDosyaYaz << "Maçta Oynayan Oyuncu Sayýsý: " << oyuncuSayisi << endl;
        maclarDosyaYaz << "Maçta Oynayan Oyuncular: \n";
        maclarDosyaYaz << "-------------------------------" << endl;
        // Her bir oyuncuyu kaydetmek için döngü
        for (int i = 1; i <= oyuncuSayisi; i++)
        {
            string oyuncuTC;
            cout << i << ". Oyuncunun TC Kimlik Numarasý: ";
            cin >> oyuncuTC;

            // Girilen TC kimlik no'ya sahip oyuncu var mý kontrol
            Futbolcu F;
            ifstream tcKontrol("futbolcular.txt");
            bool futbolcuBulundu = false;
            if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
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
            if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
            {
				cout << "Girilen TC Kimlik No'ya sahip oyuncu bulunamadý.\n";
				return;
			}
            maclarDosyaYaz << i << ". Oynayan Oyuncu: " << oyuncuTC << endl;
        } 
    }
    else
    {
        cout << "Sadece oynayan oyuncularýn sayý bilgisi kaydedildi.\n";
        maclarDosyaYaz << "Maçta Oynayan Oyuncu Sayýsý: " << oyuncuSayisi << endl;
    }

    // Oyuncu deðiþikliklerini kaydetme

    int degisiklikSayisi;
    cout << "Maç sýrasýnda kaç oyuncu deðiþikliði oldu: ";
    cin >> degisiklikSayisi;
    if (degisiklikSayisi < 0) // Deðiþiklik sayýsý negatif olamaz
    {
        cout << "Deðiþiklik sayýsý negatif olamaz!\n";
        return;
    }
    if (degisiklikSayisi > 10) // Deðiþiklik sayýsý 10'dan fazla olamaz
    {
		cout << "Deðiþiklik sayýsý 10'dan fazla olamaz!\n";
		return;
	}
    if (degisiklikSayisi > 0) // Deðiþiklik varsa
    {
        answer = 'h';
        cout << "Maçta giren-çýkan oyuncularýn TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (toplam " << degisiklikSayisi << " kadar kayýt gerekli)\n";
        cin >> answer;
        if (answer == 'e' || answer == 'E') // Giriþ kontrolü
        {
            maclarDosyaYaz << "Maçta Yapýlan Deðiþiklik Sayýsý: " << degisiklikSayisi << endl;
            // Deðiþiklikleri kaydetmek için döngü
            for (int i = 1; i <= degisiklikSayisi; ++i)
            {
                string degisenOyuncuTC, girenOyuncuTC;
                cout << i << ". Çýkan Oyuncunun TC Kimlik Numarasý: ";
                cin >> degisenOyuncuTC;

                // Deðiþen oyuncunun TC kimlik no kontrolü (tc kimlik hiçbir futbolcuda yoksa hata ver)
                Futbolcu F;
                ifstream tcKontrol("futbolcular.txt");
                bool futbolcuBulundu = false;
                if (tcKontrol.is_open()) // Dosya açýldý mý kontrol
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
                if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadý.\n";
                    return;
                }

                maclarDosyaYaz << i << ". Çýkan Oyuncu: " << degisenOyuncuTC << endl;
                cout << i << ". Giren Oyuncunun TC Kimlik Numarasý: ";
                cin >> girenOyuncuTC;

                // Giren oyuncunun TC kimlik no kontrolü (tc kimlik hiçbir futbolcuda yoksa hata ver)
                Futbolcu F2;
                ifstream tcKontrol2("futbolcular.txt");
                futbolcuBulundu = false;
                if (tcKontrol2.is_open()) // Dosya açýldý mý kontrol
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
                if (!futbolcuBulundu) // Futbolcu bulunamadýysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamadý.\n";
                    return;
                }
                maclarDosyaYaz << i << ". Giren Oyuncu: " << girenOyuncuTC << endl;
            }
        }
        else
        {
            cout << "Sadece yapýlan deðiþiklik sayýsý kaydedildi\n";
            maclarDosyaYaz << "Maçta Yapýlan Deðiþiklik Sayýsý: " << degisiklikSayisi << endl;
        }
    }
    else // Deðiþiklik 0 ise
    {
        maclarDosyaYaz << "Maçta Yapýlan Deðiþiklik Sayýsý: " << degisiklikSayisi << endl;
    }
    maclarDosyaYaz << "------------------------------" << endl;
    maclarDosyaYaz.close();

    cout << "Maç kaydý baþarýyla oluþturuldu." << endl;
}
// Haftalýk kayýt alma fonksiyonu
void haftalikKayit()
{
    // Maçlar kontrolü
    ifstream maclarKontrol("maclar.txt");
    if (!maclarKontrol.is_open()) // Maçlar var mý (oluþturulmuþ mu) kontrol
    {
        cerr << "Dosya açma hatasý! Önce maç kaydý oluþturmayý deneyin." << endl;
        return;
    }

    int istekHafta = 0;
    cout << "Kaçýncý haftanýn kaydý yapýlacak: ";
    cin >> istekHafta;
    if (istekHafta <= 0) // Hafta negatif veya sýfýr olamaz
    {
		cout << "Hafta negatif veya sýfýr olamaz!\n";
		return;
	}

    // Ýstenilen haftaya kadar kayýt yapmak için döngü (ama tam çalýþmýyor sadece girilen haftayý yapýyor)
    for (int i = 1; i <= istekHafta; i++)
    {
        string kayit = to_string(istekHafta) + ". hafta_kayit.txt";
        ofstream maclarDosyasi(kayit);
        ifstream maclarOku("maclar.txt");
        if (maclarDosyasi.is_open() && maclarOku.is_open()) // Dosyalar açýldý mý kontrol
        {
            cout << to_string(i) << ". Hafta oynanan maçlar kaydediliyor..." << endl;
            string satir;
            maclarOku.seekg(0);
            maclarDosyasi.seekp(0);
            string haftaBilgisi = to_string(istekHafta) + ". Hafta Karþýlaþmasý Kaydý";
            bool istekHaftaBasladi = false;
            string oncekiSatir;
            int a = 1;

            // Tüm maçlarýn kaydedildiði dosyadan haftaya göre maç seçmek için döngü
            while (getline(maclarOku, satir))
            {
                // Ýstenilen haftayý bulma kontrolü
                if (satir.find(haftaBilgisi) != string::npos)
                {
                    istekHaftaBasladi = true;
                }
                else
                {
                    istekHaftaBasladi = false;
                }

                // Hafta bulunduysa yapýlacak iþlemler
                if (istekHaftaBasladi)
                {
                    if (a) // Maçý yapan takýmlarý yazdýrmak için döngüde tek sefer çalýþan koþul
                    {
                        maclarDosyasi << oncekiSatir << endl;
                        a = 0;
                    }
                    // Bulunan haftanýn bilgilerini almak için döngü
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
                        // Goller ile ilgili satýrlarý alma
                        else if (satir.find("Gol") != string::npos)
                        {
                            maclarDosyasi << satir << endl;
                        }
                        // Maç kaydýnýn ilk parçasý bitti ise 2. parçayý
                       // atlayýp diðer maç kaydýna geçme
                        else if (satir.find("---") != string::npos)
                        {
                            a = 1;
                            getline(maclarOku, satir); // Gereksiz satýrý atlama
                            getline(maclarOku, satir); // Gereksiz satýrý atlama
                            getline(maclarOku, satir); // Gereksiz satýrý atlama
                            maclarDosyasi << satir << endl; //araya "-----" için
                            //getline(maclarOku, satir); // Gereksiz satýrý atlama

                            break;
                        }
                    }
                }
                oncekiSatir = satir; // Maçý yapan takýmlarý alma
                // (maclar dosyasýnda hafta bilgisinden hemen önce yer alýyorlar)
            }
            maclarDosyasi.close();
            maclarOku.close();
            cout << "Haftanýn kaydý baþarýyla tamamlandý.\n";
        }
        else // Dosyalar açýlmadýysa oynanmamýþ haftalar için de kayýt istenmiþtir veya küçük ihtimal dosya açýlamamýþtýr
        {
            cerr << "Dosya açma hatasý! Haftasý oynanmamýþ maçlar için de kayýt istemiþ olabilirsiniz. Maç kaydý yapmayý deneyin." << endl;
            break;
        }
	}
}
// Haftalýk kayýt görüntüleme fonksiyonu
void haftalikKayitGoruntule()
{
	int hafta = 0;
	cout << "Kaydý görüntülenecek haftayý girin: ";
	cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sýfýr olamaz
    {
		cout << "Hafta negatif veya sýfýr olamaz!\n";
		return;
	}
    // Dosyayý okuma
	string haftaBilgisi = to_string(hafta) + ". hafta_kayit.txt";
	ifstream dosya(haftaBilgisi);
    if (dosya.is_open()) // Dosya açýldý mý kontrol
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
		cerr << "Dosya açma hatasý! Dosya var olmayabilir, haftalýk kayýt oluþturmayý deneyin." << endl;
        return;
	}
}
// Haftalýk puan durumu görüntüleme fonksiyonu
void haftalikPuanDurumlari()
{
    int hafta = 0;
    cout << "Puan durumu gösterilecek haftayý girin: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya sýfýr olamaz
    {
        cout << "Hafta negatif veya sýfýr olamaz!\n";
        return;
    }
    const int takimSayisi = 21; // Aslýnda 20 takým var ama 0. indis boþ kalýyor çünkü takýmlar dosyasý 1. deðerden baþlýyor
    
    string takimlar[takimSayisi]{}; // Takýmlarýn isimlerini tutacak dizi
    int takimPuanlari[takimSayisi] = { 0 }; // Takýmlarýn puanlarýný tutacak dizi
    int takimOynadigiMacSayisi[takimSayisi] = { 0 }; // Takýmlarýn oynadýðý maç sayýsýný tutacak dizi
    int takimAttigiGolSayisi[takimSayisi] = { 0 }; // Takýmlarýn attýðý gol sayýsýný tutacak dizi
    int takimYedigiGolSayisi[takimSayisi] = { 0 }; // Takýmlarýn yediði gol sayýsýný tutacak dizi
    int takimAveraj[takimSayisi] = { 0 }; // Takýmlarýn averajýný tutacak dizi
    int takimGalibiyetSayisi[takimSayisi] = { 0 }; // Takýmlarýn galibiyet sayýsýný tutacak dizi
    int takimBeraberlikSayisi[takimSayisi] = { 0 }; // Takýmlarýn beraberlik sayýsýný tutacak dizi
    int takimMaglubiyetSayisi[takimSayisi] = { 0 }; // Takýmlarýn maðlubiyet sayýsýný tutacak dizi
    
    Takim T;

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt", ios::in);
    takimDosyaOku.seekg(0, ios::beg);
    // Takýmlarýn isimlerini alma
    while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        takimlar[T.takimNO] = T.adi;
    }
    takimDosyaOku.close();

    // Her bir hafta kaydýndan verileri alma
    for (int i = 1; i <= hafta; i++)
    {
        string haftaBilgisi = to_string(i) + ". hafta_kayit.txt";
        ifstream dosya(haftaBilgisi);
        if (dosya.is_open()) // Dosya açýldý mý kontrol
        {
            string satir;
            // Dosya içeriðini satýr satýr okuma
            while (getline(dosya, satir))
            {
                // Takýmlarýn isimlerini almak için koþul (bununla o takýmýn takýmNO bilgisini alýyoruz)
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
                    // Takýmlar dosyasýndan takým isimlerine göre takýmNO bilgilerini almak için döngü
                    while (takimBul >> T1.takimNO >> T1.adi >> T1.adresi >> T1.telefon >> T1.oyuncuSayisi >> T1.yoneticiIsmi)
                    {
                        if (T1.adi == evTakim) // Ev sahibi takýmýn takýmNO bilgisini almak için koþul
                        {
							takimEvNo = T1.takimNO;
						}
                        else if (T1.adi == misafirTakim) // Misafir takýmýn takýmNO bilgisini almak için koþul
                        {
                            takimMisafirNo = T1.takimNO;
                        }
                    }
                    takimBul.close();
                    if (takimEvNo == 0 && takimMisafirNo == 0) // Takýmlar dosyasýnda takým isimlerine göre takýmNO bulunamadýysa
                    {
                        cerr << "Takým bulunamadý! Takým eklemesi yapmayý deneyin.\n";
                        return;
                    }

                    int evSkor = 0, misafirSkor = 0;
                    string skor, tire; // Skor satýrýndaki gereksiz bilgileri atlamak için atama
                    getline(dosya, satir); // Tarih satýrýný atla
                    getline(dosya, satir); // Skor satýrýný oku

                    if (satir.find("Skor") != string::npos) // Skor satýrý bulunduysa
                    {
						stringstream(satir) >> skor >> evSkor >> tire >> misafirSkor;
					}
                    else
                    {
						cerr << "Skor satýrý bulunamadý!\n";
						return;
					}
                    // Puan ve diðer hesaplar için koþullar
                    if (evSkor > misafirSkor) // Ev sahibi kazandý, misafir kaybetti
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
                    else if (evSkor < misafirSkor) // Misafir kazandý, ev sahibi kaybetti
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
        else // Dosya açýlmadýysa oynanmamýþ haftalar için de kayýt istenmiþtir veya küçük ihtimal dosya açýlamamýþtýr
        {
            cerr << "Dosya açma hatasý! Önce oynanmýþ tüm maçlarýn hafta kayýtlarýný alýn." << endl;
            break;
        }
    }

    // Takýmlarý puanlarýna göre sýralama iþlemi
    for (int i = 1; i < takimSayisi; i++)
    {
        int enBuyukPuan = takimPuanlari[i];
        int enBuyukPuaninIndisi = i;

        // Dizi içinde en büyük puaný bulma
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[j] > enBuyukPuan) // Sonraki indisteki deðer bir önceki indisteki deðerden büyükse
            {
                enBuyukPuan = takimPuanlari[j];
                enBuyukPuaninIndisi = j;
            }
        }

        // Takýmlarý puanlarýna göre büyükten küçüðe sýralama
        if (enBuyukPuaninIndisi != i)
        {
            // Takýmlarýn tüm deðerlerinin yerini deðiþtirme
            swap(takimlar[i], takimlar[enBuyukPuaninIndisi]); // 1. sýraya en büyük puana sahip takýmý getir
            swap(takimPuanlari[i], takimPuanlari[enBuyukPuaninIndisi]); // 1. sýraya en büyük puaný getir vs...
            swap(takimOynadigiMacSayisi[i], takimOynadigiMacSayisi[enBuyukPuaninIndisi]);
            swap(takimAttigiGolSayisi[i], takimAttigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimYedigiGolSayisi[i], takimYedigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimAveraj[i], takimAveraj[enBuyukPuaninIndisi]);
            swap(takimGalibiyetSayisi[i], takimGalibiyetSayisi[enBuyukPuaninIndisi]);
            swap(takimBeraberlikSayisi[i], takimBeraberlikSayisi[enBuyukPuaninIndisi]);
            swap(takimMaglubiyetSayisi[i], takimMaglubiyetSayisi[enBuyukPuaninIndisi]);
        }
    }

    // Puanlar eþitse Averaj durumuna göre sýralama
    for (int i = 0; i < takimSayisi; i++)
    {
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[i] == takimPuanlari[j]) // Puanlarýn eþit olduðu durumda
            {
                if (takimAveraj[i] < takimAveraj[j]) // Averajý küçükse yerlerini deðiþtir
                {
                    // Takýmlarýn yerini deðiþtirme
                    swap(takimlar[i], takimlar[j]); // 1. sýraya en büyük averaja sahip takýmý getirdik
                    swap(takimPuanlari[i], takimPuanlari[j]); // 1. sýraya en büyük averajý getirdik
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
    // Dosyaya tabloyu yazdýrma
    ofstream puanDosyaYaz;
    puanDosyaYaz.open("SLTablo.txt");
    puanDosyaYaz << "Süper Lig Puan Durumu" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    puanDosyaYaz << "Takým\t\t  |\tPuan\t|\tO\t|\tG\t|\tM\t|\tB\t|\t+/-\t|\tA\t|" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    // Her bir takýmýn bilgilerini dosyaya yazdýrma
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
	cout << "Lig tablosu baþarýyla oluþturuldu." << endl;
}