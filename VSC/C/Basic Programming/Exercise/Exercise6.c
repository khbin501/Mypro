#include <stdio.h>

int main()
{


int num1[10] = {10, 31, 7, 3, 17};

    for (int i = 4; i >0; i--)
    {
        num1[i+1] = num1[i];
    }
    
    num1[1]=41;

for (int i = 0; i < 6; i++)
{
    printf("%d\n",num1[i]);
}






    return 0;
}
