#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
#define sz 100010
#define inf (1<<28)
using namespace std;
vector<int>adj[sz],w[sz];
int par[sz],cost[sz];

int dijkstra(int st,int des,int n)
{

    priority_queue< pair<int,int> >pq;
    cost[st]=0;
    pq.push({0,st});
    int c,u;
    while(!pq.empty())
    {
        c=pq.top().first;
        u=pq.top().second;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(c+w[u][i]<cost[adj[u][i]])
            {

                cost[adj[u][i]]=c+w[u][i];
                pq.push({cost[adj[u][i]],adj[u][i]});
                par[adj[u][i]]=u;
            }

        }



    }

    return cost[des];


}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i]=-1;
        cost[i]=inf;
    }

}

int main()
{
    freopen("dijkastra_input.txt","r+",stdin);
    //freopen("dijkastra_output.txt","w+",stdin);
    int n,e,x,y,z,st,des;
    cin>>n>>e;
    //e=n-1;
    init(n);
    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    cin>>st>>des;
    int d=dijkstra(st-1,des-1,n);
    //cout<<d<<" ";
    cout<<"The minimum cost from "<<st<<" to "<<des<<" is "<<d<<endl;

    x=des-1;
    vector<int>path;
    while(~x)
    {

        path.push_back(x+1);
        x=par[x];
    }
    reverse(path.begin(),path.end());
    cout<<"The minimum cost path is: ";
    for(int i=0; i<path.size(); i++)
    {

        cout<<path[i]<<"->";
    }


    return 0;
}
