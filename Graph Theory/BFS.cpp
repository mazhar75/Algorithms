#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<list>
#include<vector>
#define sz 200010

using namespace std;
vector<int>adj[sz];
bool vis[sz];
int parent[sz];
int bfs(int s,int d)
{
    int node,cost,u;
    queue< pair<int,int> >q;
    q.push(make_pair(s,0));
    vis[s]=true;

    while(!q.empty())
    {
        node=q.front().first;
        cost=q.front().second;
        q.pop();

        if(node==d) return cost;
        for(int i=0; i<adj[node].size(); i++)
        {
            u=adj[node][i];
            if(vis[u]) continue;
            q.push(make_pair(u,cost+1));
            vis[u]=true;
            parent[u]=node;

        }

    }
    return -1;

}
void wrmup(int n)
{
    for(int i=0; i<n; i++)
        parent[i]=-1;

}

int main()
{
    int n,e;//n=node,e=edge
    cin>>n>>e;
    wrmup(n);

    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    int s=1,d=n,ans;
    ans=bfs(s,d);

    if(ans!=-1)
    {

        vector<int>path;
        while(~d)
        {
            path.push_back(d);
            d=parent[d];

        }
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(auto it=path.begin(); it!=path.end(); it++)
        {
            cout<<*it<<" ";
        }
    }
    else
        cout<<"IMPOSSIBLE"<<endl;



}
