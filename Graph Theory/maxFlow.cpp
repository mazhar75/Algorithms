
#include <bits/stdc++.h>
#define sz 1000
using namespace std;
int graph[sz][sz];
int rGraph[sz][sz];
int parent[sz];
int n,m;

bool bfs(int s, int t)
{

    bool visited[n];
    memset(visited, 0, sizeof(visited));



    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;


    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {

                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }


    return false;
}


int fordFulkerson( int s, int t)
{
    int u, v;




    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];


    int max_flow = 0;


    while (bfs(s, t))
    {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }


        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }


        max_flow += path_flow;
    }


    return max_flow;
}


int main()
{

    freopen("00_input.txt","r+",stdin);
    cin>>n>>m;


    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;

    }
    int src,sink;
    cin>>src>>sink;


    cout << "The maximum possible flow is "
         << fordFulkerson(src, sink);

    return 0;
}
