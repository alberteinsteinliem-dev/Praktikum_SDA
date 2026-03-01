#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Masukan nilai x : ";
    cin >> x;
    
    cout << "Masukan nilai y : ";
    cin >> y;

    cout << "\nSebelum tukaran:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukar(x, y);

    cout << "Setelah tukaran:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}