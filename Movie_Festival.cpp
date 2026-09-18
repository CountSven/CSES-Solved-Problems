#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for ( auto &[x, y] : v ) cin >> y >> x;

	sort( v.begin(), v.end() );

	int last = -1, cnt = 0;

	for ( auto [x, y] : v ) {
		// cout << x << " " << y << "\n";
		if ( y >= last ) {
			cnt++;
			last = x;
		} 
	}

	cout << cnt << "\n";

	return 0;
}