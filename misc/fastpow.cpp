// https://dmoj.ca/problem/multimadness

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MN=1e6+5, mod=1e9+7;
int n;
ll p[MN];

ll fastpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	p[0] = 1;
	for (ll i=1; i<MN; ++i)
		p[i] = p[i-1] * i %mod;
	while (n--) {
		ll a, b; cin >> a >> b;
		cout << p[b] * fastpow(p[--a], mod - 2) % mod << '\n';
	}
}
