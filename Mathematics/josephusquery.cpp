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

int cnt(int n, int kth) {
  if(n == 1) {
    return 1;
  }
  if(kth <= (n+1)/2) {
    if(kth*2 > n)return 1;
    else return kth*2;
  }
  int t_kth = cnt(n/2, kth-(n+1)/2);
  if(n % 2 == 0)return t_kth*2 - 1;
  return t_kth*2 + 1;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<cnt(n,k)<<nl;
    }
}