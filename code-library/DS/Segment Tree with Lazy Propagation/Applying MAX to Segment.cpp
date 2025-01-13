#include<bits/stdc++.h>
using namespace std;
 
#define ll              long long int
#define pb              push_back
#define ff              first
#define se              second
#define LOG             25
#define endl            '\n'
#define MAX             2000000000000000000
#define MAXN            300005

struct segTree{
	ll size;
	vector<ll> operations;

	ll operation(ll a, ll b){
		return max(a, b);
	}

	void init(ll n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		operations.assign(2 * size, 0);
	}

	void set(ll l, ll r, ll v, ll x, ll lx, ll rx){
		if(r < lx || rx < l){
			return;
		}
		if(l <= lx && rx <= r){
			operations[x] = operation(operations[x], v);
			return;
		}
		ll m = (lx + rx) / 2;
		set(l, r, v, 2 * x + 1, lx, m);
		set(l, r, v, 2 * x + 2, m + 1, rx);
	}

	void set(ll l, ll r, ll v){
		set(l, r, v, 0, 0, size - 1);
	}

	ll get(ll i, ll x, ll lx, ll rx){
		if(lx == rx){
			return operations[x];
		}
		ll m = (lx + rx) / 2, res;
		if(i <= m){
			res = get(i, 2 * x + 1, lx, m);
		}
		else{
			res = get(i, 2 * x + 2, m + 1, rx);
		}
		return operation(res, operations[x]);
	}

	ll get(ll i){
		return get(i, 0, 0, size - 1);
	}

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m, op, l, r, v, i;
	cin >> n >> m;
	
	segTree st;
	st.init(n + 1);

	while(m--){
		cin >> op;
		if(op == 1){
			cin >> l >> r >> v;
			st.set(l, r - 1, v);
		}
		else{
			cin >> i;
			cout << st.get(i) << endl;
		}
	}
}

// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B