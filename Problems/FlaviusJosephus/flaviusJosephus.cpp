#include <iostream>
#include "deque"

using namespace std;

deque<int> deck;

int main() {
    cout << " The Flavious Josephus Legend Problem" << endl;

    int n, k, top;

    cout << " Digit the number of people: ";
    cin >> n;

    for (int i = 0; i < n; ++i) { //create deck
        deck.push_back(i + 1);
    }

    cout << " Digit the size of step between two men in the circle: ";
    cin >> k;

    while (deck.size() > 1) {
        for (int i = 0; i < k-1; i++) {
            top = deck[0];
            deck.push_back(top);
            deck.pop_front();
        }
        deck.pop_front();
    }

    cout << endl << " The Survivor's Number is: " << deck[0] << endl;

    return 0;
}
