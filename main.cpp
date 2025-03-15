#include <iostream>
using namespace std;

int main() {
    int num = 65;
    char* c = reinterpret_cast<char*>(&num);
    cout << *c << endl;  // Might print 'A' if stored in little-endian

    int a = 42;
    double* ptr = reinterpret_cast<double*>(&a);  // ⚠️ Very unsafe!
    cout << *ptr << endl;  // UB

    return 0;
}
