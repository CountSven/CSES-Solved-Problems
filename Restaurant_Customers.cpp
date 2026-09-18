#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for ( auto &[x, y] : v ) cin >> x >> y;

	sort( v.begin(), v.end() );

	ordered_set<int> ost;

	int res = 1;

	for ( auto [x, y] : v ) {
		int cur = ost.size() - ost.order_of_key( x );
		cur++;
		// cout << x << " " << cur << "\n";
		res = max( res, cur );
		ost.insert( y );
	}

	cout << res << "\n";

	return 0;
}