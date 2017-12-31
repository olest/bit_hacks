#include<iostream>

using namespace std;

int main(int argc, char** argv) {

    // right propagate the right most bit
    int x = 4;
    x |= (x-1);
    cout << "x= " << x << "\n"; 

    // isolate the the lowest bit that is set to one
    // useful to compute parity/number of bits set
    x = 4;
    int y = x & ~(x-1);
}
