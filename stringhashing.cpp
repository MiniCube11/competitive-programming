#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX=1e6+5, p=31;
const ll mod=1e9+7;
ll n, m, hsh[MX];
string s, t;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	n=s.size(), m=t.size();
	for (int i=1; i<=n; ++i) {
		hsh[i]=(hsh[i-1]*p+(s[i-1]-'a'))%mod;
	}
	ll h=0, pw=1;
	for (int i=0; i<m; ++i) {
		h=(h*p+(t[i]-'a'))%mod;
		pw=pw*p%mod;
	}
	for (int i=m; i<=n; ++i) {
		ll res=(hsh[i] - hsh[i-m] * pw)%mod;
		if (res<0) res+=mod;
		if (res == h) {
			cout << i-m << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}
