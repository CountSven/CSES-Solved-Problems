#include<bits/stdc++.h>
using namespace std;

void tOfH( int n, int t1, int t3, int t2 )
{
	if ( n > 0 ) {
		tOfH( n-1, t1, t2, t3 );
		cout << t1 << " " << t3 << "\n";
		tOfH( n-1, t2, t3, t1 );
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int t1 = 1, t2 = 2, t3 = 3;

	cout << pow(2, n) - 1 << "\n";

	tOfH( n, t1, t3, t2 );

	return 0;
}