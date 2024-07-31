#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Size 100

struct stack
{
	int size;
	int top;
	int * array;
};
int isEmpty(struct stack * s)
{
	return s->top == -1 ;
}
int pop(struct stack * s)
{
	return s->array[s->top--];
}
void push(struct stack* s,int item)
{
	s->array[++s->top] = item;
}
struct stack* createStack( int size )
{
	struct stack * s = (struct stack*) malloc(sizeof(struct stack));
	s->top = -1;
	s->size = 4;
	s->array = (int*) malloc(s->size * sizeof(int));
	return s;
}
int getTop(struct stack * s)
{
	return s->array[s->top];
}
void doubleStack(struct stack * s)
{
	int i;
	char p[Size];
	s->size=2;
	for(i=0; i<s->top; i++)
	 {
		p[i] = s->array[i];
	 }
	s=(struct stack*)malloc(s->size*sizeof(struct stack));
	for(i=0; i<s->top; i++)
	 {
		s->array[i]=p[i];
	 }
}
int evaluatePostfix(char * exp)
{
	struct stack * s = createStack(strlen(exp));
	int i=0;
	for (i = 0; i<strlen(exp)-1; ++i)
   	 {
		if(exp[i]==' ')
		 continue;
        else if (isdigit(exp[i]))
		{
		    int num=0;
	    	while(isdigit(exp[i]))
			{
		    	num=num*10 + (int)(exp[i]-'0');
				i++;
			}
			i--;
			push(s,num);
	    }
	   	else
	    {
			int val1 = pop(s);
			int val2 = pop(s);

			switch (exp[i])
			{
			case '+': push(s, val2 + val1);
			break;
			
			case '-': push(s, val2 - val1);
			break;
			
			case '*': push(s, val2 * val1);
			break;
			
			case '/': if(val1==0)
			         {
			        	printf("DIVBYZERO");
			        	exit(0);
         	         }
			          push(s,val2/val1);
			break;
            }
		 }
	 }
	return getTop(s);
    if(s->top==s->size-1)
	{
		doubleStack(s);
   	}
}
int main()
{
	struct stack s;
	char*exp=(char*)malloc(sizeof(char)*Size);
    fgets(exp , Size , stdin);
	printf ("%d", evaluatePostfix(exp));
	return 0;
}
     
     
