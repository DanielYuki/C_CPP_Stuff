#include <iostream>

using namespace std;

bool isPrime(int p) {

    if (p % 2 == 0) {
        return false;
    } else {
        for (int i = 3; i < p; i += 2) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {

    int n, count = 0, distPrimDiv = 0;

    cin >> n;

    for (int j = 2; j <= n; j++) {
        if (j % 2 == 0) {
            distPrimDiv++;
        }

        for (int i = 3; i <= j; i += 2) {
            if (isPrime(i) && (j % i == 0)) {
                distPrimDiv++;
            }
        }
        if (distPrimDiv == 2) {
            count++;
        }
        distPrimDiv = 0;

    }

    cout << count;

    return 0;
}
