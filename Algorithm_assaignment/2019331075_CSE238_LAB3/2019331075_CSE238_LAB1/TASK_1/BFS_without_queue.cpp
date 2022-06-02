
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
vector<vector<int>> g(mxN);
bool vis[mxN];
int dis[mxN];

void b_w_q(int node, int lev) {
        if (vis[node]) return;
        dis[node] = lev;
        vis[node] = 1;
        for (auto v: g[node]) {
                b_w_q(v, lev+1);
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
        b_w_q(1, 0);
        for (int i = 1; i <= n; i++) {
                printf("%d(%d) ", i, dis[i]);
        }

        return 0;
}

