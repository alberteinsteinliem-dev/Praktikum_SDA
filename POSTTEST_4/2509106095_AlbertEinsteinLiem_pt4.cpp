#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
    Hewan* next;
};

Hewan* head = NULL;
Hewan* front = NULL;
Hewan* rear = NULL;
Hewan* top = NULL;

void tambahData(Hewan*& head) {
    Hewan* baru = new Hewan;

    cout << "\n=== Tambah Data Hewan ===\n";
    cout << "ID: "; cin >> baru->id;
    cin.ignore();
    cout << "Nama: "; getline(cin, baru->nama);
    cout << "Jenis: "; getline(cin, baru->jenis);
    cout << "Harga: "; cin >> baru->harga;

    baru->next = NULL;

    if(head == NULL) {
        head = baru;
    } else {
        Hewan* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilData(Hewan* head) {
    if(head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Hewan* temp = head;
    while(temp != NULL) {
        cout << "ID: " << temp->id << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Jenis: " << temp->jenis << endl;
        cout << "Harga: " << temp->harga << endl;
        cout << "------------------\n";
        temp = temp->next;
    }
}

void enqueue(Hewan data) {
    Hewan* baru = new Hewan;
    *baru = data;
    baru->next = NULL;

    if(front == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << data.nama << " masuk antrian\n";
}

void dequeue() {
    if(front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan* temp = front;
    cout << "Memanggil: " << temp->nama << endl;

    // masuk ke stack
    Hewan* baru = new Hewan;
    *baru = *temp;
    baru->next = top;
    top = baru;

    front = front->next;
    delete temp;

    if(front == NULL) rear = NULL;
}

void tampilAntrian() {
    if(front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan* temp = front;
    cout << "\n=== Antrian ===\n";
    while(temp != NULL) {
        cout << temp->id << " | " << temp->nama << endl;
        temp = temp->next;
    }
}

void push(Hewan data) {
    Hewan* baru = new Hewan;
    *baru = data;

    baru->next = top;
    top = baru;
}

void pop() {
    if(top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan* temp = top;
    cout << "Hapus riwayat: " << temp->nama << endl;

    top = top->next;
    delete temp;
}

void tampilRiwayat() {
    if(top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan* temp = top;
    cout << "\n=== Riwayat ===\n";
    while(temp != NULL) {
        cout << temp->id << " | " << temp->nama << endl;
        temp = temp->next;
    }
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if(front != NULL)
        cout << "Antrian depan: " << front->nama << endl;
    else
        cout << "Antrian kosong\n";

    if(top != NULL)
        cout << "Riwayat terakhir: " << top->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

void cariNama(Hewan* head) {
    string cari;
    cout << "Cari Nama: ";
    cin.ignore();
    getline(cin, cari);

    Hewan* temp = head;
    bool ketemu = false;

    while(temp != NULL) {
        if(temp->nama == cari) {
            cout << "Ditemukan: " << temp->nama << endl;
            ketemu = true;
        }
        temp = temp->next;
    }

    if(!ketemu) cout << "Tidak ditemukan!\n";
}

int main() {
    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Masuk Antrian\n";
        cout << "5. Panggil\n";
        cout << "6. Tampil Antrian\n";
        cout << "7. Tampil Riwayat\n";
        cout << "8. Pop Riwayat\n";
        cout << "9. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahData(head); break;
            case 2: tampilData(head); break;
            case 3: cariNama(head); break;

            case 4: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;

                Hewan* temp = head;
                while(temp != NULL) {
                    if(temp->id == id) {
                        enqueue(*temp);
                        break;
                    }
                    temp = temp->next;
                }
                break;
            }

            case 5: dequeue(); break;
            case 6: tampilAntrian(); break;
            case 7: tampilRiwayat(); break;
            case 8: pop(); break;
            case 9: peek(); break;
        }

    } while(pilih != 0);

    return 0;
}