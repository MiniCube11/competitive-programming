// https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const int MN=505;
const ll inf=1e18;
int n, m, q;
ll dist[MN][MN];
vector<pll> adj[MN];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			dist[i][j] = (i == j ? 0 : inf);
	for (int i=0; i<m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		dist[a][b]=min(dist[a][b], c);
		dist[b][a]=min(dist[b][a], c);
	}
	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (dist[a][b] == inf ? -1 : dist[a][b]) << '\n';
	}
}
