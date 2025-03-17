#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif

#include <stdio.h>

#include <string.h>

#define MAX_EMPLOYEES 1000

// Define the struct for employees

struct
{

    char RRN[13]; // Unique identifier

    char name[20];

    float salary;

    float bonus; // Must be less than salary

} employee[MAX_EMPLOYEES];

// Function to check if RRN is unique

int is_unique_RRN(char RRN[])
{

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {

        if (strcmp(employee[i].RRN, RRN) == 0)
        {

            return 0; // Not unique
        }
    }

    return 1; // Unique
}

// Function to insert a new employee

int insert_employee(char RRN[], char name[], float salary, float bonus)
{

    // Check if RRN is unique

    if (!is_unique_RRN(RRN))
    {

        printf("Error: RRN '%s' is not unique.\n", RRN);

        return 0;
    }

    // Check if bonus is less than salary

    if (bonus >= salary)
    {

        printf("Error: Bonus must be less than salary.\n");

        return 0;
    }

    // Find the first empty slot in the employee array

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {

        if (employee[i].RRN[0] == '\0')
        { // Empty slot

            strcpy(employee[i].RRN, RRN);

            strcpy(employee[i].name, name);

            employee[i].salary = salary;

            employee[i].bonus = bonus;

            printf("Employee '%s' inserted successfully.\n", name);

            return 1;
        }
    }

    // If we reach here, the array is full

    printf("Error: No available slots to insert new employee.\n");

    return 0;
}

int main()
{

    // Test cases

    insert_employee("123456789012", "John Doe", 5000.0, 1000.0); // Successful insertion

    insert_employee("123456789012", "Jane Doe", 6000.0, 500.0); // Fails due to duplicate RRN

    insert_employee("987654321098", "Jane Smith", 6000.0, 7000.0); // Fails due to bonus >= salary

    insert_employee("987654321098", "James Bond", 7000.0, 1000.0); // Successful insertion

    return 0;
}