#include "agenpariwisata.h"

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