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

int get(int x, int y, vector<string> &vi){
    int sum = 0, n = vi.size(), m = vi[0].size();
    for(int i = x - 1 ; i <= x + 1 ; i++){
        for(int j = y - 1 ; j <= y + 1 ; j++){
            if((i < 0 || j < 0 || i == n || j == m) || (i == x && j == y)){
                continue;
            }
            sum += vi[i][j] == '@';
        }
    }
    return sum;
}

int solve(vector<string> &vi){
    int n = vi.size(), m = vi[0].size(), ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(vi[i][j] == '.'){
                continue;
            }
            int count = get(i, j, vi);
            if(count < 4){
                ans++;
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