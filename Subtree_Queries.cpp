#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 10;

ll n, q, timer = 1;
vector<ll> vals( N );
vector<ll> adj[N];
vector<ll> vis( N, 0 ), in( N ), out( N );
vector<ll> seq, tot, pos( N );

void dfs( ll u )
{
    seq.push_back( u );
    tot.push_back( vals[u] );
    vis[u] = 1;
    in[u] = timer++;
   
    for ( ll v : adj[u] ) {
        if ( !vis[v] ) dfs( v );
    }
   
    out[u] = timer;
}

struct FenwickTree {
    std::vector<ll> bit;
    std::vector<ll> arr; 
    ll n;

    void init(ll size) {
        n = size;
        bit.assign(n + 1, 0);
        arr.assign(n + 1, 0);
    }

    void add(ll i, ll delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & (-i); 
        }
    }

    void modify(ll i, ll new_val) {
        ll delta = new_val - arr[i]; 
        arr[i] = new_val;             
        add(i, delta);                
    }

    // Returns prefix sum from index 1 to i
    ll query(ll i) {
        ll sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }

    // Returns sum in range [left, right]
    ll range_query(ll left, ll right) {
        return query(right) - query(left - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    cin >> n >> q;
   
    for ( int i = 1; i <= n; i++ ) cin >> vals[i];
   
    for ( int i = 1, u, v; i < n; i++ ) {
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
   
    dfs( 1 );
   
    for ( int i = 1; i <= n; i++ ) pos[seq[i-1]] = i; 
   
    // for ( int i = 1; i <= n; i++ ) cout << pos[i] << " ";
    // cout << "\n";

    // for ( int i = 1; i <= n; i++ ) {
    //     cout << i << " -> " << in[i] << " " << out[i] << "\n";
    // }
   
    FenwickTree tree;
    tree.init( n );

    for ( int i = 1; i <= n; i++ ) {
        tree.modify( i, tot[i-1] );
    }
   
    while ( q-- ) {
        ll tp, u, x;
        cin >> tp >> u;
       
        ll idx = pos[u];
       
        if ( tp == 1 ) {
            cin >> x;
            tree.modify( idx, x );
        }
        else cout << tree.range_query( in[u], out[u]-1 ) << "\n";
    }
   
    return 0;
}