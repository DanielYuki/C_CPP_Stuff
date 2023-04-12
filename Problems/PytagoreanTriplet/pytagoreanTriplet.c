#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c;

    for(a = 1; a < 1000; a++){
        for(b = 1; b < 1000; b++){
            c = sqrt((pow(a,2) + pow(b,2)));
            if(a < b){
                if( (a + b + c) == 1000){
                    printf("a x b x c = %.0f",a*b*c);
                    printf("\n\n a=%.0f b=%.0f c=%.0f \n\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
