#include <iostream>
#include "string"
#include "deque"

using namespace std;

deque<int> deck1, deck2;

void deckHandler(int num) {
    int size;

    //change pile from deck1 -> deck2
    size = deck1.size();
    for (int i = 0; i < (size + 1) / 2; i++) {
        deck2.push_front(deck1[0]);
        deck1.pop_front();
    }
    deck1.push_front(num);

    //change pile back
    size = deck2.size();
    for (int i = 0; i < size; i++) {
        deck1.push_front(deck2[0]);
        deck2.pop_front();
    }
}

int main() {
    cout << endl << " TEQUE " << endl;
    string cmd;
    int n, steps;

    cout << endl <<" Digit the number of steps: ";
    cin >> steps;

    while (steps != 0) {
        cin >> cmd >> n;
        if (cmd == "push_back" || cmd == "pb") {
            deck1.push_back(n);
        } else if (cmd == "push_front" || cmd == "pf") {
            deck1.push_front(n);
        } else if (cmd == "push_middle" || cmd == "pm") {
            deckHandler(n);
        } else if (cmd == "get" || cmd == "g") {
            cout << endl << "number with index " << n << " is "<< deck1[n] << endl;
        }

        //deck visualization constructor
        string act;
        for (int i = 0; i < deck1.size(); i++) {
            act += to_string(deck1[i]) + " ";
        }

        cout << endl << "{ " << act << "} \n" << endl;
        act = "";

        steps--;
    }

    return 0;
}
