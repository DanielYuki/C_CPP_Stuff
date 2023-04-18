#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> deck;

int main() {
    cout << " THROWING CARDS AWAY " << endl;

    int n, top, aux = 0;
    string discard;

    cout << " Digit the number of cards: ";
    cin >> n;

    //Create Deck of Cards
    for (int i = 0; i < n; ++i) {
        deck.push_back(i + 1);
    }

    while (deck.size() > 1) {
        top = deck[0];
        if (aux % 2 == 0) { //to discard
            if (deck.size() != 2) {
                discard += (" " + to_string(top) + ",");
            } else {
                discard += (" " + to_string(top));
            }

            deck.pop_front();
        } else {
            deck.push_back(top); //move the card to the bottom
            deck.pop_front();
        }
        aux++;
    }

    cout << endl << " Discarded cards:" << discard;
    cout << endl << " Remaining card: " << deck[0];

    return 0;
}
