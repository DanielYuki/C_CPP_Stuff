#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    cout << " LONGEST REPETITION IN AN DNA SEQUENCE \n\n";
    char dna[] = "TCTGCGCAATGCCTATCGTAGGTAGATTGACGTATGTAGCATAGGTCAAAAATTTTATGCAAATATAGTGCGTAGACAGAATACAAACATACCGGGGTTCTATACGCACCTGCCTATCGTAGGTAGATTGACGTATGTAGCATAGGTCAATTTTATGCAAATATAGTGCGTAGACAGAATACAAACATACCGGGGTTCTATACGCACCACATGACGTCATCAATCTACCCGCCTCGTATGTACTCGTCACGTAACAGAGGTGCAAATTACCGCTCGTACAACATGACGTCATCAATCTACCCGCCTCGTATGTACTCGTCACGTAACAGAGGTGCAAATTACCGCTCGTACATCTATAGTGATTACCCATCTCTCATGTACTCAAGTGCTCGAC";
    char lngstChar[0];
    int dnaSize, longest=0, counter=1;
    for(int i=0; dna[i]!= '\0'; i++){
        dnaSize++;
    }

    for(int i=0; i < dnaSize-1; i++){
        if(dna[i] == dna[i+1]){
            counter++;
        }else{
            counter=1;
        }

        if(counter > longest){
            longest = counter;
            lngstChar[0] = dna[i];
        }
    }

    cout << " The longest repetition is " << lngstChar[0] <<" with " << longest << " occurrences \n\n";
    return 0;
}
