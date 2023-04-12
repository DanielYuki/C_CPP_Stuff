#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    cout << " WEIRD ALGORITHM \n";
    cout << "\n Digit a number to go through this weird algorithm: ";
    int n,m, counter=0, maxIteration=0;

    cin >> n;
    cout << "\n " << n;

    m=n;

    for(int i=0; i < n; i++){
        while(m != 1){
            if(m%2==0){
                m /= 2;
            }else{
                m = ((m*3) + 1);
            }

            counter++;
            cout << " -> " << m;
        }

        if(counter > maxIteration){
            maxIteration = counter;
        }

        counter = 0;
    }

    cout << "\n The number of iterations is " << maxIteration << "\n\n";

    system("pause");
    return 0;
}

