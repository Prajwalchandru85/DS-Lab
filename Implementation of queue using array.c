#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max];
int front=-1;
int rear=-1;

    void enqueue(int item)
    {
        if(rear==max-1)
        printf("queue is full\n");
    
    else
    {
        q[++rear]=item;
        if(front==-1)
        {
            front++;
        }
    }
}
void dequeue()
{
    if(front==-1)
    printf("queue is empty\n");

else
{
    int del;
    del=q[front];
    printf("the element deleted is %d\n",del);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
}
}
void display()
{
    if(front==-1)
    printf("queue is empty\n");

else
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
}
int main()
{
    int item,ch;
    while(1)
    {
         printf("1. insert\n2. delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("enter the item\n");
            scanf("%d",&item);
            enqueue(item);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("invalid choice\n");
        }
    }
    return 0;
}
        
    
