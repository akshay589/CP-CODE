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
#define LOG         20
#define MAX         10000000
#define MAXN        200002
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))
 
ll a[MAXN],BIT[MAXN];
 
void update(ll idx,ll val,ll n){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=idx & -idx;
    }
}

ll query(ll idx,ll n){
    ll sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=idx & -idx;
    }
    return sum;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,i,l,r,ans;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }
    while(q--){
        cin>>l>>r;
        ans=query(r,n)-query(l-1,n);
        cout<<ans<<endl;
    }
}