#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    int j=0;

    cout << "\n The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is... \n";
    cout << " (Yes, Its Gonna take a while(about 30sec)... )\n\n\n";
    //I already know that 100000 < i < 1000000000
    for(int i = 100000; i < 1000000000; i++){
        for(int k=1; k <= 20; k++){
            if(i%k == 0){
                j++;
            }
            if(j == 20){
                cout << i;
                return 0;
            }
        }
        j=0;
    }

    system("pause");
    return 0;
}
