#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int a[n+2], prev[n+2], next[n+2];
    
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    
    a[0] = a[n+1] = -1;
    
    stack<int> st;
    
    st.push( 0 );
    
    for ( int i = 1; i <= n; i++ ) {
        while ( st.size() && a[st.top()] >= a[i] ) st.pop();
        prev[i] = st.top();
        st.push( i );
    }
    
    while ( st.size() ) st.pop();
    
    st.push( n+1 );
    
    for ( int i = n; i >= 1; i-- ) {
        while ( st.size() && a[st.top()] >= a[i] ) st.pop();
        next[i] = st.top();
        st.push( i );
    }

    // for ( int i = 1; i <= n; i++ ) cout << prev[i] << " ";
    // cout << "\n";
    // for ( int i = 1; i <= n; i++ ) cout << next[i] << " ";
    // cout << "\n";

    long long res = 0;
    
    for ( int i = 1; i <= n; i++ ) {
        long long cur = next[i] - prev[i] - 1;
        cur *= 1LL * a[i];
        res = max( res, cur );
    }
    
    cout << res << "\n";
    
    return 0;
}