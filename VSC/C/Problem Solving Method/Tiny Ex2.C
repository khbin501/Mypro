#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int bar = 0;
    int bell = 0;
    int lemon = 0;
    int cherry = 0;

    int slot[3];

    for (int i = 0; i < 3; i++)
    {
        slot[i] = rand() % 4;
    }

    for (int i = 0; i < 3; i++)
    {
        if(slot[i] == 0)
        {
            bar++;
            printf("%d slot is bar", i+1);
        }
        else if(slot[i] == 1)
        {
            bell++;
            printf("%d slot is bell", i+1);
        }
        else if(slot[i] == 2)
        {
            lemon++;
            printf("%d slot is lemon", i+1);
        }
        else if(slot[i] == 3)
        {
            cherry++;
            printf("%d slot is cherry", i+1);
        }
        printf("\n");
    }


    printf("paid out : ");
    if(cherry == 3)
    {
        printf("JACKPOT\n");
    }
    else if(cherry == 1)
    {
        printf("One Dime");
    }
    else if(lemon == 3 || bar == 3 || bell == 3 )
    printf("One Nikel");
    else printf("Fail");
}