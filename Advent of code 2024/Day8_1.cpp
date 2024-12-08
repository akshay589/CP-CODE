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
    ll n = vi.size(), m = vi[0].size(), i, j, p, q, x, y, sum = 0, new_x, new_y;
    vector<vector<bool > > vis(n, vector<bool> (m, false));
    map<char, vector<pair<ll, ll>  > > mp1;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '.'){
                continue;
            }
            mp1[vi[i][j]].pb({i, j});
        }
    }
    for(auto z : mp1){
        vector<pair<ll, ll > > vec = z.se;
        ll sz = vec.size();
        for(i = 0 ; i < sz ; i++){
            for(j = i + 1 ; j < sz ; j++){
                x = vec[i].ff - vec[j].ff;
                y = vec[i].se - vec[j].se;
                new_x = vec[j].ff - x;
                new_y = vec[j].se - y;
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m){
                    vis[new_x][new_y] = true;
                }
                new_x = vec[i].ff + x;
                new_y = vec[i].se + y;
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m){
                    vis[new_x][new_y] = true;
                }
            }
        }
    }
    for(i = 0 ; i < n ;i++){
        for(j = 0 ; j < m ; j++){
            sum += vis[i][j];
        }
    }
    cout << sum;
}