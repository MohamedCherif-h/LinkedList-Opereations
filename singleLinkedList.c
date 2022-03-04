#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data ;
    struct node *next ;
}
node ;
node *list;

node * create (int val)
{
    node *n = malloc(sizeof(node));
    n->data = val ;
    n->next = NULL ;

    return n ;
}

node *insert(node *head , int val ) 
{
    node *new = malloc(sizeof(node));
    new->data = val ;
    new->next = head ;
    head = new ;

    return head ;

}
int count = 0;
// recursion output
int output (node *lists)
{
   
    if (lists != NULL) {
        printf("%d\n" , lists->data);
        count = count + 1 ;
        output(lists->next);
    }
       
    else {
         printf("\ncount : %d\n", count);
    }
   
    
}

int searching (node *lists , int target)
{
    node *tmp = lists ;
    for (node *tmp = lists ; tmp!= NULL ; tmp = tmp->next)
    {
        if (tmp->data == target)
        {
            printf("found ..");
            return 0 ;
        }
    }
    
    printf("not found...") ;
    return 1 ;
}

void destroy (node *l)
{
    node *tmp ;
    while (l != NULL) 
    {
        tmp = l->next ;
        free(l);
        l = tmp ;
    }
}

int main (void)
{   
    list = NULL ;
    list = create (6) ;
    list = insert(list, 8) ;
    list = insert(list, 4) ;
    list = insert(list, 2) ;
    

   output(list);
   searching (list, 10);
   destroy (list);
}

