// https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5;
int n, q, ct=0, first[MN], height[MN], walk[2*MN], st[8*MN];
vector<int> adj[MN];

void dfs(int u) {
	first[u] = ++ct;
	walk[ct] = u;
	for (int v : adj[u]) {
		height[v] = height[u] + 1;
		dfs(v);
		walk[++ct] = u;
	}
}

int getmin(int l, int r, int ql, int qr, int i) {
	if (l <= ql && qr <= r)
		return st[i];
	int mid = (ql+qr)/2;
	int lmin = -1, rmin = -1;
	if (l <= mid) lmin = getmin(l, r, ql, mid, 2*i);
	if (mid + 1 <= r) rmin = getmin(l, r, mid+1, qr, 2*i+1);
	if (lmin == -1) return rmin;
	if (rmin == -1) return lmin;
	return (height[lmin] < height[rmin] ? lmin : rmin);
}

void build(int ql, int qr, int i) {
	if (ql == qr) {
		st[i] = walk[ql];
		return;
	}
	int mid=(ql+qr)/2;
	build(ql, mid, 2*i);
	build(mid+1, qr, 2*i+1);
	st[i] = (height[st[2*i]] < height[st[2*i+1]] ? st[2*i] : st[2*i+1]);
}

int lca(int a, int b) {
	if (first[a] > first[b]) swap(a, b);
	return getmin(first[a], first[b], 1, 2*n, 1);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=2; i<=n; ++i) {
		int b; cin >> b;
		adj[b].push_back(i);
	}
	dfs(1);
	build(1, 2*n, 1);
	while (q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}
