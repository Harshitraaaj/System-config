#include <stdio.h>
#include<string.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    char ret;
    ret = stack[top];
    stack[top] = '\0';
    top--;
    return ret;
}
int inper(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    }
}

int stper(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '(':
        return 0;
    case '#':
        return -1;
    }
}
void convert(char *exprn, char *postfix)
{
    int n = 0, i = 0, j = 0;
    char ch;
    ch = exprn[i++];
    while (ch != '#')
    {
        switch (ch)
        {
        case '(':
            push(ch);
            break;

        case ')':
            while (stack[top] != '(')
                postfix[j++] = pop();

            pop();
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            while (stper(stack[top]) >= inper(ch))
                postfix[j++] = pop();
            push(ch);
            break;
        default:
            postfix[j++] = ch;
            break;
        }

        printf("\nSTACK=%s POSTFIX = %s", stack, postfix);
        ch = exprn[i++];
    }
    while (stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
}
void main()
{
    char exprn[20] = "", postfix[20] = "";
    int i;
    printf("\n Enter the postfix expn\t");
    scanf("%s", exprn);
    strcat(exprn, "#");
    push('#');
    convert(exprn, postfix);
    printf("\n After Evaluation %s", postfix);
}