#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n+1];

	a[0] = 0;

	for ( int i = 1; i <= n; i++ ) cin >> a[i];

	stack<int> st;

	st.push( 0 );

	for ( int i = 1; i <= n; i++ ) {
		while ( a[st.top()] >= a[i] ) st.pop();
		cout << st.top() << " ";
		st.push( i ); 
	}
	cout << "\n";

	return 0;
}