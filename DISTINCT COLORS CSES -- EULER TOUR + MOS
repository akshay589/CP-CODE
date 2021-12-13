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
ll f[2*MAXN];
ll in[MAXN];
ll out[MAXN];
ll flat_tree_node[2*MAXN];
ll flat_tree_value[2*MAXN];
ll timer,answer=0;
vector<ll> vi[MAXN];

struct node{
    int left,right,index;
}q[MAXN];

bool comp(node x, node y){
    if(x.left/BLOCK != y.left/BLOCK){
        return x.left/BLOCK < y.left/BLOCK;
    }
    return x.right < y.right;
}

void add(int pos){
    f[flat_tree_value[pos]]++;
    if(f[flat_tree_value[pos]]==1){
        answer++;
    }
}

void remove(int pos){
    f[flat_tree_value[pos]]--;
    if(f[flat_tree_value[pos]]==0){
        answer--;
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
    flat_tree_value[timer]=a[u];
    timer++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,x,y,start,end,count=1;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    map<ll,ll> mp1;
    for(i=1;i<=n;i++){
        if(mp1[a[i]]==0){
            mp1[a[i]]=count;
            count++;
        }
    }
    for(i=1;i<=n;i++){
        a[i]=mp1[a[i]];
    }
    for(i=1;i<n;i++){
        cin>>x>>y;
        vi[x].pb(y);
        vi[y].pb(x);
    }
    dfs(1,0);
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
    for(i=0;i<n;i++){
        q[i].left=in[i+1];
        q[i].right=out[i+1];
        q[i].index=i+1;
    }
    sort(q,q+n,comp);
    start=0;
    end=0;
    for(i=0;i<n;i++){
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
    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}