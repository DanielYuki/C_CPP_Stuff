#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "Jolly Jumpers" << endl;
    string str;
    bool isJolly = true;

    getline(cin, str); //get entire line

    vector<int> values, difVector; //create a vector of numbers

    stringstream ss(str); //makes it easier to manipulate the string... I think

    int number, dif;
    while (ss >> number) { //it expects to find a number in the "ss string", if it finds...
        values.push_back(number); //then it extracts the number and adds its value to the vector values
    }

    for (int i = 1; i < values.size(); i++) {
        //creates a vector of the absolute difference between consecutive numbers in the main vector
        dif = abs(values[i] - values[i - 1]);
        difVector.push_back(dif);

        if (values.size() < dif) {
            isJolly = false;
            cout << "\nNot Jolly" << endl;
            break;
        }
        //cout << values[i] << endl;
        //cout << difVector[i-1] << endl;
    }

    if (isJolly) {
        // checks if there are equal values in the difVector
        for (int i = 0; i < difVector.size(); i++) {
            for (int j = i + 1; j < difVector.size(); j++) {
                if (difVector[i] == difVector[j]) {
                    isJolly = false;
                    break;
                }
            }
            if (!isJolly) {
                cout << "\nNot Jolly" << endl;
                break;
            }
        }

        if (isJolly) {
            cout << "\nIs Jolly Jumper" << endl;
        }
    }


    return 0;
}