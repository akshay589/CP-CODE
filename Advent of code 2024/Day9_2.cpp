#include<bits/stdc++.h>
using namespace std;
 
#define ll              long long int
#define ld              double
#define pb              push_back
#define mp              make_pair
#define ff              first
#define se              second
#define LOG             25
#define endl            '\n'
#define MAX             2000000000000000000
#define MAXN            200005
#define mod             1000000007  
#define pi              3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<ll> a(MAXN, -1);
    vector<vector<ll> > vi, vi1;
    priority_queue<ll, vector<ll>, greater<ll> > pq[10];
    ll i, x, ptr = 0, count = 0, ans = 0, l, r, start_idx, block_no, pos, sz, len, idx, j, mi;
    for(i = 0 ; i < (ll)s.size() ; i++){
        if(i % 2 == 0){
            x = s[i] - '0';
            vi.pb({ptr, count, x});
            ptr += x;
            count++;
        }
        else{
            x = s[i] - '0';
            pq[x].push(ptr);
            ptr += x;
        }
    }
    reverse(vi.begin(), vi.end());
    for(i = 0 ; i < (ll)vi.size() ; i++){
        start_idx = vi[i][0];
        block_no = vi[i][1];
        sz = vi[i][2];
        pos = -1;
        mi = MAX;
        for(j = 1 ; j <= 9 ; j++){
            if(pq[j].size() > 0 && sz <= j && pq[j].top() < start_idx && pq[j].top() < mi){
                mi = pq[j].top();
                pos = j;
            }
        }
        if(pos != -1){
            len = pos;
            idx = pq[pos].top();
            vi1.pb({idx, block_no, sz});
            pq[pos].pop();
            if(len - sz > 0){
                pq[len - sz].push(idx + sz);
            }
        }
        else{
            vi1.pb({start_idx, block_no, sz});
        }
    }
    sort(vi1.begin(), vi1.end());
    for(auto x : vi1){
        start_idx = x[0];
        block_no = x[1];
        sz = x[2];
        for(i = 1 ; i <= sz ; i++){
            a[start_idx + i - 1] = block_no;
        }
    }
    for(i = 0 ; i < ptr ; i++){
        if(a[i] != -1){
            ans += a[i] * i;
        }
    }
    cout << ans;
}

// For 28325 ans should be 64