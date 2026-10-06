#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int a[n];

	for ( int i = 0; i < n; i++ ) cin >> a[i];

	long long res = 0, l = 0, r = 0;	

	map<int, int> mp;

	while ( r < n ) {
		mp[a[r]]++;
		while ( (int)mp.size() > k ) {
			mp[a[l]]--;
			if ( !mp[a[l]] ) mp.erase( a[l] );
			l++;
		}
		r++;
		res += ( r - l );
	}

	cout << res << "\n";

	return 0;
}