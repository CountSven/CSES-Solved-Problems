#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];

	map<int, int> mp;

	for ( int i = 1; i <= n; i++ ) mp[i]++;

	for ( int i = 1; i < n; i++ ) {
		cin >> a[i];
		mp[a[i]]++;
	}

	for ( auto u : mp ) {
		if ( u.second == 1 ) cout << u.first << "\n";
	}

	// for ( auto u : mp ) cout << u.first << " " << u.second << "\n";

	return 0;
}