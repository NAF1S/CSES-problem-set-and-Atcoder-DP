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
const int N = 6e6;
// Fixed direction vectors for spiral: right, down, left, up
const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {1, 0, -1, 0};
vector<int>t[100001];
/*
8 7 6
1 0 5
2 3 4
*/

int main(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>cnt(1000005,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int>div(1000005,0);
    for(int i=1;i<=1000005;i++){
        for(int j=i;j<=1000005;j+=i){
            div[i] += cnt[j];
        }
    }
    vector<int>spf(1000005,1);
    spf[0]=0;
    for(int i=2;i<=1000005;i++){
        if(spf[i]){
            for(int j=i;j<=1000005;j+=i){
                if(spf[j] == 1){
                    spf[j] = i;
                }
            }
        }
    }
    vector<int>pf[n+1];
    for(int i=0;i<n;i++){
        int x = a[i];
        while(x!=1){
            pf[i].pb(spf[x]);
            x /= spf[x];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        set<int>s;
        for(int x:pf[i]){
            s.insert(x);
        }
        vector<int>f;
        for(int x:s){
            f.pb(x);
        }
        int sz = f.size();
        int koto = 0;
        for(int p=1;p<(1<<sz);p++){
            int c=0;
            int mul = 1;
            for(int j=0;j<sz;j++){
                if(p&(1<<j)){
                    c++;
                    mul *= f[j];
                }
            }
            //cout<<mul<<" ";
            if(c&1){
                koto += div[mul];
            }
            else{
                koto -= div[mul];
            }
        }
        //cout<<n-koto<<" ";
        ans += (ll)(n-koto);
    }
    cout<<ans/2<<nl;
    return 0;
}