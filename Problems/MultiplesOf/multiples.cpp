#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int sum,n;

    cout << "\n SOMA DOS DIVISORES DE 3 OU 5 \n";
    cout << " Digite ate que numero vc deseja analisar: ";
    cin >> n;

    for(int i=n-1; i > 1; i--){
        if((i%3 == 0)||(i%5 == 0)){
            sum += i;
        }
    }

    cout << "\n\n Soma dos termos: " << sum << "\n";

    system("pause");
    return 0;
}
