#include<bits/stdc++.h>
using namespace std;
 
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define ff              first
#define se              second
#define endl            '\n'
#define MAX             100000000
#define MAXN            200005
#define mod             998244353  

ll dp[200][200];

ll solve(vector<string> &s, int x, int y){
    if(x + 1 == s.size()){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    ll ans = 0;
    if(s[x + 1][y] == '^'){
        ans += solve(s, x + 1, y - 1);
        ans += solve(s, x + 1, y + 1);
    }
    else{
        ans += solve(s, x + 1, y);
    }
    dp[x][y] = ans;
    return ans;
}

ll solve(vector<string> &s){
    int n = s.size(), m = s[0].size(), y = -1;
    for(int j = 0 ; j < m ; j++){
        if(s[0][j] == 'S'){
            y = j;
        }
    }
    memset(dp, -1, sizeof(dp));
    return solve(s, 1, y);
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

    cout << solve(vi);
}