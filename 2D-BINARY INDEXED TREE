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
#define MAXN        1002
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))

ll a[MAXN][MAXN],BIT[MAXN][MAXN];

void update(ll i,ll j,ll val,ll n){
    ll x,y;
    for(x=i ; x<=n ; x+=x & -x){
        for(y=j ; y<=n ; y+=y & -y){
            BIT[x][y]+=val;
        }
    }
}

ll query(ll i,ll j){
    ll ans=0,x,y;
    for(x=i ; x>0 ; x-=x & -x){
        for(y=j ; y>0 ; y-=y & -y){
            ans+=BIT[x][y];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,i,j;
    cin>>n>>q;
    char ch;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>ch;
            if(ch=='*'){
                a[i][j]=1;
                update(i,j,1,n);
            }
        }
    }
    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
        cout<<ans<<endl;
    }
}