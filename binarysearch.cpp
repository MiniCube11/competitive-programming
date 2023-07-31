// https://cses.fi/problemset/task/1620/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MN=2e5+5;
ll n, p, k[MN];
 
bool check(ll t) {
	ll tot = 0;
	for (int i=0; i<n; ++i) {
		tot += t / k[i];
		if (tot >= p) return true;
	}
	return tot >= p;
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> p;
	for (int i=0; i<n; ++i) cin >> k[i];
	ll lo = 0, hi = 1e18, ans = -1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	cout << ans << '\n';
}
