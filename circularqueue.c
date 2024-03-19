#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct
{
    int key;
} element;
element Queue[MAX_SIZE];
int front = -1;
int rear = -1;
int count = 0;
int Qfull()
{
    return count == MAX_SIZE;
}
int Qempty()
{
    return count == 0;
}
void insert(int ele)
{
    rear = (rear + 1) % MAX_SIZE;
    if (Qfull())
    {
        printf("\nQueue Full");
    }
    if (front == -1)
        front = 0;
    count++;
    Queue[rear].key = ele;
}
int deleteq()
{
    int value;
    if (Qempty())
    {
        printf("\nQueue Empty");
    }
    value = Queue[front].key;
    front = (front + 1) % MAX_SIZE;
    count--;
    return (value);
}
void display()
{
    int i, j;
    if (Qempty())
        printf("\n Queue is empty\n");
    else
    {
        j = front;
        printf("\n Elements in the Queue: \n");
        for (i = 0; i < count; i++)
        {
            printf(" %d(%d)", Queue[j].key, j);
            j = (j + 1) % MAX_SIZE;
        }
    }
}
void main()
{
    int n = 4, i, ch, ele, flag = 1;
    while (flag)
    {
        printf("\n Menu driven Program in C for the Circular QUEUE operations \n");
        printf("\n1 Insert\n2 Delete\n3 Display\n4 Exit\n Enter the Choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (Qfull())
            {
                printf("\nQueue Full");
            }
            else
            {
                printf("\n Enter the value for insert\t");
                scanf("%d", &ele);
                insert(ele);
            }
            break;
        case 2:
            if (!Qempty())
            {
                ele = deleteq();
                printf("\n%d", ele);
            }
            else
                printf("\nQueue Empty");
            break;
        case 3:
            display();
            break;
        default:
            flag = 0;
        }
    }
}
