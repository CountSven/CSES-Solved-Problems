#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for ( int i = 0, x; i < n; i++ ) {
		cin >> x;
		v[i] = { x, i };
	}

	sort( v.begin(), v.end() );

	int last = 1e9, cnt = 0;

	for ( auto [x, y] : v ) {
		if ( y < last ) cnt++;
		last = y;
	}

	cout << cnt << "\n";

	return 0;
}