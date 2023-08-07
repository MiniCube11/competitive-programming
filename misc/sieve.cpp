// https://dmoj.ca/problem/primes2

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN=5e6+5;
ll n, m;
bool m1[100000], m2[MN];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	m1[1] = 1;
	if (n == 1) m2[0] = 1;
	for (ll i=2; i*i<=m; ++i) {
		if (m1[i]) continue;
		for (ll j=i*2; j*j<=m; j+=i)
			m1[j] = 1;
		ll start = 2 * i;
		if (start < n) start = (n + i - 1) / i * i;
		for (int j=start; j<=m; j+=i) {
			if (j < n) continue;
			m2[j-n] = 1;
		}
	}
	for (int i=0; i<m-n+1; ++i)
		if (!m2[i]) cout << i + n << '\n';
}
