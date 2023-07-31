// https://dmoj.ca/problem/dmpg17s2

#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
int par[MN];

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void join(int x, int y) {
	if (find(x) > find(y)) swap(x, y);
	par[find(x)] = find(y);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; ++i)
		par[i] = i;
	while (q--) {
		char c; int a, b;
		cin >> c >> a >> b;
		if (c == 'A') join(a, b);
		else cout << (same(a, b) ? 'Y' : 'N') << '\n';
	}
}
