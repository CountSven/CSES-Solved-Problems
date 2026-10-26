#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	int c[n+1], dp[x+1];

	for ( int i = 1; i <= n; i++ ) cin >> c[i];

	memset( dp, 0, sizeof( dp ) );

	dp[0] = 1;

	for ( int i = 1; i <= x; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( i - c[j] >= 0 ) dp[i] = ( dp[i] + dp[i - c[j]] ) % MOD;
		}
	}

	cout << dp[x] << "\n";

	return 0;
}