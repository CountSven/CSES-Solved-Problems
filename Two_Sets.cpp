#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	long long sum = ( n * ( n + 1 ) ) / 2;

	if ( sum % 2 ) cout << "NO" << "\n";
	else if ( n == 3 ) {
		cout << "YES" << "\n";
		cout << 2 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << 1 << "\n";
		cout << 3 << "\n";
	}
	else {
		deque<long long> dq(n), d;

		for ( long long i = 0; i < n; i++ ) dq[i] = i + 1;

		long long halfSum = sum / 2;
		long long cnt = 0;

		while ( cnt != halfSum ) {
			if ( cnt != halfSum ) {
				d.push_back( dq.back() );
				cnt += dq.back();
				dq.pop_back();
			}
			if ( cnt != halfSum ) {
				d.push_front( dq.front() );
				cnt += dq.front();
				dq.pop_front();
			}
		}
		
		cout << "YES" << "\n";
		cout << d.size() << "\n";
		for ( auto u : d ) cout << u << " ";
		cout << "\n";
		cout << dq.size() << "\n";
		for ( auto u : dq ) cout << u << " ";
		cout << "\n";
	}

	return 0;
}