#include <iostream>
#include <string>

using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    string pemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan mobil;

    mobil.plat = "DA1234MK";
    mobil.jenis = "RUSH";
    mobil.pemilik = "Andika Hartanto";
    mobil.alamat = "Jl. Kayu Tangi 1";
    mobil.kota = "Banjarmasin";

    cout << "\n=== Data Kendaraan ===\n";
    cout << "a. Plat Nomor Kendaraan : " << mobil.plat << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << mobil.pemilik << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}
