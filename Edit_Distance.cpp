#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cin >> s >> t;

	int n = s.size(), m = t.size();

	int dp[n+1][m+1];

	for ( int i = 0; i <= n; i++ ) dp[i][0] = i;
	for ( int j = 0; j <= m; j++ ) dp[0][j] = j;

	s = '#' + s;
	t = '#' + t;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			int cost = s[i] != t[j];
			dp[i][j] = min( { dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost } );
		}
	}

	cout << dp[n][m] << "\n";

	return 0;
}