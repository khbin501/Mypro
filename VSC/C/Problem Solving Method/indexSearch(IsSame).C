

#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif

#include <stdio.h>

#include <string.h>

// PERSON ??? ??

struct PERSON
{

    char name[20];

    int age;

    char hobby[20];
};

// INDEX ??? ??

struct INDEX
{

    char key[20];

    int num;

    int array_indices[100];
};

int idx_length = 0; // ??? ??

// INDEX ?? ??: PERSON ???? ???? INDEX? ??

void create_index(struct PERSON *people, struct INDEX *index, int size)
{

    for (int i = 0; i < size; i++)
    {

        int found = 0;

        // ?? ???? key?? ??

        for (int j = 0; j < idx_length; j++)
        {

            if (strcmp(index[j].key, people[i].hobby) == 0)
            {

                index[j].array_indices[index[j].num] = i; // ?? ??

                index[j].num++; // ?? ?? ??

                found = 1;

                break;
            }
        }

        // ??? key? ?? INDEX? ??

        if (!found)
        {

            strcpy(index[idx_length].key, people[i].hobby);

            index[idx_length].array_indices[0] = i; // ?? ?? ??

            index[idx_length].num = 1; // ????? 1? ???

            idx_length++;
        }
    }
}

// INDEX ?? ??

void print_index(struct INDEX *index)
{

    printf("INDEX TABLE (based on Hobby):\n");

    printf("KEY\t\tNUM\tARRAY INDEX\n\n");

    for (int i = 0; i < idx_length; i++)
    {

        printf("%-10s\t%d\t(", index[i].key, index[i].num);

        for (int j = 0; j < index[i].num; j++)
        {

            if (j > 0)
                printf(", ");

            printf("%d", index[i].array_indices[j]);
        }

        printf(")\n");
    }

    printf("\n");
}

// ?? ??: key? ?? ?? INDEX?? ?? ??? ???? ?? ?? PERSON ?? ??

void search_index(struct INDEX *index, struct PERSON *people, char *search_key)
{

    int found = 0;

    for (int i = 0; i < idx_length; i++)
    {

        if (strcmp(index[i].key, search_key) == 0)
        {

            found = 1;

            printf("Found %s %d times:\n", index[i].key, index[i].num);

            // ??? ?? ??? ?? ?? ??

            for (int j = 0; j < index[i].num; j++)
            {

                int pos = index[i].array_indices[j];

                printf("Person at dataset index %d: (%s, %d, %s)\n", pos, people[pos].name, people[pos].age, people[pos].hobby);
            }

            break;
        }
    }

    if (!found)
    {

        printf("%s not found in the index.\n", search_key);
    }
}

int main()
{

    // PERSON ??? ?

    struct PERSON people[5] = {

        {"Kim", 39, "Tennis"},

        {"Ko", 15, "Soccer"},

        {"Lee", 17, "Soccer"},

        {"Choi", 21, "Tennis"},

        {"Park", 10, "Tennis"}

    };

    struct INDEX index[100]; // INDEX ???

    // INDEX ?? (hobby? ???? key ??)

    create_index(people, index, 5);

    // INDEX ??

    print_index(index);

    // ??? key ??

    char search_key[20] = "Tennis";

    // ?? ?? ?? (PERSON? ?? ?? ??)

    search_index(index, people, search_key);

    return 0;
}
