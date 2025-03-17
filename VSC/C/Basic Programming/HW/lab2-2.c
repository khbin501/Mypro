#include <stdio.h>

int main() {

int N,num1,num2,num3,num4,num5;
    scanf("%d", &N);

    num1 = N/10000;
    num2 = (N/1000)%10;
    num3 = (N/100)%10;
    num4 = (N/10)%10;
    num5 = N%10;



    printf("%d %d %d %d %d", num1, num2, num3, num4, num5);
    
    
    
    










    
    return 0;
}