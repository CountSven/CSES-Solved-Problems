#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> v1(n), v2(n);

	for ( int i = 0, x, y; i < n; i++ ) {
		cin >> x >> y;
		v1[i].first.first = y;
		v1[i].first.second = -x;
		v2[i].first.first = x;
		v2[i].first.second = -y;
		v1[i].second = v2[i].second = i;
	}

	sort( v1.begin(), v1.end() );
	sort( v2.begin(), v2.end() );

	// for ( auto [x, y] : v1 ) {
	// 	auto [a, b] = x;
	// 	cout << a << " " << b << " -> " << y << "\n";
	// }

	// cout << "\n";

	// for ( auto [x, y] : v2 ) {
	// 	auto [a, b] = x;
	// 	cout << a << " " << b << " -> " << y << "\n";
	// }

	vector<int> outer(n, 0), inner(n, 0);

	multiset<int> mst;

	for ( auto [x, y] : v1 ) {
		auto [a, b] = x;
		int cur = -b;
		auto it = mst.lower_bound( cur );
		if ( it != mst.end() ) outer[y] = 1;
		mst.insert( cur );
	}

	mst.clear();

	for ( auto [x, y] : v2 ) {
		auto [a, b] = x;
		int cur = -b;
		auto it = mst.lower_bound( cur );
		if ( it != mst.end() ) inner[y] = 1;
		mst.insert( cur );
	}

	for ( int i = 0; i < n; i++ ) cout << outer[i] << " \n"[i + 1 == n];
	for ( int i = 0; i < n; i++ ) cout << inner[i] << " \n"[i + 1 == n];

	return 0;
}