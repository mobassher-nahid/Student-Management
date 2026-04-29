#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include<stdlib.h>

void clearbuffer(void);
int inputint(const char* prompt);
float inputfloat(const char* prompt);
void inputstring(const char* prompt,char *data,size_t size);

#endif