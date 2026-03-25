#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

int n = 0;

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

void linearSearch(Hewan *arr) {
    string cari;
    cout << "\nCari Nama Hewan: ";
    cin.ignore();
    getline(cin, cari);

    bool ketemu = false;
    for(int i = 0; i < n; i++) {
        if((arr + i)->nama == cari) {
            cout << "\nData ditemukan:\n";
            cout << "ID: " << (arr + i)->id << endl;
            cout << "Nama: " << (arr + i)->nama << endl;
            cout << "Jenis: " << (arr + i)->jenis << endl;
            cout << "Harga: " << (arr + i)->harga << endl;
            ketemu = true;
        }
    }
    if(!ketemu) cout << "Data tidak ditemukan!\n";
}

void fibonacciSearch(Hewan *arr, int x) {
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        cout << "Cek index ke-" << i << " (ID: " << (arr + i)->id << ")\n";

        if ((arr + i)->id < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if ((arr + i)->id > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            cout << "\nData ditemukan:\n";
            cout << "Nama: " << (arr + i)->nama << endl;
            return;
        }
    }

    if (fib1 && (arr + offset + 1)->id == x) {
        cout << "\nData ditemukan:\n";
        cout << "Nama: " << (arr + offset + 1)->nama << endl;
        return;
    }

    cout << "Data tidak ditemukan!\n";
}

void bubbleSort(Hewan *arr) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if((arr + j)->nama > (arr + j + 1)->nama) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama.\n";
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
    cout << "Data berhasil diurutkan berdasarkan harga.\n";
}

int main() {
    Hewan *data = new Hewan[100];
    int pilihan;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Urutkan Nama\n";
        cout << "6. Urutkan Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: tampilData(data); break;
            case 2: tambahData(data); break;
            case 3: linearSearch(data); break;
            case 4: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;
                fibonacciSearch(data, id);
                break;
            }
            case 5: bubbleSort(data); break;
            case 6: selectionSort(data); break;
        }

    } while(pilihan != 0);

    delete[] data;
    return 0;
}