#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "||          PETA PETUALANGAN         ||" << endl;
    cout << "======================================" << endl << endl;
    cout << "Tekan tombol apa saja untuk melanjutkan..." << endl;
    system("pause>0");
    system("cls");
    cout << "======================================" << endl;
    cout << "||          PETA PETUALANGAN         ||" << endl;
    cout << "======================================" << endl;

    string namaPahlawan;
    int statsPahlawan[3] = {100, 100, 100};
    string senjata = "Tangan Kosong";
    bool gameBerakhir = false;

    cout << "========== >> Pilih karakter << ==========" << endl;
    cout << "|| [1] Ksatria  || " << endl;
    cout << "|| [2] Pemanah  || " << endl;
    cout << "|| [3] Penyihir   || " << endl;
    cout << "================== " << endl << endl;
    cout << "Pilihan [1-3] >>> ";

    int pilihanKarakter;
    cin >> pilihanKarakter;

    switch (pilihanKarakter) {
        case 1:
            namaPahlawan = "Ksatria";
            break;
        case 2:
            namaPahlawan = "Pemanah";
            break;
        case 3:
            namaPahlawan = "Penyihir";
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 1;
    }

    int pilihanAksi;
    do {
        cout << endl << "+------------------------------------+" << endl;
        cout << " Status " << namaPahlawan << endl;
        cout << " Kesehatan: " << statsPahlawan[0] << endl;
        cout << " Pengalaman: " << statsPahlawan[1] << endl;
        cout << " Koin: " << statsPahlawan[2] << endl;
        cout << " Senjata: " << senjata << endl;
        cout << "+------------------------------------+" << endl << endl;

        cout << "========== >> Pilih aksi << ==========" << endl;
        cout << "|| [1] Serang (-20 HP, +20 XP)       ||" << endl;
        cout << "|| [2] Pulihkan (+20 Kesehatan, -20 Koin) ||" << endl;
        cout << "|| [3] Beli Senjata                  ||" << endl;
        cout << "|| [0] Keluar                        ||" << endl;
        cout << "=======================================" << endl << endl;
        cout << "Pilihan [0-3] >>> ";
        cin >> pilihanAksi;

        switch (pilihanAksi) {
            case 1:
                cout << "[INFO] Anda menyerang monster dengan Tangan kosong" << endl;
                statsPahlawan[0] -= 20;
                statsPahlawan[1] += 20;
                if (statsPahlawan[0] < 0) {
                    gameBerakhir = true;
                }
                break;
            case 2:
                cout << "[INFO] Anda pulihkan kesehatan!" << endl;
                statsPahlawan[0] += 40;
                statsPahlawan[1] -= 20;
                statsPahlawan[2] -= 20;
                if (statsPahlawan[0] < 0) {
                    gameBerakhir = true;
                }
                break;
            case 3:
                cout << endl;
                cout << "+------------------------------------+" << endl;
                cout << "|           TOKO SENJATA             |" << endl;
                cout << "+------------------------------------+" << endl;
                cout << "Pilihan Senjata:" << endl;
                cout << "[1] Panah [10 Koin]" << endl;
                cout << "[2] Pedang [20 Koin]" << endl;
                cout << endl;
                cout << "Pilihan [1-2] >>> ";
                int pilihanSenjata;
                cin >> pilihanSenjata;

                switch (pilihanSenjata) {
                    case 1:
                        statsPahlawan[0] -= 20;
                        if (statsPahlawan[2] >= 10) {
                            senjata = "Panah";
                            statsPahlawan[2] -= 10;
                            cout << "[INFO] Anda membeli Panah!" << endl;
                        } else {
                            cout << "[WARNING] Koin tidak mencukupi!" << endl;
                        }
                        break;
                    case 2:
                        statsPahlawan[0] -= 20;
                        if (statsPahlawan[2] >= 20) {
                            senjata = "Pedang";
                            statsPahlawan[2] -= 20;
                            cout << "[INFO] Anda membeli Pedang!" << endl;
                        } else {
                            cout << "[WARNING] Koin tidak mencukupi!" << endl;
                        }
                        break;
                    default:
                        cout << "[WARNING] Pilihan tidak valid!" << endl;
                }
                break;
            case 0:
                cout << "Terima kasih telah bermain!" << endl;
                break;
            default:
                cout << "[WARNING] Pilihan tidak valid!" << endl;
        }

    } while (pilihanAksi != 0 && !gameBerakhir);

    return 0;
}

