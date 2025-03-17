#include <stdio.h>

int case1(char c)
{
    if(c >= 65 && c<= 90)
    return 1;
    else if(c >= 97 && c <= 122)
    return 0;
}

    
int main(void)
{
char input;

for(int i=0; i<3; i++)
{
    printf("Enter the character : ");
    scanf(" %c", &input);

    if(case1(input) == 1)
    {
        printf("%c is in uppercase\n", input);
        continue;
    }

    else
    {
        printf("%c is in lowercase\n", input);
        continue;
    }
}


    return 0;
}
