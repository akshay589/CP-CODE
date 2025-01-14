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
    vector<ll> mins;

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        operations.assign(2 * size, 0);
        mins.assign(2 * size, 0);
    }

    void add(ll l, ll r, ll v, ll x, ll lx, ll rx){
        if(l <= lx && rx <= r){
            operations[x] += v;
            mins[x] += v;
            return; 
        }
        if(r < lx || rx < l){
            return;
        }
        ll m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m + 1, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + operations[x];
    }

    void add(ll l, ll r, ll v){
        add(l, r, v, 0, 0, size - 1);
    }

    ll getmin(ll l, ll r, ll x, ll lx, ll rx){
        if(l <= lx && rx <= r){
            return mins[x];
        }
        if(r < lx || rx < l){
            return MAX;
        }
        ll m = (lx + rx) / 2;
        ll s1 = getmin(l, r, 2 * x + 1, lx, m);
        ll s2 = getmin(l, r, 2 * x + 2, m + 1, rx);
        return min(s1, s2) + operations[x];
    }

    ll getmin(ll l, ll r){
        return getmin(l, r, 0, 0, size - 1);
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
            st.add(l, r - 1, v);
        }
        else{
            cin >> l >> r;
            cout << st.getmin(l, r - 1) << endl;
        }
    }
}

// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A