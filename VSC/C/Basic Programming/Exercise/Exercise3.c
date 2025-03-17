#include <stdio.h>

int main()
{
int num1[15], num2[5];

for (int i = 0; i < 5; i++)
{
    scanf("%d",&num2[i]);
}

for (int i = 0; i < 10; i++)
{
    scanf("%d", &num1[i]);

}

for (int i = 0; i < 10; i++)
{
    printf("%d\n",num1[i]);
}


int k=10;

for (int i = 0; i < 5; i++)
{
    num1[k] = num2[i];
    k++;
}

for (int i = 0; i < 15; i++)
{
    printf("changed num2 is%d\n",num1[i]);
}






    return 0;
}
