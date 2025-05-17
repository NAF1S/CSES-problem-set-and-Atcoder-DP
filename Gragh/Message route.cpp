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
// Fixed direction vectors for spiral: right, down, left, up
const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {1, 0, -1, 0};

 vector<int>adj[100005];
 vector<int>vis(100005,-1);



int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int>from(100005,0);

    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u]=1;
        if(u == n){
            break;
        }
        for(int x:adj[u]){
            if(vis[x]==-1){
                vis[x]=1;
                from[x]=u;
                q.push(x);
            }
        }
    }
    vector<int>path;
    if(vis[n]==-1){
        cout<<"IMPOSSIBLE"<<nl;
    }
    else{
        path.pb(n);
        int curr = n;
        while(curr != 1){
            curr = from[curr];
            path.pb(curr);
        }
        cout<<path.size()<<nl;
        reverse(path.begin(),path.end());
        for(int x:path){
            cout<<x<<" ";
        }
    }

    
}