#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 1, maxCnt = 1;

	for ( int i = 1; i < s.size(); i++ ) {
		if ( s[i] == s[i-1] ) {
			cnt++;
			maxCnt = max( maxCnt, cnt );
		}
		else cnt = 1;
	}

	cout << maxCnt << "\n";

	return 0; 
}
