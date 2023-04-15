#include <iostream>

using namespace std;

long double factorialCalc(long double n) {
    int m = n;

    while (m > 1) {
        n *= --m;
    }

    return n;
}

int main() {
    cout << "\n LATTICE PATHS\n";
    cout << " Define a pxqGrid => digit the p and q value: ";
    int sizeP, sizeQ;
    long double a,b,c;

    cin >> sizeP >> sizeQ;

    //using math and permutation concepts: total paths = a! / b!*c!, given a is the sum of the "size p and q"
    // b is the number of times that I have to go to the right to get to the end
    // c works the same as b, but in the other direction

    a = factorialCalc(sizeQ+sizeP);
    b = factorialCalc(sizeP);
    c = factorialCalc(sizeQ);

    cout << "\n There are " << (a/b)/c << " possible Paths \n";

    return 0;
}
