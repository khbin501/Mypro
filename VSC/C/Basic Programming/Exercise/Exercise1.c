#include <stdio.h>

int main()
{
int grade[100]={};
int sum=0;
for (int i = 0; i < 100; i++)
{
    scanf("%d",&grade[i]);
}
int min = grade[0];

for (int k = 0; k < 100; k++)
{
    if (grade[k] <= min)
    {
        min = grade[k];
        
    }
    sum += grade[k];
   

}
 printf("%d %f",min, sum/100);


    return 0;
}
