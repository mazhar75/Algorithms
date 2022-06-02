#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define mx 100000
using namespace std;
vector<vector<int>>adj(mx);
//vector<int>path;
bool vis[mx];
bool vis2[mx];
int parent[mx];
int x,y;
int bfs(int s)
{
    int node,cost,u;
    queue< pair<int,int> >q;
    q.push(make_pair(s,0));
    vis[s]=true;
    int t=0;

    while(!q.empty())
    {
        node=q.front().first;
        cost=q.front().second;
        q.pop();

        if(cost>=t)x=node;
        for(int i=0; i<adj[node].size(); i++)
        {
            u=adj[node][i];
            if(vis[u]) continue;
            q.push(make_pair(u,cost+1));

            vis[u]=true;
            //parent[u]=node;

        }

    }
    return x;

}
void dis_bfs(int s,int d)
{
    int node,u;
    queue<int>q;
    q.push(s);
    vis2[s]=true;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node==d)return;
        for(int i=0; i<adj[node].size(); i++)
        {
            u=adj[node][i];
            if(vis2[u])continue;
            q.push(u);
            vis2[u]=true;
            parent[u]=node;

        }



    }


}
void init(int n)
{
    for(int i=0; i<n; i++)
    {
        vis[i]=false;
        vis2[i]=false;
    }

}
void wrmup(int n)
{
    for(int i=0; i<n; i++)
        parent[i]=-1;

}
int main()
{
    freopen("DiameterOfTree.txt","r+",stdin);
    int n;
    cin>>n;
    init(n);
    for(int i=0,u,v; i<n-1; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int p=bfs(0);
    init(n);
    int q=bfs(p);
    //cout<<p<<" "<<q<<endl;
    wrmup(n);
    dis_bfs(p,q);
    vector<int>path;
    while(~q)
    {
        path.push_back(q);
        q=parent[q];

    }
    cout<<path.size()<<endl;
    //reverse(path.begin(),path.end());
    for(auto it=path.begin(); it!=path.end(); it++)
    {
        cout<<*it<<" ";
    }


    return 0;
}
/**
12
0 1
1 11
2 11
0 3
0 4
3 7
4 8
5 10
4 5
11 6
1 9
*/

