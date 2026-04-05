#include <iostream>
#define max 10
using namespace std;

struct Stack {
    int data[max];
    int atas;
} Tumpuk;

int kosong() {
    return (Tumpuk.atas == -1);
}

int penuh() {
    return (Tumpuk.atas == max-1);
}

void input(int data) {
    if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    } else {
        cout << "Tumpukan Penuh\n";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas " << Tumpuk.data[Tumpuk.atas]
             << " Sudah Terambil\n";
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        cout << "Isi Stack:\n";
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i
                 << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Stack direset, sekarang kosong!\n";
}

int main() {
    Tumpuk.atas = -1;

    cout << "\n=== STACK ===\n";

    input(10);
    input(20);
    tampil();
    hapus();
    tampil();
    bersih();
    tampil();

    return 0;
}