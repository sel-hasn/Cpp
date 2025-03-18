#include <iostream>
using namespace std;

int main() {
    // int num = 65;
    // char* c = reinterpret_cast<char*>(&num);
    // cout << *c << endl;  // Might print 'A' if stored in little-endian

    // int a = 42;
    // double* ptr = reinterpret_cast<double*>(&a);  // ⚠️ Very unsafe!
    // cout <<std::fixed<< *ptr << endl;  // UB
    float f = 2147483635.0f;
    // double d = 340282346638528859811704183484516925486237455545564646454646.0;
    std::cout<<f<<std::endl;
    std::cout<<std::fixed<<f<<std::endl;
    // std::cout<<std::fixed<<d<<std::endl;
    return 0;
}
