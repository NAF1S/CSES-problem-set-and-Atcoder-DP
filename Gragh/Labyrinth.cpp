#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define pb push_back
#define pi acos(-1)
#define fi first
#define se second
#define lightSpeed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int dirx[] = {0, 0, 1, -1};  // Directions: Left, Right, Down, Up
int diry[] = {-1, 1, 0, 0};
//char moveChar[] = {'L', 'R', 'D', 'U'};

using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using p = pair<int, int>;

const ll inf = 1e18;
const ll mod = 1e9 + 7;



const int N = 1000;
char Grid[N+1][N+1], parent[N+1][N+1];
bool vis[N+1][N+1];
int n, m;
 
bool inside(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    if(vis[i][j] || Grid[i][j] == '#')return false;
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> Grid[i][j];
    }
  }
  int l, r, _l, _r; //Store the position of start and end
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(Grid[i][j] == 'A')l = i, r = j;
        if(Grid[i][j] == 'B')_l = i, _r = j;
    }
  }
  queue<pair<int, int>> q;
  q.push({l ,r});
  vis[l][r] = true;
  bool ok = false;
  while(!q.empty()) {
    auto now = q.front();
    int i = now.first;
    int j = now.second;
    if(i == _l && j == _r) {
        ok = true;
        break;
    }
    q.pop();
    if(inside(i+1, j)) {
        vis[i+1][j] = true;
        q.push({i+1, j});
        parent[i+1][j] = 'D';
    }
    if(inside(i, j+1)) {
        q.push({i, j+1});
        vis[i][j+1] = true;
        parent[i][j+1] = 'R';
    }
    if(inside(i-1, j)) {
        q.push({i-1, j});
        vis[i-1][j] = true;
        parent[i-1][j] = 'U';
    }
    if(inside(i, j-1)) {
        q.push({i, j-1});
        vis[i][j-1] = true;
        parent[i][j-1] = 'L';
    }
  }
  string ans = "";
  if(!ok) {
    cout << "NO\n";
    return 0;
  }
  while(1) {
    if(l == _l && r == _r)break;
    ans+=parent[_l][_r];
    if(parent[_l][_r] == 'L') {
        _r++;
    }else if(parent[_l][_r] == 'R') {
        _r--;
    }
    else if(parent[_l][_r] == 'U') {
        _l++;
    }
    else if(parent[_l][_r] == 'D') {
        _l--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "YES" << "\n" << ans.size() << "\n" << ans << "\n";
  return 0;
}