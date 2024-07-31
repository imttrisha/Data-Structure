#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
	int count= 0, i;
	for(i= 1; i<= n; i++)
	{
		if(n%i== 0)
		count++;
	}
	if(count== 2)
	 return 1;
	else
	 return 0;
}
int circularPrime(int n)
{
	int count= 0, temp, num, rem, d;
	temp= n;
	while(temp)
	{
		count++;
		temp= temp/10;
	}
	num=n;
	
	while(isPrime(num))
	{
		rem= num%10;
		d= num/10;
		num= (pow(10, count-1))*rem+d;
		if(num== n)
		return 1;
	}
   return 0;
}
int main()
{
	int i;
	printf("enter the number: ");
	scanf("%d",&i);
	if(i<= 0)
	printf("-1");
    else if(circularPrime(i))
	{
		printf("1");
	}
	else
	printf("0");
  return 0;
}
