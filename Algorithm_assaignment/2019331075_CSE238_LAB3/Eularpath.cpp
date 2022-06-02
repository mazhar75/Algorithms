#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back

using vi = vector<int>;
using pii = pair<int, int>;

const int mxN = 1e2+1;
int n, m;
bool vis[mxN];
int ad[mxN][mxN], in_deg[mxN];
vector<pii> euler_path;

void add_edge(int u, int v) {
	ad[u][v] = ad[v][u] = 1;
}
void del_edge(int u, int v) {
	ad[u][v] = ad[v][u] = 0;
}
void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	for (int i = 0; i < n; i++) {
		if (ad[node][i]) dfs(i);
	}
}
bool isArtiBridge(int u, int v) {
	memset(vis, false, sizeof(vis));
	dfs(u);
	int before = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) before++;
	}
	del_edge(u, v);
	memset(vis, false, sizeof(vis));
	dfs(u);
	int after = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) after++;
	}
	add_edge(u, v);
	return before != after;
}
void findEulerPath(int node) {
	if ((int)euler_path.size() == m) return;
	vi arti_bridge;
	for (int i = 0; i < n; i++) {
		if (!ad[node][i]) continue;
		if (isArtiBridge(node, i)) {
			arti_bridge.pb(i);
			continue;
		}
		del_edge(node, i);
		euler_path.pb(make_pair(node, i));
		findEulerPath(i);
		return;
	}
	if (arti_bridge.empty()) {
		printf("Okay\n");
		return;
	}
	int nxt = arti_bridge[0];
	euler_path.pb(make_pair(node, nxt));
	findEulerPath(nxt);
}
int findSource() {
	vi pos;
	for (int i = 0; i < n; i++) {
		if (in_deg[i]&1) {
			pos.pb(i);
		}
	}
	if (pos.size() && pos.size() != 2) {
		return -1;
	} else if (pos.size()) {
		return pos[0];
	} return 0;
}
void doEulerPath() {
	int source = findSource();
	if (source == -1) {
		printf("No Euler Path\n");
		return;
	}
	findEulerPath(source);
	if ((int)euler_path.size() != m) {
		printf("No Euler Path\n");
		return;
	}
	for (auto i: euler_path) {
		printf("(%d ----- %d) -> ", i.ff, i.ss);
	}
}
int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; i++) {
		scanf("%d %d", &u, &v);
		ad[u][v] = ad[v][u] = 1;
		in_deg[u]++, in_deg[v]++;
	}

	doEulerPath();

	return 0;
}
