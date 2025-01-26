
/*
    Problem: Building Roads
    Link: https://cses.fi/problemset/task/1666
    Solution: 
        We have to find the connected components of the graph and then connect them with roads.
        We can do this by running a dfs from each node and marking all the nodes that are reachable from that node.
        Then we can connect the first node of each connected component with all the other nodes of that component.
        The number of roads will be the number of connected components - 1.
*/


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

void jatra(int s){
    vis[s] = true;
    for(auto x: adj[s]){
        if(!vis[x]){
            jatra(x);
        }
    }
}



int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            jatra(i);
            ans.pb(i);
        }
    }
    if(ans.size() == 1){
        cout<<0<<nl;
    }else{
        cout<<ans.size()-1<<nl;
        for(int i=1;i<ans.size();i++){
            cout<<ans[0]<<" "<<ans[i]<<nl;
        }
    }

}