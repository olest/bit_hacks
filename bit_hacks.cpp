#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

void dump_bits(long input) {
    std::stringstream bits;
    while(input) {
        if (input & 1) {
            bits << "1";
        } else {
            bits << "0";
        }
        input >>= 1;
    }
    string bits_str = bits.str();
    std::reverse(std::begin(bits_str),std::end(bits_str));
    cout << bits_str << "\n";
}

// bits indexed from zero
long swap_bits(long input, int i, int j) {
    std::cout << "T1: " << ((input >> i) & 1) << "\n";
    std::cout << "T2: " << ((input >> j) & 1) << "\n";
    if ( ((input >> i) & 1) != ((input >> j) & 1) ) {
        unsigned long bit_mask = (1L << i) | (1L << j);
        cout << "bit_mask=" << bit_mask << "\n";
        input ^= bit_mask;
    }
    return input;
}

int count_ones_fast(int num) {
    int numOnes = 0;
    while(num) {
        num &= (num-1);
        ++numOnes;
    }
    return numOnes;
}

// return true if LSB is 1 (= Little Endian)
bool is_little_endian() {
    int testNum;
    char* ptr;

    testNum = 1;
    ptr = (char*) &testNum;
    return (*ptr);
}

// works because a union stores all its members at the same memory address
// so accessing endianTest.b gives acess to the LSB
// Programming Interviews Exposed p. 155
bool is_little_endian_fancy() {
    union {
        int i;
        char b;
    } endianTest;
    endianTest.i = 1;
    return endianTest.b;
}

int main(int argc, char** argv) {

    // right propagate the right most bit
    int x = 4;
    x |= (x-1);
    cout << "x= " << x << "\n"; 

    // isolate the the lowest bit that is set to one
    // useful to compute parity/number of bits set
    x = 4;
    int y = x & ~(x-1);
    cout << x << " has " << count_ones_fast(x) << " bits set to 1." << std::endl;
    x= 5;
    cout << x << " has " << count_ones_fast(x) << " bits set to 1." << std::endl;

    std::cout << "Is this platform Little Endian ? " << std::boolalpha << is_little_endian() << std::endl;
             
    long x2 = 2; // 10
    dump_bits(x2);
    int i = 1, j=3;
    long x2_swapped = swap_bits(x2,i,j);
    std::cout << "x=" << x2 << " x_swapped=" << x2_swapped << std::endl;
}
