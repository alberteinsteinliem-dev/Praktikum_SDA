#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

int n = 0;

#define MAX 100
Hewan riwayat[MAX];
int top = -1;

Hewan antrian[MAX];
int dpn = -1, blkng = -1;

void swap(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData(Hewan *&arr) {
    cout << "\n=== Tambah Data Hewan ===\n";
    cout << "ID: "; cin >> (arr + n)->id;
    cin.ignore();
    cout << "Nama: "; getline(cin, (arr + n)->nama);
    cout << "Jenis: "; getline(cin, (arr + n)->jenis);
    cout << "Harga: "; cin >> (arr + n)->harga;
    n++;
}

void tampilData(Hewan *arr) {
    cout << "\n=== Data Hewan ===\n";
    for(int i = 0; i < n; i++) {
        cout << "ID: " << (arr + i)->id << endl;
        cout << "Nama: " << (arr + i)->nama << endl;
        cout << "Jenis: " << (arr + i)->jenis << endl;
        cout << "Harga: " << (arr + i)->harga << endl;
        cout << "----------------------\n";
    }
}

bool isQueueFull() {
    return blkng == MAX - 1;
}

bool isQueueEmpty() {
    return dpn == -1 || dpn > blkng;
}

void enqueue(Hewan data) {
    if(isQueueFull()) {
        cout << "Antrian penuh!\n";
        return;
    }

    if(dpn == -1) dpn = 0;

    blkng++;
    antrian[blkng] = data;

    cout << data.nama << " masuk antrian.\n";
}

Hewan dequeue() {
    Hewan kosong;
    if(isQueueEmpty()) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Hewan temp = antrian[dpn];
    dpn++;

    if(isQueueEmpty()) {
        dpn = blkng = -1;
    }

    return temp;
}

void tampilAntrian() {
    if(isQueueEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== Antrian Pasien ===\n";
    for(int i = dpn; i <= blkng; i++) {
        cout << "ID: " << (antrian + i)->id
             << " | Nama: " << (antrian + i)->nama << endl;
    }
}

bool isStackEmpty() {
    return top < 0;
}

void push(Hewan data) {
    if(top >= MAX - 1) {
        cout << "Riwayat penuh!\n";
        return;
    }

    top++;
    riwayat[top] = data;

    cout << "Tindakan untuk " << data.nama << " disimpan.\n";
}

void pop() {
    if(isStackEmpty()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Menghapus riwayat: " << riwayat[top].nama << endl;
    top--;
}

void tampilRiwayat() {
    if(isStackEmpty()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== Riwayat Tindakan ===\n";
    for(int i = top; i >= 0; i--) {
        cout << "ID: " << (riwayat + i)->id
             << " | Nama: " << (riwayat + i)->nama << endl;
    }
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if(!isQueueEmpty()) {
        cout << "Antrian dpn: "
             << antrian[dpn].nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if(!isStackEmpty()) {
        cout << "Riwayat terakhir: "
             << riwayat[top].nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void linearSearch(Hewan *arr) {
    string cari;
    cout << "\nCari Nama Hewan: ";
    cin.ignore();
    getline(cin, cari);

    bool ketemu = false;
    for(int i = 0; i < n; i++) {
        if((arr + i)->nama == cari) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }
    if(!ketemu) cout << "Tidak ditemukan!\n";
}

void bubbleSort(Hewan *arr) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if((arr + j)->nama > (arr + j + 1)->nama) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void selectionSort(Hewan *arr) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        swap(arr + i, arr + minIdx);
    }
}

int main() {
    Hewan *data = new Hewan[100];
    int pilihan;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Masuk Antrian\n";
        cout << "5. Panggil Pasien\n";
        cout << "6. Tampil Antrian\n";
        cout << "7. Tampil Riwayat\n";
        cout << "8. Hapus Riwayat\n";
        cout << "9. Peek\n";
        cout << "10. Urut Nama\n";
        cout << "11. Urut Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: tampilData(data); break;
            case 2: tambahData(data); break;
            case 3: linearSearch(data); break;

            case 4: {
                int idx;
                cout << "Masukkan index data: ";
                cin >> idx;
                if(idx >= 0 && idx < n)
                    enqueue(*(data + idx));
                break;
            }

            case 5: {
                Hewan h = dequeue();
                if(h.nama != "") {
                    cout << "Memanggil: " << h.nama << endl;
                    push(h);
                }
                break;
            }

            case 6: tampilAntrian(); break;
            case 7: tampilRiwayat(); break;
            case 8: pop(); break;
            case 9: peek(); break;

            case 10: bubbleSort(data); break;
            case 11: selectionSort(data); break;
        }

    } while(pilihan != 0);

    delete[] data;
    return 0;
}