#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int x = 1,y = 2,z, terms, sum = 2;

    cout << "\n SUM EVEN NUMBERS FIBONACCI \n";
    cout << "\n Digit the number of terms(must be higher than 2): ";
    cin >> terms;

    for(int i = 0; i != terms; i++){
        z = x + y;
        x = y;
        y = z;

        if(z%2 == 0){
            sum += z;
        }
    }

    cout << "\n The sum is: " << sum << "\n\n";

    system("pause");
    return 0;
}
