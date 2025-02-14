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

const ll inf = 1e18;
const ll mod = 1e9 + 7;

ll pow(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

vector<int>adj[100001];
bool vis[100001];
vector<ll>vor;
int n;

int main() {
    int t;cin>>t;
    while(t--){
        cin>>n;
        vor.resize(n+1);
        for(int i=1;i<=n;i++){
            cin>>vor[i];
        }
        vector<pair<pair<int,int>,ll>>rasta;
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            ll sum = vor[v]+vor[u];
            rasta.pb({{u,v},sum});
        }
        
    }
}
