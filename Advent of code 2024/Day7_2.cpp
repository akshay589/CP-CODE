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

ll solve(vector<ll> &vi, ll idx, ll temp, ll num){
    if(idx == vi.size()){
        if(temp == num){
            return 1;
        }
        return 0;
    }
    if(temp > num){
        return 0;
    }
    ll ans = 0;
    ans += solve(vi, idx + 1, stol(to_string(temp) + to_string(vi[idx])), num);
    ans += solve(vi, idx + 1, temp + vi[idx], num);
    ans += solve(vi, idx + 1, temp * vi[idx], num);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<string>> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        vector<string> row;
        string num;
        while (ss >> num) { 
            row.push_back(num);
        }
        vi.push_back(row);
    }
    ll n = vi.size(), m = vi[0].size(), ans = 0, i, j;
    for(auto x : vi){
        vector<string> temp = x;
        vector<ll> vi1;
        ll num;
        for(i = 0 ; i < temp.size() ; i++){
            if(i == 0){
                temp[i].pop_back();
                num = stol(temp[i]);
            }
            else{
                vi1.pb(stol(temp[i]));
            }
        }
        if(solve(vi1, 1, vi1[0], num) > 0){
            ans += num;
        }
    } 
    cout << ans ;
}