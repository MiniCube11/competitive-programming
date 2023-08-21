// https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
using namespace std;
 
const int MN=2e5+5;
int n, q, up[MN][20], depth[MN];
vector<int> adj[MN];
 
void dfs(int u) {
	for (int v : adj[u])
		depth[v] = depth[u] + 1, dfs(v);
}
 
int lift(int u, int k) {
	for (int l=0; l<20; ++l)
		if (k & (1<<l) && u != -1)
			u = up[u][l];
	return u;
}
 
int lca(int a, int b) {
	if (depth[a] > depth[b]) a = lift(a, depth[a] - depth[b]);
	if (depth[b] > depth[a]) b = lift(b, depth[b] - depth[a]);
	if (a == b) return a;
	for (int l=19; l>=0; --l)
		if (up[a][l] != up[b][l])
			a = up[a][l], b = up[b][l];
	return up[a][0];
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	memset(up, -1, sizeof up);
	for (int i=2; i<=n; ++i) {
		cin >> up[i][0];
		adj[up[i][0]].push_back(i);
	}
	dfs(1);
	for (int l=0; l<20; ++l)
		for (int i=1; i<=n; ++i)
			if (up[i][l-1] != -1)
				up[i][l] = up[up[i][l-1]][l-1];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}
