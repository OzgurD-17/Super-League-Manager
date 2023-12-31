/****************************************************************************************
**
**
**���������               SAKARYA �N�VERS�TESݠ��������������������������������
**�����         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTESݠ�������������������
**��������           B�LG�SAYAR M�HEND�SL��� B�L�Mܠ�������������������������
**�������   ���        PROGRAMLAMAYA G�R�� DERSݠ����������������������������
**�����������������������������������������������������������������������
**����� ��DEV NUMARASI��� : 1. D�nem Projesi����������TAR�H: 31/12/2023����������������������
**����� ���RENC� ADI����� : �zg�r Demir�������������������������
**����� ���RENC� NUMARASI : B221210017�����������������������
**������ DERS GRUBU������ : C�������������������������������������
**
** ���������������������������������������������������������������������
*****************************************************************************************/



#include <fstream>
#include <string>
#include <sstream> // stringstream dosya okuma i�lemlerinde belirli veriyi alabilmem i�in birka� noktada gerekti
#include <iomanip>
#include <iostream>

using namespace std;

// Tak�m s�n�f�
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
    // Dosyay� okuma fonksiyonu
    void dosyayiOku(ifstream& dosya)
    {
        dosya >> takimNO >> adi >> adresi >> telefon >> oyuncuSayisi >> yoneticiIsmi;
    }
};

// Futbolcu s�n�f�
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
    // Dosyay� okuma fonksiyonu
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
    // Ana men�
    int secim;
    do
    {
        cout << "\n---------------------------------------------" << endl
            << "\t S�PER L�G KONTROL MERKEZ� \t" << endl
            << "---------------------------------------------" << endl << endl
            << "\t     ***-MEN�-***" << endl << endl
            << "\t1-Tak�m Olu�turma:" << endl
            << "\t2-Tak�m Silme:" << endl
            << "\t3-Tak�mlar� Listeleme:" << endl
            << "\t4-Tak�ma Futbolcu Ekleme:" << endl
            << "\t5-Tak�mdan Futbolcu Silme:" << endl
            << "\t6-Ligdeki Futbolcular� Listeleme:" << endl
            << "\t7-Belirli Bir Tak�mdaki Futbolcular� Listeleme:" << endl
            << "\t8-Tak�mdaki Bir Futbolcuyu G�ncelleme:" << endl
            << "\t9-Oyuncu Men�s�:" << endl
            << "\t10-Ma� Kayd�:" << endl
            << "\t11-Haftal�k Lig Kayd�:" << endl
            << "\t12-Haftal�k Lig Kayd�n� G�r�nt�le:" << endl
            << "\t13-Haftal�k Puan Durumlar�:" << endl
            << "\t0-��k��:" << endl << endl
            << "Se�iminiz: ";
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
            // Oyuncu men�s�
            int oyuncuSecim;
            do {
                cout << "Oyuncu Men�s�:\n"
                    << "\t1- Oyuncu Ekleme\n"
                    << "\t2- Oyuncu Silme\n"
                    << "\t3- Oyuncu G�ncelleme\n"
                    << "\t4- Oyuncular� Listeleme\n"
                    << "\t0- Ana Men�ye D�n\n"
                    << "Se�iminiz: ";
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
                    cout << "Ge�ersiz se�im!\n";
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
            cout << "Programdan ��k�l�yor...\n";
            break;
        default:
            cout << "Ge�ersiz se�im!\n";
            break;
        }
    } while (secim != 0);

    return 0;
}


// Fonksiyonlar

// Tak�m olu�turma fonksiyonu
void takimOlustur()
{
    // Tak�m no alma ve kontrol
    Takim T1;
    cout << "Tak�m no girin: \n";
    cin >> T1.takimNO;
    cout << endl;
    if (T1.takimNO <= 0)
    {
		cout << "Tak�m no en az 1 olmal�!\n";
		return;
	}

    // Girilen tak�m no'ya sahip tak�m zaten var m� kontrol
    Takim T2;
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var m� (olu�turulmu� mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T2.takimNO >> T2.adi >> T2.adresi >> T2.telefon >> T2.oyuncuSayisi >> T2.yoneticiIsmi)
        {
            if (T1.takimNO == T2.takimNO)
            {
                cout << "Bu tak�m no'ya sahip tak�m zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();
    
    cout << "Tak�m ad� girin: \n";
    cin >> T1.adi;

    // Girilen tak�m ad�na sahip tak�m zaten var m� kontrol
    Takim T3;
    takimDosyaOku.open("takimlar.txt");
    if (takimDosyaOku.is_open()) // Dosya var m� (olu�turulmu� mu) kontrol
    {
        takimDosyaOku.seekg(0, ios::beg);
        while (takimDosyaOku >> T3.takimNO >> T3.adi >> T3.adresi >> T3.telefon >> T3.oyuncuSayisi >> T3.yoneticiIsmi)
        {
            if (T1.adi == T3.adi)
            {
                cout << "Bu tak�m ad�na sahip tak�m zaten var!\n";
                return;
            }
        }
    }
    takimDosyaOku.close();

    cout << "Tak�m adresini girin: \n";
    cin >> T1.adresi;
    cout << "Tak�m telefon numaras�n� girin: \n";
    cin >> T1.telefon;
    cout << "Tak�mdaki oyuncu say�s�n� girin: \n";
    cin >> T1.oyuncuSayisi;
    cout << "Tak�m y�neticisinin ad�n� girin: \n";
    cin >> T1.yoneticiIsmi;

    ofstream dosyaYaz;
    dosyaYaz.open("takimlar.txt", ios::app);
    //dosyaYaz.write(reinterpret_cast<char*>(&T1), sizeof(T1));
    T1.dosyayaYaz(dosyaYaz);
    dosyaYaz.close();
}
// Tak�m silme fonksiyonu
void takimSil()
{
    Takim T;
    int silinecekTakimNo;
    cout << "Silinecek Tak�m Numaras�: ";
    cin >> silinecekTakimNo;
    cout << endl;

    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Dosya a��ld� m� kontrol
    {
		cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
		return;
	}

    takimKontrol.seekg(0, ios::beg);
    bool takimBulundu = false;
    // Girilen tak�m no'ya sahip tak�m var m� kontrol
    while (takimKontrol >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (silinecekTakimNo == T.takimNO)
        {
            takimBulundu = true;
			break;
		}
	}
    takimKontrol.close();
    if (!takimBulundu) // Tak�m bulunamad�ysa hata ver
    {
        cout << "Girilen tak�m no'ya sahip tak�m bulunamad�.\n";
        return;
    }

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    ofstream geciciDosya;
    geciciDosya.open("gecici.txt");
    takimDosyaOku.seekg(0, ios::beg);
    geciciDosya.seekp(0, ios::beg);

    if (takimDosyaOku.is_open() && geciciDosya.is_open()) // Dosyalar a��ld�ysa devam et
    {   // Dosya i�eri�i okunurken ko�ula g�re ge�ici dosyaya kaydet
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {   
            //takimDosyaOku.read(reinterpret_cast<char*>(&T), sizeof(T));
            if (T.takimNO != silinecekTakimNo) // Tak�m bulunmad�k�a kaydet
            {
                T.dosyayaYaz(geciciDosya);
				//geciciDosya.write(reinterpret_cast<char*>(&T), sizeof(T));
			}
		}
        takimDosyaOku.close();
        geciciDosya.close();

        remove("takimlar.txt");
        if (rename("gecici.txt", "takimlar.txt")) // Dosya ad� de�i�tirildi mi
        {
            cout << "Tak�m silme ba�ar�s�z." << endl;

		}
        else
        {
            cout << "Tak�m ba�ar�yla silindi." << endl;
		}
    }
    // Dosyalar veya dosya a��lmad�ysa hata ver
    else {
        cerr << "Dosya a�ma hatas�!" << endl;
    }
}
// Tak�mlar� listeleme fonksiyonu
void takimlariListele()
{
    ifstream takimDosyaOku;
	takimDosyaOku.open("takimlar.txt", ios::in);

    if (!takimDosyaOku.is_open()) // Dosya a��ld� m� kontrol
    {
        cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
        return;
    }

    string satir;
    int takimSayisi = 0;
    // Tak�m say�s�n� alma
    while (getline(takimDosyaOku, satir))
    {
        takimSayisi += 1;
    }
    takimDosyaOku.close();
    //takimSayisi -= 1; // Son sat�r bo� oldu�u i�in 1 azaltma (ama gerek kalm�yor neden?)
    takimDosyaOku.open("takimlar.txt");
	Takim T;
	takimDosyaOku.seekg(0, ios::beg);
    if (takimDosyaOku.is_open()) // Dosya a��ld� m� kontrol
    {
        cout << "Tak�mlar (toplam " << takimSayisi << " adet):" << endl
            << "-----------------------------" << endl;
        // Tak�mlar� ekrana yazd�rma
        while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
        {
			cout << "Tak�m No: " << T.takimNO << endl;
			cout << "Tak�m Ad�: " << T.adi << endl;
			cout << "Tak�m Adresi: " << T.adresi << endl;
			cout << "Tak�m Telefonu: " << T.telefon << endl;
			cout << "Tak�mdaki Oyuncu Say�s�: " << T.oyuncuSayisi << endl;
			cout << "Tak�m Y�neticisi: " << T.yoneticiIsmi << endl;
			cout << "-----------------------------" << endl;
		}
		takimDosyaOku.close();
	}
    else
    {
		cerr << "Dosya a�ma hatas�!" << endl;
	}

}
// Tak�ma futbolcu ekleme fonksiyonu
void futbolcuEkle()
{
    Futbolcu F;
    cout << "Futbolcunun Eklenece�i Tak�m�n Tak�mNo'su: ";
    cin >> F.takimNO;

    // Girilen tak�m no'ya sahip tak�m var m� kontrol
    Takim T5;
    ifstream takimKontrol("takimlar.txt");
    bool takimBulundu = false;
    if (takimKontrol.is_open()) // Dosya var m� (olu�turulmu� mu) kontrol
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
        cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
        return;
    }
    takimKontrol.close();
    if (!takimBulundu) // Tak�m bulunamad�ysa hata ver
    {
        cout << "Girilen tak�m no'suna sahip tak�m bulunamad�.\n";
        return;
    }

    cout << "Futbolcunun TC Kimlik No'su: ";
    cin >> F.TCNO;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme
    // Temizlemeyince ve say� atama sonras� string atama i�lemi yap�nca atama eksik/hatal� oluyor

    // Girilen TC kimlik no'ya sahip ba�ka bir oyuncu var m� kontrol
    Futbolcu F2;
    ifstream tcKontrol("futbolcular.txt");
    if (tcKontrol.is_open()) // Dosya var m� (olu�turulmu� mu) kontrol
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

    cout << "Futbolcunun Ad�: ";
    getline(cin, F.adi);

    cout << "Futbolcunun Soyad�: ";
    getline(cin, F.soyadi);

    cout << "Lisans No'su: ";
    getline(cin, F.lisansNO);

    // Girilen lisans no'ya sahip ba�ka bir oyuncu var m� kontrol
    Futbolcu F3;
    ifstream lisansKontrol("futbolcular.txt");
    if (lisansKontrol.is_open()) // Dosya var m� (olu�turulmu� mu) kontrol
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

    cout << "�creti: ";
    cin >> F.ucret;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

    cout << "Do�um Tarihi: ";
    getline(cin, F.dogumTarihi);

    ofstream futbolcuYaz;
    futbolcuYaz.open("futbolcular.txt", ios::app);
    F.dosyayaYaz(futbolcuYaz);

    // Tak�m dosyas�n� g�ncelleme
    Takim T;
    ifstream dosyaOku("takimlar.txt");
    ofstream tempYaz;
    tempYaz.open("temp.txt");

    dosyaOku.seekg(0, ios::beg);
    tempYaz.seekp(0, ios::beg);

    if (!dosyaOku.is_open() || !tempYaz.is_open()) // Dosyalar a��ld� m� kontrol
    {
        cerr << "Dosya a��lamad�!" << endl;
        return;
    }

    takimBulundu = false;
    // Tak�m� bulma ve oyuncu say�s�n� artt�rma
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (F.takimNO == T.takimNO) // Tak�m bulunduysa oyuncu say�s�n� artt�r
        {
            takimBulundu = true;
            T.oyuncuSayisi += 1;
        }
        T.dosyayaYaz(tempYaz);
    }

    dosyaOku.close();
    tempYaz.close();

    if (takimBulundu) // Tak�m dosya i�inde varsa devam et
    {
        remove("takimlar.txt");
        if (rename("temp.txt", "takimlar.txt"))
        {
            cout << "Oyuncu ekleme ba�ar�s�z." << endl;
        }
        else
        {
            cout << "Oyuncu ba�ar�yla eklendi." << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "Tak�m bulunamad�." << endl;
        return;
    }
}
// Tak�mdan futbolcu silme fonksiyonu
void futbolcuSil()
{
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Tak�mlar var m� (olu�turulmu� mu) kontrol
    {
        cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
        return;
    }
    takimKontrol.close();

    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var m� (olu�turulmu� mu) kontrol
    {
        cerr << "Dosya a�ma hatas�! �nce futbolcu eklemeyi deneyin." << endl;
        return;
    }
    futbolcuKontrol.close();

    int takimno = 0;
    cout << "Oyuncusu silinecek tak�m�n no'su: ";
    cin >> takimno;
    cout << endl;

    // Girilen tak�m no'ya sahip tak�m var m� kontrol
    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt");
    Takim T5;
    bool takimBulundu = false;
    if (takimDosyaOku.is_open()) // Dosya a��ld� m� kontrol
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
    if (!takimBulundu) // Tak�m bulunamad�ysa hata ver
    {
        cerr << "Girilen tak�m no'ya sahip tak�m bulunamad�.\n";
        return;
    }

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No'sunu kullanarak silmek i�in '1'i, Lisans No'su ile silmek i�in '2'yi tu�lay�n\n";
    cin >> answer;
    cout << endl;
    if (answer == 1)
    {
		string silinecektcno;
		cout << "Silinecek futbolcunun TC kimlik no'su: ";
		cin >> silinecektcno;
		cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var m� kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
		{
			tcKontrol.seekg(0, ios::beg);
			while (tcKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
			{
                if (silinecektcno == F.TCNO && takimno == F.takimNO) // Girilen TC kimlik no'ya sahip oyuncu varsa sil ama ayn� tak�mda olmal�
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
		tcKontrol.close();
        if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamad�.\n";
            return;
        }

		ifstream futbolcudosyaoku("futbolcular.txt");
		ofstream gecicidosya("gecici_futbolcu.txt");
		// Dosyalar a��ld� m� kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
			Futbolcu F;
			// Ge�ici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.TCNO != silinecektcno) // Oyuncu TC'si silinecek TC'ye e�it de�ilse kaydet
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
            cout << "Futbolcu silme i�lemi ba�ar�s�z oldu." << endl;
        }
        else
        {
            cout << "Futbolcu ba�ar�yla silindi." << endl;
        }
    }
    else if (answer == 2)
    {
        string silineceklisansno;
        cout << "Silinecek futbolcunun lisans no'su: ";
        cin >> silineceklisansno;
        
        // Girilen lisans no'ya sahip oyuncu var m� kontrol
        Futbolcu F;
        ifstream lisansKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (lisansKontrol.is_open()) // Dosya a��ld� m� kontrol
		{
			lisansKontrol.seekg(0, ios::beg);
            while (lisansKontrol >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (silineceklisansno == F.lisansNO && takimno == F.takimNO) // Girilen lisans no'ya sahip oyuncu varsa sil ama ayn� tak�mda olmal�
                {
                    futbolcuBulundu = true;
					break;
				}
			}
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamad�.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar a��ld� m� kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Ge�ici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                if (F.lisansNO != silineceklisansno) // Oyuncu LisansNo'su silinecek LisansNo'ya e�it de�ilse kaydet
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
            cout << "Futbolcu silme i�lemi ba�ar�s�z oldu." << endl;
        }
        else
        {
            cout << "Futbolcu ba�ar�yla silindi." << endl;
        }
    }
    else
	{
		cout << "Ge�ersiz se�im!\n";
		return;
	}


    ifstream dosyaOku("takimlar.txt");
    ofstream tempeYaz("temp.txt");
    Takim T;
    // Tak�m dosyas�n� g�ncelleme
    while (dosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Tak�m bulunduysa oyuncu say�s�n� 1 azalt
        {
            T.oyuncuSayisi -= 1;
        }
        T.dosyayaYaz(tempeYaz);
    }
    dosyaOku.close();
    tempeYaz.close();

    remove("takimlar.txt");
    if (rename("temp.txt", "takimlar.txt")) // Dosya ad� de�i�tirildi mi kontrol
    {
        cout << "Tak�m g�ncelleme ba�ar�s�z." << endl;
    }
    else
    {
        cout << "Tak�m ba�ar�yla g�ncellendi." << endl;
    }
}
// T�m futbolcular� listeleme fonksiyonu
void tumFutbolculariListele()
 {
    ifstream futbolcudosyaoku;
    futbolcudosyaoku.open("futbolcular.txt");
    if (!futbolcudosyaoku.is_open()) // Futbolcu var m� kontrol
	{
		cerr << "Dosya a�ma hatas�! �nce futbolcu eklemeyi deneyin." << endl;
		return;
	}

    string satir;
    int futbolcuSayisi = 0;
    futbolcudosyaoku.seekg(0, ios::beg);
    // Futbolcu say�s�n� bulma
    while (getline(futbolcudosyaoku, satir))
    {
        futbolcuSayisi += 1;
    }
    futbolcudosyaoku.close();
    //futbolcuSayisi -= 1; // Son sat�r bo� oldu�u i�in 1 azalt (azaltmaya gerek kalmadan do�ru say�yor ama neden?)
    futbolcudosyaoku.open("futbolcular.txt");
    if (futbolcudosyaoku.is_open()) // Dosya a��ld� m� kontrol
    {
		 Futbolcu F;
         cout << "Futbolcular (toplam "<< futbolcuSayisi << " adet):" << endl;
         cout << "-----------------------------" << endl;
         // Futbolcular� ekrana yazd�rma
         while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
         {
			 cout << "Tak�m No: " << F.takimNO << endl;
			 cout << "TC Kimlik No: " << F.TCNO << endl;
			 cout << "Ad�: " << F.adi << endl;
			 cout << "Soyad�: " << F.soyadi << endl;
			 cout << "Lisans No: " << F.lisansNO << endl;
			 cout << "Oyundaki Konumu: " << F.konumu << endl;
			 cout << "�creti: " << F.ucret << endl;
			 cout << "Do�um Tarihi: " << F.dogumTarihi << endl;
			 cout << "-----------------------------" << endl;
		 }
		 futbolcudosyaoku.close();
	}
    else
    {
		 cerr << "Dosya a�ma hatas�!" << endl;
	}
 
}
// Tak�ma g�re futbolcular� listeleme fonksiyonu
void takimaGoreFutbolculariListele()
{
    ifstream takimKontrol("takimlar.txt");

    if (!takimKontrol.is_open()) // Tak�m var m� kontrol
    {
        cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
        return;
    }
    takimKontrol.close();

    int takimno = 0;
    cout << "Futbolcular� Listelenecek Tak�m�n Tak�mNo'su: ";
    cin >> takimno;
    cout << endl;

    ifstream takimOku("takimlar.txt");
    Takim T;
    bool takimBulundu = false;
    // B�yle bir tak�m var m� yok mu kontrol
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (takimno == T.takimNO) // Tak�m bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku.close();

    if (!takimBulundu) // Tak�m bulunamad�ysa d�n�t
    {
        cout << "Girilen tak�mNo'suna sahip tak�m bulunamad�.\n";
        return;
    }

    ifstream futbolcudosyaoku("futbolcular.txt");

    if (!futbolcudosyaoku.is_open()) // Futbolcu var m� kontrol
	{
		cerr << "Dosya a�ma hatas�! �nce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    else if (futbolcudosyaoku.is_open())
    {
        Futbolcu F;
        cout << takimno << " No'lu Tak�m�n Futbolcular�:" << endl;
        cout << "-----------------------------" << endl;
        // Tak�ma ait futbolcular� ekrana yazd�rma
        while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
        {
            if (F.takimNO == takimno) // Tak�m bulunduysa ekrana yazd�r
            {
                cout << "Tak�m No: " << F.takimNO << endl;
                cout << "TC Kimlik No: " << F.TCNO << endl;
                cout << "Ad�: " << F.adi << endl;
                cout << "Soyad�: " << F.soyadi << endl;
                cout << "Lisans No: " << F.lisansNO << endl;
                cout << "Oyundaki Konumu: " << F.konumu << endl;
                cout << "�creti: " << F.ucret << endl;
                cout << "Do�um Tarihi: " << F.dogumTarihi << endl;
                cout << "-----------------------------" << endl;
            }
        }
        futbolcudosyaoku.close();
    }
    else
    {
        cerr << "Dosya a�ma hatas�!" << endl;
    }
}
// Futbolcu g�ncelleme fonksiyonu
void futbolcuGuncelle()
{
    ifstream futbolcuKontrol("futbolcular.txt");
    if (!futbolcuKontrol.is_open()) // Futbolcular var m� (olu�turulmu� mu) kontrol
    {
		cerr << "Dosya a�ma hatas�! �nce futbolcu eklemeyi deneyin." << endl;
		return;
	}
    futbolcuKontrol.close();

    int answer = 0;
    cout << "Futbolcuyu TC Kimlik No ile g�ncellemek i�in '1'i, Lisans No ile g�ncellemek i�in '2'yi tu�lay�n\n";
    cin >> answer;
    cout << endl;

    if (answer != 1 && answer != 2)
    {
        cout << "Hatal� se�im!\n";
        return;
    }

    if (answer == 1)
    {
        string guncellenecektcno;
        cout << "G�ncellenecek Futbolcunun TC kimlik No Bilgisi: ";
        cin >> guncellenecektcno;
        cout << endl;

        // Girilen TC kimlik no'ya sahip oyuncu var m� kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        string guncelleneceklisansno;
        if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
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

        if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
        {
			cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamad�.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar a��ld� m� kontrol�
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Ge�ici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // E�er oyuncu bulunmad�ysa direkt dosyaya yaz
                if (F.TCNO != guncellenecektcno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // G�ncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Tak�m No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    // Girilen TC kimlik no'ya sahip ba�ka bir oyuncu var m� kontrol
                    Futbolcu F2;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
                    {
						tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F2.takimNO >> F2.TCNO >> F2.adi >> F2.soyadi >> F2.lisansNO >> F2.konumu >> F2.ucret >> F2.dogumTarihi)
                        {
                            if (guncellenecektcno == F2.TCNO) // Kendi TC'si hari� ayn� TC'ye sahip ba�ka bir oyuncu var m� kontrol et
                            {
                                continue;
                            }

                            if (F.TCNO == F2.TCNO) // Girilen TC kimlik no'ya sahip ba�ka bir oyuncu var m� kontrol et
                            {
								cout << "Bu TC kimlik no'ya sahip bir oyuncu zaten var!\n";
								return;
							}
						}
					}

                    cout << "Yeni Ad�: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyad�: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip ba�ka bir oyuncu var m� kontrol
                    Futbolcu F3;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya a��ld� m� kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F3.takimNO >> F3.TCNO >> F3.adi >> F3.soyadi >> F3.lisansNO >> F3.konumu >> F3.ucret >> F3.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F3.lisansNO) // Kendi Lisans No'su hari� ayn� Lisans No'ya sahip oyuncu var m� kontrol et
                            {
                                continue;
                            }

                            if (F.lisansNO == F3.lisansNO) // Girilen lisans no'ya sahip ba�ka bir oyuncu var m� kontrol et
                            {
								cout << "Bu lisans no'ya sahip oyuncu zaten var!\n";
								return;
							}
						}
                    }

                    cout << "Yeni Oyundaki Konumu: ";
                    getline(cin, F.konumu);

                    cout << "Yeni �creti: ";
                    cin >> F.ucret;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    cout << "Yeni Do�um Tarihi: ";
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
        cout << "G�ncellenecek futbolcunun lisans no'su: ";
        cin >> guncelleneceklisansno;
        cout << endl;

        Futbolcu F;
        ifstream lisansKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        string guncellenecektcno;
        // Girilen lisans no'ya sahip bir oyuncu var m� kontrol
        if (lisansKontrol.is_open()) // Dosya a��ld� m� kontrol
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
			cerr << "Dosya a�ma hatas�! Futbolcu eklemeyi deneyin." << endl;
			return;
		}
        lisansKontrol.close();

        if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
        {
			cout << "Girilen lisans No'ya sahip oyuncu bulunamad�.\n";
			return;
		}

        ifstream futbolcudosyaoku("futbolcular.txt");
        ofstream gecicidosya("gecici_futbolcu.txt");
        // Dosyalar a��ld� m� kontrol
        if (futbolcudosyaoku.is_open() && gecicidosya.is_open())
        {
            Futbolcu F;
            // Ge�ici dosyaya kaydetme
            while (futbolcudosyaoku >> F.takimNO >> F.TCNO >> F.adi >> F.soyadi >> F.lisansNO >> F.konumu >> F.ucret >> F.dogumTarihi)
            {
                // E�er oyuncu bulunmad�ysa direkt dosyaya yaz
                if (F.lisansNO != guncelleneceklisansno)
                {
                    F.dosyayaYaz(gecicidosya);
                }
                else // G�ncellenecek oyuncu bulunduysa yeni bilgileri al
                {
                    cout << "Yeni bilgileri girin:" << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Yeni Tak�m No: ";
                    cin >> F.takimNO;

                    cout << "Yeni TC Kimlik No: ";
                    cin >> F.TCNO;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme


                    // Girilen TC kimlik no'ya sahip ba�ka bir oyuncu var m� kontrol
                    Futbolcu F6;
                    ifstream tcKontrol("futbolcular.txt");
                    if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
                    {
                        tcKontrol.seekg(0, ios::beg);
                        while (tcKontrol >> F6.takimNO >> F6.TCNO >> F6.adi >> F6.soyadi >> F6.lisansNO >> F6.konumu >> F6.ucret >> F6.dogumTarihi)
                        {
                            if (guncellenecektcno == F6.TCNO) // Kendi TC'si hari� ayn� TC'ye sahip oyuncu var m� kontrol et
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

                    cout << "Yeni Ad�: ";
                    getline(cin, F.adi);

                    cout << "Yeni Soyad�: ";
                    getline(cin, F.soyadi);

                    cout << "Yeni Lisans No: ";
                    getline(cin, F.lisansNO);

                    // Girilen lisans no'ya sahip oyuncu var m� kontrol
                    Futbolcu F7;
                    ifstream lisansKontrol("futbolcular.txt");
                    if (lisansKontrol.is_open()) // Dosya a��ld� m� kontrol
                    {
                        lisansKontrol.seekg(0, ios::beg);
                        while (lisansKontrol >> F7.takimNO >> F7.TCNO >> F7.adi >> F7.soyadi >> F7.lisansNO >> F7.konumu >> F7.ucret >> F7.dogumTarihi)
                        {
                            if (guncelleneceklisansno == F7.lisansNO) // Kendi LisansNo'su hari� ayn� LisansNo'ya sahip oyuncu var m� kontrol et
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

                    cout << "Yeni �creti: ";
                    cin >> F.ucret;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer temizleme

                    cout << "Yeni Do�um Tarihi: ";
                    getline(cin, F.dogumTarihi);

                    F.dosyayaYaz(gecicidosya);
                }
            }
            futbolcudosyaoku.close();
            gecicidosya.close();
        }
    }

	remove("futbolcular.txt");
    // Dosya ad� de�i�tirildi mi kontrol
    if (rename("gecici_futbolcu.txt", "futbolcular.txt"))
    {
        cout << "Futbolcu g�ncelleneme i�lemi ba�ar�s�z." << endl;
	}
    else
    {
        cout << "Futbolcu ba�ar�yla g�ncellendi." << endl;
    }
}
// Ma� kayd� alma fonksiyonu
void futbolOyunuKaydi()
{
    // Tak�m kontrol�
    ifstream takimKontrol("takimlar.txt");
    if (!takimKontrol.is_open()) // Tak�mlar var m� (olu�turulmu� mu) kontrol
    {
		cerr << "Dosya a�ma hatas�! �nce tak�m olu�turmay� deneyin." << endl;
		return;
	}
    takimKontrol.close();

    string evSahibi;
    cout << "Ev sahibi tak�m�n ad�n� girin: ";
    cin.ignore(); // Say�sal giri� ald�ktan sonra metinsel giri� al�yosak gerekiyor
    getline(cin, evSahibi);                  // �nceki giri�lerin tamam�n� temizler
    cout << endl;

    // B�yle bir tak�m var m� yok mu kontrol
    Takim T;
    ifstream takimOku("takimlar.txt");
    bool takimBulundu = false;
    while (takimOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (evSahibi == T.adi) // Tak�m bulundu mu kontrol
        {
			takimBulundu = true;
			break;
		}
	}
    takimOku.close();
    if (!takimBulundu) // Tak�m bulunamad�ysa d�n�t
    {
        cerr << "Girilen tak�m bulunamad�.\n";
        return;
    }

    string rakipTakim;
    cout << "Kar��la��lan tak�m�n ad�n� girin: ";
    getline(cin, rakipTakim);
    cout << endl;

    // B�yle bir tak�m var m� yok mu kontrol
    ifstream takimOku2("takimlar.txt");
    takimOku2.seekg(0, ios::beg);
    takimBulundu = false;
    while (takimOku2 >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        if (rakipTakim == T.adi) // Tak�m bulundu mu kontrol
        {
            takimBulundu = true;
            break;
        }
    }
    takimOku2.close();
    if (!takimBulundu) // Tak�m bulunamad�ysa d�n�t
    {
		cerr << "Girilen tak�m bulunamad�.\n";
		return;
	}

    int skorEv = 0, skorMisafir = 0;
    cout << "Ev sahibi tak�m skoru: ";
    cin >> skorEv;
    if (skorEv < 0) // Skor negatif olamaz
    {
		cout << "Skor negatif olamaz!\n";
		return;
	}

    cout << "Misafir tak�m skoru: ";
    cin >> skorMisafir;
    if (skorMisafir < 0) // Skor negatif olamaz
    {
        cout << "Skor negatif olamaz!\n";
        return;
    }

    string tarih;
    cout << "Ma� Tarihi: ";
    cin.ignore();
    getline(cin, tarih);

    int hafta = 0;
    cout << "Ka��nc� hafta: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya s�f�r olamaz
    {
		cout << "Hafta negatif veya s�f�r olamaz!\n";
		return;
	}

    ofstream maclarDosyaYaz;
    maclarDosyaYaz.open("maclar.txt", ios::app);
    maclarDosyaYaz << "\t" << evSahibi << " vs " << rakipTakim << endl;
    maclarDosyaYaz << hafta << ". Hafta Kar��la�mas� Kayd�\n";
    maclarDosyaYaz << "##############################" << endl;
    maclarDosyaYaz << "Tarih: " << tarih << endl;
    maclarDosyaYaz << "Skor: " << skorEv << " - " << skorMisafir << endl;

    int toplamGolAtanOyuncu = 0;
    cout << "Toplam ka� farkl� oyuncu gol att�: ";
    cin >> toplamGolAtanOyuncu;
    if (toplamGolAtanOyuncu < 0)
    {
		cout << "Gol atan oyuncu say�s� negatif olamaz!\n";
		return;
	}

    string golAtan;
    int gol = 0;
    // Gol yoksa terminale gereksiz yazma
    if (toplamGolAtanOyuncu > 0)
    {
        cout << "Gol Atan Oyuncular:\n";
    }
    
    maclarDosyaYaz << "Gol Atan Farkl� Oyuncu Say�s�: " << toplamGolAtanOyuncu << endl;
    maclarDosyaYaz << "Gol Atan Oyuncular:\n";
    
    for (int i = 1; i <= toplamGolAtanOyuncu; i++)
    {
        cout << "Gol Atan Oyuncunun TC'si: ";
        cin >> golAtan;

        // Girilen TC kimlik no'ya sahip oyuncu var m� kontrol
        Futbolcu F;
        ifstream tcKontrol("futbolcular.txt");
        bool futbolcuBulundu = false;
        if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
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
        if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
        {
            cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamad�.\n";
            return;
        }


        cout << "Att��� Gol Say�s�: ";
        cin >> gol;
        if (gol < 0) // Gol negatif olamaz
        {
            cout << "Gol say�s� negatif olamaz!\n";
            return;
        }

        maclarDosyaYaz << golAtan << ": " << gol << " Gol\n";
    }
    maclarDosyaYaz << "-------------------------------" << endl;

    // Ma�ta oynayan oyuncular� kaydetme

    int oyuncuSayisi;
    cout << "Ma�ta oynayan oyuncu say�s�: ";
    cin >> oyuncuSayisi;
    if (oyuncuSayisi <= 21) // Oyuncu say�s� 22 den k���k olamaz
    {
		cout << "Oyuncu say�s� 22 den k���k olamaz!\n";
		return;
	}

    char answer = 'h';
    cout << "Ma�ta oynayan oyuncular�n TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (" << oyuncuSayisi << " adet kay�t gerekli)\n";
    cin >> answer;
    if (answer == 'e' || answer == 'E') // Giri� kontrol�
    {
        maclarDosyaYaz << "Ma�ta Oynayan Oyuncu Say�s�: " << oyuncuSayisi << endl;
        maclarDosyaYaz << "Ma�ta Oynayan Oyuncular: \n";
        maclarDosyaYaz << "-------------------------------" << endl;
        // Her bir oyuncuyu kaydetmek i�in d�ng�
        for (int i = 1; i <= oyuncuSayisi; i++)
        {
            string oyuncuTC;
            cout << i << ". Oyuncunun TC Kimlik Numaras�: ";
            cin >> oyuncuTC;

            // Girilen TC kimlik no'ya sahip oyuncu var m� kontrol
            Futbolcu F;
            ifstream tcKontrol("futbolcular.txt");
            bool futbolcuBulundu = false;
            if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
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
            if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
            {
				cout << "Girilen TC Kimlik No'ya sahip oyuncu bulunamad�.\n";
				return;
			}
            maclarDosyaYaz << i << ". Oynayan Oyuncu: " << oyuncuTC << endl;
        } 
    }
    else
    {
        cout << "Sadece oynayan oyuncular�n say� bilgisi kaydedildi.\n";
        maclarDosyaYaz << "Ma�ta Oynayan Oyuncu Say�s�: " << oyuncuSayisi << endl;
    }

    // Oyuncu de�i�ikliklerini kaydetme

    int degisiklikSayisi;
    cout << "Ma� s�ras�nda ka� oyuncu de�i�ikli�i oldu: ";
    cin >> degisiklikSayisi;
    if (degisiklikSayisi < 0) // De�i�iklik say�s� negatif olamaz
    {
        cout << "De�i�iklik say�s� negatif olamaz!\n";
        return;
    }
    if (degisiklikSayisi > 10) // De�i�iklik say�s� 10'dan fazla olamaz
    {
		cout << "De�i�iklik say�s� 10'dan fazla olamaz!\n";
		return;
	}
    if (degisiklikSayisi > 0) // De�i�iklik varsa
    {
        answer = 'h';
        cout << "Ma�ta giren-��kan oyuncular�n TC kimlik bilgilerini kaydetmek istiyor musunuz? (e/h) (toplam " << degisiklikSayisi << " kadar kay�t gerekli)\n";
        cin >> answer;
        if (answer == 'e' || answer == 'E') // Giri� kontrol�
        {
            maclarDosyaYaz << "Ma�ta Yap�lan De�i�iklik Say�s�: " << degisiklikSayisi << endl;
            // De�i�iklikleri kaydetmek i�in d�ng�
            for (int i = 1; i <= degisiklikSayisi; ++i)
            {
                string degisenOyuncuTC, girenOyuncuTC;
                cout << i << ". ��kan Oyuncunun TC Kimlik Numaras�: ";
                cin >> degisenOyuncuTC;

                // De�i�en oyuncunun TC kimlik no kontrol� (tc kimlik hi�bir futbolcuda yoksa hata ver)
                Futbolcu F;
                ifstream tcKontrol("futbolcular.txt");
                bool futbolcuBulundu = false;
                if (tcKontrol.is_open()) // Dosya a��ld� m� kontrol
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
                if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamad�.\n";
                    return;
                }

                maclarDosyaYaz << i << ". ��kan Oyuncu: " << degisenOyuncuTC << endl;
                cout << i << ". Giren Oyuncunun TC Kimlik Numaras�: ";
                cin >> girenOyuncuTC;

                // Giren oyuncunun TC kimlik no kontrol� (tc kimlik hi�bir futbolcuda yoksa hata ver)
                Futbolcu F2;
                ifstream tcKontrol2("futbolcular.txt");
                futbolcuBulundu = false;
                if (tcKontrol2.is_open()) // Dosya a��ld� m� kontrol
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
                if (!futbolcuBulundu) // Futbolcu bulunamad�ysa hata ver
                {
                    cout << "Girilen TC kimlik No'ya sahip oyuncu bulunamad�.\n";
                    return;
                }
                maclarDosyaYaz << i << ". Giren Oyuncu: " << girenOyuncuTC << endl;
            }
        }
        else
        {
            cout << "Sadece yap�lan de�i�iklik say�s� kaydedildi\n";
            maclarDosyaYaz << "Ma�ta Yap�lan De�i�iklik Say�s�: " << degisiklikSayisi << endl;
        }
    }
    else // De�i�iklik 0 ise
    {
        maclarDosyaYaz << "Ma�ta Yap�lan De�i�iklik Say�s�: " << degisiklikSayisi << endl;
    }
    maclarDosyaYaz << "------------------------------" << endl;
    maclarDosyaYaz.close();

    cout << "Ma� kayd� ba�ar�yla olu�turuldu." << endl;
}
// Haftal�k kay�t alma fonksiyonu
void haftalikKayit()
{
    // Ma�lar kontrol�
    ifstream maclarKontrol("maclar.txt");
    if (!maclarKontrol.is_open()) // Ma�lar var m� (olu�turulmu� mu) kontrol
    {
        cerr << "Dosya a�ma hatas�! �nce ma� kayd� olu�turmay� deneyin." << endl;
        return;
    }

    int istekHafta = 0;
    cout << "Ka��nc� haftan�n kayd� yap�lacak: ";
    cin >> istekHafta;
    if (istekHafta <= 0) // Hafta negatif veya s�f�r olamaz
    {
		cout << "Hafta negatif veya s�f�r olamaz!\n";
		return;
	}

    // �stenilen haftaya kadar kay�t yapmak i�in d�ng� (ama tam �al��m�yor sadece girilen haftay� yap�yor)
    for (int i = 1; i <= istekHafta; i++)
    {
        string kayit = to_string(istekHafta) + ". hafta_kayit.txt";
        ofstream maclarDosyasi(kayit);
        ifstream maclarOku("maclar.txt");
        if (maclarDosyasi.is_open() && maclarOku.is_open()) // Dosyalar a��ld� m� kontrol
        {
            cout << to_string(i) << ". Hafta oynanan ma�lar kaydediliyor..." << endl;
            string satir;
            maclarOku.seekg(0);
            maclarDosyasi.seekp(0);
            string haftaBilgisi = to_string(istekHafta) + ". Hafta Kar��la�mas� Kayd�";
            bool istekHaftaBasladi = false;
            string oncekiSatir;
            int a = 1;

            // T�m ma�lar�n kaydedildi�i dosyadan haftaya g�re ma� se�mek i�in d�ng�
            while (getline(maclarOku, satir))
            {
                // �stenilen haftay� bulma kontrol�
                if (satir.find(haftaBilgisi) != string::npos)
                {
                    istekHaftaBasladi = true;
                }
                else
                {
                    istekHaftaBasladi = false;
                }

                // Hafta bulunduysa yap�lacak i�lemler
                if (istekHaftaBasladi)
                {
                    if (a) // Ma�� yapan tak�mlar� yazd�rmak i�in d�ng�de tek sefer �al��an ko�ul
                    {
                        maclarDosyasi << oncekiSatir << endl;
                        a = 0;
                    }
                    // Bulunan haftan�n bilgilerini almak i�in d�ng�
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
                        // Goller ile ilgili sat�rlar� alma
                        else if (satir.find("Gol") != string::npos)
                        {
                            maclarDosyasi << satir << endl;
                        }
                        // Ma� kayd�n�n ilk par�as� bitti ise 2. par�ay�
                       // atlay�p di�er ma� kayd�na ge�me
                        else if (satir.find("---") != string::npos)
                        {
                            a = 1;
                            getline(maclarOku, satir); // Gereksiz sat�r� atlama
                            getline(maclarOku, satir); // Gereksiz sat�r� atlama
                            getline(maclarOku, satir); // Gereksiz sat�r� atlama
                            maclarDosyasi << satir << endl; //araya "-----" i�in
                            //getline(maclarOku, satir); // Gereksiz sat�r� atlama

                            break;
                        }
                    }
                }
                oncekiSatir = satir; // Ma�� yapan tak�mlar� alma
                // (maclar dosyas�nda hafta bilgisinden hemen �nce yer al�yorlar)
            }
            maclarDosyasi.close();
            maclarOku.close();
            cout << "Haftan�n kayd� ba�ar�yla tamamland�.\n";
        }
        else // Dosyalar a��lmad�ysa oynanmam�� haftalar i�in de kay�t istenmi�tir veya k���k ihtimal dosya a��lamam��t�r
        {
            cerr << "Dosya a�ma hatas�! Haftas� oynanmam�� ma�lar i�in de kay�t istemi� olabilirsiniz. Ma� kayd� yapmay� deneyin." << endl;
            break;
        }
	}
}
// Haftal�k kay�t g�r�nt�leme fonksiyonu
void haftalikKayitGoruntule()
{
	int hafta = 0;
	cout << "Kayd� g�r�nt�lenecek haftay� girin: ";
	cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya s�f�r olamaz
    {
		cout << "Hafta negatif veya s�f�r olamaz!\n";
		return;
	}
    // Dosyay� okuma
	string haftaBilgisi = to_string(hafta) + ". hafta_kayit.txt";
	ifstream dosya(haftaBilgisi);
    if (dosya.is_open()) // Dosya a��ld� m� kontrol
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
		cerr << "Dosya a�ma hatas�! Dosya var olmayabilir, haftal�k kay�t olu�turmay� deneyin." << endl;
        return;
	}
}
// Haftal�k puan durumu g�r�nt�leme fonksiyonu
void haftalikPuanDurumlari()
{
    int hafta = 0;
    cout << "Puan durumu g�sterilecek haftay� girin: ";
    cin >> hafta;
    if (hafta <= 0) // Hafta negatif veya s�f�r olamaz
    {
        cout << "Hafta negatif veya s�f�r olamaz!\n";
        return;
    }
    const int takimSayisi = 21; // Asl�nda 20 tak�m var ama 0. indis bo� kal�yor ��nk� tak�mlar dosyas� 1. de�erden ba�l�yor
    
    string takimlar[takimSayisi]{}; // Tak�mlar�n isimlerini tutacak dizi
    int takimPuanlari[takimSayisi] = { 0 }; // Tak�mlar�n puanlar�n� tutacak dizi
    int takimOynadigiMacSayisi[takimSayisi] = { 0 }; // Tak�mlar�n oynad��� ma� say�s�n� tutacak dizi
    int takimAttigiGolSayisi[takimSayisi] = { 0 }; // Tak�mlar�n att��� gol say�s�n� tutacak dizi
    int takimYedigiGolSayisi[takimSayisi] = { 0 }; // Tak�mlar�n yedi�i gol say�s�n� tutacak dizi
    int takimAveraj[takimSayisi] = { 0 }; // Tak�mlar�n averaj�n� tutacak dizi
    int takimGalibiyetSayisi[takimSayisi] = { 0 }; // Tak�mlar�n galibiyet say�s�n� tutacak dizi
    int takimBeraberlikSayisi[takimSayisi] = { 0 }; // Tak�mlar�n beraberlik say�s�n� tutacak dizi
    int takimMaglubiyetSayisi[takimSayisi] = { 0 }; // Tak�mlar�n ma�lubiyet say�s�n� tutacak dizi
    
    Takim T;

    ifstream takimDosyaOku;
    takimDosyaOku.open("takimlar.txt", ios::in);
    takimDosyaOku.seekg(0, ios::beg);
    // Tak�mlar�n isimlerini alma
    while (takimDosyaOku >> T.takimNO >> T.adi >> T.adresi >> T.telefon >> T.oyuncuSayisi >> T.yoneticiIsmi)
    {
        takimlar[T.takimNO] = T.adi;
    }
    takimDosyaOku.close();

    // Her bir hafta kayd�ndan verileri alma
    for (int i = 1; i <= hafta; i++)
    {
        string haftaBilgisi = to_string(i) + ". hafta_kayit.txt";
        ifstream dosya(haftaBilgisi);
        if (dosya.is_open()) // Dosya a��ld� m� kontrol
        {
            string satir;
            // Dosya i�eri�ini sat�r sat�r okuma
            while (getline(dosya, satir))
            {
                // Tak�mlar�n isimlerini almak i�in ko�ul (bununla o tak�m�n tak�mNO bilgisini al�yoruz)
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
                    // Tak�mlar dosyas�ndan tak�m isimlerine g�re tak�mNO bilgilerini almak i�in d�ng�
                    while (takimBul >> T1.takimNO >> T1.adi >> T1.adresi >> T1.telefon >> T1.oyuncuSayisi >> T1.yoneticiIsmi)
                    {
                        if (T1.adi == evTakim) // Ev sahibi tak�m�n tak�mNO bilgisini almak i�in ko�ul
                        {
							takimEvNo = T1.takimNO;
						}
                        else if (T1.adi == misafirTakim) // Misafir tak�m�n tak�mNO bilgisini almak i�in ko�ul
                        {
                            takimMisafirNo = T1.takimNO;
                        }
                    }
                    takimBul.close();
                    if (takimEvNo == 0 && takimMisafirNo == 0) // Tak�mlar dosyas�nda tak�m isimlerine g�re tak�mNO bulunamad�ysa
                    {
                        cerr << "Tak�m bulunamad�! Tak�m eklemesi yapmay� deneyin.\n";
                        return;
                    }

                    int evSkor = 0, misafirSkor = 0;
                    string skor, tire; // Skor sat�r�ndaki gereksiz bilgileri atlamak i�in atama
                    getline(dosya, satir); // Tarih sat�r�n� atla
                    getline(dosya, satir); // Skor sat�r�n� oku

                    if (satir.find("Skor") != string::npos) // Skor sat�r� bulunduysa
                    {
						stringstream(satir) >> skor >> evSkor >> tire >> misafirSkor;
					}
                    else
                    {
						cerr << "Skor sat�r� bulunamad�!\n";
						return;
					}
                    // Puan ve di�er hesaplar i�in ko�ullar
                    if (evSkor > misafirSkor) // Ev sahibi kazand�, misafir kaybetti
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
                    else if (evSkor < misafirSkor) // Misafir kazand�, ev sahibi kaybetti
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
        else // Dosya a��lmad�ysa oynanmam�� haftalar i�in de kay�t istenmi�tir veya k���k ihtimal dosya a��lamam��t�r
        {
            cerr << "Dosya a�ma hatas�! �nce oynanm�� t�m ma�lar�n hafta kay�tlar�n� al�n." << endl;
            break;
        }
    }

    // Tak�mlar� puanlar�na g�re s�ralama i�lemi
    for (int i = 1; i < takimSayisi; i++)
    {
        int enBuyukPuan = takimPuanlari[i];
        int enBuyukPuaninIndisi = i;

        // Dizi i�inde en b�y�k puan� bulma
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[j] > enBuyukPuan) // Sonraki indisteki de�er bir �nceki indisteki de�erden b�y�kse
            {
                enBuyukPuan = takimPuanlari[j];
                enBuyukPuaninIndisi = j;
            }
        }

        // Tak�mlar� puanlar�na g�re b�y�kten k����e s�ralama
        if (enBuyukPuaninIndisi != i)
        {
            // Tak�mlar�n t�m de�erlerinin yerini de�i�tirme
            swap(takimlar[i], takimlar[enBuyukPuaninIndisi]); // 1. s�raya en b�y�k puana sahip tak�m� getir
            swap(takimPuanlari[i], takimPuanlari[enBuyukPuaninIndisi]); // 1. s�raya en b�y�k puan� getir vs...
            swap(takimOynadigiMacSayisi[i], takimOynadigiMacSayisi[enBuyukPuaninIndisi]);
            swap(takimAttigiGolSayisi[i], takimAttigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimYedigiGolSayisi[i], takimYedigiGolSayisi[enBuyukPuaninIndisi]);
            swap(takimAveraj[i], takimAveraj[enBuyukPuaninIndisi]);
            swap(takimGalibiyetSayisi[i], takimGalibiyetSayisi[enBuyukPuaninIndisi]);
            swap(takimBeraberlikSayisi[i], takimBeraberlikSayisi[enBuyukPuaninIndisi]);
            swap(takimMaglubiyetSayisi[i], takimMaglubiyetSayisi[enBuyukPuaninIndisi]);
        }
    }

    // Puanlar e�itse Averaj durumuna g�re s�ralama
    for (int i = 0; i < takimSayisi; i++)
    {
        for (int j = i + 1; j < takimSayisi; j++)
        {
            if (takimPuanlari[i] == takimPuanlari[j]) // Puanlar�n e�it oldu�u durumda
            {
                if (takimAveraj[i] < takimAveraj[j]) // Averaj� k���kse yerlerini de�i�tir
                {
                    // Tak�mlar�n yerini de�i�tirme
                    swap(takimlar[i], takimlar[j]); // 1. s�raya en b�y�k averaja sahip tak�m� getirdik
                    swap(takimPuanlari[i], takimPuanlari[j]); // 1. s�raya en b�y�k averaj� getirdik
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
    // Dosyaya tabloyu yazd�rma
    ofstream puanDosyaYaz;
    puanDosyaYaz.open("SLTablo.txt");
    puanDosyaYaz << "S�per Lig Puan Durumu" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    puanDosyaYaz << "Tak�m\t\t  |\tPuan\t|\tO\t|\tG\t|\tM\t|\tB\t|\t+/-\t|\tA\t|" << endl;
    puanDosyaYaz << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    // Her bir tak�m�n bilgilerini dosyaya yazd�rma
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
	cout << "Lig tablosu ba�ar�yla olu�turuldu." << endl;
}