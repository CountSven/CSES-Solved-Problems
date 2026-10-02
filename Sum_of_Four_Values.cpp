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

	for ( int i = 0; i+3 < n; i++ ) {
		for ( int j = i+1; j+2 < n; j++ ) {
			int l = j+1, r = n-1;
			while ( l < r ) {
				long long sum = v[i].first + v[j].first + v[l].first + v[r].first;
				if ( sum == x ) {
					cout << v[i].second << " " << v[j].second << " " << v[l].second << " " << v[r].second << "\n";
					return 0;
				}
				else if ( sum < x ) l++;
				else r--;
			}
		}
	}   
	
	cout << "IMPOSSIBLE" << "\n";

	return 0;
}