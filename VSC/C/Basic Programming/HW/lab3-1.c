#include <stdio.h>

int main(void)
{

char line1[81], line2[81], i=0, k=0;

gets(line1);

gets(line2);

while (line1[i])
{
    i++;
}
while (line2[k])
{
    line1[i] = line2[k];
    k++;
    i++;
}

puts(line1);







    return 0;
}