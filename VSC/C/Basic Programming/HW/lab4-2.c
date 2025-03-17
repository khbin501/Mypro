#include <stdio.h>

int myatoi(char *str)
{
    int num = 0, i=1, ne;

    if(str[0] == '+')
    {
        while (1)
        {
            if(str[i] <= '9' && str[i] >= '0')
            {
                num = (num*10) + (str[i] - '0');
            }

            else if(str[i] == '\0')
            {
                break;
            }
            i++;
        }
        return num;
    }
        else if(str[0] == '-')
        {
            while (1)
        {
            if(str[i] <= '9' && str[i] >= '0')
            {
                num = (num*10) + (str[i] - '0');
            }

            else if(str[i] == '\0')
            {
                break;
            }
                i++;
        }
        ne = -num;
        return ne;
        }
}

int main(void)
{

char str[100];
int N;
scanf("%s", &str);

printf("%d", myatoi(str));


    return 0;
}
