#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

void judulProgram() {
    cout << "\n=== PROGRAM HITUNG PASANGAN DARI JUMLAH TARGET ===\n";
    cout << "Masukkan input:\n";
    cout << "Baris 1: N (jumlah elemen array) dan X (target penjumlahan)\n";
    cout << "Baris 2: Elemen array random menyesuaikan input N\n";
    cout << "Output: Jumlah pasangan nilai yang jika dijumlahkan = X\n";
    cout << "=============================================================\n\n";
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

bool binarySearch(int arr[], int l, int r, int target, int excludeIndex) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target && mid != excludeIndex) return true;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    judulProgram();
    int N, X;
    cout << "Masukkan N dan X: ";
    cin >> N >> X;
    int arr[N];
    srand(time(NULL));
    cout << "Array random: ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 25 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, N - 1);
    set<pair<int,int>> pasanganUnik;
    for (int i = 0; i < N; i++) {
        int pasangan = X - arr[i];
        if (binarySearch(arr, i + 1, N - 1, pasangan, i)) {
            pasanganUnik.insert({min(arr[i], pasangan), max(arr[i], pasangan)});
        }
    }
    cout << "\nJumlah pasangan unik yang ditemukan: " << pasanganUnik.size() << endl;
    return 0;
}