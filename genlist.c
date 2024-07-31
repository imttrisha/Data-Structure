#include<stdio.h>
#include<stdlib.h>

struct Node {
    void *data;
    struct Node *next;
};

// function to add a new node in the
// beginning of the linked list.
void push_front(struct Node** head, void *x, size_t x_size){
	int i;
    
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data  = malloc(x_size);
    new_node->next = (*head);
        
    // here we are copying the data x to new node created
    for( i=0; i < x_size; i++){
        *(char *)(new_node->data + i) = *(char *)(x + i);
    }

    (*head) = new_node;
}

// function to print the linked list
void printIt(struct Node *node, void (*prt)(void *))
{
    while (node != NULL) {
        (*prt)(node->data);
        node = node->next;
    }
    printf("\n");
}

// function to print integer values
void prInt(void *x){
    printf(" %d", *(int *)x );
}

// function to print float values
void prFlt(void *x){
    printf(" %f", *(float *)x );
}

int main()
{
    struct Node *start = NULL;
    int i;
    // Create and print linked list storing int data
    unsigned int_size = sizeof(int);
    int a[] = {7, 42, 11, 41, 5};
    for (i=4; i>=0; i--)
       push_front(&start, &a[i], int_size);

    printIt(start, prInt);
 
    // Create and print linked list storing float data
    unsigned float_size = sizeof(float);
    start = NULL;
    float b[] = {1.1, 6.43, 4.2, 3.14, 5.08};
    for (i=4; i>=0; i--)
       push_front(&start, &b[i], float_size);

    printIt(start, prFlt);
 
    return 0;
}
