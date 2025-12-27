#include "agenpariwisata.h"
void createListAgen(ListAgen &L){ 
    L.first = nullptr; 
}

void createListLokasi(ListLokasi &L){
    L.first = nullptr; 
}

void createListRelasi(ListRelasi &L){ 
    L.first = nullptr; 
}

adrAgen createAgen(string id, string nama, string alamat){
    adrAgen P = new Agen;
    P->idAgen = id;
    P->namaAgen = nama;
    P->alamat = alamat;
    P->next = nullptr;
    return P;
}

adrLokasi createLokasi(string id, string nama, string daerah){
    adrLokasi P = new Lokasi;
    P->idLokasi = id;
    P->namaLokasi = nama;
    P->daerah = daerah;
    P->next = nullptr;
    return P;
}

adrRelasi createRelasi(adrAgen A, adrLokasi B){
    adrRelasi R = new Relasi;
    R->agen = A;
    R->lokasi = B;
    R->next = nullptr;
    return R;
}

void insertFirstAgen(ListAgen &L, adrAgen P){
    P->next = L.first;
    L.first = P;
}

void insertLastAgen(ListAgen &L, adrAgen P){
    if(L.first == nullptr){ L.first = P; }
    else{
        adrAgen Q = L.first;
        while(Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void insertFirstLokasi(ListLokasi &L, adrLokasi P){
    P->next = L.first;
    L.first = P;
}

void insertLastLokasi(ListLokasi &L, adrLokasi P){
    if(L.first == nullptr){ L.first = P; }
    else{
        adrLokasi Q = L.first;
        while(Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void insertFirstRelasi(ListRelasi &L, adrRelasi R){
    R->next = L.first;
    L.first = R;
}

adrAgen searchAgen(ListAgen L, string id){
    adrAgen P = L.first;
    while(P != nullptr && P->idAgen != id) P = P->next;
    return P;
}

adrLokasi searchLokasi(ListLokasi L, string id){
    adrLokasi P = L.first;
    while(P != nullptr && P->idLokasi != id) P = P->next;
    return P;
}

void deleteRelasiAgen(ListRelasi &LR, adrAgen A){
    adrRelasi R = LR.first, prev = nullptr;
    while(R != nullptr){
        if(R->agen == A){
            if(prev == nullptr) LR.first = R->next;
            else prev->next = R->next;
            adrRelasi del = R;
            R = R->next;
            delete del;
        } else {
            prev = R;
            R = R->next;
        }
    }
}

void deleteRelasiLokasi(ListRelasi &LR, adrLokasi L){
    adrRelasi R = LR.first, prev = nullptr;
    while(R != nullptr){
        if(R->lokasi == L){
            if(prev == nullptr) LR.first = R->next;
            else prev->next = R->next;
            adrRelasi del = R;
            R = R->next;
            delete del;
        } else {
            prev = R;
            R = R->next;
        }
    }
}

void deleteAgen(ListAgen &LA, ListRelasi &LR, string id){
    adrAgen P = LA.first, prev = nullptr;
    while(P != nullptr && P->idAgen != id){ prev = P; P = P->next; }
    if(P != nullptr){
        deleteRelasiAgen(LR, P);
        if(prev == nullptr) LA.first = P->next;
        else prev->next = P->next;
        delete P;
    }
}

void deleteLokasi(ListLokasi &LL, ListRelasi &LR, string id){
    adrLokasi P = LL.first, prev = nullptr;
    while(P != nullptr && P->idLokasi != id){ prev = P; P = P->next; }
    if(P != nullptr){
        deleteRelasiLokasi(LR, P);
        if(prev == nullptr) LL.first = P->next;
        else prev->next = P->next;
        delete P;
    }
}

void showAllAgen(ListAgen LA){
    adrAgen P = LA.first;
    while(P != nullptr){
        cout << "ID: " << P->idAgen << " | " << P->namaAgen << " | " << P->alamat << endl;
        P = P->next;
    }
}

void showAllLokasi(ListLokasi LL){
    adrLokasi P = LL.first;
    while(P != nullptr){
        cout << "ID: " << P->idLokasi << " | " << P->namaLokasi << " | " << P->daerah << endl;
        P = P->next;
    }
}

void showAllRelasi(ListRelasi LR){
    adrRelasi R = LR.first;
    while(R != nullptr){
        cout << R->agen->namaAgen << " -> " << R->lokasi->namaLokasi << endl;
        R = R->next;
    }
}

void hubungkanAgenLokasi(ListRelasi &LR, adrAgen A, adrLokasi B){
    adrRelasi R = createRelasi(A, B);
    insertFirstRelasi(LR, R);
}

void tampilkanLokasiDariAgen(ListRelasi LR, adrAgen A){
    adrRelasi R = LR.first;
    while(R != nullptr){
        if(R->agen == A) cout << "- " << R->lokasi->namaLokasi << endl;
        R = R->next;
    }
}

void tampilkanAgenDariLokasi(ListRelasi LR, adrLokasi B){
    adrRelasi R = LR.first;
    while(R != nullptr){
        if(R->lokasi == B) cout << "- " << R->agen->namaAgen << endl;
        R = R->next;
    }
}

int hitungLokasiAgen(ListRelasi LR, adrAgen A){
    int count = 0;
    adrRelasi R = LR.first;
    while(R != nullptr){
        if(R->agen == A) count++;
        R = R->next;
    }
    return count;
}