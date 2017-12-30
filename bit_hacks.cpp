#include<iostream>

using namespace std;

int main(int argc, char** argv) {

    // right propagate the right most bit
    int x = 4;
    x |= (x-1);
    cout << "x= " << x << "\n"; 

}
