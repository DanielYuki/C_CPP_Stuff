#include<stdio.h>
#include<iostream>

using namespace std;

bool isPalindrome(int p){
    int dig1,dig2,dig3,dig4,dig5,dig6;

    if(p < 99999){
        dig5 = p%10;
        p /= 10;
        dig4 = p%10;
        p /= 10;
        p /= 10;
        dig2 = p%10;
        p /= 10;
        dig1 = p%10;
        p /= 10;

        if(dig1 == dig5 && dig2 == dig4){
            return true;
        }else{
            return false;
        }
    }else{
        dig6 = p%10;
        p /= 10;
        dig5 = p%10;
        p /= 10;
        dig4 = p%10;
        p /= 10;
        dig3 = p%10;
        p /= 10;
        dig2 = p%10;
        p /= 10;
        dig1 = p%10;
        p /= 10;

        if(dig1 == dig6 && dig2 == dig5 && dig3 == dig4){
            return true;
        }else{
            return false;
        }
    }
}

int main(){

    int a,b, prod, largest=0;

    for(a=100; a<1000; a++){
        for(b=100; b<1000; b++){
            prod = a*b;
            if(isPalindrome(prod)){
                if(prod > largest){
                    largest = prod;
                }
            }
        }

    }

    cout << "\n The Largest palindrome made from the product of two 3-digit numbers is: " << largest <<"\n\n";

    system("pause");

    return 0;
}
