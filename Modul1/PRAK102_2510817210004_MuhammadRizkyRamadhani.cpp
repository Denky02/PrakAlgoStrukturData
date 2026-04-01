#include <iostream>
using namespace std;

struct Kendaraan {
    char plat[15];
    char jenis[20];
    char pemilik[30];
    char alamat[50];
    char kota[20];
};

int main() {
    Kendaraan mobil;

    cout << "\n\nMasukkan Plat Nomor Kendaraan : ";
    cin >> mobil.plat;
    cout << "Masukkan Jenis Kendaraan      : ";
    cin >> mobil.jenis;
    cout << "Masukkan Nama Pemilik         : ";
    cin.ignore();
    cin.getline(mobil.pemilik, 30);
    cout << "Masukkan Alamat               : ";
    cin.getline(mobil.alamat, 50);
    cout << "Masukkan Kota                 : ";
    cin >> mobil.kota;

    cout << "\n=== Data Kendaraan ===\n";
    cout << "a. Plat Nomor Kendaraan : " << mobil.plat << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << mobil.pemilik << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}