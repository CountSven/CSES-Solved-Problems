#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	int c[n+1], dp[x+1];

	for ( int i = 1; i <= n; i++ ) cin >> c[i];

	memset( dp, 0x3f, sizeof( dp ) );

	dp[0] = 0;

	for ( int i = 1; i <= x; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( i - c[j] >= 0 ) dp[i] = min( dp[i], dp[i - c[j]] + 1 );
		}
	}

	if ( dp[x] == 0x3f3f3f3f ) dp[x] = -1;

	cout << dp[x] << "\n";

	return 0;
}