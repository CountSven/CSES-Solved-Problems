#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for ( long long i = 1; i <= n; i++ ) {
		long long kPos = ( (i * i ) * ( ( i * i ) - 1 ) ) / 2 ;
		long long kGrid = ( 2 * ( i - 2 ) * ( i - 1 ) ) + ( 2 * ( i - 1 ) * ( i - 2 ) );

		long long res = kPos - kGrid;

		cout << res << "\n";
	}

	return 0;
}