#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;

	while ( n ) {
		int tmp = n, mx = 0;
		while ( tmp ) {
			mx = max( mx, tmp % 10 );
			tmp /= 10;
		}
		n -= mx;
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}