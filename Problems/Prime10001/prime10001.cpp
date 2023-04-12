#include<stdio.h>
#include<iostream>

using namespace std;

int primeNum(int nth){
    int prime=0,counter=1;
    bool isPrime = true;

    for(int i= 3; counter<nth ; i+=2){
        for(int j = 2; j<i ; j++){
            //reassume that i is prime
            isPrime = true;
            //checks if i is divisible by other number than 1 or itself
            if(i%j ==0){
                // if it is, then i is not prime
                isPrime = false;
                break;
            }
            //checks if the choosen number is the nth number of this particular prime
            if(counter == nth-1){
                prime = i;
            }
        }
        // if it is prime, then add 1 to the counter
        if(isPrime==true){
            counter++;
        }
    }

    //return the value of the prime number
    return prime;
}

int main(){

    int n=0;
    cout << " THE Nth PRIME NUMBER \n";
    cout << "\n Digit the Nth number that u want to know the prime of: ";
    cin >> n;

    cout <<"\n The "<< n<<"th prime number is: " << primeNum(n) << "\n\n";

    system("pause");
    return 0;
}

