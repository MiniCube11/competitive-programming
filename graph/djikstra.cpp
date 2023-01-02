// Problem: https://dmoj.ca/problem/sssp

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MN=1005, inf=1e9;
int n, m, dist[MN];
vector<pii> adj[MN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	fill(dist, dist+MN, inf);
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [c, v] : adj[u]) {
			if (dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				pq.push({dist[v], v});
			}
		}
	}
	for (int i=1; i<=n; ++i)
		cout << (dist[i]==inf ? -1 : dist[i]) << '\n';
}
