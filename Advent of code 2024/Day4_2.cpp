#include<bits/stdc++.h>
using namespace std;
 
#define ll              int
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
    int n = vi.size(), m = vi[0].size(), ans = 0, i, j;
    // cout << n << " " << m << endl;
    for(i = 1 ; i < n - 1 ; i++){
        for(j = 1 ; j < m - 1 ; j++){
            if(vi[i][j] == 'A'){
                if(vi[i - 1][j - 1] == 'M' && vi[i - 1][j + 1] == 'M' && vi[i + 1][j + 1] == 'S' && vi[i + 1][j - 1] == 'S'){
                    ans++;
                }
                else if(vi[i - 1][j - 1] == 'S' && vi[i - 1][j + 1] == 'M' && vi[i + 1][j + 1] == 'M' && vi[i + 1][j - 1] == 'S'){
                    ans++;
                }
                else if(vi[i - 1][j - 1] == 'S' && vi[i - 1][j + 1] == 'S' && vi[i + 1][j + 1] == 'M' && vi[i + 1][j - 1] == 'M'){
                    ans++;
                }
                else if(vi[i - 1][j - 1] == 'M' && vi[i - 1][j + 1] == 'S' && vi[i + 1][j + 1] == 'S' && vi[i + 1][j - 1] == 'M'){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}