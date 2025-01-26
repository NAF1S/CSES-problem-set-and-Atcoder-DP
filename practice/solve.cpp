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
using p = pair<int, int>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

const int N = 21;
ll dp[100006];



int main(){
    ll k;cin>>k;
    string s = "";
    for(int i=1;i<=100000;i++){
        s += 'c';
    }
    for(int i=1;i<=100000;i++){
        s += 'o';
    }
    for(int i=1;i<=100000;i++){
        s += 'd';
    }
    for(int i=1;i<=100000;i++){
        s += 'e';
    }
    for(int i=1;i<=100000;i++){
        s += 'f';
    }
    for(int i=1;i<=100000;i++){
        s += 'o';
    }
    for(int i=1;i<=100000;i++){
        s += 'r';
    }
    for(int i=1;i<=100000;i++){
        s += 'c';
    }
    for(int i=1;i<=100000;i++){
        s += 'e';
    }
    for(int i=1;i<=100000;i++){
        s += 's';
    }
    cout<<s;
}