// Problem: https://cses.fi/problemset/task/1679/

#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;

int n, m, in_deg[MN];
vector<int> adj[MN], ans;
queue<int> q;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		in_deg[b]++;
	}
	for (int i=1; i<=n; ++i) {
		if (in_deg[i]==0)
			q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ans.push_back(u);
		for (int v : adj[u]) {
			in_deg[v]--;
			if (in_deg[v]==0)
				q.push(v);
		}
	}
	if ((int)ans.size() == n) {
		for (int a : ans)
			cout << a << ' ';
		cout << '\n';
	} else {
		cout << "IMPOSSIBLE\n";
	}
}
