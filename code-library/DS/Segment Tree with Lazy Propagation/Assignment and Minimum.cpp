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
    vector<ll> values;

    ll NEUTRAL_ELEMENT = MAX - 1;
    ll NO_OPERATION = MAX;

    ll modify_op(ll a, ll b, ll len){
        if(b == NO_OPERATION){
            return a;
        }
        return b;
    }

    ll calc_op(ll a, ll b){
        return min(a, b);
    }

    void apply_mod_op(ll &a, ll b, ll len){
        a = modify_op(a, b, len);
    }

    void propagate(ll x, ll lx, ll rx){
        if(lx == rx){
            return;
        }
        ll m = (lx + rx) / 2;
        apply_mod_op(operations[2 * x + 1], operations[x], 1);
        apply_mod_op(values[2 * x + 1], operations[x], m - lx + 1);
        apply_mod_op(operations[2 * x + 2], operations[x], 1);
        apply_mod_op(values[2 * x + 2], operations[x], rx - (m + 1) - 1);
        operations[x] = NO_OPERATION;
    }

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        operations.assign(2 * size, 0);
        values.assign(2 * size, 0);
    }

    void modify(ll l, ll r, ll v, ll x, ll lx, ll rx){
        propagate(x, lx, rx);
        if(l <= lx && rx <= r){
            apply_mod_op(operations[x], v, 1);
            apply_mod_op(values[x], v, rx - lx + 1);
            return; 
        }
        if(r < lx || rx < l){
            return;
        }
        ll m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m + 1, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }

    void modify(ll l, ll r, ll v){
        modify(l, r, v, 0, 0, size - 1);
    }

    ll calc(ll l, ll r, ll x, ll lx, ll rx){
        propagate(x, lx, rx);
        if(l <= lx && rx <= r){
            return values[x];
        }
        if(r < lx || rx < l){
            return NEUTRAL_ELEMENT;
        }
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m + 1, rx);
        return calc_op(s1, s2);
    }

    ll calc(ll l, ll r){
        return calc(l, r, 0, 0, size - 1);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	ll n, m, op, l, r, v;
    cin >> n >> m;

    segTree st;
    st.init(n + 1);

    while(m--){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> v;
            st.modify(l, r - 1, v);
        }
        else{
            cin >> l >> r;
            cout << st.calc(l, r - 1) << endl;
        }
    }
}

// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/E