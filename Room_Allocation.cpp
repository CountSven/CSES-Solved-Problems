#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> v(n);

	for ( int i = 0; i < n; i++ ) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}

	sort( v.begin(), v.end() );

	multiset<pair<int, int>> mst;

	vector<int> room(n);

	int cur = 1;

	for ( auto [x, y] : v ) {
		auto [a, b] = x;
		if ( !mst.size() ) {
			mst.insert( { b, cur } );
			room[y] = cur++;
		}
		else {
			auto [t, id] = *mst.begin();
			if ( t < a ) {
				mst.erase( mst.find( *mst.begin() ) );
				mst.insert( { b, id } );
				room[y] = id;
			}
			else {
				mst.insert( { b, cur } );
				room[y] = cur++;
			}
		}
	}

	cout << cur - 1 << "\n";
	for ( int i = 0; i < n; i++ ) cout << room[i] << " \n"[i + 1 == n];

	return 0;
}