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
    ll mat[2][2];
};

struct segTree{

    ll size, mod;
    vector<item> values;

    ll getmod(ll v){
        return v % mod;
    }

    item NEUTRAL_ELEMENT = item({{1, 0}, {0, 1}});

    item single(item x){
        return x;
    }

    item merge(item a, item b){
        return item(
            {
                {
                    getmod(a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]),
                    getmod(a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1])
                }, 
                {
                    getmod(a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]),
                    getmod(a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1])
                }
            }
        );
    }

    void init(ll n, ll m){
        mod = m;
        size = 1;
        while(size < n){
            size *= 2;
        }
        values.resize(2 * size);
    }
    
    void build(vector<item> &a, ll x, ll lx, ll rx){
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

    void build(vector<item> &a){
        build(a, 0, 0, size - 1);
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

    void print(item x){
        for(ll i = 0 ; i < (ll)2 ; i++){
            for(ll j = 0 ; j < (ll)2 ; j++){
                cout << x.mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    item input(){
        item x;
        for(ll j = 0 ; j < (ll)2 ; j++){
            for(ll k = 0 ; k < (ll)2 ; k++){
                cin >> x.mat[j][k];
            }
        }
        return x;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll r, n, m, i, j, k, l;
    cin >> r >> n >> m;

    segTree st;
    st.init(n + 1, r);
    vector<item> a;

    for(i = 0 ; i < n ; i++){
        a.pb(st.input());
    }

    st.build(a);

    while(m--){
        cin >> l >> r;
        l--;
        r--;
        item s = st.calc(l, r);
        st.print(s);
    }
}

// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B