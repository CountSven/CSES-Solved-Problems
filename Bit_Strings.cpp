#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	long long res = 1;
	long long mod = 1000000007;

	for ( long long i = 1; i <= n; i++ ) {
		res = ( res * 2 ) % mod;
	}

	cout << res << "\n";

	return 0; 
}