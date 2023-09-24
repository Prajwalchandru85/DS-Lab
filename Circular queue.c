#include<stdio.h>
#include<stdlib.h>
#define size 5
int f = -1, r = -1;
int q[size];

void enqueue(int item)
{
    if ((r + 1) % size == f)
        printf("Queue is full\n");
    else
    {
        r = (r + 1) % size;
        q[r] = item;
        if (f == -1)
        {
            f = 0;
        }
    }
}

void dequeue()
{
    if (f == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted element is %d\n", q[f]);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % size;
        }
    }
}

void display()
{
    if (f == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue content:\n");
        for (int i = f; i != (r + 1) % size; i = (i + 1) % size)
        {
            printf("%d\n", q[i]);
        }
    }
}

int main()
{
    int item, ch;
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the item: ");
            scanf("%d", &item);
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
            printf("Invalid choice\n");
        }
    }
    return 0;
}
