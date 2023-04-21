#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << " Greedily Increasing Subsequence " << endl;

    int n, next, m, count = 0;
    string subsequence;

    cout << " Digit the size of the sequence: ";
    cin >> n;
    cout << " Digit the sequence of numbers: ";

    for (int i = n; i > 0; i--) {
        cin >> next;
        if (next > m || i == n) {
            subsequence += to_string(next) + " ";
            count++;
        }
        m = next;

    }

    cout << endl << " My Subsequence is: " << subsequence << "and it has " << count << " Numbers" <<endl;

    return 0;
}
