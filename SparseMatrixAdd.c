#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int row, col;
    int data;
    struct Node * next;
};
struct List
{
    struct Node * head;
    struct Node * tail;
    int size;
};
typedef struct Node node;
typedef struct List list;
node * createNode(int row, int col, int data)
{
    node * n = (node *) malloc(sizeof(node));
    n->row = row;
    n->col = col;
    n->data = data;
    n->next = NULL;
    return n; 
}
list * createList()
{
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}
int isEmpty(list * l)
{
    if(l->head == NULL)
        return 1; 
    else
        return 0;
}
void addition(list * l, int row, int col, int data)
{
    node * n = createNode(row, col, data);
    
    if(l->head == NULL)
    {
        l->head = n;
        l->tail = n;
        l->size = (l->size) + 1;
    }
    else
    {
        l->tail->next = n;
        l->tail = l->tail->next;
        l->size = (l->size) + 1;
    }
}
void displayAddition(list * C, int m, int n)
{
    node * temp;
    int i, j;
    temp = C->head;
    printf("\n");
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((temp != NULL) && (temp->row == i) && (temp->col == j))
            {
                printf("%d\t", temp->data);
                temp = temp->next;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}

list * sparseMatrix(list * A, list * B, list * C)
{
    int m, n, p, q;
    int i, j, row, col, val;
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);
    scanf("%d", &q);
    
    if(m < 1 || n < 1 || p < 0 || q < 0 || p > (m * n) || q > (m * n))
    {
        printf("INVALID INPUT\n");
        return NULL;
    }
    else
    {
        for(i = 0; i < p; i++)
        {
            scanf("%d", &row);
            scanf("%d", &col);
            scanf("%d", &val);
            
            if((row >= 0 && row < m) && (col >= 0 && col < n))
                addition(A, row, col, val);
            else
            {
                printf("INVALID INPUT\n");
                return NULL;
            }
        }
        for(i = 0; i < q; i++)
        {  
            scanf("%d", &row);
            scanf("%d", &col);
            scanf("%d", &val);
            
            if((row >= 0 && row < m) && (col >= 0 && col < n))
                addition(B, row, col, val);
            else
            {
                printf("INVALID INPUT\n");
                return NULL;
            }
            
        }
        node * list1 = A->head;
        node * list2 = B->head;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->row == list2->row)
            {
                if(list1->col == list2->col)
                {
                    addition(C, list1->row, list1->col, ((list1->data) + (list2->data)));
                    list1 = list1->next;
                    list2 = list2->next;
                }
                else
                {
                   if(list1->col < list2->col)
                   {
                        addition(C, list1->row, list1->col, list1->data);
                        list1 = list1->next;
                   }
                   else
                   {
                        addition(C, list2->row, list2->col, list2->data);
                        list2 = list2->next;
                   }
                }
            }
            else
            {
                if(list1->row < list2->row)
                {
                    addition(C, list1->row, list1->col, list1->data);
                    list1 = list1->next;
                }
                else
                {
                    addition(C, list2->row, list2->col, list2->data);
                    list2 = list2->next;
                }
            }
        }
        
        while(list1 != NULL)
        {
            addition(C, list1->row, list1->col, list1->data);
            list1 = list1->next;
        }
        
        while(list2 != NULL)
        {
            addition(C, list2->row, list2->col, list2->data);
            list2 = list2->next;
        }
        
        displayAddition(C, m, n);
    }
return C;    
}

int main()
{
    list * A = createList();
    list * B = createList();
    list * C = createList();
    C = sparseMatrix(A, B, C);
    return 0; 
}

