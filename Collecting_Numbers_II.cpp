#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n, m;
int a[N+1], pos[N+1];

int calc( int p, int q )
{
	if ( p > q ) swap( p, q );

	int cnt = 0;

	if ( p > 1 ) {
		if ( pos[p] < pos[p-1] ) cnt++;
	}
	if ( q < n ) {
		if ( pos[q] > pos[q+1] ) cnt++;
	}

	if ( q - p <= 1 ) {
		if ( pos[p] > pos[q] ) cnt++;
	}
	else {
		if ( pos[p] > pos[p+1] ) cnt++;
		if ( pos[q] < pos[q-1] ) cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	int res = 1;

	for ( int i = 2; i <= n; i++ ) {
		if ( pos[i] < pos[i-1] ) res++;
	}

	while ( m-- ) {
		int x, y;
		cin >> x >> y;

		int before = calc( a[x], a[y] );

		swap( pos[a[x]], pos[a[y]] );
		swap( a[x], a[y] );

		int after = calc( a[x], a[y] );

		// cout << before << " " << after << "\n";

		int diff = abs( before - after );

		if ( before > after ) res -= diff;
		else res += diff;

		cout << res << "\n"; 
	}

	return 0;
}