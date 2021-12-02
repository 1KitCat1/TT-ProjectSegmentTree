#include <bits/stdc++.h>
/*Author: _KitCat_*/
/*Riabtsev Denis*/

#pragma GCC optimize ("O3")

#define ll long long
#define pii pair<long long, long long>
#define vi vector<long long>
#define pb push_back
#define mp make_pair
#define um unordered_map
#define iospeed cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#define fin for(int i = 0; i < n; i++)
#define rep(a,b,c) for(int a = b; a < c; a++)
#define TESTS int tests; cin >> tests; while(tests--)
#define nl '\n'
#define print(STRUCT) for(auto VALUE : STRUCT) cout << VALUE << ' '; cout << endl;
#define all(x) x.begin(), x.end()
#define int long long
#define f first
#define s second

using namespace std;
struct Comparator{
    bool operator() (const pair<int, int>& lhs,const pair<int, int>& rhs) const{
      if (lhs.first == rhs.first) return lhs.second < rhs.second;
      return lhs.first < rhs.first;
  }
  	bool operator() (int a, int b) const {return a > b;}      
};

struct stree{
	int n;
	vector<int> tree;
	vector<int> pushMem;
	const int inf = 999999999;
	
	stree(int n){
		tree.resize(4*n);
		pushMem.resize(4*n, 0);
	}
	void build(vi& arr, int v = 0, int l = 0, int r = -1){
		if(r == -1) r = arr.size()-1;
		// push[v] = 0;
		if(l == r) {
			tree[v] = arr[l];
			return;
		}
		int mid = (l+r) / 2;
		build(arr, 2*v + 1, l, mid);
		build(arr, 2*v + 2, mid+1, r);
		tree[v] = min(tree[2*v+1], tree[2*v+2]);
	}
	void push(int v, int l, int r){
		// int mid = (l + r) / 2;
		tree[2*v+1] += pushMem[v];
		tree[2*v+2] += pushMem[v];
		pushMem[2*v+1] += pushMem[v];
		pushMem[2*v+2] += pushMem[v];
		pushMem[v] = 0;
	}
	void change(int l, int r, int val, int v = 0, int vL = 0, int vR = -1){
		if(vR == -1) vR = tree.size() / 4 - 1;
		if(vR < l || vL > r) return;
		if(vL >= l && vR <= r){
			tree[v] += val;
			pushMem[v] += val;
			return;
		}
		// cout << v << ' ' << vL << ' ' << vR << endl;
		push(v, vL, vR);
		int mid = (vL+vR) / 2;
		change(l, r, val, 2*v+1, vL, mid);
		change(l, r, val, 2*v+2, mid + 1, vR);
		tree[v] = min(tree[2*v+1], tree[2*v+2]);
	}
	int get(int l, int r, int v = 0, int vL = 0, int vR = -1){
		if(vR == -1) vR = tree.size() / 4 - 1;
		// cout << v << ' ' << vL << ' ' << vR << endl;
		if(vR < l || vL > r) return inf;
		if(vL >= l && vR <= r){
			return tree[v];
		}
		push(v, vL, vR);
		int mid = (vL + vR) / 2;
		return min(get(l, r, 2*v+1, vL, mid), get(l, r, 2*v+2, mid + 1, vR));
	}
};


void solve(){

}

signed main() {
	iospeed;
	TESTS
		solve();
	

	return 0;
}