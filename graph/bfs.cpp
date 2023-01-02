#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
int n, m, dist[MN];
vector<int> adj[MN];

void bfs(int start) {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] != -1) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
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
	bfs(1);
}
