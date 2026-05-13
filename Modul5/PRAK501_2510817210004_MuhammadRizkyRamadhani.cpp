#include <iostream>
#include <string>
using namespace std;

void insertionSort(string arr[], int n) {
    for (int i=1; i<n; i++) {
        string key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(string arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    string L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int j=0; j<n2; j++) R[j] = arr[m+1+j];
    int i=0, j=0, k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i<n1) arr[k++] = L[i++];
    while (j<n2) arr[k++] = R[j++];
}
void mergeSort(string arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(string arr[], int n) {
    for (int gap=n/2; gap>0; gap/=2) {
        for (int i=gap; i<n; i++) {
            string temp = arr[i];
            int j;
            for (j=i; j>=gap && arr[j-gap] > temp; j-=gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void printInt(int arr[], int n) {
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

void printStr(string arr[], int n) {
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nSORTING\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Quick Sort (NIM)\n";
        cout << "5. Bubble Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Exit\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            int nNama;
            cout << "Masukkan jumlah huruf Nama: ";
            cin >> nNama;
            string nama[nNama], namaCopy[nNama];
            cout << "Masukkan Nama (pisahkan per huruf): ";
            for (int i=0; i<nNama; i++) cin >> nama[i];

            for (int i=0; i<nNama; i++) namaCopy[i] = nama[i];
            if (pilihan == 1) { insertionSort(namaCopy, nNama); cout<<"Hasil Insertion Sort: "; printStr(namaCopy,nNama); }
            else if (pilihan == 2) { mergeSort(namaCopy,0,nNama-1); cout<<"Hasil Merge Sort: "; printStr(namaCopy,nNama); }
            else if (pilihan == 3) { shellSort(namaCopy,nNama); cout<<"Hasil Shell Sort: "; printStr(namaCopy,nNama); }
        }
        else if (pilihan >= 4 && pilihan <= 6) {
            int nNim;
            cout << "Masukkan jumlah digit NIM: ";
            cin >> nNim;
            int nim[nNim], nimCopy[nNim];
            cout << "Masukkan NIM (pisahkan dengan spasi): ";
            for (int i=0; i<nNim; i++) cin >> nim[i];

            for (int i=0; i<nNim; i++) nimCopy[i] = nim[i];
            if (pilihan == 4) { quickSort(nimCopy,0,nNim-1); cout<<"Hasil Quick Sort: "; printInt(nimCopy,nNim); }
            else if (pilihan == 5) { bubbleSort(nimCopy,nNim); cout<<"Hasil Bubble Sort: "; printInt(nimCopy,nNim); }
            else if (pilihan == 6) { selectionSort(nimCopy,nNim); cout<<"Hasil Selection Sort: "; printInt(nimCopy,nNim); }
        }
    } while (pilihan != 7);

    cout << "\nTerimakasih telah menggunakan program sorting ini!\n";
    return 0;
}