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
#define MAX             100000000
#define MAXN            200005
#define mod             1000000007  
#define pi              3.1415926535897932384626433

vector<string> grid;
ll dx[] = {-1, +1, 0, 0};
ll dy[] = {0, 0, +1, -1};

void getdis(vector<vector<ll> > &vi, ll start_x, ll start_y, ll n, ll m){
    queue<pair<ll, ll> > qe;
    ll vis[n][m], x, y, new_x, new_y, k;
    memset(vis, 0, sizeof(vis));
    qe.push({start_x, start_y});
    vis[start_x][start_y] = true;

    while(!qe.empty()){
        x = qe.front().ff;
        y = qe.front().se;
        qe.pop();
        for(k = 0 ; k < 4 ; k++){
            new_x = x + dx[k];
            new_y = y + dy[k];
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !vis[new_x][new_y] && grid[new_x][new_y] != '#'){
                qe.push({new_x, new_y});
                vis[new_x][new_y] = true;
                vi[new_x][new_y] = vi[x][y] + 1;
            }
        }
    }
}


bool check(ll x1, ll y1, ll x2, ll y2, ll n, ll m){
    return (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >=0 && y1 < m && y2 >= 0 && y2 < m);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            grid.pb(s);
        }
    }
    ll n = grid.size(), m = grid[0].size(), start_x, start_y, end_x, end_y, i, j, mx = 0, sum = 0;
    vector<vector<ll> > dis_from_S(n, vector<ll> (m, MAX));
    vector<vector<ll> > dis_from_E(n, vector<ll> (m, MAX));

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(grid[i][j] == 'E'){
                start_x = i;
                start_y = j;
            }
            if(grid[i][j] == 'S'){
                end_x = i;
                end_y = j;
            }
        }
    }


    dis_from_S[start_x][start_y] = 0;
    dis_from_E[end_x][end_y] = 0;

    getdis(dis_from_S, start_x, start_y, n, m);
    getdis(dis_from_E, end_x, end_y, n, m);

    mx = dis_from_S[end_x][end_y];

    ll p, p1, p2, q, new_y_left, new_x_left, new_y_right, new_x_right;
    map<ll , set<pair<ll, ll > > > mp1;

    for(i = 0 ; i < n ; i++){
        vector<ll> temp;
        for(j = 0 ; j < m ; j++){
            ll mi = MAX;
            if(grid[i][j] != '#'){
                continue;
            }
            for(p1 = 0 ; p1 < 4 ;p1++){
                for(p2 = 0 ; p2 < 4 ; p2++){
                    if(p1 == p2){
                        continue;
                    }
                    new_x_left = i + dx[p1];
                    new_y_left = j + dy[p1];

                    new_x_right = i + dx[p2];
                    new_y_right = j + dy[p2];
                    if(check(new_x_left, new_y_left, new_x_right, new_y_right, n, m)){
                        ll temp_dis = dis_from_S[new_x_left][new_y_left] + dis_from_E[new_x_right][new_y_right] + 2;
                        ll temp_dis_1 = dis_from_E[new_x_left][new_y_left] + dis_from_S[new_x_right][new_y_right] + 2;
                        mi = min(mi, temp_dis);
                        mi = min(mi, temp_dis_1);
                    }
                }
            }
            if(mi < mx){
                mp1[mx - mi].insert({i, j});
            }
        }
    }
    for(auto x: mp1){
        if(x.ff >= 100){
            sum += x.se.size();
        }
    }
    cout << sum << endl;
}