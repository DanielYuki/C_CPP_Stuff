#include <stdio.h>
#include <iostream>

using namespace std;


bool isPrime(long int p){

    if(p%2 == 0){
        return false;
    }else{
        for(int i=3; i<p; i+=2){
            if(p%i == 0){
                return false;
            }
        }
        return true;
    }
}


int main(){
    long int n,sum = 2;

    cin >> n;

    for(int i=3;i<n;i+=2){
        if(isPrime(i)){
            sum += i;
            //cout << i;
        }
    }

    cout << sum;

    return 0;
}
