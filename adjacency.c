#include <stdio.h>
#include <stdlib.h>
int a[20][20],q[20],visited[20],reach[20],n,f=0,r=-1,count=0;
void bfs(int v)
{
    int i;
    for(i=1;i<=n;i++)
      if(a[v][i]&&!visited[i])
      {
        visited[i]=1;
        q[++r]=i;
      }
      if(f<=r)
        bfs(q[f++]);
}
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
      if(a[v][i]&&!reach[i])
      {
        printf("%d->%d\n",v,i);
        count++;
        dfs(i);
      }
}
int main()
{
    int v,ch,i,j;
    printf("\nenter no. of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      reach[i]=visited[i]=q[i]=0;
    printf("\nEnter graph data in matrix form:\n");
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    printf("\n1.BFS\n2.DFS\n3.Exit\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter vertex:");
               scanf("%d",&v);
               bfs(v);
               printf("\nThe nodes that are reacheble from %d are:\n",v);
               for(i=1;i<=n;i++)
                  if(visited[i])
                    printf("%d ",i);
               break;
        case 2:dfs(1);
               if(count==n-1)
                  printf("\ngraph is connected");
               else
                  printf("\ngraph is not connected");
               break;
        case 3:exit(0);
        default:printf("\nInvalid choice");
    }
    return 0;

}

/*
#include <stdio.h>
#include <stdlib.h>
struct Term
{
    int vertex, cost;
};
struct node
{
    struct node *next;
    int vertex;
};
typedef struct node *Node;
Node front, rear, Bfront, Brear;
Node G[20];
int visited[20];
Node CreateNode(int info)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->vertex = info;
    temp->next = NULL;
    return temp;
}
void DFS(int i)
{
    Node p;
    printf("%5d", i);
    p = G[i];
    visited[i] = 1;
    while (p != NULL)
    {
        i = p->vertex;
        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}
void insert(int vi, int vj)
{
    Node p, q;
    q = CreateNode(vj);
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
void read_graph(int n)
{
    int i, st, ed, no_of_edges, j;
    Node first;
    for (i = 0; i < n; i++)
    {
        first = NULL;
        G[i] = first;
        printf("Enter number of edges from node %d:", i);
        scanf("%d", &no_of_edges);
        for (j = 0; j < no_of_edges; j++)
        {
            printf("Enter an edge(%d,v):", i);
            scanf("%d", &ed);
            insert(i, ed);
        }
    }
}
void addQ(int i)
{
    Node temp = CreateNode(i);
    if (front == NULL && rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
int delQ()
{
    int i;
    i = front->vertex;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    return i;
}
void BFS(int v)
{
    Node w;
    printf("%5d", v);
    visited[v] = 1;
    addQ(v);
    while (front)
    {
        v = delQ();
        for (w = G[v]; w; w = w->next)
        {
            if (!visited[w->vertex])
            {
                printf("%5d", w->vertex);
                addQ(w->vertex);
                visited[w->vertex] = 1;
            }
        }
    }
}

void main()
{
    int i, flag = 1, ch, n;
    front = NULL;
    rear = NULL;
    Bfront = NULL;
    Brear = NULL;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    read_graph(n);
    Bfront = front;
    Brear = rear;
    while (flag)
    {
        printf("\nEnter the choice\n1: DFS\n2: BFS\n3: Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            DFS(0);
            break;
        case 2:
            BFS(0);
            break;
        case 3:
        default:
            flag = 0;
        }
    }
}
*/
