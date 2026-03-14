#include <stdio.h>

int adj[10][10], visited[10], queue[10];
int n, front = -1, rear = -1;

// BFS function to traverse the graph
void bfs(int v)
{
    int i;

    for(i=1;i<=n;i++)
    {
        if(adj[v][i] && !visited[i])
        {
            queue[++rear] = i;
        }
    }

    if(front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}

int main()
{
    int i,j,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\nEnter 0 for no edge and 1 for edge\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            printf("adj[%d][%d]: ", i, j);
            scanf("%d",&adj[i][j]);
        }

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    front = rear = 0;
    queue[rear] = start; // enqueue the starting vertex
    visited[start] = 1;

    printf("BFS Traversal: ");

    // Loop until the queue is empty
    while(front <= rear)
    {
        start = queue[front++]; // dequeue the front element
        printf("%d ", start);

        for(i=1;i<=n;i++)
        {
            if(adj[start][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i; // enqueue the adjacent vertex
            }
        }
    }

    return 0;
}