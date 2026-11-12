#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int a[n+1], b[m+1], dp[n+1][m+1];

	for ( int i = 1; i <= n; i++ ) cin >> a[i];
	
	for ( int i = 1; i <= m; i++ ) cin >> b[i];

	memset( dp, 0, sizeof( dp ) );

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
			if ( a[i] == b[j] ) dp[i][j] = max( dp[i][j], dp[i - 1][j - 1] + 1 ); 
		}
	}

	// for ( int i = 0; i <= n; i++ ) {
	// 	for ( int j = 0; j <= m; j++ ) cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	vector<int> res;

	for ( int i = n, j = m; i > 0 && j > 0; ) {
		if ( dp[i][j] == dp[i - 1][j] ) i--;
		else if ( dp[i][j] == dp[i][j - 1] ) j--;
		else {
			res.push_back( a[i] );
			i--;
			j--;
		}
	}

	reverse( res.begin(), res.end() );

	cout << dp[n][m] << "\n";
	for ( int i = 0; i < res.size(); i++ ) cout << res[i] << " \n"[i == res.size() - 1];

	return 0;
}