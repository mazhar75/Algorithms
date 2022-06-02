#include <bits/stdc++.h>
#define sz 1000
using namespace std;
vector<int>adj[sz],w[sz];
int par[sz];
bool vis[sz];
priority_queue<pair<int,pair<int,int>>,
               vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
int par_find(int node){
   if(par[node]==node)return node;
   return par[node]=par_find(par[node]);

}
int mst_prims(int src)
{
    int p,q,cost,total=0;
    for(int i=0;i<adj[src].size(); i++)
    {
        q=max(src,adj[src][i]);
        p=min(src,adj[src][i]);
        pq.push({w[src][i],{p,q}});

    }
    vis[src]=true;
    vector<pair<int,pair<int,int>>>ans;
    while(!pq.empty())
    {
        cost=pq.top().first;
        p=pq.top().second.first;
        q=pq.top().second.second;
        pq.pop();
        int u=par_find(p);
        int v=par_find(q);
        if(u!=v)
        {
            par[v]=u;
            ans.push_back({cost,{p,q}});
            total+=cost;
            src=vis[p]?q:p;
            vis[src]=true;
            for(int i=0; i<adj[src].size(); i++)
            {
                q=max(src,adj[src][i]);
                p=min(src,adj[src][i]);
                pq.push({w[src][i],{p,q}});

            }


        }

    }
    return total;





}
void mst_init(int n)
{
    for(int i=0; i<=n; i++)
    {
        par[i]=i;
        vis[i]=false;
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y,z;
    mst_init(n);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    int total=mst_prims(1);
    cout<<"Total minimum cost ="<<total<<endl;
    return 0;
}
