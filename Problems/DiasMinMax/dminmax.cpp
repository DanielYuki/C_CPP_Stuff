#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    int d, sumTime, minTime=0, maxTime=0, timeSpentMin=0, timeSpentMax=0, difTime=0;
    int hoursMax[31], hoursMin[31];
    cin >> d >> sumTime;

    for(int i=0; i < d; i++){
        //cout << "\n";
        cin >> minTime >> maxTime;

        hoursMax[i] = maxTime;
        hoursMin[i] = minTime;

        timeSpentMax += hoursMax[i];
        timeSpentMin += hoursMin[i];
    }

    if(timeSpentMax < sumTime || timeSpentMin > sumTime){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        for(int i=0; i<d ;i++){
            difTime = min(hoursMax[i], sumTime-timeSpentMin+hoursMin[i]);
            sumTime -= difTime;
            timeSpentMin -= hoursMin[i];

            cout << difTime << " ";

        }
    }

    return 0;
}
