#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         10000000
#define MAXN        200002
#define BLOCK       555
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))

// https://cses.fi/problemset/task/1139
// 5
// 2 3 2 2 1
// 1 2
// 1 3
// 3 4
// 3 5

ll a[MAXN];
ll ans[MAXN];
vector<ll> vi[MAXN];
set<ll> st[MAXN];

void dfs(ll u,ll p){
    for(auto x:vi[u]){
        if(x!=p){
            dfs(x,u);
            if(st[x].size() > st[u].size()){
                swap(st[x],st[u]);
            }
            for(auto y:st[x]){
                st[u].insert(y);
            }
            st[x].clear();
        }
    }
    ans[u]=st[u].size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,x,y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        st[i].insert(a[i]);
    }
    for(i=1;i<n;i++){
        cin>>x>>y;
        vi[x].pb(y);
        vi[y].pb(x);
    }
    dfs(1,0);
    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}