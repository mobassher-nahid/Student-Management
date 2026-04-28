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

void inputstudents(student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        inputstring("Enter Students Name : ", students[i].name, NAME_LEN);
        students[i].id=inputint("Enter ID :");
        students[i].grade=inputfloat("Enter Grade : ");
    }
}
void savestudenttxt(const char *filename, student *students, int n)
{
    FILE *fp=fopen(filename,"a");
    if(!fp)
    {
        printf("Can not open file!\n");
        return;
    }

    fprint("...............................................");
    fprint("           Student Details                     ");
    fprint("...............................................");

    for(int i=0;i<n;i++)
    {
        fprint(fp,"Name :%s\n,ID :%d\n,Grade :%.2f\n",students[i].name,students[i].id,students[i].grade);
    }
    fclose(fp);
}