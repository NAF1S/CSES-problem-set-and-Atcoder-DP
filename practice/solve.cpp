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
    
}