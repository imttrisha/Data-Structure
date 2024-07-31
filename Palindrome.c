#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char data;
	struct Node *link;
};
struct Node* getNode()
{
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	return n;
}
typedef struct Node *ptr;
void push(ptr *q, char x)
{
	ptr a = *q;
	*q = getNode();
	(*q)->data = x;
	(*q)->link = a;
}
char popStack(ptr *s)
{
	ptr a = *s;
	char value = 0;
	if(a == NULL)
	{
		return value;
	}
	else
	{
		value = a -> data;
		*s = a -> link;
		return value;
	}
}

char popQueue(ptr *q)
{
	ptr a = *q;
	char value = 0;
	if(a == NULL)
		{
			return value;
		}
	else if(a -> link == NULL)
		{
			value = a->data;
			*q = NULL;
			return value;
		}
	else
		{
			while((a->link)->link != NULL)
				{
					a = a->link;
				}
			value = (a->link) -> data;
			a->link = NULL;
			free(a->link);
			return value;
		}
}
int main()
{
	int i=0;
	char a, b;
	char str[32];
	ptr Queue;
	ptr Stack;
	Queue = 0;
	Stack = 0;
	scanf("%s",str);
    while((b = str[i]) != '\0')
		{
			push(&Queue, b);
			push(&Stack, b);
			i++;
		}
	i = 1;
	a = 1; 
	b = 1;
	while(b != 0 && a != 0 && i == 1)
		{
			b = popStack(&Stack);
			a = popQueue(&Queue);
	    	if(b != a)
			{
		    	i = 0;
		    }
	
		}
	if(i == 1)
	{
	  printf("1");
    }
	else
	{
	  printf("0");
    }
return 0;
}

