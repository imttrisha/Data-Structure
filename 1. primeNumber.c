#include<stdio.h>
int isPrime(int number)
{
  int i;
  int count=0;

  for(i=2; i<=number/2; i++)
  {
     if(number%i == 0)
     {
       count=1;
       break;
     }
  }

  if(number==1) 
  count=1;

  return count;
}

int main()
{
  int number ;
  scanf("%d",&number);
  if(number<=1)
  {
  	 printf("-1");
  }
  else
  {
  if(isPrime(number) == 0)
  printf("1");
  else
  printf("0");
  }
  return 0;
}
