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

// https://cses.fi/problemset/task/1734
// 4 10
// 1 2 3 4
// 1 1
// 1 2 
// 1 3
// 1 4
// 2 2 
// 2 3
// 2 4
// 3 3
// 3 4
// 4 4


ll a[MAXN],ans[MAXN],f[MAXN];
ll answer=0;

struct node{
    int left,right,index;
}q[MAXN];

bool comp(node x,node y){
    if(x.left/BLOCK != y.left/BLOCK){
        return x.left/BLOCK < y.left/BLOCK;
    }
    return x.right < y.right;
}
 
void add(int pos){
    f[a[pos]]++;
    if(f[a[pos]]==1){
        answer++;
    }
} 

void remove(int pos){
    f[a[pos]]--;
    if(f[a[pos]]==0){
        answer--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,count,x,y,start,end;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    map<ll,ll> mp1;
    count=1;
    for(i=0;i<n;i++){
        if(mp1[a[i]]==0){
            mp1[a[i]]=count;
            count++;
        }
    }
    for(i=0;i<n;i++){
        a[i]=mp1[a[i]];
    }
    // for(i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    for(i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        q[i].left=x;
        q[i].right=y;
        q[i].index=i;
    }
    sort(q,q+m,comp);
    start=0;
    end=0;
    for(i=0;i<m;i++){
        while(start < q[i].left){
            remove(start);
            start++;
        }
        while(start > q[i].left){
            start--;
            add(start);
        }
        while(end <= q[i].right){
            add(end);
            end++;
        }
        while(end > q[i].right+1){
            end--;
            remove(end);
        }
        ans[q[i].index]=answer;
    }
    for(i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
}


