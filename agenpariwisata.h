#ifndef AGENPARIWISATA_H_INCLUDED
#define AGENPARIWISATA_H_INCLUDED
#include <iostream>
using namespace std;

struct Agen {
    string idAgen;
    string namaAgen;
    string alamat;
    Agen *next;
};
typedef Agen* adrAgen;

struct ListAgen {
    adrAgen first;
};

struct Lokasi {
    string idLokasi;
    string namaLokasi;
    string daerah;
    Lokasi *next;
};
typedef Lokasi* adrLokasi;

struct ListLokasi {
    adrLokasi first;
};

struct Relasi {
    adrAgen agen;
    adrLokasi lokasi;
    Relasi *next;
};
typedef Relasi* adrRelasi;

struct ListRelasi {
    adrRelasi first;
};

// ===== PROTOTYPE =====
void createListAgen(ListAgen &L);
void createListLokasi(ListLokasi &L);
void createListRelasi(ListRelasi &L);

adrAgen createAgen(string id, string nama, string alamat);
adrLokasi createLokasi(string id, string nama, string daerah);
adrRelasi createRelasi(adrAgen A, adrLokasi B);

void insertFirstAgen(ListAgen &L, adrAgen P);
void insertLastAgen(ListAgen &L, adrAgen P);
void insertFirstLokasi(ListLokasi &L, adrLokasi P);
void insertLastLokasi(ListLokasi &L, adrLokasi P);
void insertFirstRelasi(ListRelasi &L, adrRelasi R);

adrAgen searchAgen(ListAgen L, string id);
adrLokasi searchLokasi(ListLokasi L, string id);

void deleteAgen(ListAgen &LA, ListRelasi &LR, string id);
void deleteLokasi(ListLokasi &LL, ListRelasi &LR, string id);
void deleteRelasiAgen(ListRelasi &LR, adrAgen A);
void deleteRelasiLokasi(ListRelasi &LR, adrLokasi L);

void showAllAgen(ListAgen LA);
void showAllLokasi(ListLokasi LL);
void showAllRelasi(ListRelasi LR);

void hubungkanAgenLokasi(ListRelasi &LR, adrAgen A, adrLokasi B);
void tampilkanLokasiDariAgen(ListRelasi LR, adrAgen A);
void tampilkanAgenDariLokasi(ListRelasi LR, adrLokasi B);
int hitungLokasiAgen(ListRelasi LR, adrAgen A);

#endif
