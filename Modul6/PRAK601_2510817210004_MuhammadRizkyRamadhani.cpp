#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequentialSearch() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }
}

void binarySearch() {
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data: ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] = ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "=============================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }

    cout << "\n=============================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (ketemu == true) {
        cout << "Angka ditemukan! ";
    } else {
        cout << "Angka tidak ditemukan!";
    }
}

void penjelasanPerbedaan() {
    clrscr();
    cout << "=== Perbedaan Sequential dan Binary Search ===\n\n";

cout << "Sequential Search:\n";
    cout << "Metode pencarian yang dilakukan dengan cara memeriksa data satu per satu\n";
    cout << "dari awal sampai akhir.\n\n";
    cout << "- Kelebihan: sederhana, mudah dipahami, tidak perlu data terurut.\n";
    cout << "- Kekurangan: lambat jika data banyak atau target di belakang.\n\n";

 cout << "Binary Search:\n";
    cout << "Metode pencarian yang dilakukan dengan membagi dua ruang pencarian secara\n";
    cout << "berulang-ulang.\n";
    cout << "\n- Kelebihan: jauh lebih cepat untuk data besar, sedikit perbandingan.\n";
    cout << "- Kekurangan: harus diurutkan dulu, tidak bisa untuk data acak.\n\n";

    cout << "Kesimpulannya:\n";
    cout << "- Sequential cocok untuk data kecil/acak.\n";
    cout << "- Binary cocok untuk data besar, tapi syaratnya data harus terurut.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Menu Program Searching Denky02 ===\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: sequentialSearch(); break;
            case 2: binarySearch(); break;
            case 3: penjelasanPerbedaan(); break;
            case 4: cout << "Terima kasih telah menggunakan program Denky02!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}