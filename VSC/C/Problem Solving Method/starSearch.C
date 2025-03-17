

#include <stdio.h>

char string1[1000];
char string2[1000];
int p;

int strlen(char text[])
{
    int count = 0;

    while (text[count] != '\0')
    {
        count++;
    }
    return count;
}

void strStarCpy(char text[])
{
    int count = 0;
    int count2 = 0;
    while (text[count] != '*')
    {
        string1[count] = text[count];
        count++;
    }
    string1[count] = '\0';
    count++;

    while (text[count] != '\0')
    {
        string2[count2] = text[count];
        count++;
        count2++;
    }
    string2[count2] = '\0';
}

int strSearch(char fullText[], char searchingText[1000])
{

    int wordCount = 0;
    for (int i = 0; i < strlen(fullText); i++)
    {
        int o = 0;
        if (searchingText[0] == fullText[i])
        {
            int start = i;
            for (int k = 0; k < strlen(searchingText); k++)
            {
                if (searchingText[k] == fullText[start])
                {
                    o++;
                    start++;
                }
            }
            if (o == strlen(searchingText))
            {
                //    printf("match found\n");
                wordCount++;
                p = start;
                break;
            }
        }
    }
    if (wordCount <= 0)
    {
        // printf("match not found\n");
        return -1;
    }
    else
        return 1;
}

void strStarSearch(char fullText[], char searchingText[1000])
{
    strStarCpy(searchingText);
    if (strSearch(fullText, string1) == 1)
    {
        int first = p;
        if (strSearch(fullText, string2) == 1)
        {
            int second = p;
            if (first < second && second - first < 10)
                printf("match found");
            else
                printf("match not found");
        }
    }
    else
        printf("match not found");
}

int strCheck(char searchingText[])
{

    int count = 0;
    for (int i = 0; i < strlen(searchingText); i++)
    {

        if (searchingText[i] == '*')
        {
            count++;
        }
    }
    if (count >= 2)
    {
        printf("there are many \'*\' character\n");
        return 0;
    }

    if (strSearch(searchingText, "*") == -1)
    {
        printf("there is not \'*\' character\n");
        return 0;
    }

    if (searchingText[0] == '*')
    {
        printf("\'*\' character is in first array\n");
        return 0;
    }

    if (searchingText[strlen(searchingText) - 1] == '*')
    {
        printf("\'*\' character is in last array\n");
        return 0;
    }

    return 1;
}

int main()
{

    char fullText[] = "A thief named hong gil dong lived with friends named hong gildon and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gildong village.";
    char searchingText[1000];

    scanf(" %99s", searchingText);
    if (strCheck(searchingText) == 1)
    {
        strStarSearch(fullText, searchingText);
    }
    return 0;
}