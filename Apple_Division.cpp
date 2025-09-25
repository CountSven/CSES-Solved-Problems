#include<bits/stdc++.h>
using namespace std;

void appDiv( int i, int n, long long sum1, long long sum2, vector<long long> &v, long long &mn )
{
	if ( i == n ) {
		mn = min( mn, abs( sum1 - sum2 ) );
		return;
	}
	appDiv( i+1, n, sum1 + v[i], sum2, v, mn );
	appDiv( i+1, n, sum1, sum2 + v[i], v, mn );
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> v(n);

	for ( int i = 0; i < n; i++ ) cin >> v[i];

	long long mn = INT_MAX;

	appDiv( 0, n, 0, 0, v, mn );

	cout << mn << "\n";

	return 0;
}