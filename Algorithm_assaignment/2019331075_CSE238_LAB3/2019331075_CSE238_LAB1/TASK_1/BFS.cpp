
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
vector<vector<int>> g(mxN);
bool vis[mxN];
int dis[mxN];

void bfs() {
        vis[1] = 1;
        dis[1] = 0;
        queue<int> q;
        q.push(1);
        while (q.size()) {
                int node = q.front();
                q.pop();
                for (auto v: g[node]) {
                        if (vis[v]) continue;
                        q.push(v);
                        vis[v] = 1;
                        dis[v] = dis[node] + 1;
                }
        }
}

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0, u, v; i < n; i++) {
                scanf("%d %d", &u, &v);
                g[u].push_back(v);
                g[v].push_back(u);
        }
        bfs();
        for (int i = 1; i <= n; i++) {
                printf("%d(%d) ", i, dis[i]);
        }

        return 0;
}
