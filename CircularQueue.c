#include <stdio.h>
#include <stdlib.h>
struct circularQueue
{
	int capacity;
	int front;
	int rear;
	int * array;
};
int isEmpty(struct circularQueue *cq)
{
	if(cq->rear==-1 && cq->front==-1)
		return 1;
	else
		return 0;
}
int isFull(struct circularQueue *cq)
{
	if((cq->rear+1)%(cq->capacity)==cq->front)
		return 1;
	else
		return 0;
}
struct circularQueue* createQueue(int cap)
{
	struct circularQueue * temp;
	temp=(struct circularQueue*)malloc(sizeof(struct circularQueue));
	temp->capacity=cap;
	temp->front=-1;
	temp->rear=-1;
	temp->array=(int*)malloc(sizeof(int)*temp->capacity);
	return temp;
}

int cqSize(struct circularQueue *cq)
{
	if(cq->front==-1 && cq->rear==-1)
		return 0;
	else
	{
		if(isFull(cq))
		return(cq->capacity);
		else
		return(((cq->capacity)-(cq->front)+(cq->rear)+1)%(cq->capacity));
	}
}
void getFront(struct circularQueue *cq)
{
	if(isEmpty(cq))
	{
		printf("QE ");
	}
	else
	{
		int index=cq->front;
		printf("%d ",cq->array[index]);
	}
}
void doubleQueueCapacity(struct circularQueue *cq)
{
	int size=cqSize(cq),i;
	int *temp=(int*)malloc(sizeof(int)*((cq->capacity)*2));
	int index=cq->front;
	for(i=0;size--;i++)
	{
		temp[i]=cq->array[index];
		index=(index+1)%(cq->capacity);
	}
	free(cq->array);
	cq->capacity=(cq->capacity)*2;
	cq->array=temp;
	cq->front=0;
	cq->rear=i-1;
}

void enqueue(struct circularQueue *cq)
{
	if(isFull(cq))
	{
		printf("QF QSD ");
		doubleQueueCapacity(cq);
	}
	int value;
	scanf("%d",&value);
	cq->rear=(cq->rear+1)%(cq->capacity);
	if(cq->front==-1)
		cq->front++;
	cq->array[cq->rear]=value;
}
void dequeue(struct circularQueue *cq)
{
	if(isEmpty(cq))
	{
		printf("QE ");
	}
	else
	{
		int value=cq->array[cq->front];
		if(cq->front==cq->rear)
		{
			cq->front=-1;
			cq->rear=-1;
		}
		else
		{
			cq->front=((cq->front)+1)%(cq->capacity);
		}
		printf("%d ",value);
	}
}
int menu()
{
	int choice;
	scanf("%d ",&choice);
	return choice;
}

int main()
{
	struct circularQueue *cq=NULL;
	cq=createQueue(4);
	while(1)
	{
		switch(menu()){
			case 1:
				enqueue(cq);
				break;
			case 2:
				dequeue(cq);
				break;
			
			case 3:
				getFront(cq);
				break;
				
			case -1:
				exit(0);
			
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
