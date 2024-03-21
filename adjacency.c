#include <stdio.h>
#include<stdlib.h>
int count = 0;
void creategraph(int n, int a[20][20])
{
    int i, j;
    printf("enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void bfs(int a[20][20], int n, int source, int s[])
{
    int f, r, q[10], u, v, i;
    printf("enter the source vertex\n");
    scanf("%d", &source);
    printf("the nodes reachable are\n"); 
    
    for (i = 1; i <= n; i++)
        s[i] = 0;
    f = r = 0;
    q[r] = source;
    s[source] = 1;
    while (f <= r)
    {
        u = q[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && s[v] == 0)
            {
                printf("\n%d", v);
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void dfs(int a[20][20], int n, int vis[], int v)
{
    int i;
    count++;
    vis[v] = count;
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && a[v][i] == 1)
            dfs(a, n, vis, i);
    }
}
int main()
{
    int a[20][20], n, source, s[10], i, j, vis[10];
    int ch;

    while (1)
    { printf("\nEnter your choice\n1:Create graph\n2:Check Reachability\n3:Check Connectivity\n4.Exit\n"); 
scanf("%d",&ch); 
switch(ch) 
{
        case 1:
            printf("Enter the number of nodes:");
            scanf("%d", &n);
            creategraph(n, a);
            break;
        case 2:
            bfs(a, n, source, s);
            break;
        case 3:
            for (i = 1; i <= n; i++)
                vis[i] = 0;
            dfs(a, n, vis, 1);
            if (count == n)
                printf("the graph is connected\n");
            else
                printf("the graph is not connected\n");
            break;
        case 4:
            exit(0); 
}
    }
    return 0;
}