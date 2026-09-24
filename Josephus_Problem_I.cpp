#include<bits/stdc++.h>
using namespace std;

void solve( vector<int>& v )
{
	int sz = v.size();

	if ( sz == 1 ) {
		cout << v[0] << "\n";
		return;
	}

	for ( int i = 1; i < sz; i += 2 ) cout << v[i] << " ";

	vector<int> tmp;

	if ( sz % 2 ) tmp.push_back( v.back() );
	v.pop_back();

	sz = v.size();

	for ( int i = 0; i < sz; i += 2 ) tmp.push_back( v[i] );

	solve( tmp ); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);

	for ( int i = 0; i < n; i++ ) v[i] = i+1;

	solve( v );

	return 0;
}