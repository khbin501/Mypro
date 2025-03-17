#include <stdio.h>

int max(int a[], int num){
    int max = -1;
    for (int i = 0; i < num; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }

    }
    return max;
}

int min(int a[], int num){
    int min = 10000;
    for (int i = 0; i < num; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}

void scan (int MxMn[],int num,int mx, int count[]){

    for (int i = 0; i < num; i++)
    {
        if(MxMn[i] == mx){
            count[i] = i;  
        }
        else count[i] = -1;
    }
}


int main(){

int age[5] = {2, -1, 3, 2, 1};
int grade[5] = {11, 30, 30, 11, 3};

for (int i = 0; i < 5; i++)
{
    if(age[i] < 0 || grade[i] < 0)
    {
        printf("there's positive integer\n");
        return 0;
    }    
}



int maxAge = max(age,5);
int minAge = min(age,5);

int maxGrage = max(grade,5);
int minGrage = min(grade,5);

int ageMaxCount[5] = {};
scan(age, 5, maxAge, ageMaxCount);

int ageMinCount[5] = {};
scan(age, 5, minAge, ageMinCount);

int gradeMaxCount[5] = {};
scan(grade, 5, maxGrage, gradeMaxCount);

int gradeMinCount[5] = {};
scan(grade, 5, minGrage, gradeMinCount);

    printf("the scores of the oldest students : ");

for (int i = 0; i < 5; i++)
{
    if(ageMaxCount[i] != -1)
    printf("%d " , grade[ageMaxCount[i]]);
}
    printf("\n");

    printf("the scores of the youngest students : ");

for (int i = 0; i < 5; i++)
{
    if(ageMinCount[i] != -1)
    printf("%d " , grade[ageMinCount[i]]);
}
    printf("\n");

    
    printf("the ages of the highest score students : ");

for (int i = 0; i < 5; i++)
{
    if(gradeMaxCount[i] != -1)
    printf("%d " ,age[gradeMaxCount[i]]);
}
    printf("\n");


    printf("the ages of the lowest score students : ");

for (int i = 0; i < 5; i++)
{
    if(gradeMinCount[i] != -1)
    printf("%d " ,age[gradeMinCount[i]]);
}




    return 0;
}