#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    int n = 5;
    Mahasiswa mhs[5];

    int i;
    for(i = 0; i < n; i++) {

        int nomor = i + 1;
        cout << "Mahasiswa ke-" << nomor << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    int posisi = 0;

    for(i = 0; i < n; i++) {
        if(mhs[i].ipk > mhs[posisi].ipk) {
            posisi = i;
        }
    }

    cout << "Mahasiswa IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[posisi].nama << endl;
    cout << "NIM  : " << mhs[posisi].nim << endl;
    cout << "IPK  : " << mhs[posisi].ipk << endl;

    return 0;
}