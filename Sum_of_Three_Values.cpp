#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> v(n);

	for ( int i = 0; i < n; i++ ) {
		cin >> v[i].first;
		v[i].second = i+1;
	}

	sort( v.begin(), v.end() );

	for ( int i = 0; i+2 < n; i++ ) {
		int l = i+1, r = n-1;
		while ( l < r ) {
			long long cur = v[i].first + v[l].first + v[r].first;
			if ( cur == x ) {
				cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n";
				return 0;
			}
			else if ( cur < x ) l++;
			else r--;
		} 
	}

	cout << "IMPOSSIBLE" << "\n";

	return 0;
}