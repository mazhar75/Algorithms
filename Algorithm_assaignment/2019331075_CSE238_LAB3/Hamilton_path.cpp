
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
int ad[mxN][mxN];
vi hamilton_path, pos_hamilton_path;

void findHamiltonPath(int node) {
	if ((int)pos_hamilton_path.size() == n) {
		hamilton_path = pos_hamilton_path;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!ad[node][i] || vis[i]) continue;
		vis[i] = true;
		pos_hamilton_path.pb(i);
		findHamiltonPath(i);
		vis[i] = false;
		pos_hamilton_path.pop_back();
	}
}
void doHamiltonPath() {
	findHamiltonPath(0);
	if ((int)hamilton_path.size() != n) {
		printf("No Hamilton path\n");
		return;
	}
	reverse(hamilton_path.begin(), hamilton_path.end());
	for (auto i: hamilton_path) {
		printf("%d -> ", i);
	} printf("\n");
}
int main() {
	freopen("01_input.txt", "r+", stdin);

	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0, u, v; i < m; i++) {
			scanf("%d %d", &u, &v);
			ad[u][v] = ad[v][u] = 1;
		}

		doHamiltonPath();
		memset(ad, 0, sizeof(ad));
		memset(vis, false, sizeof(vis));
		hamilton_path.clear(), pos_hamilton_path.clear();
	}

	return 0;
}
