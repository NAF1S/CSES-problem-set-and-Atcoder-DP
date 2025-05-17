#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl "\n"

const ll MOD = 1e9+7;

ll power(ll a, ll b, ll mod) {
    ll result = 1;
    while(b > 0) {
        if(b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

ll inverse(ll a) {
    return power(a, MOD-2, MOD);  // Using Fermat's Little Theorem
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    const int MAXN = 1000001;
    ll fact[MAXN];
    ll inv_fact[MAXN];
    
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[MAXN-1] = inverse(fact[MAXN-1]);
    for(int i = MAXN-2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
    
    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        
        if(a < b || a < 0 || b < 0) {
            cout << 0 << nl;
            continue;
        }
        
        ll ans = fact[a];
        ans = (ans * inv_fact[b]) % MOD;
        ans = (ans * inv_fact[a-b]) % MOD;
        cout << ans << nl;
    }
    
    return 0;
}
