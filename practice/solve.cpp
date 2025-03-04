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

const int MAX_N = 1000000;
vector<int> cnt_div[MAX_N + 1];
bool isPerfectSquare[MAX_N + 1]; // Explicitly initialized to false

void preprocess() {
    // Mark perfect squares
    for (int i = 1; i * i <= MAX_N; i++) {
        isPerfectSquare[i * i] = true;
    }

    // Precompute divisors
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i) {
            cnt_div[j].pb(i);
        }
    }
}

int main() {
    lightSpeed();
    preprocess();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> chk;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            chk.insert(a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int x : cnt_div[a[i]]) {
                int d = a[i] / x;
                int p = sqrt(d);
                
                // Ensure p is a perfect square without precision issues
                if (p * p == d) {
                    if (chk.count(a[i] / d) && chk.count(a[i] / p)) {
                        ans += 6;
                    }
                }
            }
        }
        cout << ans << nl;
    }
}
