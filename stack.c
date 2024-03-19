#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack_array[max];
int top = -1;

int isfull()
{
  if (top == max)
  {
    return 1;
  }
  return 0;
}
int isempty()
{
  if (top == -1)
  {
    return 1;
  }
  return 0;
}

void push(int data)
{
  if (isfull())
  {
    printf("stackoverflow\n");
    return;
  }
  top += 1;
  stack_array[top] = data;
}

void print()
{
  if (isempty())
  {
    printf("stackunderflow\n");
    return;
  }
  for (int i = top; i >= 0; i--)
  {
    printf("%d\t", stack_array[i]);
  }
  printf("\n");
}
int pop()
{
  if (isempty())
  {
    printf("stackunderflow\n");
    exit(1);
  }
  int value;
  value = stack_array[top];
  top -= 1;
  return value;
}

void main()
{
  int  i, oldTop, num, OrgNum, ele;
  int ch, flag = 1;
  int flag1;
  while (flag)
  {
    printf("\n Menu Driven Program\n");
    printf("\n1 Push\n2 Pop\n3 Palindrom\n4 Display\n5 Exit\n");
    printf("\nEnter the Choice\t");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\nEnter the Element to push\t");
      scanf("%d", &ele);
      push(ele);
      break;

    case 2:
      ele = pop();
      printf("\n The Element Poped is %d", ele);
      break;

    case 3:
      oldTop = top;
      top = -1;
      printf("\n Enter a number\t");
      scanf("%5d", &num);
      OrgNum = num;
      while (num != 0)
      {
        push(num % 10);
        num = num / 10;
      }
      flag1 = 1;
      num = OrgNum;
      while (!isempty())
      {
        if (num % 10 != pop())
          flag1 = 0;
        num = num / 10;
      }
      if (flag1 == 0)
        printf("\n %d is not palindrom", OrgNum);
      else
        printf("\n %d is palindrom", OrgNum);
      top = -1;
      break;
    case 4:
      print();
      break;
    case 5:
    default:
      flag = 0;
    }
  }
}

 
