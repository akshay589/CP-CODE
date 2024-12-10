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

vector<string> vi;
ll vis[100][100];
ll dx[] = {-1, +1, 0, 0};
ll dy[] = {0, 0, +1, -1};

ll solve(ll x, ll y, ll count){
    vis[x][y] = 1;
    if(count == 9){
        return 1;
    }
    ll ans = 0, i, new_x, new_y, n = vi.size(), m = vi[0].size();
    for(i = 0 ; i < 4 ; i++){
        new_x = x + dx[i];
        new_y = y + dy[i];
        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && (vi[new_x][new_y] - '0') == count + 1 && !vis[new_x][new_y]){
            ans += solve(new_x, new_y, count + 1);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    ll n = vi.size(), m = vi[0].size(), ans = 0, i, j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '0'){
                memset(vis, 0, sizeof(vis));
                ans += solve(i, j, 0);
            }
        }
    }
    cout << ans;
}
