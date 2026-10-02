#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for ( auto &[x, y] : v ) cin >> x >> y;

	sort( v.begin(), v.end() );

	long long cur = 0, res = 0;

	for ( auto [x, y] : v ) {
		cur += x;
		res += y - cur;
	}

	cout << res << "\n";

	return 0;
}