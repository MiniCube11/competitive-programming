// https://cses.fi/problemset/task/1683/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define pb push_back

const int MN=1e5+5;
int n, m, ct=1, cmp[MN];
bool vis[MN];
vi order, adj1[MN], adj2[MN];

void dfs1(int u) {
	vis[u]=1;
	for (int v : adj1[u])
		if (!vis[v]) dfs1(v);
	order.pb(u);
}

void dfs2(int u) {
	vis[u]=1;
	cmp[u]=ct;
	for (int v : adj2[u])
		if (!vis[v]) dfs2(v);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj1[a].pb(b);
		adj2[b].pb(a);
	}
	// post order
	for (int i=1; i<=n; ++i)
		if (!vis[i]) dfs1(i);
	// traverse transposed graph
	memset(vis, 0, sizeof vis);
	for (int i=n-1; i>=0; --i)
		if (!vis[order[i]])
			dfs2(order[i]), ct++;
	cout << ct - 1 << '\n';
	for (int i=1; i<=n; ++i)
		cout << cmp[i] << " \n"[i==n];
}
