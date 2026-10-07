#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n), pref(n+1, 0);

	for ( int i = 0; i < n; i++ ) {
		cin >> v[i];
		pref[i+1] = v[i] + pref[i];
	} 

	multiset<ll> mst;

	for ( int i = a; i <= b; i++ ) mst.insert( pref[i] );

	ll res = *mst.rbegin() - pref[0];

	for ( int i = 2, j = a, k = b+1; i+a-1 <= n; i++, j++, k++ ) {
		// cout << i << " " << j << " " << k << "\n";
		if ( j <= n ) mst.erase( mst.find( pref[j] ) );
		if ( k <= n ) mst.insert( pref[k] );
		res = max( res, *mst.rbegin() - pref[i-1] );
	}

	cout << res << "\n";

	return 0;
}