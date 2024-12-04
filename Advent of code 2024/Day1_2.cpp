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
    vector<vector<int>> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        vector<int> row;
        int num;
        while (ss >> num) { 
            row.push_back(num);
        }
        vi.push_back(row);
    }
    int ans = 0;
    vector<int> temp1, temp2;
    for(auto x : vi){
        temp1.pb(x[0]);
        temp2.pb(x[1]);
    }
    map<ll, ll> mp1;
    for(auto x : temp2){
        mp1[x]++;
    }
    for(auto x : temp1){
        ans += x * mp1[x];
    }
    cout << ans;
}