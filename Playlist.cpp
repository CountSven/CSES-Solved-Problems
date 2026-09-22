#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n+1];

	for ( int i = 1; i <= n; i++ ) cin >> a[i];

	map<int, int> mp;

	int res = 0;

	for ( int l = 1, r = 1; r <= n; r++ ) {
		mp[a[r]]++;
		while ( mp[a[r]] >= 2 ) {
			mp[a[l]]--;
			l++;
		}
		res = max( res, r - l + 1 );
	} 
	
	cout << res << "\n";

	return 0;
}