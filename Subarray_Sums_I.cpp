#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	set<long long> st = { 0LL };

	long long sum = 0, cnt = 0;

	for ( int i = 0, val; i < n; i++ ) {
		cin >> val;
		sum += val;
		cnt += st.count( sum - x );
		st.insert( sum );
	}

	cout << cnt << "\n";

	return 0;
}