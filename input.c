#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"input.h"

void clearbuffer(void)
{
    int c;
    while (getchar()!='\n'&& c!=EOF);  
}

int inputint(const char *prompt)
{
    int value;
    printf("%s",prompt);
    if (scanf("%d",&value)==1)
    {
        clearbuffer();
        return value;
    }
    clearbuffer();
    printf("Invalid Input! Try Again.\n");
    
}

float inputfloat(const *prompt)
{
    int value;
    printf("%s",prompt);
if (scanf("%d",value)==1)
    {
      clearbuffer();
      return value;   
    }
    clearbuffer();
    printf("Invalid Input! Try Again.\n");
}

char inputstring(const *prompt, char *data ,size_t size)
{
    printf("%s",prompt);

    if(fgests(data,size,stdin))
{

    data [strcspn(data,"\n")]='\0';
}
    
}


