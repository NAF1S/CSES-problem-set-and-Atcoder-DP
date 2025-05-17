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

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ll n;
    cin>>n;
    int k;cin>>k;
    vector<ll>p(k);
    for(int i=0;i<k;i++){
        cin>>p[i];
    }
    ll ans = 0;
    for(int i=0;i<(1<<k);i++){
        int cnt = 0;
        ll mul = n;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                mul /= p[j];
                cnt++;
            }
        }
        //cout<<cnt<<" ";
        if(cnt == 0)continue;
        if(cnt&1){
            ans += mul;
        }
        else{
            ans -= mul;
        }
    }
    cout<<ans<<nl;
}