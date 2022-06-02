#include<iostream>
#include<vector>
#define sz 1000
using namespace std;
vector<int>adj[sz];
bool vis[sz];
int arrived[sz];
int depurture[sz];
//int time;
void dfs(int node,int time){
   //if(vis[node])return;
   vis[node]=true;
   arrived[node]=++time;
   for(int i=0;i<adj[node].size();i++){
     if(!vis[adj[node][i]])dfs(adj[node][i],time);
   }
   depurture[node]=++time;
}
void init(int n){
  for(int i=0;i<=n;i++){
    arrived[i]=0;
    depurture[i]=0;
  }

}
int main(){
int n,m;
cin>>n>>m;
init(n);
for(int i=0;i<m;i++){
 int u,v;
 cin>>u>>v;
 adj[u].push_back(v);
 adj[v].push_back(u);
}
dfs(1,1);
for(int i=1;i<=n;i++){
cout<<"starting time="<<arrived[i]<<" "<<"Ending time="<<depurture[i]<<endl;
}
return 0;

}
