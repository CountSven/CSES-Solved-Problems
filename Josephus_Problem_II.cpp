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

	int n, k;
	cin >> n >> k;

	ordered_set<int> ost;

	for ( int i = 1; i <= n; i++ ) ost.insert( i );

	int cur = 0;
	
	while ( ost.size() ) {
		cur = ( cur + k ) % (int)ost.size();
		auto it = ost.find_by_order( cur );
		cout << *it << " ";
		ost.erase( it );
	}
	cout << "\n";

	return 0;
}