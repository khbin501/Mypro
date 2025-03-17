#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif

#define DEBUG

#include <stdio.h>

#include <string.h>

#define MAXNUM 30

// struct for the person data

struct Person
{

    char name[20];

    int age;

    char hobby[20];
};

// struct for the age index

struct IndexAge
{

    int age;

    int num;

    int position[MAXNUM];
};

// struct for the hobby index

struct IndexHobby
{

    char hobby[20];

    int num;

    int position[MAXNUM];
};

// global variables

int idx_length_for_age = 0;

int idx_length_for_hobby = 0;

int n_persons = 0;

// function prototype

void init_struct(struct Person[], struct IndexAge[], struct IndexHobby[]);

void read_data(char[], struct Person[]);

void create_index_for_age_group(struct IndexAge[], struct Person[]);

void create_index_for_hobby_group(struct IndexHobby[], struct Person[]);

void write_age_group(char[], struct IndexAge[], struct Person[]);

void write_hobby_group(char[], struct IndexHobby[], struct Person[]);

int main()
{

    // declaration

    struct Person person[MAXNUM];

    struct IndexAge index_age[MAXNUM];

    struct IndexHobby index_hobby[MAXNUM];

    // filenames

    char in_file[] = "personal.txt";

    char out_file_age[] = "age.txt";

    char out_file_hobby[] = "hobby.txt";

    init_struct(person, index_age, index_hobby);

#ifdef DEBUG

    printf("\ninit_struct is done.\n");

#endif // DEBUG

    read_data(in_file, person); // read data

    create_index_for_age_group(index_age, person); // create index for the age group

#ifdef DEBUG

    printf("\ncreate_index_for_age_group is done.\n");

#endif // DEBUG

    create_index_for_hobby_group(index_hobby, person); // create index for the hobby group

#ifdef DEBUG

    printf("\ncreate_index_for_hobby_group is done.\n");

#endif // DEBUG

    write_age_group(out_file_age, index_age, person); // write age.txt

#ifdef DEBUG

    printf("\nwrite_age_group is done.\n");

#endif // DEBUG

    write_hobby_group(out_file_hobby, index_hobby, person); // write hobby.txt

#ifdef DEBUG

    printf("\nwrite_hobby_group is done.\n");

#endif // DEBUG

    return 0;
}

void init_struct(struct Person per[], struct IndexAge idx_age[], struct IndexHobby idx_hobby[])
{

    for (int i = 0; i < MAXNUM; i++)
    {

        // person

        per[i].name[0] = '\0';

        per[i].age = -1;

        per[i].hobby[0] = '\0';

        // idx_age

        idx_age[i].age = -1;

        idx_age[i].num = 0;

        idx_age[i].position[0] = -1;

        // idx_hobby

        idx_hobby[i].hobby[0] = '\0';

        idx_hobby[i].num = 0;

        idx_hobby[i].position[0] = -1;
    }
}

void read_data(char filename[], struct Person per[])

{

    FILE *in_file = NULL;

    in_file = fopen(filename, "r");

    if (in_file == NULL)
    {

        printf("\nInput File Could Not Be Opened.\n");

        return;
    }

    while (fscanf(in_file, "%s %d %s", per[n_persons].name, &per[n_persons].age, per[n_persons].hobby) == 3)

    {

#ifdef DEBUG

        printf("% s % d % s\n", per[n_persons].name, per[n_persons].age, per[n_persons].hobby);

#endif

        n_persons++;
    }

    if (in_file != NULL)
    {

        fclose(in_file);

        in_file = NULL;

#ifdef DEBUG

        printf("\nInput File for Person Has Been Closed.\n");

#endif // DEBUG
    }
}

void create_index_for_age_group(struct IndexAge idx[], struct Person per[])

{

    for (int i = 0; i < n_persons; i++)

    {

        // searching

        int searching = 1;

        for (int j = 0; j < idx_length_for_age; j++)
        {

            if (idx[j].age == per[i].age)
            {

                idx[j].position[idx[j].num] = i;

                idx[j].num++;

                searching = 0;
            }
        }

        if (searching)

        {

            idx[idx_length_for_age].age = per[i].age;

            idx[idx_length_for_age].position[idx[idx_length_for_age].num] = i;

            idx[idx_length_for_age].num++;

            idx_length_for_age++;
        }
    }
}

void create_index_for_hobby_group(struct IndexHobby idx[], struct Person per[])

{

    for (int i = 0; i < n_persons; i++)

    {

        // searching

        int searching = 1;

        for (int j = 0; j < idx_length_for_hobby; j++)
        {

            if (strcmp(idx[j].hobby, per[i].hobby) == 0)
            {

                idx[j].position[idx[j].num] = i;

                idx[j].num++;

                searching = 0;
            }
        }

        if (searching)

        {

            strcpy(idx[idx_length_for_hobby].hobby, per[i].hobby);

            idx[idx_length_for_hobby].position[idx[idx_length_for_hobby].num] = i;

            idx[idx_length_for_hobby].num++;

            idx_length_for_hobby++;
        }
    }
}

void write_age_group(char filename[], struct IndexAge idx[], struct Person per[])

{

    FILE *out_file = NULL;

    out_file = fopen(filename, "w");

    if (out_file == NULL)

    {

        printf("\nError age: Output FileCould Not Be Opened.\n");

        return;
    }

    else

    {

        for (int i = 0; i < idx_length_for_age; i++)

        {

            for (int j = 0; j < idx[i].num; j++)

            {

                int position = idx[i].position[j];

                fprintf(out_file, "%s %d %s\n", per[position].name, per[position].age, per[position].hobby);
            }
        }
    }

    if (out_file != NULL)
    {

        fclose(out_file);

        out_file = NULL;

#ifdef DEBUG

        printf("\nOutput File for IndexAge Has Been Closed.\n");

#endif // DEBUG
    }
}

void write_hobby_group(char filename[], struct IndexHobby idx[], struct Person per[])

{

    FILE *out_file = NULL;

    out_file = fopen(filename, "w");

    if (out_file == NULL)

    {

        printf("\nError hobby: Output FileCould Not Be Opened.\n");

        return;
    }

    else

    {

        for (int i = 0; i < idx_length_for_hobby; i++)

        {

            for (int j = 0; j < idx[i].num; j++)

            {

                int position = idx[i].position[j];

                fprintf(out_file, "%s %d %s\n", per[position].name, per[position].age, per[position].hobby);
            }
        }
    }

    if (out_file != NULL)
    {

        fclose(out_file);

        out_file = NULL;

#ifdef DEBUG

        printf("\nOutput File for IdexAge Has Been Closed.\n");

#endif // DEBUG
    }
}