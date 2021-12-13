[#include<bits/stdc++.h>
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
 
ll a[MAXN];
ll m[MAXN][LOG];
ll bin_log[MAXN];
 
ll query(ll l,ll r){
    ll len=r-l+1;
    ll k=bin_log[len];
    return min(m[l][k],m[r-(1<<k)+1][k]);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,i,l,r,j;
    cin>>n>>q;
    bin_log[1]=0;
    for(i=2;i<MAXN;i++){
        bin_log[i]=bin_log[i/2]+1;   
    }
    for(i=0;i<n;i++){
        cin>>a[i];
        m[i][0]=a[i];
    }
    for(j=1;j<LOG;j++){
        for(i=0;(i+(1<<j)-1)<n;i++){
            m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
        }
    }
    // for(j=0;j<5;j++){
    //     cout<<j<<"->";
    //     for(i=0;i<n;i++){
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        cin>>l>>r;
        l--;
        r--;
        cout<<query(l,r)<<endl;
    }
}