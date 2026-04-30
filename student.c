#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "input.h"

student *allocatestudent(int n)
{
    student *students = (student *)malloc(n * sizeof(student));

    if (!students)
    {
        printf("Memorry allocation failed!");
        return NULL;
    }
    return students;
}


int isduplicate(student *students, int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            return 1;
        }
    }
    return 0;
}



void inputstudents(student *students, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("student - %d\n", i + 1);
        inputstring("Enter Students Name : ", students[i].name, NAME_LEN);

        while (1)
        {
            students[i].id = inputint("Enter ID :");
            if (isduplicate(students, i, students[i].id))
            {
                printf("ID -%d already exist! Try again.\n", students[i].id);
            }
            else

            {
                break;
            }
        }

        students[i].grade = inputfloat("Enter Grade : ");
    }
}


void savestudenttxt(const char *filename, student *students, int n)
{
    FILE *fp = fopen(filename, "a");
    if (!fp)
    {
        printf("Can not open file!\n");
        return;
    }

    fprintf(fp, "\n...............................................\n");
    fprintf(fp, "             Student Details                     \n");
    fprintf(fp, "\n...............................................\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "Name : %s\n ID : %d\nGrade : %.2f\n",
                students[i].name,
                students[i].id,
                students[i].grade);
    }
    fclose(fp);
}

void displaydata(student *students, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Name :%s\nID :%d\nGrade :%.2f\n",
        students[i].name,
        students[i].id,
        students[i].grade);
    }
}

void clearscreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}