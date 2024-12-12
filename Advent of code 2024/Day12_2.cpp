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

ll getCount(map<ll, vector<ll> > mp1){
    ll count = 0;
    for(auto x : mp1){
        vector<ll> temp = x.se;
        sort(temp.begin(), temp.end());
        count++;
        ll sz = temp.size();{
            for(ll i = 0 ; i < sz - 1 ; i++){
                if(temp[i] + 1 != temp[i + 1]){
                    count++;
                }
            }
        }
    }
    return count;
}

ll solve(map<ll, vector<ll> > mp1[2]){
    ll count = 0;
    count += getCount(mp1[0]);
    count += getCount(mp1[1]);
    return count;
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
    ll n = vi.size(), m = vi[0].size(), x, y, sides, new_x, new_y, ans = 0, sz = 0;
    vector<vector<bool> > vis(n, vector<bool> (m, false));
    ll dx[] = {-1, +1, 0, 0};
    ll dy[] = {0, 0, +1, -1};
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < m ; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                queue<pair<ll, ll > > qe;
                qe.push({i, j});
                sz = 0;
                map<ll, vector<ll> > mp1[2], mp2[2];
                // mp1 -> horizontal
                // mp2 -> vertical
                while(!qe.empty()){
                    x = qe.front().ff;
                    y = qe.front().se;
                    qe.pop();
                    sz++;
                    for(int k = 0 ; k < 4 ; k++){
                        new_x = x + dx[k];
                        new_y = y + dy[k];
                        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && vi[new_x][new_y] == vi[x][y]){
                            if(!vis[new_x][new_y]){
                                vis[new_x][new_y] = true;
                                qe.push({new_x, new_y});
                            }
                        }
                        else{
                            if(k == 0){
                                mp1[0][new_x].pb(new_y);
                            }
                            if(k == 1){
                                mp1[1][new_x].pb(new_y);
                            }
                            if(k == 2){
                                mp2[0][new_y].pb(new_x);
                            }
                            if(k == 3){
                                mp2[1][new_y].pb(new_x);
                            }
                        }
                    }
                }
                sides = solve(mp1);
                sides += solve(mp2);
                ans += sz * sides;
            }
        }
    }
    cout << ans;
}