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

class SegmentTree {
	private:
		vector<int> tree;
		int n;
	
		void build(const vector<int>& arr, int node, int start, int end) {
			if (start == end) {
				tree[node] = arr[start];
			} else {
				int mid = (start + end) / 2;
				build(arr, 2 * node, start, mid);
				build(arr, 2 * node + 1, mid + 1, end);
				tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Changed min to max
			}
		}
	
		int query(int node, int start, int end, int l, int r) {
			if (r < start || end < l) {
				return INT_MIN; // Changed INT_MAX to INT_MIN for max query
			}
			if (l <= start && end <= r) {
				return tree[node];
			}
			int mid = (start + end) / 2;
			int left = query(2 * node, start, mid, l, r);
			int right = query(2 * node + 1, mid + 1, end, l, r);
			return max(left, right); // Changed min to max
		}
	
		void update(int node, int start, int end, int idx, int val) {
			if (start == end) {
				tree[node] = val;
			} else {
				int mid = (start + end) / 2;
				if (start <= idx && idx <= mid) {
					update(2 * node, start, mid, idx, val);
				} else {
					update(2 * node + 1, mid + 1, end, idx, val);
				}
				tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Changed min to max
			}
		}
	
	public:
		SegmentTree(const vector<int>& arr) {
			n = arr.size();
			tree.resize(4 * n);
			build(arr, 1, 0, n - 1);
		}
	
		int queryRange(int l, int r) {
			return query(1, 0, n - 1, l, r);
		}
	
		void updateValue(int idx, int val) {
			update(1, 0, n - 1, idx, val);
		}
};
int main(){
    int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	SegmentTree segtree(a);

	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<segtree.queryRange(l-1,r-1)<<nl;
	}
}