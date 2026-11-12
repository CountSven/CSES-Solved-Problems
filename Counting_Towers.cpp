#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7, MOD = 1e9+7;
int dp[N][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0][0] = dp[0][1] = 1;

	for ( int i = 1; i < N; i++ ) {
		dp[i][0] = ( dp[i][0] + ( ( 2LL * dp[i-1][0] ) % MOD ) ) % MOD;
		dp[i][0] = ( dp[i][0] + dp[i-1][1] ) % MOD;
		dp[i][1] = ( dp[i][1] + dp[i-1][0] ) % MOD;
		dp[i][1] = ( dp[i][1] + ( ( 4LL * dp[i-1][1] ) % MOD ) ) % MOD; 
	}

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;
		cout << ( dp[n-1][0] + dp[n-1][1] ) % MOD << "\n";
	}

	return 0;
}