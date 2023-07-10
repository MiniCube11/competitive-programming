// https://cses.fi/problemset/task/1694/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef array<ll, 3> ar3;

#define f first
#define s second
#define pb push_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int MN=505, MM=1005;
int level[MN], nxt[MN], ct=0, n, m;
vi adj[MN];
ar3 edges[2*MM];

void addedge(ll a, ll b, ll c) {
	adj[a].pb(ct); edges[ct] = {b, 0, c}; ct++;
	adj[b].pb(ct); edges[ct] = {a, 0, 0}; ct++;	
}

bool bfs(int s, int t) {
	memset(level, -1, sizeof level);
	queue<int> q;
	q.push(s);
	level[s]=0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int id : adj[u]) {
			auto [v, flow, cap] = edges[id];
			if (level[v]==-1 && flow<cap)
				q.push(v), level[v]=level[u]+1;
		}
	}
	return level[t]>=0;
}

ll dfs(int u, int t, ll pushed) {
	if (u==t) return pushed;
	for (; nxt[u] < sz(adj[u]); ++nxt[u]) { // pruning
		int id = adj[u][nxt[u]];
		auto [v, flow, cap] = edges[id];
		if (level[v] != level[u] + 1 || cap <= flow) continue;
		ll tf = dfs(v, t, min(pushed, cap - flow));
		if (tf) {
			edges[id][1] += tf;
			edges[id^1][1] -= tf; // reverse edge
			return tf;
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;
		addedge(a, b, c);
	}
	ll maxflow = 0;
	while (bfs(1, n)) {
		memset(nxt, 0, sizeof nxt);
		while (ll pushed = dfs(1, n, 1e18))
			maxflow += pushed;
	}
	cout << maxflow << '\n';
}
