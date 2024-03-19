#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
  char USN[10];
  char Name[20];
  char Branch[15];
  char Sem[3];
  char PhNo[10];
};

typedef struct Student STU;

struct Node
{
  STU info;
  struct Node *link;
};

typedef struct Node *Node;

STU GetData()
{
  STU temp;
  printf("Enter USN : ");
  scanf("%s", temp.USN);
  printf("Enter Name : ");
  scanf("%s", temp.Name);
  printf("Enter Branch : ");
  scanf("%s", temp.Branch);
  printf("Enter Sem : ");
  scanf("%s", temp.Sem);
  printf("Enter PhNo: ");
  scanf("%s", temp.PhNo);
  return temp;
}

void displayRec(STU ele)
{
  printf("%s\t%s\t%s\t%s\t%s\n", ele.USN, ele.Name, ele.Branch, ele.Sem, ele.PhNo);
}

Node Create(STU ele)
{
  Node temp = malloc(sizeof(struct Node));
  temp->info = ele;
  temp->link = NULL;
  return temp;
}

Node Insert(Node first, STU ele, int atFront)
{
  Node temp = Create(ele), cur = first;
  if (!first)
    return temp;
  if (atFront)
  {
    temp->link = first;
    return temp;
  }
  while (cur->link)
    cur = cur->link;
  cur->link = temp;
  return first;
}

Node Delete(Node first, int atFront)
{
  if (!first)
  {
    printf("List is empty\n");
    return NULL;
  }
  Node temp = first;
  if (atFront)
  {
    displayRec(temp->info);
    first = first->link;
  }
  else
  {
    while (temp->link->link)
      temp = temp->link;
    displayRec(temp->link->info);
    free(temp->link);
    temp->link = NULL;
  }
  return first;
}

void Display(Node first)
{
  if (!first)
  {
    printf("List is empty\n");
    return;
  }
  printf("USN\tName\tBranch\tSem\tPhNo\n");
  while (first)
  {
    displayRec(first->info);
    first = first->link;
  }
}

int Count(Node first)
{
  int cnt = 0;
  while (first)
  {
    cnt++;
    first = first->link;
  }
  return cnt;
}

int main()
{
  Node first = NULL;
  int flag = 1, ch;
  STU ele;
  while (flag)
  {
    printf("\nMenu\n");
    printf("1. Front Insert\n2. End Insert\n3. Front Delete\n4. End Delete\n5. Display\n6. No. of Nodes\n7. Exit\nEnter Choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter Student Details:\n");
      ele = GetData();
      first = Insert(first, ele, 1);
      break;
    case 2:
      printf("Enter Student Details:\n");
      ele = GetData();
      first = Insert(first, ele, 0);
      break;
    case 3:
      first = Delete(first, 1);
      break;
    case 4:
      first = Delete(first, 0);
      break;
    case 5:
      Display(first);
      break;
    case 6:
      printf("Number of Nodes: %d\n", Count(first));
      break;
    case 7:
      flag = 0;
      break;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}