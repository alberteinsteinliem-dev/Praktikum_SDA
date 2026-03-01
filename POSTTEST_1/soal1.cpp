#include <iostream>
using namespace std;

int main() {

    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int n = 8;
    int min = A[0];
    int posisi = 0;

        for(int i = 1; i < n; ++i) {
            int nilai = A[i];

        if(nilai < min) {
            min = nilai;
            posisi = i;
    }
}

    cout << "Nilai minimum : " << min << endl;
    cout << "posisi minimum : " << posisi << endl;

    return 0;
}
