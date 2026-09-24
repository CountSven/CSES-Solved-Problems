#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];

	for ( int i = 0; i < n; i++ ) cin >> a[i];

	map<int, int> mp;

	long long res = 0;
	int l = 0, r = 0;

	while ( r < n ) {
		mp[a[r]]++;
		while ( mp[a[r]] >= 2 ) {
			mp[a[l]]--;
			l++;
		}
		r++;
		// cout << l << " " << r << "\n";
		int cur = r - l;
		res += cur;
	}

	cout << res << "\n";

	return 0;
}