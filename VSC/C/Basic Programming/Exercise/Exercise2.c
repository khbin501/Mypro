#include <stdio.h>

int main()
{
int num1[5], num2[5];

for (int i = 0; i < 5; i++)
{
    scanf("%d",&num2[i]);
}

for (int k = 0; k < 5; k++)
{
    num1[k] = num2[k];
    
}

for (int l = 0; l < 5; l++)
{
printf("%d\n", num1[l]);
    
}

for (int l = 0; l < 5; l++)
{
printf("%d", num2[l]);
    
}

    return 0;
}
