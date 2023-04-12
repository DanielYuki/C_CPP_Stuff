#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    cout << "\n SUM SQUARE DIFFERENCE \n";
    int sumSquared, squareSum=0, n;

    cout << " The difference between the sum of the squares of the first: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        sumSquared = sumSquared + (i*i);
        squareSum += i;
    }

    squareSum = squareSum * squareSum;

    cout << "\n The difference between the square of the sum and the sum of squares is: "<<(squareSum - sumSquared) << "\n\n";

    system("pause");
    return 0;
}
