#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif

#define DEBUG

#include <stdio.h>

#include <string.h>

#define MAXNUM 30

// struct for the person data

struct PERSON
{

    char name[20];

    int age;

    char hobby[20];
};

// function prototype

void init_struct(struct PERSON[]);

void read_data(char[], struct PERSON[], int *);

void sort_by_age(struct PERSON[], int);

void sort_by_hobby(struct PERSON[], int);

void write_results(char[], struct PERSON[], int);

int main()
{

    // declaration

    int n_persons = 0;

    struct PERSON person[MAXNUM];

    // filenames

    char in_file[] = "personal.txt";

    char out_file_age[] = "age.txt";

    char out_file_hobby[] = "hobby.txt";

    init_struct(person);

#ifdef DEBUG

    printf("\ninit_struct is done.\n");

#endif // DEBUG

    read_data(in_file, person, &n_persons); // read data

#ifdef DEBUG

    printf("\nread_data is done.\n");

#endif // DEBUG

    sort_by_age(person, n_persons); // age group

#ifdef DEBUG

    printf("\nsort_by_age is done.\n");

#endif // DEBUG

    write_results(out_file_age, person, n_persons); // write age.txt

#ifdef DEBUG

    printf("\nwrite_results for the age group is done.\n");

#endif // DEBUG

    sort_by_hobby(person, n_persons); // hobby group

#ifdef DEBUG

    printf("\nsort_by_hobby is done.\n");

#endif // DEBUG

    write_results(out_file_hobby, person, n_persons); // write hobby.txt

#ifdef DEBUG

    printf("\nwrite_results for the hoddy group is done.\n");

#endif // DEBUG

    return 0;
}

void init_struct(struct PERSON per[])
{

    for (int i = 0; i < MAXNUM; i++)
    {

        // person

        per[i].name[0] = '\0';

        per[i].age = -1;

        per[i].hobby[0] = '\0';
    }
}

void read_data(char filename[], struct PERSON per[], int *n_persons)
{

    int n = 0;

    FILE *in_file = NULL;

    in_file = fopen(filename, "r");

    if (in_file == NULL)
    {

        printf("\nInput File Could Not Be Opened.\n");

        return;
    }

    while (fscanf(in_file, "%s %d %s", per[n].name, &per[n].age, per[n].hobby) == 3)
    {

#ifdef DEBUG

        printf("% s % d % s\n", per[n].name, per[n].age, per[n].hobby);

#endif

        n++;
    }

    *n_persons = n;

    if (in_file != NULL)
    {

        fclose(in_file);

        in_file = NULL;

#ifdef DEBUG

        printf("\nInput File for Person Has Been Closed.\n");

#endif // DEBUG
    }
}

void swap(struct PERSON *a, struct PERSON *b)
{

    struct PERSON tmp = *a;

    *a = *b;

    *b = tmp;
}

// bubble sort

void sort_by_age(struct PERSON per[], int n)
{

    for (int i = 0; i < n - 1; i++)

        for (int j = 0; j < n - i - 1; j++)

            if (per[j].age > per[j + 1].age)

                swap(&per[j], &per[j + 1]);
}

// bubble sort

// https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/

void sort_by_hobby(struct PERSON per[], int n)
{

    for (int i = 0; i < n - 1; i++)

        for (int j = 0; j < n - i - 1; j++)

            if (strcmp(per[j].hobby, per[j + 1].hobby) > 0)

                swap(&per[j], &per[j + 1]);
}

void write_results(char filename[], struct PERSON per[], int n)
{

    FILE *out_file = NULL;

    out_file = fopen(filename, "w");

    if (out_file == NULL)
    {

        printf("\nError age: Output FileCould Not Be Opened.\n");

        return;
    }

    for (int i = 0; i < n; i++)

        fprintf(out_file, "%s %d %s\n", per[i].name, per[i].age, per[i].hobby);

    if (out_file != NULL)
    {

        fclose(out_file);

        out_file = NULL;

#ifdef DEBUG

        printf("\nOutput File Has Been Closed.\n");

#endif // DEBUG
    }
}