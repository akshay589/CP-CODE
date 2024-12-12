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
    int n = vi.size(), m = vi[0].size(), x, y, perimeter, new_x, new_y, ans = 0, sz = 0;
    vector<vector<bool> > vis(n, vector<bool> (m, false));
    ll dx[] = {-1, +1, 0, 0};
    ll dy[] = {0, 0, +1, -1};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                queue<pair<ll, ll > > qe;
                qe.push({i, j});
                perimeter = 4;
                sz = 0;
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
                                perimeter += 3;
                            }
                            else{
                                perimeter--;
                            }
                        }
                    }
                }
                ans += sz * perimeter;
            }
        }
    }
    cout << ans;
}