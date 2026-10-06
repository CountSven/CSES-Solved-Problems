#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	map<long long, int> mp;

	mp[0LL] = 1;

	long long sum = 0, cnt = 0;

	for ( int i = 0, val; i < n; i++ ) {
		cin >> val;
		sum = ( sum + val ) % n;
		sum = ( sum + n ) % n;
		cnt += mp[sum];
		mp[sum]++;
	}

	cout << cnt << "\n";

	return 0;
}