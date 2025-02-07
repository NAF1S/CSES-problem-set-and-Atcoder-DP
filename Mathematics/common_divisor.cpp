#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl "\n"
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
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int modPow(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (1LL * ans * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans= 0 ;
        
}