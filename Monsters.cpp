#include<bits/stdc++.h>
using namespace std;
 
int n, m, stI, stJ, f = 0;
char c[1001][1001];
vector<pair<int, int>> pos, res;
vector<vector<int>> dist( 1001, vector<int>(1001, 1e9) );
vector<vector<int>> distH( 1001, vector<int>(1001, 1e9) );
map<pair<int, int>, pair<int, int>> par;
 
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };
 
void bfs()
{
    queue<pair<int, int>> q;

    for ( auto [i, j] : pos ) {
        q.push( { i, j } );
        dist[i][j] = 0;
    }
    
    while ( !q.empty() ) {
        auto [x, y] = q.front();
        q.pop();
        
        for ( int z = 0; z < 4; z++ ) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if ( nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] == '.' ) {
                if ( dist[nx][ny] > dist[x][y] + 1 ) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push( { nx, ny } );
                }
            }
        }
    }
}
 
void bfs1()
{
    queue<pair<int, int>> q;
    q.push( { stI, stJ } );
    distH[stI][stJ] = 0;
    
    while ( !q.empty() ) {
        auto [x, y] = q.front();
        q.pop();

        if ( x == 0 || x == n-1 || y == 0 || y == m-1 ) {
            pair<int, int> cur = { x, y };
            res.push_back( cur );
            while ( cur != make_pair( stI, stJ ) ) {
                cur = par[cur];
                res.push_back( cur );
            }
            f = 1;
            return;
        }
        
        for ( int z = 0; z < 4; z++ ) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if ( nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] == '.' ) {
                if ( distH[nx][ny] > distH[x][y] + 1 ) {
                    if ( dist[nx][ny] > distH[x][y] + 1 ) {
                        distH[nx][ny] = distH[x][y] + 1;
                        par[{ nx, ny }] = { x, y }; 
                        q.push( { nx, ny } );
                    }
                }
            }
        }
    }
}

 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
    cin >> n >> m;
    
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            cin >> c[i][j];
            if ( c[i][j] == 'A' ) {
                stI = i;
                stJ = j;
            }
            else if ( c[i][j] == 'M' ) pos.push_back( { i, j } );
        }
    }

    bfs();
    
    bfs1();

    if ( stI == 0 || stI == n-1 || stJ == 0 || stJ == m-1 ) cout << "YES" << "\n" << 0 << "\n";
    else if ( !f ) cout << "NO" << "\n";
    else {
        reverse( res.begin(), res.end() );

        string s = "";

        int lastI= -1, lastJ = -1;

        for ( auto [i, j] : res ) {
            if ( lastI == -1 ) lastI = i, lastJ = j;
            else {
                if ( j - lastJ == 1 ) s += 'R';
                else if ( lastJ - j == 1 ) s += 'L';
                else if ( i - lastI == 1 ) s += 'D';
                else s += 'U';
                lastI = i, lastJ = j;  
            }
        }

        cout << "YES" << "\n";
        cout << s.size() << "\n";
        cout << s << "\n";
    }
    
 
	return 0;
}