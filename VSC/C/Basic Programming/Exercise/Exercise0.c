#include <stdio.h>

int main(void)
{
float grade=0, sum_s, sum_d=0;
for (int i = 0; i < 5; i++)
{
    sum_s=0;
    for (int k = 0; k < 3; k++)
    {
        scanf("%f",&grade);
        sum_s = sum_s + grade;
    }
    printf("one's average is %f\n", sum_s/3);
    sum_d = sum_d + sum_s; 
}
printf("dapartment's average is %f\n",sum_d/15);

return 0;
}