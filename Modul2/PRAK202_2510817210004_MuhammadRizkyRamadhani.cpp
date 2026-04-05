#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

int F, R;
char Q[n];
int PIL;

void Inisialisasi() {
    F = 0;
    R = -1;
}

int kosong() {
    return (R < F);
}

int penuh() {
    return (R == n - 1);
}

void INSERT() {
    if (penuh()) {
        cout << "Queue penuh, tidak bisa menambah data.\n";
    } else {
        char huruf;
        cout << "Masukkan data (huruf): ";
        cin >> huruf;
        R++;
        Q[R] = huruf;
        cout << "Data " << huruf << " masuk ke Queue.\n";
    }
}

void DELETE() {
    if (kosong()) {
        cout << "Queue kosong, tidak ada data yang dihapus.\n";
    } else {
        cout << "Data " << Q[F] << " dihapus dari Queue.\n";
        F++;
    }
}

void CETAKLAYAR() {
    if (kosong()) {
        cout << "Queue kosong.\n";
    } else {
        cout << "Isi Queue:\n";
        for (int i = F; i <= R; i++) {
            cout << "Queue ke-" << i << " = " << Q[i] << endl;
        }
    }
}

void RESET() {
    Inisialisasi();
    cout << "Queue direset, sekarang kosong.\n";
}

int main() {
    Inisialisasi();
    do {
        cout << "\n=== QUEUE ===\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. CETAK QUEUE\n";
        cout << "4. RESET\n";
        cout << "5. QUIT\n";
        cout << "PILIHAN : ";
        cin >> PIL;

        switch (PIL) {
            case 1: INSERT(); break;
            case 2: DELETE(); break;
            case 3: CETAKLAYAR(); break;
            case 4: RESET(); break;
            case 5: cout << "TERIMA KASIH\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }

        cout << "Press any key to continue...\n";
        getch();
        system("cls");
    } while (PIL != 5);

    return 0;
}