#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	map<int, vector<int>> mp;

	for ( int i = 1, x; i <= n; i++ ) {
		cin >> x;
		mp[x].push_back( i );
	}

	for ( auto [v, pos] : mp ) {
		if ( v > x ) break;
		int need = x - v, p1 = pos[0], p2 = -1;

		if ( v == need ) {
			if ( pos.size() >= 2 ) p2 = pos[1];
		}
		else {
			if ( mp.find( need ) != mp.end() ) p2 = mp[need][0];
		}

		if ( p2 != -1 ) {
			if ( p1 > p2 ) swap( p1, p2 );
			cout << p1 << " " << p2 << "\n";
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << "\n";

	return 0;
}