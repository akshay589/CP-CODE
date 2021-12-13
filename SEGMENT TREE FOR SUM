#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         1000000000000000
#define MAXN        100005
#define mod         100000000 
#define pi          3.1415926535897932384626433
 
ll a[MAXN], st[5*MAXN];
 
void build(ll node, ll l, ll r){
    // cout<<node<<" -> "<<l<<" "<<r<<endl;
    if(l==r){
        st[node]=a[l];
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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,p,pos,val,x,y,ans;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    while(m--){
        cin>>p;
        if(p==1){
            cin>>pos>>val;
            update(0,0,n-1,pos,val);
            a[pos]=val;
        }
        else{
            cin>>x>>y;
            y--;
            ans=query(0,0,n-1,x,y);
            cout<<ans<<endl;
        }
    }
}