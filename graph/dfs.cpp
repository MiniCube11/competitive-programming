#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
int n, m;
vector<int> adj[MN];
bool vis[MN];

void dfs(int u) {
	for (int v : adj[u]) {
		if (vis[v]) continue;
		vis[v] = true;
		dfs(v);
	}
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
}
