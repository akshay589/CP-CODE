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
#define mod             1000000007  

struct item{
    ll seg, pref, suf, sum;
};

struct segTree{

    ll size;
    vector<item> values;

    item NEUTRAL_ELEMENT = {0, 0, 0, 0};

    item single(ll v){
        if(v > 0){
            return {v, v, v, v};
        }
        else{
            return {0, 0, 0, v};
        }
    }

    item merge(item a, item b){
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
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
        item s1 = calc(l, r, 2 * x + 1, l, m);
        item s2 = calc(l, r, 2 * x + 2, m + 1, r);
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

    ll n, m, i, v;
    cin >> n >> m;

    segTree st;
    vector<ll> a(n);
    st.init(n);

    for(i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    st.build(a);
    cout << st.calc(0, n - 1).seg << endl;
    while(m--){
        cin >> i >> v;
        st.set(i, v);
        cout << st.calc(0, n - 1).seg << endl;
    }
}


// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A