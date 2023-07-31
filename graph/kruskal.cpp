// https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MN=1e5+5;
ll n, m, par[MN], ct=0, ans=0;
vector<array<ll, 3>> edges;
 
ll find(int x) {
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}
 
void join(int x, int y) {
	if (find(x)>find(y)) swap(x,y);
	par[find(y)]=find(x);
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; ++i) par[i]=i;
	for (int i=0; i<m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());
	for (int i=0; i<m; ++i) {
		auto [c, a, b] = edges[i];
		if (find(a) != find(b)) {
			join(a, b);
			ct++, ans+=c;
		}
		if (ct==n-1) break;
	}
	if (ct==n-1) cout << ans << '\n';
	else cout << "IMPOSSIBLE\n";
}
