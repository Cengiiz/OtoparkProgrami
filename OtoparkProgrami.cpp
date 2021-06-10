#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class otopark {
private:
    string tasit_turu;
    double saatlik_ucreti;
    double kacsaat_kaldi;
public:
    otopark() {}
    otopark(string tur, double ucret)
    {
        tasit_turu = tur;
        saatlik_ucreti = ucret;

    }
    void ucret_listesi_goster()
    {
        cout << "Tasit Turu No           Tasit Turu          Saatlik Ucret   " << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "  0                       araba                   1.5       " << endl;
        cout << "  1                       minibus                 3.5       " << endl;
        cout << "  2                       kamyon                  4         " << endl;

    }
    void park_eden_tasit_bilgisi_doldur(otopark gelen_tasit, double kac_saat)
    {
        tasit_turu = gelen_tasit.tasit_turu;
        saatlik_ucreti = gelen_tasit.saatlik_ucreti;
        kacsaat_kaldi = kac_saat;
    }
    double ciro_hesapla()
    {
        return saatlik_ucreti * kacsaat_kaldi;
    }
    void park_listesi()
    {
        cout << tasit_turu << " " << kacsaat_kaldi << " saat park etti" << endl;
    }


};
int main()
{
    int tercih, saat;
    int sayac = 0;
    char secim;
    otopark tasit_turleri[3] = {
        {"araba" , 1.5},
        {"minibus",3.5},
        {"kamyon",4}
    };
    otopark park_siniri[30];
BASLANGIC:
    otopark sistem;

    sistem.ucret_listesi_goster();
    cout << "Tasit Turu No giriniz:";
    cin >> tercih;
    cout << "Kac saat park etti:";
    cin >> saat;
    if (tercih != 0 && tercih != 1 && tercih != 2)
    {
        cout << "Yanlis arac numarasi girdiniz" << endl;
        this_thread::sleep_for(std::chrono::milliseconds(1500));
        goto BASLANGIC;
    }
    park_siniri[sayac].park_eden_tasit_bilgisi_doldur(tasit_turleri[tercih], saat);

    cout << sayac + 1 << ". arac park edildi. Tasic cirosu->" << park_siniri[sayac].ciro_hesapla() << endl;
    sayac++;
    cout << "Yeni park bilgisi girmek istiyor musunuz ? (E-e,H-h)";
    cin >> secim;
    if (secim == 'e' || secim == 'E')
    {
        goto BASLANGIC;
    }

    cout << endl;
    cout << endl;
    cout << "Park listesi" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0;i < sayac;i++) {
        cout << i + 1 << "->";park_siniri[i].park_listesi();
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Toplamda " << sayac << " arac park edildi." << endl;
    double topciro = 0;
    for (int i = 0;i < sayac;i++)
    {
        topciro += park_siniri[i].ciro_hesapla();
    }
    cout << "Toplam ciromuz: " << topciro << " TL" << endl;
}


