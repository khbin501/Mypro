#include <stdio.h>

void strcopy(char str1[], char str2[])
{

    int i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

int main()
{

    char string1[20];
    char string2[20] = "I want to go home";

    strcopy(string1, string2);

    puts(string1);

    return 0;
}