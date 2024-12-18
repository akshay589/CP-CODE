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

ll a[71][71];

ll getdis(ll n){
    ll dx[] = {-1, +1, 0, 0};
    ll dy[] = {0, 0, +1, -1};
    ll  x, y, new_x, new_y, k;
    queue<pair<ll, ll > > qe;
    ll vis[n][n], dp[n][n];
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    qe.push({0, 0});
    vis[0][0] = true;
    while(!qe.empty()){
        x = qe.front().ff;
        y = qe.front().se;
        qe.pop();
        for(k = 0 ; k < 4 ; k++){
            new_x = x + dx[k];
            new_y = y + dy[k];
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && a[new_x][new_y] == 0 && !vis[new_x][new_y]){
                vis[new_x][new_y] = true;
                qe.push({new_x, new_y});
                dp[new_x][new_y] = dp[x][y] + 1;
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    ll n = 71, sz = vi.size(), i, j;
    memset(a, 0, sizeof(a));
    for(auto s : vi){
        vector<ll> temp;
        string s1 = "";
        for(i = 0 ; i < (ll)s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                s1 += s[i];
            }
            else{
                temp.pb(stoi(s1));
                s1 = "";
            }
        }
        temp.pb(stoi(s1));
        a[temp[0]][temp[1]] = 1;
        if(getdis(n) == 0){
            cout << temp[0] << "," << temp[1] << endl;
            break;
        }
    }

}