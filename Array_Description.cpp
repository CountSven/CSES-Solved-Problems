#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m;
	cin >> n >> m;
	int a[n];
 
	for ( int i = 0; i < n; i++ ) cin >> a[i];
 
	vector<vector<long long>> dp( n, vector<long long>( m+1, 0 ) );
 
	if ( a[0] != 0 ) dp[0][a[0]] = 1;
	else {
		for ( int i = 1; i <= m; i++ ) dp[0][i] = 1;
	}
 
	for ( int i = 1; i < n; i++ ) {
		if ( a[i] == 0 ) {
			for ( int j = 1; j <= m; j++ ) {
				if ( j - 1 >= 1 ) dp[i][j] = ( dp[i][j] + dp[i-1][j-1] ) % mod;
				dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % mod;
				if ( j + 1 <= m ) dp[i][j] = ( dp[i][j] + dp[i-1][j+1] ) % mod;
			}
		}
		else {
			if ( a[i] - 1 >= 1 ) dp[i][a[i]] = ( dp[i][a[i]] + dp[i-1][a[i]-1] ) % mod;
			dp[i][a[i]] = ( dp[i][a[i]] + dp[i-1][a[i]] ) % mod;
			if ( a[i] + 1 <= m ) dp[i][a[i]] = ( dp[i][a[i]] + dp[i-1][a[i]+1] ) % mod;
		}
	}
 
	long long res = 0;
 
	for ( int i = 1; i <= m; i++ ) res = ( res + dp[n-1][i] ) % mod;
 
	cout << res << "\n";
 
	return 0;
}