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

int solve(vector<string> &s){
    int n = s.size(), m = s[0].size(), ans = 0;
    for(int j = 0 ; j < m ; j++){
        if(s[0][j] == 'S'){
            s[1][j] = '|';
        }
    }
    for(int i = 1 ; i < n - 1 ; i++){
        for(int j = 0 ; j < m ; j++){
            if(s[i][j] == '|' && s[i + 1][j] == '^'){
                ans++;
                s[i + 1][j - 1] = '|';
                s[i + 1][j + 1] = '|';
            }
            else if(s[i][j] == '|'){
                s[i + 1][j] = '|';
            }
        }
    }
    return ans;
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