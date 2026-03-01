#include <iostream>
using namespace std;

void printArray(int* arr, int n) {
    int* p = arr;
    cout << "Nilai   | Alamat memori" << endl;
    
    for (int i = 0; i < n; i++) {
        if (*p < 10) {
            cout << " ";
        }
        
        cout << *p << "      |   " << p << endl;
        p++;
    }
    cout << endl;
}

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + n - 1;
    
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        
        awal++;
        akhir--;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array kalau tidak di balik" << endl;
    printArray(prima, n);

    reverseArray(prima, n);

    cout << "Array kalau di Balik" << endl;
    printArray(prima, n);

    return 0;
}