#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int compute(char symbol, int op1, int op2)
{
  switch (symbol)
  {
  case '+':
    return op1 + op2;
  case '-':
    return op1 - op2;
  case '*':
    return op1 * op2;
  case '/':
    return op1 / op2;
  case '$':
  case '^':
    return pow(op1, op2);
  default:
    return 0;
  }
}

int main()
{
  int s[20], res, op1, op2, top, i;
  char postfix[20], symbol;

  printf("\nEnter the postfix expression:\n");
  scanf("%s", postfix);

  top = -1;

  for (i = 0; i < strlen(postfix); i++)
  {
    symbol = postfix[i];

    if (isdigit(symbol))
    {
      s[++top] = symbol - '0'; // Convert character to integer
    }
    else
    {
      op2 = s[top--];
      op1 = s[top--];
      res = compute(symbol, op1, op2);
      s[++top] = res;
    }
  }

  res = s[top--];
  printf("\nThe result is: %d\n", res);

  return 0;
}