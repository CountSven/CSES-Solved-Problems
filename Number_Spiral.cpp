#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while ( t-- ) {
		int x, y;
		cin >> x >> y;

		long long diag, ans;

		long long mx = max( x, y );

		diag = ( mx * mx ) - ( mx - 1 );

		if ( x == y ) ans = diag;
		else if ( x > y ) {
			if ( x % 2 ) ans = diag - ( x - y );
			else ans = diag + ( x - y );
		}
		else {
			if ( y % 2 ) ans = diag + ( y - x );
			else ans = diag - ( y - x );
		}

		cout << ans << "\n";
	}

	return 0;
}