// OPTIMIZED
/*
#include <iostream>

using namespace std;

int main() {

    int numTest, n, q, num;
    scanf("%d", &numTest);

    while (numTest--) {

        scanf("%d %d", &n, &q);

        int array[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            array[i] = num;
        }

        // Compute prefix sum
        int prefixSum[n];
        prefixSum[0] = array[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + array[i];
        }

        while (q--) {
            int  l, r, k, sum = 0;

            scanf("%d %d %d", &l, &r, &k);

            // Incrementally update sum based on prefix sum
            if (l > 1) {
                sum += prefixSum[l-2];
            }
            sum += (r-l+1) * k;
            if (r < n) {
                sum += prefixSum[n-1] - prefixSum[r-1];
            }

            if (sum % 2 == 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}
*/


// NOT OPTIMIZED
#include <iostream>

using namespace std;

int main() {

    int numTest, n, q, l, r, k, num, sum = 0;

    cin >> numTest;

    while (numTest--) {
        cin >> n >> q;

        int array[n + 1];
        //int auxArray[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> num;
            array[i] = num;
        }

        while (q--) {
            cin >> l >> r >> k;

            for (int j = 0; j < n; j++) {
                if (j >= l - 1 && j <= r - 1) {
                    sum += k;
                } else {
                    //sum += auxArray[j];
                    sum += array[j];
                }
            }

            if (sum % 2 == 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }

            sum = 0;
        }
    }

    return 0;
}
