#include <stdio.h>

int visited[10], adj[10][10], n;

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 1; i <= n; i++)
    {
        // call dfs only if there exists an edge and the vertex is not visited
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\nFor no edge enter 0\nFor edge enter 1\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            printf("adj[%d][%d]: ", i, j);
            scanf("%d",&adj[i][j]);
        }

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    dfs(start);

    return 0;
}

/*
    vis=0 -> not visited
    vis=1 -> visited
    adj=1 -> edge exists
    adj=0 -> no edge

    Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
    Space Complexity: O(V) for the visited array and O(V) for the recursion stack

*/