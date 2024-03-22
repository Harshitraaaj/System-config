#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int stack[100];
int top = -1;
char exprn[20];

void push(int ele)
{
  stack[++top] = ele;
}
int pop()
{
  return (stack[top--]);
}
void compute(int opr1, char ch, int opr2)
{
  switch (ch)
  {
  case '+':
    push(opr1 + opr2);
    break;
  case '-':
    push(opr1 - opr2);
    break;
  case '*':
    push(opr1 * opr2);
    break;
  case '/':
    if (opr2 != 0)
      push(opr1 / opr2);
    else
    {
      printf("\nDivide by Zero Error");
      exit(0);
    }
    break;
  }
}

int eval()
{
  int i = 0;
  char ch;
  int opr1, opr2;
  ch = exprn[i++];
  while (ch != '#')
  {
    printf("\n%c", ch);
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
      opr2 = pop();
      opr1 = pop();
      printf("\n%d %d %c", opr1, opr2, ch);
      compute(opr1, ch, opr2);
      break;
    default:
      push(ch - '0');
    }
    ch = exprn[i++];
  }
  return pop();
}

void main()
{
  printf("\n Enter the postfix expn\t");
  scanf("%s", exprn);
  strcat(exprn, "#");
  printf("\n After Evaluation %d", eval());
}