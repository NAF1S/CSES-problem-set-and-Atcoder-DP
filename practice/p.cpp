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

void readGraph(int m, vector<vector<int>>& g) {
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

vector<bool> findGoodNodes(int n, const vector<vector<int>>& g1, const vector<vector<int>>& g2) {
    vector<bool> good(n + 1, false);
    for (int v = 1; v <= n; ++v) {
        unordered_set<int> s(g2[v].begin(), g2[v].end());
        for (int nb : g1[v]) {
            if (s.count(nb)) {
                good[v] = true;
                break;
            }
        }
    }
    return good;
}

ll findShortestPath(int n, int s1, int s2, const vector<vector<int>>& g1, const vector<vector<int>>& g2, const vector<bool>& good) {
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    dist[s1][s2] = 0;
    
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.push({0, s1, s2});
    
    while (!pq.empty()) {
        auto [d, u, v] = pq.top();
        pq.pop();
        
        if (d != dist[u][v]) continue;
        
        if (u == v && good[u]) return d;
        
        for (int nu : g1[u]) {
            for (int nv : g2[v]) {
                ll nd = d + 1; 
                if (nd < dist[nu][nv]) {
                    dist[nu][nv] = nd;
                    pq.push({nd, nu, nv});
                }
            }
        }
    }
    return -1;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, s1, s2, m1, m2;
        cin >> n >> s1 >> s2 >> m1;
        
        vector<vector<int>> g1(n + 1), g2(n + 1);
        readGraph(m1, g1);
        
        cin >> m2;
        readGraph(m2, g2);
        
        vector<bool> good = findGoodNodes(n, g1, g2);
        ll ans = findShortestPath(n, s1, s2, g1, g2, good);
        
        cout << ans << nl;
    }
}

int main() {
    lightSpeed();
    solve();
    return 0;
}
