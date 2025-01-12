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

struct item{
    ll mask;
};

struct segTree{

    ll size;
    vector<item> values;

    item NEUTRAL_ELEMENT = item({0});

    item merge(item a, item b){
        return item({a.mask | b.mask});
    }

    item single(ll v){
        return {((ll)1 << v)};
    }

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        values.resize(2 * size);
    }
    
    void build(vector<ll> &a, ll x, ll lx, ll rx){
        if(lx == rx){
            if(lx < (ll)a.size()){
                values[x] = single(a[lx]);
            }
            else{
                values[x] = NEUTRAL_ELEMENT;
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m + 1, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<ll> &a){
        build(a, 0, 0, size - 1);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(lx == rx){
            values[x] = single(v);
            return;
        }
        ll m = (lx + rx) / 2;
        if(i <= m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m + 1, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size - 1);
    }

    item calc(ll l, ll r, ll x, ll lx, ll rx){
        if(l <= lx && rx <= r){
            return values[x];
        }
        if(r < lx || rx < l){
            return NEUTRAL_ELEMENT;
        }
        ll m = (lx + rx) / 2;
        item s1 = calc(l, r, 2 * x + 1, lx, m);
        item s2 = calc(l, r, 2 * x + 2, m + 1, rx);
        return merge(s1, s2);
    }
    
    item calc(ll l, ll r){
        return calc(l, r, 0, 0, size - 1);
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, i, op, m, l, r, v;
    cin >> n >> m;

    vector<ll> a(n);
    segTree st;
    st.init(n + 1);

    for(i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    st.build(a);

    while(m--){
        cin >> op;
        if(op == 2){
            cin >> i >> v;
            i--;
            st.set(i, v);
        }
        else{
            cin >> l >> r;
            auto s = st.calc(l - 1, r - 1);
            cout << __builtin_popcountll(s.mask) << endl;
        }
    }   
}

// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/D