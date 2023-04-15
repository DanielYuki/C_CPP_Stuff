#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int r1, x1, y1, r2, x2, y2;
    float distO;

    //raio e plano cartesiano
    cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2;

    distO = sqrt( pow(x1-x2,2)+pow(y1-y2,2) );

    if(r1 > r2 && (distO + r2 <= r1) && (distO < r1)){
        cout << "NICE";
    }else{
        cout << "DED";
    }

    return 0;
}
