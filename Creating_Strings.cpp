#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	vector<char> v;

	for ( int i = 0; i < s.size(); i++ ) v.push_back( s[i] );

	sort( v.begin(), v.end() );

	vector<string> vs;

	do {
		string r;
		for ( auto u : v ) r += u;
		vs.push_back( r );
	} while ( next_permutation( v.begin(), v.end() ) );

	cout << vs.size() << "\n";
	for ( auto u : vs ) cout << u << "\n";

	return 0;
}