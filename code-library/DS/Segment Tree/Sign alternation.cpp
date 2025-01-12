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

typedef long long int item;

struct segTree{

    ll size;
    vector<item> values;

    item NEUTRAL_ELEMENT = 0;

    item merge(item a, item b){
        return a + b;
    }

    item single(ll v){
        return v;
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

    item calc(ll l, ll r, ll x, ll lx, ll rx){
        if(l <= lx && rx <= r){
            return values[x];
        }
        if(r < lx || rx < l){
            return NEUTRAL_ELEMENT;
        }
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m + 1, rx);
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

    ll n, i, op, m, l, r, v, val1, val2;
    cin >> n;

    vector<ll> a(n);
    segTree st[2];
    st[0].init(n + 1);
    st[1].init(n + 1);

    for(i = 0 ; i < n ; i++){
        cin >> a[i];
        st[i % 2].set(i, a[i]);
    }

    cin >> m;
    while(m--){
        cin >> op;
        if(op == 0){
            cin >> i >> v;
            i--;
            st[i % 2].set(i, v);
        }
        else{
            cin >> l >> r;
            l--;
            r--;
            val1 = st[0].calc(l, r);
            val2 = st[1].calc(l, r);
            if(l % 2 == 0){
                cout << val1 - val2;
            }
            else{
                cout << val2 - val1;
            }
            cout << endl;
        }
    }   
}

// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A