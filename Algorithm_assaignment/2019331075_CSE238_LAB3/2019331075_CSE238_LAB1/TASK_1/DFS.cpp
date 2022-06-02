
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
vector<vector<int>> g(mxN);
bool vis[mxN];
int disc[mxN], fini[mxN], cur_time;
int cnt=0,m=0;

void dfs(int node,int n) {
        if ( node==n) return ;


        vis[node] = 1;
         m=max(node,m);
        for (auto v: g[node]) {
                dfs(v,n);
        }
        if(m<n){
          cnt++;
          dfs(m+1,n);
        }

}

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0, u, v; i < m; i++) {
                scanf("%d %d", &u, &v);
                g[u].push_back(v);
                g[v].push_back(u);
        }
        dfs(1,n);

        cout<<cnt<<endl;



        return 0;
}

