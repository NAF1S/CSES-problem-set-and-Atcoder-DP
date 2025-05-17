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

void solve(){
    ll n,b,c;cin>>n>>b>>c;
    if(b == 0 && c == 0){
        cout<<-1<<nl;
        return;
    }
    if(n==1){
        if(c==0){
            cout<<0<<nl;
        }
        else{
            cout<<1<<nl;
        }
        return;
    }
    if(b == 0){
        // sob element c
        if(c <= n-1){
            cout<<n-1<<nl;
        }
        else{
            cout<<n<<nl;
        }
        return;
    }
    if(c == 0){
        cout<<0<<nl;
        return;
    }
    ll ans = 0;
    ll lo = 1,hi=n;
    while(hi-lo <= 5ll){
        ll m = (hi+lo)/2ll;
        if(b*(m-1ll)+c <= n-1ll){
            lo = m;
        }
        else if(b*(m-1ll)+c > n-1ll){
            hi = m;
        }
    }
    for(ll i = lo;i<=hi;i++){
        if(b*(i-1ll)+c > n-1ll){
            hi=i;
            break;
        }
    }
    ll boro = n-hi+1ll;
    cout<<boro<<nl;

}

int main(){
    fastIO();
    int t;cin>>t;
    while(t--){
        
        solve();
    }
    return 0;
}