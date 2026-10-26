#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int x[n+1], dp[n+1][m+1];

	for ( int i = 1; i <= n; i++ ) cin >> x[i];

	memset( dp, 0, sizeof( dp ) );

	for ( int j = 1; j <= m; j++ ) {
		if ( x[1] && j != x[1] ) continue;
		dp[1][j] = 1;
	}

	for ( int i = 2; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			if ( x[i] && j != x[i] ) continue;
			if ( j - 1 >= 1 ) dp[i][j] = ( dp[i][j] + dp[i-1][j-1] ) % MOD;
			dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % MOD;
			if ( j + 1 <= m ) dp[i][j] = ( dp[i][j] + dp[i-1][j+1] ) % MOD;
		}
	}

	int res = 0;

	for ( int j = 1; j <= m; j++ ) res = ( res + dp[n][j] ) % MOD;

	cout << res << "\n";

	return 0;
}