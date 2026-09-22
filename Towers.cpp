#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	multiset<int> mst;

	for ( int i = 0, x; i < n; i++ ) {
		cin >> x;
		auto it = mst.upper_bound( x );
		if ( it != mst.end() ) mst.erase( it );
		mst.insert( x );
	}

	cout << mst.size() << "\n";

	return 0;
}