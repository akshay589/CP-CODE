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


bool check(ll x, ll y, ll n, ll m){
    return (x >= 0 && x < n && y >=0 && y < m);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            grid.pb(s);
        }
    }
    ll n = grid.size(), m = grid[0].size(), start_x, start_y, end_x, end_y, i, j, mx = 0, sum = 0, k, dis, new_x, new_y, x, y;
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
    map<vector<ll>, ll > mp1;

    for(i = 0 ; i < n ; i++){
        vector<ll> temp;
        for(j = 0 ; j < m ; j++){
            if(grid[i][j] == '#'){
                continue;
            }

            queue<vector<ll> > qe;
            map<pair<ll, ll>, bool> vis;
            qe.push({0, i, j});
            vis[{i, j}] = true;

            while(!qe.empty()){
                vector<ll> temp = qe.front();
                dis = temp[0];
                x = temp[1];
                y = temp[2];
                qe.pop();

                if(dis > 0){
                    for(k = 0 ; k < 4 ; k++){
                        new_x = x + dx[k];
                        new_y = y + dy[k];
                        if(new_x == i && new_y == j){
                            continue;
                        }
                        if(check(new_x, new_y, n, m) && grid[new_x][new_y] != '#'){
                            ll mi = MAX;
                            ll temp_dis = dis_from_S[new_x][new_y] + dis_from_E[i][j] + (dis + 1);
                            ll temp_dis_1 = dis_from_S[i][j] + dis_from_E[new_x][new_y] + (dis + 1);
                            mi = min(mi, temp_dis);
                            mi = min(mi, temp_dis_1);
                            if(mi < mx){
                                if(mp1.find({i, j, new_x, new_y}) == mp1.end()){
                                    mp1[{i, j, new_x, new_y}] = mi;
                                }
                                else{
                                    mp1[{i, j, new_x, new_y}] = min(mp1[{i, j, new_x, new_y}], mi);
                                }
                            }
                        }
                    }
                }

                for(k = 0 ; k < 4 ; k++){
                    new_x = x + dx[k];
                    new_y = y + dy[k];

                    if(check(new_x, new_y, n, m)){
                        if(!vis[{new_x, new_y}]){
                            vis[{new_x, new_y}] = true;
                            if(dis + 1 >= 20){
                                continue;
                            }
                            qe.push({dis + 1, new_x, new_y});
                        }
                    }
                }
            }

        }
    }
    map<ll, ll> mp2;
    for(auto x : mp1){
        mp2[mx - x.se]++;
    }
    sum = 0;
    for(auto x : mp2){
        if(x.ff >= 100){
            sum += x.se / 2;
        }
    }
    cout << sum << endl;
}

// Needs optimization in this, takes 2 min to give the output for matrix size 141 * 141