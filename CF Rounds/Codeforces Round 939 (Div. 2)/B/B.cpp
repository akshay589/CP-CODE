#include<bits/stdc++.h>
using namespace std;
 
#define ll              int
#define ld              double
#define pb              push_back
#define mp              make_pair
#define ff              first
#define se              second
#define endl            '\n'
#define fd(n)           fixed<<setprecision(n)
#define MAX             2000000000000000000
#define MAXN            1000000000
#define mod             1000000007  
#define pi              3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))
#define print(vi)       for(auto x:vi) {cout<<x<<" ";} cout<<endl
#define printv(a)       cout<<a<<endl
#define add(a,b)        (((a%mod)+(b%mod)+mod)%mod)
#define sub(a,b)        (((a%mod)-(b%mod)+mod)%mod) 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,i,ans=0,x;
        cin>>n;
        map<ll,ll> mp1;
        for(i=0;i<n;i++){
            cin>>x;
            mp1[x]++;
            if(mp1[x]==2){
                ans++;
            }
        }
        cout<<ans<<endl;
   }
}