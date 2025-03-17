#include <stdio.h>

int main()
{

    int second, min = 0, hour = 0;

    printf("Please type seconds ");
        scanf("%d", &second);

    min = second / 60;
    hour = min / 60;
    second = second % 60;

    printf("%d:%d:%d [hours : minutes : seconds", hour, min, second);

    return 0;
}