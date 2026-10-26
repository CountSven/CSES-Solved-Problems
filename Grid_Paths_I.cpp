#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int dp[n+1][n+1];

	memset( dp, 0, sizeof( dp ) );

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			char c;
			cin >> c;
			if ( c == '*' ) continue;
			if ( i == 1 && j == 1 ) dp[i][j] = 1;
			else {
				dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % MOD;
				dp[i][j] = ( dp[i][j] + dp[i][j-1] ) % MOD;
			}
		}
	}

	cout << dp[n][n] << "\n";

	return 0;
}