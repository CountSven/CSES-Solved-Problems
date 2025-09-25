#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	map<char, int> mp;

	for ( int i = 0; i < s.size(); i++ ) mp[s[i]]++;

	int cntOdd = 0;

	for ( auto u : mp ) {
		if ( u.second % 2 ) cntOdd++;
	}

	if ( cntOdd > 1 ) cout << "NO SOLUTION" << "\n";
	else {
		string r1, r2, rM;

		for ( auto u : mp ) {
			if ( u.second % 2 ) {
				int mTot = u.second;
				char m = u.first;
				while ( mTot-- ) rM += m;
			}
			else {
				int flTot = u.second / 2;
				char fl = u.first;
				while ( flTot-- ) r1 += fl;
			}
		}

		r2 = r1;

		reverse( r2.begin(), r2.end() );

		string res = r1 + rM + r2;

		cout << res << "\n";
	}

	return 0;
}