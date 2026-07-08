#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int n, m;
vector<int> adj[N];
vector<int> dp( N, 0 ), par( N, -1 );
 
// void dfs( int v )
// {
//     vis[v] = 1;
//     for ( int u : adj[v] ) {
//         if ( !vis[u] ) {
//             if ( dp[u] < dp[v] + 1 ) {
//                 dp[u] = dp[v] + 1;
//                 par[u] = v;
//                 dfs( u );
//             }
//         }
//     }
// }
 
void dfs1( int v )
{
    if ( !dp[v] ) return;
    for ( int u : adj[v] ) {
        if ( dp[u] < dp[v] + 1 ) {
            dp[u] = dp[v] + 1;
            par[u] = v;
        }
    }
}
 
vector<bool> visited;
vector<int> ans;
 
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for ( int i = 0, a, b; i < m; i++ ) {
        cin >> a >> b;
        adj[a].push_back( b );
    }
    
    // dfs( 1 );
    
    visited.assign(N, false);
    ans.clear();
    for ( int i = 1; i <= n; i++ ) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse( ans.begin(), ans.end() );
    
    // for ( auto u : ans ) cout << u << " ";
    // cout << "\n";
    
    dp[1] = 1;
    
    for ( auto v : ans ) {
        dfs1( v );
    }
    
    // for ( int i = 1; i <= n; i++ ) cout << dp[i] << " ";
    // cout << "\n";
    // for ( int i = 1; i <= n; i++ ) cout << par[i] << " ";
    // cout << "\n";
    
    if ( dp[n] == 0 ) cout << "IMPOSSIBLE" << "\n";
    else {
        int cur = n;
        vector<int> path;
        
        while ( cur != -1 ) {
            path.push_back( cur );
            cur = par[cur];
        }
        
        reverse( path.begin(), path.end() );
        cout << (int)path.size() << "\n";
        for ( auto u : path ) cout << u << " ";
        cout << "\n";
    }
    
    return 0;
}