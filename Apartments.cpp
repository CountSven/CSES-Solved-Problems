#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];

	for ( int i = 0; i < n; i++ ) cin >> a[i];
	for ( int i = 0; i < m; i++ ) cin >> b[i];

	sort( a, a+n );
	sort( b, b+m );

	int i = 0, j = 0, cnt = 0;

	while ( i < n && j < m ) {
		if ( abs( a[i] - b[j] ) <= k ) {
			cnt++;
			i++;
			j++;
		}
		else if ( a[i] < b[j] ) i++;
		else j++;
	}

	cout << cnt << "\n";

	return 0;
}