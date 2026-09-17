#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<int> st;

	for ( int i = 0, x; i < n; i++ ) {
		cin >> x;
		st.insert( x );
	}

	cout << st.size() << "\n";

	return 0;
}