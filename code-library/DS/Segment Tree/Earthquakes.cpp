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
    ll val;
};

struct segTree{

    ll size;
    vector<item> values;

    item NEUTRAL_ELEMENT = {MAX};

    item merge(item a, item b){
        return {min(a.val, b.val)};
    }

    item single(ll v){
        return {v};
    }

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        values.assign(2 * size, NEUTRAL_ELEMENT);
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

    item first_above(ll l, ll r, ll v, ll x, ll lx, ll rx){
        if(values[x].val > v){
            return {-1};
        }
        if(r < lx || rx < l){
            return {-1};
        }
        if(lx == rx){
            return {lx};
        }
        ll m = (lx + rx) / 2;
        item res = first_above(l, r, v, 2 * x + 1, lx, m);
        if(res.val == -1){
            res = first_above(l, r, v, 2 * x + 2, m + 1, rx);
        }
        return res;
    }
    
    item first_above(ll l, ll r, ll v){
        return first_above(l, r, v, 0, 0, size - 1);
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, i, op, m, l, r, v, p;
    cin >> n >> m;

    vector<ll> a(n);
    segTree st;
    st.init(n + 1);

    while(m--){
        cin >> op;
        if(op == 1){
            cin >> i >> v;
            st.set(i, v);
        }
        else{
            cin >> l >> r >> p;
            r--;
            ll ans = 0;
            while(l <= r){
                auto s = st.first_above(l, r, p);
                if(s.val == -1){
                    break;
                }
                st.set(s.val, MAX);
                l = s.val;
                ans++;
            }
            cout << ans << endl;
        }
    }   
}

// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E