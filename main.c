#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "student.h"

int main()
{
    int choice;
    int n = 0;
    student *students = NULL;

    do
    {
        clearscreen();
        
        printf("========STUDENT MANAGEMENT======\n");
        printf("1.Enter students\n");
        printf("2.Save student data\n");
        printf("3.Exit\n");
        choice = inputint("Enter....");

        switch (choice)
        {
        case 1:
            if (students != NULL)
            {
                free(students);
                students = NULL;
            }

            n = inputint("Number of students : ");

            if (n <= 0)
            {
                printf("Invalid input!");
                n = 0;
                break;
            }

            students = allocatestudent(n);
            {
                if (!students)
                {
                    printf("Memory allocation failed!");
                    n = 0;
                    break;
                }

                inputstudents(students, n);
                break;
            }

        case 2:
            if (!students || n == 0)
            {
                printf("No Students Data To Save! Input Students Data first.\n");
                break;
            }

            savestudenttxt("student.txt", students, n);
            printf("Saved data successfully\n");
            break;
            
            
case 3:
                printf("Exiting program. Goodbye!\n");
                break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    }
    while (choice != 3);
    {
        if (students)
        {
            free(students);
        }
    }
    return 0;
}
