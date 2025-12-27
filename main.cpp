#include <iostream>
#include "agenpariwisata.h"
using namespace std;

int main(){
    ListAgen LA;
    ListLokasi LL;
    ListRelasi LR;

    createListAgen(LA);
    createListLokasi(LL);
    createListRelasi(LR);

    int pilih;
    do{
        cout << "\n===== MENU AGEN PARIWISATA =====" << endl;
        cout << "1. Tambah Agen" << endl;
        cout << "2. Tambah Lokasi" << endl;
        cout << "3. Hubungkan Agen - Lokasi" << endl;
        cout << "4. Tampilkan Semua Agen" << endl;
        cout << "5. Tampilkan Semua Lokasi" << endl;
        cout << "6. Tampilkan Semua Relasi" << endl;
        cout << "7. Tampilkan Lokasi dari Agen" << endl;
        cout << "8. Tampilkan Agen dari Lokasi" << endl;
        cout << "9. Hapus Agen" << endl;
        cout << "10. Hapus Lokasi" << endl;
        cout << "11. Lokasi Paling Diminati & Paling Sepi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        if(pilih == 1){
            int jumlahAgen;
            cout << "Masukkan jumlah agen yang ingin ditambahkan: ";
            cin >> jumlahAgen;
            for(int i = 0; i < jumlahAgen; ++i) {
                cout << "\n--- Agen ke-" << i + 1 << " ---" << endl;
                string id, nama, alamat;
                cout << "ID Agen: "; cin >> id;
                cout << "Nama Agen: "; 
                cin.ignore(); 
                getline(cin, nama);
                cout << "Alamat: "; getline(cin, alamat);
                adrAgen A = createAgen(id, nama, alamat);
                insertLastAgen(LA, A);
                cout << "Agen berhasil ditambahkan!" << endl;
            }
        }
        else if(pilih == 2){
            int jumlahLokasi;
            cout << "Masukkan jumlah lokasi yang ingin ditambahkan: ";
            cin >> jumlahLokasi;
            for(int i = 0; i < jumlahLokasi; ++i) {
                cout << "\n--- Lokasi ke-" << i + 1 << " ---" << endl;
                string id, nama, daerah;
                cout << "ID Lokasi: "; cin >> id;
                cout << "Nama Lokasi: "; 
                cin.ignore();
                getline(cin, nama);
                cout << "Daerah: "; getline(cin, daerah);
                adrLokasi L = createLokasi(id, nama, daerah);
                insertLastLokasi(LL, L);
                cout << "Lokasi berhasil ditambahkan!" << endl;
            }
        }
        else if(pilih == 3){
            string idA, idL;
            cout << "ID Agen: "; cin >> idA;
            cout << "ID Lokasi: "; cin >> idL;
            adrAgen A = searchAgen(LA, idA);
            adrLokasi B = searchLokasi(LL, idL);
            if(A != NULL && B != NULL){
                hubungkanAgenLokasi(LR, A, B);
                cout << "Relasi berhasil ditambahkan!" << endl;
            } else cout << "Agen/Lokasi tidak ditemukan!" << endl;
        }

        else if(pilih == 4){
            cout << "===== DAFTAR AGEN =====" << endl;
            showAllAgen(LA);
        }
        else if(pilih == 5){
            cout << "===== DAFTAR LOKASI =====" << endl;
            showAllLokasi(LL);
        }
        else if(pilih == 6){
            cout << "===== DAFTAR RELASI =====" << endl;
            showAllRelasi(LR);
        }
        else if(pilih == 7){
            string id;
            cout << "Masukkan ID Agen: "; cin >> id;
            adrAgen A = searchAgen(LA, id);
            if(A != NULL){
                cout << "Lokasi yang ditangani agen " << A->namaAgen << ":" << endl;
                tampilkanLokasiDariAgen(LR, A);
            } else cout << "Agen tidak ditemukan!" << endl;
        }
        else if(pilih == 8){
            string id;
            cout << "Masukkan ID Lokasi: "; cin >> id;
            adrLokasi L = searchLokasi(LL, id);
            if(L != NULL){
                cout << "Agen yang menangani lokasi " << L->namaLokasi << ":" << endl;
                tampilkanAgenDariLokasi(LR, L);
            } else cout << "Lokasi tidak ditemukan!" << endl;
        }
        else if(pilih == 9){
            string id;
            cout << "ID Agen yang akan dihapus: "; cin >> id;
            deleteAgen(LA, LR, id);
            cout << "Agen berhasil dihapus (beserta relasinya)." << endl;
        }
        else if(pilih == 10){
            string id;
            cout << "ID Lokasi yang akan dihapus: "; cin >> id;
            deleteLokasi(LL, LR, id);
            cout << "Lokasi berhasil dihapus (beserta relasinya)." << endl;
        }
        else if(pilih == 11){
            if(LL.first == NULL){
                cout << "Belum ada lokasi!" << endl;
            } else {
                adrLokasi P = LL.first;
                adrLokasi maxLoc = LL.first;
                adrLokasi minLoc = LL.first;
                int maxCount = -1;
                int minCount = 999999;

                while(P != NULL){
                    int count = 0;
                    adrRelasi R = LR.first;
                    while(R != NULL){
                        if(R->lokasi == P) count++;
                        R = R->next;
                    }
                    if(count > maxCount){ maxCount = count; maxLoc = P; }
                    if(count < minCount){ minCount = count; minLoc = P; }
                    P = P->next;
                }

                cout << "\n=== LOKASI TERPOPULER ===" << endl;
                cout << maxLoc->namaLokasi << " (" << maxCount << " agen)" << endl;

                cout << "\n=== LOKASI PALING SEPI ===" << endl;
                cout << minLoc->namaLokasi << " (" << minCount << " agen)" << endl;
            }
        }

    } while(pilih != 0);

    cout << "Program selesai." << endl;
    return 0;
}