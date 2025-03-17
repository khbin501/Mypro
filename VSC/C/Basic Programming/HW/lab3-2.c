#include <stdio.h>

int main(void)
{

int a[10] = {}, temp, min, f=0, t;

for (int i = 0; i < 10; i++)
{
    scanf("%d", &a[i]);
}

for (int i = 0; i < 10; i++)
{
    min = a[i];
    
    for (int k=9; k>=i; k--)
    {
        if(min >= a[k])
        {
            min = a[k];
            t = k;
        }
    }
    
    temp = min;
    a[t] = a[f];
    a[f] = temp;
    f++;
}

for (int i = 0; i < 10; i++)
{
    printf("%d ", a[i]);
}



    
    return 0;
}