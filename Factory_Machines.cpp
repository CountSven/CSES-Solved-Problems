#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, t;
	cin >> n >> t;
	int k[n];
 
	for ( int i = 0; i < n; i++ ) cin >> k[i];
 
	ll l = 1, r = 2e18, res = 2e18;
 
	while ( l <= r ) {
		ll mid = l + ( r - l ) / 2;
		ll cur = 0;
 
		for ( int i = 0; i < n; i++ ) {
			if ( cur >= t ) break;
			cur += mid / k[i];
		}
 
		if ( cur >= t ) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
 
	cout << res << "\n";
 
	return 0;
}