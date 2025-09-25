#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> v,r;

	int pwr = pow( 2, n );

	for ( int i = 0; i < pwr; i++ ) {
		string bin = bitset<64>( i ).to_string().substr( 64 - n );
		v.push_back( bin );
	}

	for ( auto u : v ) {
		string bs;
		bs += u[0];

		for ( int i = 0; i < u.size()-1; i++ ) {
			int bit1 = u[i] - '0';
			int bit2 = u[i+1] - '0';
			int xr = bit1 ^ bit2;
			bs += xr + '0';
		}

		r.push_back( bs );
	}

	for ( auto u : r ) cout << u << "\n";

	return 0;
}