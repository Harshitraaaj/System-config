#include <stdio.h>
#include <stdlib.h>
struct Employee
{
  char SSN[10];
  char Name[10];
  char Branch[10];
  char Des[10];
  char sal[10];
  char phone[10];
};
typedef struct Employee EMP;
struct node
{
  EMP info;
  struct node *llink, *rlink;
};
typedef struct node *Node;

EMP GetRec()
{
  EMP temp;
  printf("Enter the SSN: ");
  scanf("%s", temp.SSN);
  printf("Enter the Name:");
  scanf("%s", temp.Name);
  printf("Enter branch:");
  scanf("%s", temp.Branch);
  printf("Enter the designation: ");
  scanf("%s", temp.Des);
  printf("Enter sal:");
  scanf("%s", temp.sal);
  printf("Enter the phone number:");
  scanf("%s", temp.phone);
  return temp;
}
void DispRec(EMP temp)
{
  printf("%s\t\t%s\t\t%s\t%s\t%s\t%s\n", temp.SSN, temp.Name, temp.Branch, temp.Des, temp.sal, temp.phone);
}
Node Create(EMP ele)
{
  Node temp;
  temp = (Node)malloc(sizeof(struct node));
  temp->info = ele;
  temp->llink = NULL;
  temp->rlink = NULL;
  return temp;
}
Node Insert(Node first, EMP ele, int atFront)
{
  Node temp = Create(ele), cur = first;
  if (!first)
    return temp;
  if (atFront)
  {
    temp->rlink = first;
    first->llink=temp;
    return temp;
  }
  while (cur->rlink!=NULL)
    cur = cur->rlink;
  cur->rlink = temp;
  temp->rlink=NULL;
  return first;
}

Node delete(Node first, int atFront)
{
  if (!first)
  {
    printf("List is empty\n");
    return NULL;
  }
  Node temp = first;
  if (atFront)
  {
    DispRec(temp->info);
    first = first->rlink;
  }
  else
  {
    while (temp->rlink->rlink!=NULL)
      temp = temp->rlink;
    DispRec(temp->rlink->info);
    free(temp->rlink);
    temp->rlink = NULL;
  }
  return first;
}


void display(Node first)
{
 if(!first){
  printf("List is empty\n");
  return;
 }
 printf("\nSSN\t\tNamt\t\tBranch\t\tdesignation\tsalary\tphonenum\n");
 while(first){
  DispRec(first->info);
  first=first->rlink;

 }
}
void main()
{  Node first=NULL;
  EMP ele;
  int flag = 1, ch;
  while (flag)
  {
    printf("\n Menu Implementation of Double Ended Queue using DLL\n");
    printf("\n1 Insert Front \n2 Insert rear \n3 Delete Front \n4 Delete Rear \n5 Display\n");
    printf("6 Exit\n Enter the Choice :  ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\n Enter the Employee Record to Insert Front of Queue\n");
      ele = GetRec();
      first=Insert(first,ele,1);
      break;
    case 2:
      printf("\n Enter the Employee Record to Insert rear of Queue\n");
      ele = GetRec();
      first=Insert(first,ele,0);
      break;
    case 3:
      first=delete(first,1);
      break;
    case 4:
      first=delete(first,0);
      break;
    case 5:
      display(first);
      break;
    default:
      flag = 0;
    }
  }
}
