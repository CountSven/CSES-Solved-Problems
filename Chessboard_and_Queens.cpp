#include<bits/stdc++.h>
using namespace std;

const int n = 8;
char c[n+5][n+5];
vector<int> cols( n+5, 0 ), diag1( 2*n+5, 0 ), diag2( 2*n+5, 0 );
int cnt = 0;

void solve( int row )
{
	if ( row == n ) {
		cnt++;
		return;
	}

	for ( int col = 0; col < n; col++ ) {
		int d1 = row - col + n;
		int d2 = row + col;
		if ( c[row][col] != '*' && !cols[col] && !diag1[d1] && !diag2[d2] ) {
			cols[col] = 1;
			diag1[d1] = 1;
			diag2[d2] = 1;
			solve( row + 1 );
			cols[col] = 0;
			diag1[d1] = 0;
			diag2[d2] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) cin >> c[i][j];
	}

	solve( 0 );

	cout << cnt << "\n";

	return 0;
}