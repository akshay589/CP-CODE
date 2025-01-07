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

typedef long long int item;

struct segTree{

    ll size;
    vector<item> values;

    item NEUTRAL_ELEMENT = -MAX;

    item single(ll v){
        return v;
    }

    item merge(item a, item b){
        return max(a, b);
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

    ll first_above(ll v, ll l, ll x, ll lx, ll rx){
        if(values[x] < v){
            return -1;
        }
        if(rx < l){
            return -1;
        }
        if(lx == rx){
            return lx;
        }
        ll m = (lx + rx) / 2;
        ll res = first_above(v, l, 2 * x + 1, lx, m);
        if(res == -1){
            res = first_above(v, l, 2 * x + 2, m + 1, rx);
        }
        return res;
    }

    ll first_above(ll v, ll l){
        return first_above(v, l, 0, 0, size - 1);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m, i, x, op, v, l;
    cin >> n >> m;

    segTree st;
    vector<ll> a(n);
    st.init(n);

    for(i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    st.build(a);

    while(m--){
        cin >> op;
        if(op == 1){
            cin >> i >> v;
            st.set(i, v);
        }
        else{
            cin >> x >> l;
            cout << st.first_above(x, l) << endl;
        }
    }
}
