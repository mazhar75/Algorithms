#include<iostream>
#include<set>
#define sz 1000
using namespace std;
int head[sz];
int find(int node){
  if(node==head[node])return node;
  return head[node]=find(head[node]);

}

void uni_on(int u,int v){
int head_u=find(u);
int head_v=find(v);
if(head_u==head_v)return;
head[head_v]=u;

}
void init(int n){
 for(int i=0;i<=n;i++){
   head[i]=i;
 }
}
int main(){
int n,e;
cin>>n>>e;
init(n);
for(int i=0,u,v;i<e;i++){
  cin>>u>>v;
  uni_on(u,v);

}
set<int>s;
for(int i=1;i<=n;i++){
  s.insert(find(i));
}
cout<<"Connected Components="<<" "<<s.size()<<endl;


return 0;
}
