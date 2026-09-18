#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	multiset<int> mst;

	for ( int i = 0, x; i < n; i++ ) {
		cin >> x;
		mst.insert( x );
	}

	while ( m-- ) {
		int x;
		cin >> x;

		auto it = mst.upper_bound( x );
		if ( it != mst.begin() ) {
			it--;
			cout << *it << "\n";
			mst.erase( it );
		}
		else cout << -1 << "\n";
	}

	return 0;
}