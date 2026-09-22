#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n;
	cin >> x >> n;

	set<int> pos;
	multiset<int> len;

	pos.insert( 0 );
	pos.insert( x );
	len.insert( x );

	while ( n-- ) {
		int p;
		cin >> p;

		auto it = pos.upper_bound( p );
		int up = *it;
		it--;
		int down = *it;

		len.erase( len.find( up - down ) );

		pos.insert( p );

		int v1 = p - down;
		int v2 = up - p;

		len.insert( v1 );
		len.insert( v2 );

		cout << *len.rbegin() << " ";
	}
	cout << "\n";

	return 0;
}