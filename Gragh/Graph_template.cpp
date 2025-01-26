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

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using p = pair<int, int>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

const int N = 21;

// normal dfs

vector<int> adj[100005];
bool vis[100005];

void dfs(int node){
    vis[node] = true;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
// dfs on grid
int n, m;
char grid[1005][1005];
bool vis2d[1005][1005];
void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#' || vis2d[i][j]){
        return;
    }
    vis2d[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}




int main(){
    

}