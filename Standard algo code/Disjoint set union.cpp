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
#define MAX         2000000000000000000
#define MAXN        300002
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))
 
ll p[MAXN],sz[MAXN],mi[MAXN],mx[MAXN];
 
ll find(ll u){
    if(u==p[u]){
        return u;
    }
    return p[u]=find(p[u]);
}

void merge(ll a,ll b){
    a=find(a);
    b=find(b);
    if(sz[a]>sz[b]){
        swap(a,b);
    }
    if(a!=b){
        mi[b]=min(mi[b],mi[a]);
        mx[b]=max(mx[b],mx[a]);
        sz[b]+=sz[a];
        p[a]=b;
        sz[a]=0;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,x,y;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        p[i]=mi[i]=mx[i]=i;
        sz[i]=1;
    }
    while(m--){
        string s;
        cin>>s;
        if(s=="union"){
            cin>>x>>y;
            merge(x,y);
        }
        else{
            cin>>x;
            x=find(x);
            cout<<mi[x]<<" "<<mx[x]<<" "<<sz[x]<<endl;
        }
    }
}