#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n+1], left[n+1];

	for ( int i = 1; i <= n; i++ ) cin >> a[i];

	stack<int> st;

	a[0] = INT_MIN;
	st.push( 0 );

	for ( int i = 1; i <= n; i++ ) {
		while ( st.size() && a[st.top()] >= a[i] ) st.pop();
		left[i] = st.top();
		st.push( i ) ;
	}

	for ( int i = 1; i <= n; i++ ) cout << left[i] << " ";
	cout << "\n";

	return 0;
}