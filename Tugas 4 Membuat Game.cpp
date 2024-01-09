#include <iostream>
#include <string>

using namespace std;

class Karakter {
public:
    string nama;
    int kesehatan;
    int pengalaman;
    int koin;
    string senjata;

    Karakter(string n, int h, int xp, int c) : nama(n), kesehatan(h), pengalaman(xp), koin(c), senjata("Tangan Kosong") {}

    void tampilStatus() {
        cout << "Status " << nama << ":\n";
        cout << "Kesehatan: " << kesehatan << " | Pengalaman: " << pengalaman << " | Koin: " << koin << " | Senjata: " << senjata << endl;
    }

    void serang() {
        cout << "Anda menyerang monster dengan " << senjata << "!\n";
        kesehatan -= 10;
        pengalaman += 10;
        tampilStatus();
    }

    void pulihkan() {
        cout << "Anda memulihkan diri.\n";
        kesehatan += 10;
        koin -= 10;
        pengalaman += 5;
        tampilStatus();
    }

    void beliSenjata(string senjataBaru, int biaya) {
        if (koin >= biaya) {
            cout << "Anda membeli senjata " << senjataBaru << " dengan biaya " << biaya << " koin!\n";
            koin -= biaya;
            senjata = senjataBaru;
            tampilStatus();
        } else {
            cout << "Koin tidak cukup untuk membeli senjata.\n";
        }
    }
};

void tampilkanPilihanSenjata() {
    cout << "\nPilihan Senjata:\n1. Panah (20 koin)\n2. Pedang (30 koin)\n";
}

int main() {
    Karakter pemain("Pemain", 100, 100, 100);

    cout << "SELAMAT DATANG DI GAME PETUALANGAN!\n";

    int pilihanKarakter;
    cout << "\nPilih karakter:\n1. Ksatria\n2. Pemanah\n3. Medis\nPilih karakter (1-3): ";
    cin >> pilihanKarakter;

    switch (pilihanKarakter) {
        case 1:
            pemain.nama = "Ksatria";
            break;
        case 2:
            pemain.nama = "Pemanah";
            break;
        case 3:
            pemain.nama = "Medis";
            break;
        default:
            cout << "Pilihan tidak valid. Memilih karakter default: " << pemain.nama << endl;
            break;
    }

    pemain.tampilStatus();
    tampilkanPilihanSenjata();

    int pilihanAksi;
    while (true) {
        cout << "\nPilih aksi:\n1. Serang (-10 HP, +10 XP)\n2. Pulihkan (+10 Kesehatan, -10 Coin)\n3. Beli Senjata\n0. Keluar\nPilih aksi (0-3): ";
        cin >> pilihanAksi;

        switch (pilihanAksi) {
            case 1:
                pemain.serang();
                break;
            case 2:
                pemain.pulihkan();
                break;
            case 3: {
                tampilkanPilihanSenjata();
                int PilihanSenjata;
                cout << "Pilihan senjata (1-2): ";
                cin >> PilihanSenjata;

                if (PilihanSenjata == 1) {
                    pemain.beliSenjata("Panah", 20);
                } else if (PilihanSenjata == 2) {
                    pemain.beliSenjata("Pedang", 30);
                } else {
                    cout << "Pilihan senjata tidak valid.\n";
                }
                break;
            }
            case 0:
                cout << "Keluar dari permainan.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
                break;
        }
    }

    return 0;
}
