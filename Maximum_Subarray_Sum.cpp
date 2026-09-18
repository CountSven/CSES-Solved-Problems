#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long cur = -2e18, best = -2e18, x;

	for ( int i = 0; i < n; i++ ) {
		cin >> x;
		cur = max( cur + x, x );
		best = max( best, cur );
	}

	cout << best << "\n";

	return 0;
}