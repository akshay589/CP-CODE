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
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))
 
ll a[MAXN];
ll in[MAXN];
ll out[MAXN];
ll flat_tree_node[2*MAXN];
ll flat_tree_value[2*MAXN];
ll st[8*MAXN];
vector<ll> vi[MAXN];
ll timer;

//https://cses.fi/problemset/task/1138
// INPUT
// 7 7
// 1 2 3 4 5 6 7
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 4 7
// 2 1
// 2 2 
// 2 3
// 2 4
// 2 5
// 2 6
// 2 7

void build(ll node, ll l, ll r){
    // cout<<node<<" -> "<<l<<" "<<r<<endl;
    if(l==r){
        st[node]=flat_tree_value[l];
        return ;
    }
    ll mid=(l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    st[node]=st[2*node+1]+st[2*node+2];
}
 
ll query(ll node,ll l,ll r, ll x, ll y){
    if(x<=l && r<=y){
        return st[node];
    }
    if(r<x || y<l){
        return 0;
    }
    ll mid=(l+r)/2;
    ll ans1=query(2*node+1,l,mid,x,y);
    ll ans2=query(2*node+2,mid+1,r,x,y);
    return ans1+ans2;
}
 
void update(ll node,ll l,ll r,ll pos,ll val){
    if(l==pos && r==pos){
        st[node]=val;
    }
    else{
        ll mid=(l+r)/2;
        if(pos<=mid){
            update(2*node+1,l,mid,pos,val);
        }
        else{
            update(2*node+2,mid+1,r,pos,val);
        }   
        st[node]=st[2*node+1]+st[2*node+2];
    }
}

void dfs(ll u,ll p){
    in[u]=timer;
    flat_tree_node[timer]=u;
    flat_tree_value[timer]=a[u];
    timer++;
    for(auto x:vi[u]){
        if(x!=p){
            dfs(x,u);
        }
    }
    out[u]=timer;
    flat_tree_node[timer]=u;
    flat_tree_value[timer]=-a[u];
    timer++;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,i,x,y,p,l,r,node,value,ans;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        cin>>x>>y;
        vi[x].pb(y);
        vi[y].pb(x);
    }
    dfs(1,0);
    build(0,0,2*n-1);
    // for(i=1;i<=n;i++){
    //     cout<<in[i]<<" ";
    // }
    // cout<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<out[i]<<" ";
    // }
    // cout<<endl;
    // for(i=0;i<2*n;i++){
    //     cout<<flat_tree_node[i]<<" ";
    // }
    // cout<<endl;
    // for(i=0;i<2*n;i++){
    //     cout<<flat_tree_value[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        cin>>p;
        if(p==1){
            cin>>node>>value;
            update(0,0,2*n-1,in[node],value);
            update(0,0,2*n-1,out[node],-value);
        }
        else{
            cin>>node;
            l=0;
            r=in[node];
            ans=query(0,0,2*n-1,l,r);
            cout<<ans<<endl;
        }
    }
}