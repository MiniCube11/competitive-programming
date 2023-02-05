// Problem: https://cses.fi/problemset/task/1651/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN=2e5;
ll tree[4*MN], lazy[4*MN], a[MN];
int n, q;

void apply(int i, int ql, int qr, ll val) {
	lazy[i] += val;
	tree[i] += (qr - ql + 1) * val;
}

void push(int i, int ql, int qr) {
	if (lazy[i]) {
		if (ql != qr) {
			int mid = (ql + qr) / 2;
			apply(2*i, ql, mid, lazy[i]);
			apply(2*i+1, mid+1, qr, lazy[i]);
		}
		lazy[i] = 0;
	}
}

void update(ll val, int l, int r, int ql, int qr, int i) {
	push(i, ql, qr);
	if (l <= ql && qr <= r) {
		apply(i, ql, qr, val);
		return;
	}
	int mid = (ql+qr)/2;
	if (l <= mid) update(val, l, r, ql, mid, 2*i);
	if (mid + 1 <= r) update(val, l, r, mid+1, qr, 2*i+1);
	tree[i] = tree[2*i] + tree[2*i+1];
}

ll getsum(int l, int r, int ql, int qr, int i) {
	push(i, ql, qr);
	if (l <= ql && qr <= r) {
		return tree[i];
	}
	int mid = (ql+qr)/2;
	ll lsum = 0, rsum=0;
	if (l <= mid) lsum = getsum(l, r, ql, mid, 2*i);
	if (mid + 1 <= r) rsum = getsum(l, r, mid+1, qr, 2*i+1);
	return lsum + rsum;
}

void build(int i, int ql, int qr) {
	if (ql == qr) {
		tree[i] = a[ql];
		return;
	}
	int mid = (ql+qr)/2;
	build(2*i, ql, mid);
	build(2*i+1, mid+1, qr);
	tree[i] = tree[2*i] + tree[2*i+1];
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int qt; cin >> qt;
		if (qt == 1) {
			int l, r; ll val; cin >> l >> r >> val;
			update(val, l, r, 1, n, 1);
		} else {
			int pos; cin >> pos;
			cout << getsum(pos, pos, 1, n, 1) << '\n';
		}
	}
}
