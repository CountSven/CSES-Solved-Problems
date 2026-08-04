#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while ( q-- ) {
		ll k;
		cin >> k;
		ll cnt = 9, val = 1;

		for ( ll len = 1; ; len++ ) {
			ll cur = cnt * len;
			if ( k > cur ) {
				k -= cur;
				val += cnt;
			}
			else {
				ll rem = ( k - 1 ) / len;
				k -= ( rem * len );
				val += rem;
				// cout << val << " " << k << "\n";
				string s = to_string( val );
				cout << s[k - 1] << "\n";
				break;
			}
			cnt *= 10;
		}
	}

	return 0;
}