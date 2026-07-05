#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll V = 1e5 + 5, MOD = 1e9+7;
 
ll n, m;
vector<vector<pair<ll, ll>>> adj(V);
vector<ll> dist(V, 1e18);
vector<ll> dp( V, 0 ), mn( V, 1e18 ), mx( V, -1e18 );
 
void dijkstra( ll src) {
    // Min-heap storing {distance, node}
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,
                   greater<pair<ll,ll>>> pq;
 
    // Distance to source is 0
    dist[src] = 0LL;
 
    // Push source into heap
    pq.push({0LL, src});
    dp[src] = 1;
    mn[src] = 0;
    mx[src] = 0;
 
    // Process nodes until heap is empty
    while (!pq.empty()) {
        // Extract node with minimum distance
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
 
        // Skip if this distance is outdated
        if (d > dist[node]) continue;
 
        // Traverse all adjacent neighbors
        for (auto it : adj[node]) {
            ll next = it.first;
            ll wt = it.second;
 
            // Relaxation check
            if (dist[node] + wt > dist[next]) continue;
            else if ( dist[node] + wt == dist[next] ) {
                dp[next] = ( dp[next] + dp[node] ) % MOD;
                mx[next] = max( mx[next], mx[node] + 1 );
                mn[next] = min( mn[next], mn[node] + 1 );
            }
            else {
                // Update distance
                dist[next] = dist[node] + wt;
                mn[next] = mn[node] + 1;
                mx[next] = mx[node] + 1;
                dp[next] = dp[node];
                pq.push({dist[next], next});
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
 
    for ( int i = 0; i < m; i++ ) {
        ll u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back( { v, d } );
    }
 
    dijkstra( 1 );
 
    cout << dist[n] << " " << dp[n] << " " << mn[n] << " " << mx[n] << "\n";
 
    return 0;
}