#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <limits>
using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
} TNode;

TNode *head, *tail;

int pil, menu;
char pilihan[10];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH(int N);
void hapusBelakangHT(int N);
void hapusTargetH(string target);
void hapusTargetHT(string target);
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();
int hitungNodeH();
int hitungNodeHT();

int main()
{
menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"=============================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5: {
                    int n;
                    cout<<"Hapus node ke-N dari belakang (N): ";
                    cin>>n;
                    hapusBelakangH(n);
                    break;
                }
                case 6: {
                    string target;
                    cout<<"Masukkan data target yang ingin dihapus: ";
                    cin>>target;
                    hapusTargetH(target);
                    break;
                }
                case 7:
                    clearH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5: {
                    int n;
                    cout<<"Hapus node ke-N dari belakang (N): ";
                    cin>>n;
                    hapusBelakangHT(n);
                    break;
                }
                case 6: {
                    string target;
                    cout<<"Masukkan data target yang ingin dihapus: ";
                    cin>>target;
                    hapusTargetHT(target);
                    break;
                }
                case 7:
                    clearHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\nPress any key to continue"<<endl;
            getch();
            system("cls");
        } while (pil!=8);
    }

    cout<<"\nTERIMA KASIH"<<endl;
    cout<<"Program was made by Muhammad Rizky Ramadhani (2510817210004)."<<endl;
}


void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}

int hitungNodeH(){
    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL){
        count++;
        bantu = bantu->next;
    }
    return count;
}

int hitungNodeHT(){
    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL){
        count++;
        bantu = bantu->next;
    }
    return count;
}

void tambahDepanH(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Masukkan data (pisahkan dengan spasi): ";
    getline(cin, dataBaru);
    stringstream ss(dataBaru);
    string kata;
    TNode *firstNew = NULL, *lastNew = NULL;
    while(ss >> kata){
        TNode *baru = new TNode;
        baru->data = kata;
        baru->next = NULL;
        baru->prev = lastNew;
        if(lastNew != NULL) lastNew->next = baru;
        else firstNew = baru;
        lastNew = baru;
    }
    if(firstNew == NULL) return;
    firstNew->prev = NULL;
    if(isEmptyH()){
        head = firstNew;
    } else {
        lastNew->next = head;
        head->prev = lastNew;
        head = firstNew;
    }
    cout<<"Data berhasil ditambahkan di depan sesuai urutan input.";
}

void tambahDepanHT(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Masukkan data (pisahkan dengan spasi): ";
    getline(cin, dataBaru);
    stringstream ss(dataBaru);
    string kata;
    TNode *firstNew = NULL, *lastNew = NULL;
    while(ss >> kata){
        TNode *baru = new TNode;
        baru->data = kata;
        baru->next = NULL;
        baru->prev = lastNew;
        if(lastNew != NULL) lastNew->next = baru;
        else firstNew = baru;
        lastNew = baru;
    }
    if(firstNew == NULL) return;
    firstNew->prev = NULL;
    if(isEmptyHT()){
        head = firstNew;
        tail = lastNew;
    } else {
        lastNew->next = head;
        head->prev = lastNew;
        head = firstNew;
    }
    cout<<"Data berhasil ditambahkan di depan sesuai urutan input.";
}

void tambahBelakangH(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Masukkan data (pisahkan dengan spasi): ";
    getline(cin, dataBaru);
    stringstream ss(dataBaru);
    string kata;
    TNode *firstNew = NULL, *lastNew = NULL;
    while(ss >> kata){
        TNode *baru = new TNode;
        baru->data = kata;
        baru->next = NULL;
        baru->prev = lastNew;
        if(lastNew != NULL) lastNew->next = baru;
        else firstNew = baru;
        lastNew = baru;
    }
    if(firstNew == NULL) return;
    if(isEmptyH()){
        head = firstNew;
    } else {
        TNode *bantu = head;
        while(bantu->next != NULL) bantu = bantu->next;
        bantu->next = firstNew;
        firstNew->prev = bantu;
    }
    cout<<"Data berhasil ditambahkan di belakang sesuai urutan input.";
}

void tambahBelakangHT(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Masukkan data (pisahkan dengan spasi): ";
    getline(cin, dataBaru);
    stringstream ss(dataBaru);
    string kata;
    TNode *firstNew = NULL, *lastNew = NULL;
    while(ss >> kata){
        TNode *baru = new TNode;
        baru->data = kata;
        baru->next = NULL;
        baru->prev = lastNew;
        if(lastNew != NULL) lastNew->next = baru;
        else firstNew = baru;
        lastNew = baru;
    }
    if(firstNew == NULL) return;
    if(isEmptyHT()){
        head = firstNew;
        tail = lastNew;
    } else {
        tail->next = firstNew;
        firstNew->prev = tail;
        tail = lastNew;
    }
    cout<<"Data berhasil ditambahkan di belakang sesuai urutan input.";
}

void tampilkanH(){
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0){
        while(bantu != NULL){
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void tampilkanHT(){
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0){
        while(bantu != NULL){
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanH(){
    TNode *hapus;
    string data;
    if(isEmptyH() == 0){
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanHT(){
    TNode *hapus;
    string data;
    if(isEmptyHT() == 0){
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusBelakangH(int N){
    if(isEmptyH() == 1){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int total = hitungNodeH();
    if(N > total){
        N = N % total;
        if(N == 0) N = total;
    }
    TNode *hapus = head;
    while(hapus->next != NULL) hapus = hapus->next;
    for(int i = 1; i < N && hapus != NULL; i++) hapus = hapus->prev;
    if(hapus == NULL){
        cout<<"Node tidak valid.";
        return;
    }
    cout<<"Data \""<<hapus->data<<"\" (node ke-"<<N<<" dari belakang) telah berhasil dihapus.";
    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;
    if(hapus->next != NULL) hapus->next->prev = hapus->prev;
    delete hapus;
}

void hapusBelakangHT(int N){
    if(isEmptyHT() == 1){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int total = hitungNodeHT();
    if(N > total){
        N = N % total;
        if(N == 0) N = total;
    }
    TNode *hapus = tail;
    for(int i = 1; i < N && hapus != NULL; i++) hapus = hapus->prev;
    if(hapus == NULL){
        cout<<"Node tidak valid.";
        return;
    }
    cout<<"Data \""<<hapus->data<<"\" (node ke-"<<N<<" dari belakang) telah berhasil dihapus.";
    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;
    if(hapus->next != NULL) hapus->next->prev = hapus->prev;
    else tail = hapus->prev;
    delete hapus;
}

void hapusTargetH(string target){
    if(isEmptyH()){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    TNode *bantu = head;
    bool found = false;
    while(bantu != NULL){
        if(bantu->data == target){
            found = true;
            TNode *hapus = bantu;
            if(hapus->prev != NULL) hapus->prev->next = hapus->next;
            else head = hapus->next;
            if(hapus->next != NULL) hapus->next->prev = hapus->prev;
            bantu = hapus->next;
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    if(found) cout<<"Semua data \""<<target<<"\" berhasil dihapus.";
    else cout<<"Data \""<<target<<"\" tidak ditemukan.";
}

void hapusTargetHT(string target){
    if(isEmptyHT()){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    TNode *bantu = head;
    bool found = false;
    while(bantu != NULL){
        if(bantu->data == target){
            found = true;
            TNode *hapus = bantu;
            if(hapus->prev != NULL) hapus->prev->next = hapus->next;
            else head = hapus->next;
            if(hapus->next != NULL) hapus->next->prev = hapus->prev;
            else tail = hapus->prev;
            bantu = hapus->next;
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    if(found) cout<<"Semua data \""<<target<<"\" berhasil dihapus.";
    else cout<<"Data \""<<target<<"\" tidak ditemukan.";
}

void clearH(){
    if(isEmptyH()){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int urutan = 1;
    while(head != NULL){
        if(urutan % 2 == 1){
            TNode *hapus = head;
            cout<<"Penghapusan ke-"<<urutan<<": "<<hapus->data<<endl;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            delete hapus;
        } else {
            TNode *hapus = head;
            while(hapus->next != NULL) hapus = hapus->next;
            cout<<"Penghapusan ke-"<<urutan<<": "<<hapus->data<<endl;
            if(hapus->prev != NULL) hapus->prev->next = NULL;
            else head = NULL;
            delete hapus;
        }
        urutan++;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT(){
    if(isEmptyHT()){
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int urutan = 1;
    while(head != NULL){
        if(urutan % 2 == 1){
            TNode *hapus = head;
            cout<<"Penghapusan ke-"<<urutan<<": "<<hapus->data<<endl;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            else tail = NULL;
            delete hapus;
        } else {
            TNode *hapus = tail;
            cout<<"Penghapusan ke-"<<urutan<<": "<<hapus->data<<endl;
            tail = tail->prev;
            if(tail != NULL) tail->next = NULL;
            else head = NULL;
            delete hapus;
        }
        urutan++;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}