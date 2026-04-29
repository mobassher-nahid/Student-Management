#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LEN 50

typedef struct 
{
    char name[NAME_LEN];
    int id;
    float grade;
} student;

student* allocatestudent(int n);
void savestudenttxt(const char *filename, student *students ,int n);
void inputstudents(student* students,int n);
int isduplicate(student *students ,int count ,int id);
void clearscreen(void);


#endif