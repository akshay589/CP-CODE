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


struct segTree{
    
    ll size;
    vector<ll> sums; 

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        sums.assign(2 * size, 0);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx){
        if(lx == rx){
            if(lx < (ll)a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m + 1, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<ll> &a){
        build(a, 0, 0, size - 1);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(lx == rx){
            sums[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if(i <= m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m + 1, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size - 1);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx){
        if(l <= lx && rx <= r){
            return sums[x];
        }
        if(r < lx || rx < l){
            return 0;
        }
        ll m = (lx + rx) / 2;
        ll sum1 = sum(l, r, 2 * x + 1, lx, m);
        ll sum2 = sum(l, r, 2 * x + 2, m + 1 , rx);
        return sum1 + sum2;
    }

    ll sum(ll l, ll r){
        return sum(l, r, 0, 0, size - 1);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m, op, i, v, l, r;
    cin >> n >> m;

    segTree st;
    st.init(n);
    vector<ll> a(n);
    
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
            cin >> l >> r;
            cout << st.sum(l, r - 1) << endl;
        }
    }
}


//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A