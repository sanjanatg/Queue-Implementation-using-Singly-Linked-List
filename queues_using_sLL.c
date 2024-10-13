//PROGRAM  TO IMPLEMENT QUEUES USING SLL
#include <stdio.h>
#include <stdlib.h>
// MACRO FOR MALLOC
#define MALLOC(p, size, type) \
    p = (type*)malloc(size * sizeof(type)); \
    if (p == NULL) { \
        printf("\nInsufficient memory\n"); \
        exit(1); \
    }

// DEFINING NODE TYPE
typedef struct node {
    int info;
    struct node *link; 
} NODE;

// Function to insert an element in the queue
NODE* Insertrear(int item,NODE *first)
{
    NODE *cur,*temp;
    MALLOC(temp,1,NODE);
    //READY THE TEMP
    temp->info=item;
    temp->link=NULL;

    if(first==NULL)
    {
       return temp;
    }
    cur=first;
    while(cur->link!=NULL)
       cur=cur->link;
    
    cur->link=temp;
    return first;
}

//FUNCTION TO DELETE AN ELEMENT IN THE QUEUE
NODE* Deletefront(NODE *first)
{
    NODE *temp;
    if(first==NULL)
    {
        printf("\nQueue is empty\n");
        return first;
    }
    temp=first;
    temp=temp->link;
    printf("\nThe deleted element is %d",first->info);
    free(first);
    return temp;
}
//FUNCTION TO DISPLAY THE QUEUE
void display(NODE *first)
{
    NODE *temp;
    temp = first;
    if(temp==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
        exit(0);
    }
    while(temp!=NULL)
    {
        printf("%d,\t",temp->info);
        temp=temp->link;
    }
    printf("\nEND OF LIST");
}
int main()
{
    NODE *first=NULL;//EMPTY QUEUE;
    int size,choice,count=-1;
    printf("\nEnter size of queue=  ");
    scanf("%d",&size);
    
    while(1)
    {
        printf("\nENTER\n1=to inster an element to a queue\n2=to delete an element\n3=to display\nor any other value to exit ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                count++;
                if(count<size)
                {
                  int item;
                  printf("\nEnter element to be inserted");
                  scanf("%d",&item);
                  first=Insertrear(item,first);
                  break;                
                }
                else
                {
                    printf("\nQueue is full\ndelete an element to insert again");
                    break;
                }
            }
            case 2:
           {
            count--;

            if(count>=0)
            {
              first = Deletefront(first);
              break;
            }
            else{
                printf("queue is empty \npush an element\n");
                break;
            }
           }
           case 3:
           {
            printf("\nPRINTING THE queue\n");
            display(first);
            exit(0);
           }
          default:
            printf("\nWRONG CHOICE\n");
            exit(0);
        }
    }
    return 0;
}