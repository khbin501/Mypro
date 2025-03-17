#include <stdio.h>

int main()
{


int num[5];

for (int i = 0; i < 5; i++)
{
    scanf("%d",&num[i]);
}


for (int i = 0; i < 5; i++)
{
    for (int k = 0; k < num[i]; k++)
    {
        printf("*");
    }
    printf("\n");
}







    return 0;
}
