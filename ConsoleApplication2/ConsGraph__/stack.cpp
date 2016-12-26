#include "stdafx.h"
#include "stack.h"

#define STACK_LENGTH 128  
#define INT_MIN 0

struct stack {
	int top;

	int buf[STACK_LENGTH];
};

struct stack S;

int stack_empty(void)
{
	return S.top == 0;
}

int stack_full(void)
{
	return S.top == STACK_LENGTH;
}

int pop(void)
{
	if (stack_empty()) {
		printf("Stack underflow!\n");
		return INT_MIN;
	}

	return S.buf[--S.top];
}

/*int gettop(void)
{
if (stack_empty()) {
printf("Stack underflow!\n");
return INT_MIN;
}

return S.buf[S.top - 1];
}*/

void push(int x)
{
	if (stack_full()) {
		printf("Stack overflow!\n");
		return;
	}

	S.buf[S.top++] = x;
}