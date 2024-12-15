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
    string dir = "";
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            dir += s;
        }
    }

    vector<string> vi1;
    ll k = dir.size(), n = vi.size(), m = vi[0].size(), pos_i, pos_j, x, y, temp_x, temp_y, i, j, ans = 0;
    for(i = 0 ; i < n ; i++){
        string s1 = "";
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '@'){
                s1 += "@.";
            }
            if(vi[i][j] == '#'){
                s1 += "##";
            }
            if(vi[i][j] == 'O'){
                s1 += "[]";
            }
            if(vi[i][j] == '.'){
                s1 += "..";
            }
        }
        vi1.pb(s1);
    }
    
    vi = vi1;
    n = vi.size();
    m = vi[0].size();

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '@'){
                pos_i = i;
                pos_j = j;
            }
        }
    }

    for(i = 0 ; i < k ; i++){
        if(dir[i] == '<'){
            x = 0;
            y = -1;
        }
        else if(dir[i] == '>'){
            x = 0;
            y = 1;
        }
        else if(dir[i] == '^'){
            x = -1;
            y = 0;
        }
        else{
            x = 1;
            y = 0;
        }

        if(dir[i] == '<' || dir[i] == '>'){
            temp_x = pos_i + x;
            temp_y = pos_j + y;
            while(temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < m && (vi[temp_x][temp_y] == '[' || vi[temp_x][temp_y] == ']')){
                temp_x += x;
                temp_y += y;
            }
            if(vi[temp_x][temp_y] == '.'){
                vi[temp_x][temp_y] = vi[temp_x - x][temp_y - y];
                while(temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < m && vi[temp_x][temp_y] != '@'){
                    vi[temp_x][temp_y] = vi[temp_x - x][temp_y - y];
                    temp_x -= x;
                    temp_y -= y;
                }
                temp_x = pos_i + x;
                temp_y = pos_j + y;
                vi[temp_x][temp_y] = '@';
                vi[pos_i][pos_j] = '.';
                pos_i = temp_x;
                pos_j = temp_y;

            }
        }
        else{
            map<vector<ll>, ll > vis;
            queue<pair<ll, ll> > qe;
            vector<vector<ll>  > temp;

            temp_x = pos_i + x;
            temp_y = pos_j + y;
            
            if(vi[temp_x][temp_y] == '['){
                qe.push({temp_y, temp_y + 1});
            }
            if(vi[temp_x][temp_y] == ']'){
                qe.push({temp_y - 1, temp_y});
            }
            while(temp_x >= 0 && temp_x < n){
                ll sz = qe.size();
                temp_x += x;
                while(sz > 0){
                    sz--;
                    pair<ll, ll> p = qe.front();
                    qe.pop();
                    temp.pb({temp_x - x, p.ff, p.se});

                    if(vi[temp_x][p.ff] == '[' && !vis[{temp_x, p.ff, p.ff + 1}]){
                        qe.push({p.ff, p.ff + 1});
                        vis[{temp_x, p.ff, p.ff + 1}] = true;
                    }
                    if(vi[temp_x][p.ff] == ']'  && !vis[{temp_x, p.ff - 1, p.ff}]){
                        qe.push({p.ff - 1, p.ff});
                        vis[{temp_x, p.ff - 1, p.ff}] = true;
                    }
                    if(vi[temp_x][p.se] == '[' && !vis[{temp_x, p.se, p.se + 1}]){
                        qe.push({p.se, p.se + 1});
                        vis[{temp_x, p.se, p.se + 1}] = true;
                    }
                    if(vi[temp_x][p.se] == ']' && !vis[{temp_x, p.se - 1, p.se}]){
                        qe.push({p.se - 1, p.se});
                        vis[{temp_x, p.se - 1, p.se}] = true;
                    }
                }
            }   

            reverse(temp.begin(), temp.end());

            ll flag = 0;
            for(auto z : temp){
                if(vi[z[0] + x][z[1]] == '#' || vi[z[0] + x][z[2]] == '#'){
                    flag = 1;
                }
            }
            if(flag == 0){
                for(auto z : temp){
                    vi[z[0] + x][z[1]] = vi[z[0]][z[1]]; 
                    vi[z[0] + x][z[2]] = vi[z[0]][z[2]];
                    vi[z[0]][z[1]] = '.';
                    vi[z[0]][z[2]] = '.';
                }
                
                temp_x = pos_i + x;
                temp_y = pos_j + y; 
                if(vi[temp_x][temp_y] == '.'){
                    vi[temp_x][temp_y] = '@';
                    vi[pos_i][pos_j] = '.';
                    pos_i = temp_x;
                    pos_j = temp_y;
                }
            }
        }
    }
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '['){
                ans += (i * 100 + j);
            }
        }
    }
    cout << ans;
}