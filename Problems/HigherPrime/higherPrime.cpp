#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    int n, largestP, m;

    cout << " LARGEST PRIME NUMBER \n";
    cout << " Write a number: ";
    cin >> n;

    m = n;

    //checks if 2 is a factor and reduce to the smallest term
    if(n%2==0){
        largestP = 2;
        while(n%2==0){
            n = n/2;
        }
    }

    //checks if this odd number is prime and reduce it to it's smallest term
    for(int i=3; i*i < n; i+=2){
        while(n%i ==0){
            largestP = i;
            n = n/i;
        }
    }

    //if number is prime, then print it
    if(n > 2){
        largestP = n;
    }

    cout << "\n The LARGEST prime number in " << m << " is: " << largestP << "\n\n" ;

    system("pause");
    return 0;
}
