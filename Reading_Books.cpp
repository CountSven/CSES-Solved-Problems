#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long sum = 0;
	int mx = 0;

	for ( int i = 0, x; i < n; i++ ) {
		cin >> x;
		sum += x;
		mx = max( mx, x );
	}

	cout << max( sum, 2LL * mx ) << "\n";

	return 0;
}