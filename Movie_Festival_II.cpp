#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);

	for ( auto &[x, y] : v ) cin >> y >> x;

	sort( v.begin(), v.end() );

	multiset<int> mst;

	for ( int i = 0; i < k; i++ ) mst.insert( 0 );

	int cnt = 0;

	for ( auto [x, y] : v ) {
		auto it = mst.upper_bound( y );
		if ( it == mst.begin() ) continue;
		it--;
		mst.erase( mst.find( *it ) );
		mst.insert( x );
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}