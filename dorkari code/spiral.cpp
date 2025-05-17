#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl "\n"

#define pb push_back
#define fi first
#define se second
#define fastIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 998244353;
const int N = 2e5+1;
// Direction vectors for spiral: right, down, left, up
const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {1, 0, -1, 0};
vector<int>t[100001];
bool vis[100001];
vector<int>c(100001);
vector<int>cnt[300005];

int main(){
    fastIO();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        // Create grid using vector
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        // Start position - modified for even values
        int x_md, y_md;
        if(n & 1){
            // For odd n, start at true center
            x_md = n/2;
            y_md = n/2;
        }
        else{
            // For even n, start slightly off center
            x_md = n/2 - 1;
            y_md = n/2 - 1;
        }
        
        grid[x_md][y_md] = 0;
        int num = 1;
        int st = 1;
        int way = 0;
        
        while(num < n*n){
            for(int i = 0; i < 2 && num < n*n; i++){
                for(int j = 0; j < st && num < n*n; j++){
                    x_md += dx[way];
                    y_md += dy[way];
                    if(x_md >= 0 && x_md < n && y_md >= 0 && y_md < n){
                        grid[x_md][y_md] = num++;
                    }
                }
                way = (way + 1) % 4;
            }
            st++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] << " ";
            }
            cout << nl;
        }
    }
    return 0;
}

// Alternative implementation with better handling
void betterImplementation(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        // Direction vectors: right, down, left, up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Start position based on n
        int x, y;
        if(n % 2 == 1){
            // Odd n: start at center
            x = y = n/2;
        }
        else{
            // Even n: start at slightly offset position
            x = n/2 - 1;
            y = n/2 - 1;
        }
        
        grid[x][y] = 0;
        
        int num = 1;
        int steps = 1;
        int dir = 0;
        
        while(num < n*n) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < steps && num < n*n; j++) {
                    x += dx[dir];
                    y += dy[dir];
                    
                    if(x >= 0 && x < n && y >= 0 && y < n) {
                        grid[x][y] = num++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << grid[i][j];
                if(j < n-1) cout << " ";
            }
            cout << nl;
        }
    }
}