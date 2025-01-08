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

    item NEUTRAL_ELEMENT = 0;

    item single(ll v){
        return v;
    }

    item merge(item a, item b){
        return a + b;
    }

    void init(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        values.assign(2 * size, 0);
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

    ll calc(ll l, ll r, ll x, ll lx, ll rx){
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

    ll calc(ll l, ll r){
        return calc(l, r, 0, 0, size - 1);
    }

    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, i;
    cin >> n;

    segTree st;
    vector<ll> a(n);
    st.init(n + 1);

    for(i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(i = 0 ; i < n ; i++){
        cout << st.calc(a[i] + 1, n) << " ";
        st.set(a[i], 1);
    }
}


// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
