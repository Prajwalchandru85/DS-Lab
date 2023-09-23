#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
    int top;
    int data[size];
  
};
typedef struct stack STACK;
void push(STACK *s, int item)
{
    if (s->top == size - 1) // Check if the stack is full
        printf("\nStack is full\n");
    else 
    {
        s->data[++(s->top)] = item; // Increment top and then push the item
    }
}
int pop(STACK*s)
{
    if(s->top==-1)
    {
    printf("\nstack is underflow\n");
    return -1;
    }
    else
    {
        return s->data[(s->top)--];
        
    }
}
void display(STACK s)
{
    if(s.top==-1)
    printf("\nstack is empty\n");
    else
    {
        for(int i=s.top;i>=0;i--)//reverse loop coz to display elements from where //top is pointing to
        {
            printf("%d\n",s.data[i]);
        }
    }
}
int main()
{
    STACK s;
    s.top=-1;
    int ch,item,del;
    while(1)
    {
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\n Reading choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the element to be pushed:");
            scanf("%d",&item);
            push(&s,item);
            break;
            case 2:
            del=pop(&s);
            if(del!=-1)
            printf("element popped is %d \n",del);
            break;
            case 3:
            display(s);
            break;
            case 4:
            printf("\nexitting\n");
            default:
            exit(0);
        }
    }
    return 0;
}
