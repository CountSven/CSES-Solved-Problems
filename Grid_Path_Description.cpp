#include<bits/stdc++.h>
using namespace std;

const int n = 7;
int cnt = 0;
string s;

bool vis[n][n];

bool isGood( int i, int j )
{
	return ( 0 <= min( i, j ) && max( i, j ) < n && !vis[i][j] );
}

void dfs( int i, int j, int pos )
{
	if ( ( i == n-1 && j == 0 ) || pos == 48 ) {
		cnt += ( ( i == n-1 && j == 0 ) && pos == 48 );
		return;
	}

	if ( isGood( i+1, j ) && isGood( i-1, j ) && !isGood( i, j+1 ) && !isGood( i, j-1 ) ) return;
	if ( !isGood( i+1, j ) && !isGood( i-1, j ) && isGood( i, j+1 ) && isGood( i, j-1 ) ) return;

	vis[i][j] = true;

	if ( ( s[pos] == '?' || s[pos] == 'R' ) && isGood( i, j+1 ) ) dfs( i, j+1, pos+1 );
	if ( ( s[pos] == '?' || s[pos] == 'L' ) && isGood( i, j-1 ) ) dfs( i, j-1, pos+1 );
	if ( ( s[pos] == '?' || s[pos] == 'D' ) && isGood( i+1, j ) ) dfs( i+1, j, pos+1 );
	if ( ( s[pos] == '?' || s[pos] == 'U' ) && isGood( i-1, j ) ) dfs( i-1, j, pos+1 );

	vis[i][j] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	
	dfs( 0, 0, 0 );

	cout << cnt << "\n";

	return 0;
}