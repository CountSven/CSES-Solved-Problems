#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, k;
	cin >> n >> k;
	int a[n];
 
	for ( int i = 0; i < n; i++ ) cin >> a[i];
 
	ll l = 1, r = 2e18, res = 2e18;
	
	while ( l <= r ) {
		ll mid = l + ( r - l ) / 2;
		ll sum = 0, cnt = 1, mx = 0;
 
		for ( int i = 0; i < n; i++ ) {
			if ( sum + a[i] > mid ) {
				mx = max( mx, sum );
				sum = a[i];
				cnt++;
			}
			else sum += a[i];
			if ( cnt > k ) break;
		}
 
		mx = max( mx, sum );
 
		// cout << mid << " " << cnt << " " << mx << "\n";
 
		if ( cnt <= k ) {
			res = min( res, mx );
			r = mid - 1;
		}
		else l = mid + 1;
	}
 
	cout << res << "\n";
 
	return 0;
}