#include <iostream>
#include "deque"
#include "string"

using namespace std;

deque<int> deck;

int main() {
    cout << endl << " PIVOT " << endl;

    int n, count = 0, pivot;
    bool isPivot = true;
    string pivotList;

    cout << endl << " Digit the size of my base Array: ";
    cin >> n;

    int baseArray[n + 1];

    cout << " Digit the numbers of this array: ";
    for (int i = 0; i < n; i++) {
        cin >> baseArray[i];
        //scanf("%d", &baseArray[i]);
        //cout << baseArray[i];
    }

    for (int i = 0; i < n; i++) {
        pivot = baseArray[i];
        for (int j = 0; j <= i; j++) {
            if (baseArray[j] > pivot) {
                isPivot = false;
                break;
            }
            for (int k = n-1; k > i; k--) {
                if (baseArray[k] < pivot) {
                    isPivot = false;
                    break;
                }
            }
        }
        if (isPivot) {
            count++;
            deck.push_front(pivot);
            pivotList += to_string(pivot) + " ";
        }
        isPivot = true;
    }

    if (count == 0) {
        cout << endl << " There is no valid Pivot Number in this sequence " << endl;
    } else if (count == 1) {
        cout << endl << " There is " << count << " Pivot, and it is the number " << pivotList << endl;
    } else {
        cout << endl << " There are " << count << " Pivots, and they are the numbers " << pivotList << endl;
    }

    return 0;
}
