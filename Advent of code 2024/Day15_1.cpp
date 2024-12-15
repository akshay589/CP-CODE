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

    ll k = dir.size(), n = vi.size(), m = vi[0].size(), pos_i, pos_j, x, y, temp_x, temp_y, i, j, ans = 0;
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
        
        temp_x = pos_i + x;
        temp_y = pos_j + y;

        while(temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < m && vi[temp_x][temp_y] == 'O'){
            temp_x += x;
            temp_y += y;
        }

        if(vi[temp_x][temp_y] == '.'){
            vi[temp_x][temp_y] = 'O';
            temp_x = pos_i + x;
            temp_y = pos_j + y;
            vi[temp_x][temp_y] = '@';
            vi[pos_i][pos_j] = '.';
            pos_i = temp_x;
            pos_j = temp_y;
        }
    }
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == 'O'){
                ans += (i * 100 + j);
            }
        }
    }
    cout << ans;
}