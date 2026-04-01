#include <iostream>
using namespace std;

struct DataInput {
    char huruf;
    char kata[50];
    int angka;
};

int main() {
    DataInput data;

    cout << "\n\na. Masukkan sebuah huruf = ";
    cin >> data.huruf;

    cout << "b. Masukkan sebuah kata  = ";
    cin >> data.kata;

    cout << "c. Masukkan sebuah angka = ";
    cin >> data.angka;

    cout << "\n=== Hasil Output ===\n";
    cout << "d. Huruf yang Anda masukkan adalah " << data.huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << data.kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << data.angka << endl;

    return 0;
}