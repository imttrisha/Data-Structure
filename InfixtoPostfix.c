#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

struct node
{
  char data;
  struct node *next;
}*top=NULL;

void push (char ch)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = ch;
    if(top == NULL)
    {
     top = n;
     n->next = NULL;
    }
    else
    {
        n->next = top;
        top = n;
    }
}
char  pop()
{
    struct node *m;
    char x;
    if(top == NULL)
    {
        return 0;
    }
    else
    {
        m = top;
        top = top->next;
        x = m->data;
        free(m);
        m = NULL;
        return x;
    }
}
int precedence(char ch)
{
    if(ch =='*' || ch == '/' || ch == '%')
        return (4);
    else if (ch == '+' || ch == '-')
        return (3);
    else
        return 0;
}

void infixToPostfix(char infix[])
{
    char temp;
    char *token;
    token = strtok(infix," ");
    while( token != NULL )
    {
        if (isalnum(token[0]))
        {
          printf("%s ",token);
        }
        
        else if(token[0] == '(')
		{
            push(token[0]);
        }
        else if(token[0] ==  ')')
		{
            char temp;
            while((temp=pop()) != '(')
            {
                printf("%c ",temp);
            }
        }
		else
		{
            while(top != NULL && (precedence(top->data) >= precedence(token[0])))
            {
                printf("%c ",pop());
            }
            push(token[0]);
        }
        token = strtok(NULL," ");
    }

    while(top != NULL)
    {
        printf("%c ",pop());
    }
    return;
}
int main()
{
    char infix[100];
    fgets(infix, 100, stdin);
    infix[strlen(infix)-1] ='\0';
    infixToPostfix(infix);
    return 0;
}
