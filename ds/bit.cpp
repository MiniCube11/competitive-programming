// Problem: https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN=2e5+5;
int n, q;
ll bit[MN];

ll query(int x) {
	ll res = 0;
	for (; x>0; x-=x&-x)
		res += bit[x];
	return res;
}

ll sum(int l, int r) {
	return query(r) - query(l-1);
}

void update(int x, int k) {
	for (; x<MN; x+=x&-x)
		bit[x] += k;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<=n; ++i) {
		int a; cin >> a;
		update(i, a);
	}
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int pos, val; cin >> pos >> val;
			update(pos, val - sum(pos, pos));
		} else {
			int l, r; cin >> l >> r;
			cout << sum(l, r) << '\n';
		}
	}
}
