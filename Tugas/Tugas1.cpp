#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>


using namespace std;

struct TNode{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil=atoi(pilihan);

        switch(pil) {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            hapusDepan();
            cout<<"Data \""<<dataHapus<<"\" yang berada di depan telah berhasil dihapus."<<endl;
            break;
        case 4:
            hapusBelakang();
            cout<<"Data \""<<dataHapus<<"\" yang berada di belakang telah berhasil dihapus."<<endl;
            break;
        case 5:
            tampilkan();
            break;
        case 6:
            reset();
            break;
        case 7:
            cariData();
            break;
        case 8:
            hapusData();
            break;
        case 9:
            sisipkanSebelum();
            break;
        case 10:
            sisipkanSetelah();
            break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by Muhammad Rizky Ramadhani (2510817210004)."<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pil < 11);
}

    void init() {
        head = NULL;
        tail = NULL;
    }

    int isEmpty() {
        if(head == NULL) return 1;
        else return 0;
    }

    void tambahDepan() {
        cout << "Masukkan beberapa data (pisahkan dengan spasi): ";
        string line;
        cin.ignore();
        getline(cin, line);

        stringstream ss(line);
        string item;
        vector<string> dataList;

        while (ss >> item) {
            dataList.push_back(item);
        }

        for (int i = dataList.size() - 1; i >= 0; i--) {
            TNode *baru = new TNode;
            baru->data = dataList[i];
            baru->next = baru;

            if (isEmpty() == 1) {
                head = baru;
                tail = baru;
            } else {
                baru->next = head;
                head = baru;
                tail->next = head;
            }
            cout << "Data \"" << dataList[i] << "\" berhasil dimasukkan di bagian depan." << endl;
    }
}

    void tambahBelakang() {
        cout<<"Masukkan data : ";
        TNode *baru;
        baru = new TNode;
        cin>>dataBaru;
        baru->data =  dataBaru;
        baru->next = baru;

        if(isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
        cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan dibagian belakang."<<endl;
    }

void hapusDepan() {
    if (isEmpty() == 0) {
        int N;
        cout << "Masukkan posisi node ke-N dari depan yang ingin dihapus: ";
        cin >> N;

        int jumlah = 0;
        TNode *bantu = head;
        do {
            jumlah++;
            bantu = bantu->next;
        } while (bantu != head);

        if (N > jumlah) {
            TNode *hapus = tail;
            dataHapus = hapus->data;

            if (head != tail) {
                TNode *sebelum = head;
                while (sebelum->next != tail) {
                    sebelum = sebelum->next;
                }
                tail = sebelum;
                tail->next = head;
            } else {
                init();
            }

            delete hapus;
            cout << "Karena N lebih besar dari jumlah node, maka data \"" << dataHapus << "\" (tail) dihapus." << endl;
            return;
        }

        if (N == 1) {
            TNode *hapus = head;
            dataHapus = hapus->data;

            if (head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }

            delete hapus;
            cout << "Data \"" << dataHapus << "\" (head) dihapus." << endl;
            return;
        }

        TNode *sebelum = head;
        for (int i = 1; i < N - 1; i++) {
            sebelum = sebelum->next;
        }

        TNode *hapus = sebelum->next;
        dataHapus = hapus->data;

        if (hapus == tail) {
            tail = sebelum;
        }
        sebelum->next = hapus->next;
        delete hapus;

        tail->next = head;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

    void hapusBelakang() {
        if (isEmpty() == 0) {
            int N;
            cout << "Masukkan posisi node ke-N dari belakang yang ingin dihapus: ";
            cin >> N;

            int jumlah = 0;
            TNode *bantu = head;
            do {
                jumlah++;
                bantu = bantu->next;
            } while (bantu != head);

            if (N > jumlah) {
                TNode *hapus = head;
                dataHapus = hapus->data;

                if (head != tail) {
                    head = head->next;
                    tail->next = head;
                } else {
                    init();
                }

                delete hapus;
                cout << "Karena N lebih besar dari jumlah node, maka data \"" << dataHapus << "\" (head) dihapus." << endl;
                return;
            }

            int posisi = jumlah - N + 1;

            if (posisi == 1) {
                TNode *hapus = head;
                dataHapus = hapus->data;

                if (head != tail) {
                    head = head->next;
                    tail->next = head;
                } else {
                    init();
                }

                delete hapus;
                cout << "Data \"" << dataHapus << "\" (head) dihapus." << endl;
                return;
            }

            TNode *sebelum = head;
            for (int i = 1; i < posisi - 1; i++) {
                sebelum = sebelum->next;
            }

            TNode *hapus = sebelum->next;
            dataHapus = hapus->data;

            if (hapus == tail) {
                tail = sebelum;
            }
            sebelum->next = hapus->next;
            delete hapus;

            tail->next = head;
        } else {
            cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

    void tampilkan() {
        if(isEmpty() == 0) {
            TNode *bantu;
            bantu = head;

            do {
                cout<<bantu->data<<' ';
                bantu = bantu->next;
            } while(bantu != head);
            cout<<endl;
        } else cout<<"Tidak terdapat data pada Linked List."<<endl;
    }

    void reset() {
        if (isEmpty() == 0) {
            TNode *bantu = head;
            int nomor = 1;

            do {
                TNode *hapus = bantu;
                bantu = bantu->next;
                cout << "Menghapus node ke-" << nomor << " dengan data \"" << hapus->data << "\"" << endl;
                delete hapus;
                nomor++;
            } while (bantu != head);

            init();
            cout << "Seluruh elemen pada Linked List telah dihapus." << endl;
        } else {
            cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

    void cariData(){
        if(isEmpty() == 0) {
            string cari;
            cout<<"Masukan data yang ingin dicari : ";
            cin>>cari;

            TNode *bantu, *hapus, *newTail, *bantuTampilkan;
            bool apaDitemukan = false;

            bantu = head;

            do {
                if(cari == bantu->data){
                    cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                        <<"merupakan data yang anda cari."<<endl;
                    cout<<"Linked List : ";
                    bantuTampilkan = head;

                    do {
                        if(cari == bantuTampilkan->data)
                            cout<<"["<<bantuTampilkan->data<<"] ";
                        else
                            cout<<bantuTampilkan->data<<' ';
                        bantuTampilkan = bantuTampilkan->next;
                    } while(bantuTampilkan != head);

                    apaDitemukan = true;
                    cout<<endl;
                    break;
                }
                bantu = bantu->next;
            } while(bantu != head);

            if(apaDitemukan == false)
                cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        } else cout<<"Tidak terdapat data pada Linked List."<<endl;
    }

    void hapusData(){
        if(isEmpty() == 0) {
            string cari;
            cout<<"Masukkan data yang ingin dihapus : ";
            cin>>cari;

            TNode *bantu, *sebelum, *hapus[225], *bantu2;
            int hitung = 0;
            bool apaDitemukan = false;

            bantu = head;

            do {
                bantu2 = bantu;
                if(cari == bantu->data){
                    hapus[hitung++] = bantu;
                    apaDitemukan = true;
                    if(bantu != head && bantu != tail) {
                        sebelum->next = bantu->next;
                        bantu2 = sebelum;
                    }
                }
                sebelum = bantu2;
                bantu = bantu->next;
            } while(bantu != head);

            if(apaDitemukan == true) {
                for(int i = 0; i < hitung; i++) {
                    if(hapus[i] == head){
                        hapusDepan();
                    } else if(hapus[i] == tail) {
                        hapusBelakang();
                    } else {
                        delete hapus[i];
                    }
                }

                cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus";
            } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;

        } else cout<<"Tidak terdapat data pada Linked List."<<endl;
    }

    void sisipkanSebelum() {
        if(isEmpty() == 0) {
            TNode *bantu, *sebelum;
            string nextData;
            bool apaAda;

            bantu = head;
            sebelum = tail;

            cout<<"Sisipkan data baru sebelum data : ";
            cin>>nextData;

            do {
                if(nextData == bantu->data){
                    apaAda = true;
                    break;
                } else {
                    sebelum = bantu;
                    bantu = bantu->next;
                }
            } while(bantu != head);

            if(apaAda==true) {
                cout<<"Masukkan data yang ingin ditambahkan : ";
                cin>>dataBaru;

                TNode *baru;
                baru = new TNode;

                baru->data = dataBaru;
                baru->next = bantu;

                sebelum->next = baru;

                if(bantu == head){
                    head = baru;
                }

                cout << "Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
            } else {
                cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
            }
        } else cout<<"Tidak tedapat data pada Linked List."<<endl;
    }

    void sisipkanSetelah() {
        if(isEmpty() == 0) {
            TNode *bantu;
            string prevData;
            bool apaAda;

            bantu = head;

            cout<<"Sisipkan data baru setelah data : ";
            cin>>prevData;

            do {
                if(prevData == bantu->data){
                    apaAda = true;
                    break;
                } else {
                    bantu = bantu->next;
                }
            } while(bantu != head);

            if(apaAda==true) {
                cout<<"Masukkan data yang ingin ditambahkan : ";
                cin>>dataBaru;

                TNode *baru;
                baru = new TNode;

                baru->data = dataBaru;
                baru->next = bantu->next;
                
                bantu->next = baru;

                if(bantu == tail){
                    tail = baru;
                }

                cout << "Data \""<<dataBaru<<"\" berhasil disisipkan setelah data \""<<prevData<<"\"."<<endl;
            } else {
                cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
            }
        } else cout<<"Tidak terdapat data pada Linked List."<<endl;
    }