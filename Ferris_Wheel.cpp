#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	multiset<int> mst;

	for ( int i = 0, v; i < n; i++ ) {
		cin >> v;
		mst.insert( v );
	}

	int cnt = 0;

	while ( mst.size() ) {
		int cur = *mst.rbegin();
		mst.erase( mst.find( cur ) );
		if ( mst.size() ) {
			int need = x - cur;
			auto it = mst.upper_bound( need );
			if ( it != mst.begin() ) {
				it--;
				int val = *it;
				mst.erase( mst.find( val ) );
			}
		}
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}