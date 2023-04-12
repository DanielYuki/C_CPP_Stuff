#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    long int nth, sum, numDiv=1, highestNumDiv=0;

    cin >> nth;

    for(int i=1;i<=nth;i++){
        sum += i;

        for(int j=1;j<=sum/2;j++){
            if(sum%j == 0){
                numDiv++;
            }
        }

        if(numDiv > highestNumDiv){
            highestNumDiv = numDiv;
            if(numDiv >= 500){
                cout << numDiv << "a "<< sum;
                return 0;
            }
            cout << sum << " ";
        }


        numDiv = 1;
        //cout << sum;
    }

    cout << highestNumDiv;

    return 0;
}
