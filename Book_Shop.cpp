#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	int h[n+1], s[n+1], dp[n+1][x+1];

	for ( int i = 1; i <= n; i++ ) cin >> h[i];
	for ( int i = 1; i <= n; i++ ) cin >> s[i];

	memset( dp, 0, sizeof( dp ) );
	
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= x; j++ ) {
			dp[i][j] = dp[i-1][j];
			if ( j - h[i] >= 0 ) dp[i][j] = max( dp[i][j], dp[i-1][j - h[i]] + s[i] );
		}
	}

	cout << dp[n][x] << "\n";

	return 0;
}