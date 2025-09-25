#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	long long cnt = 0;

	for ( long long i = 1; i <= n; i++ ) {
		long long mult = pow( 5, i );
		if ( mult <= n ) cnt += n / mult;
		else break;
	}

	cout << cnt << "\n";

	return 0;
}