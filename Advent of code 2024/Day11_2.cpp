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

map<pair<ll, ll>, ll > mp1;

ll solve(ll x, ll y){
    if(y == 0){
        return 1;
    }
    if(mp1.find({x, y}) != mp1.end()){
        return mp1[{x, y}];
    }
    ll ans = 0;
    string s = to_string(x);
    if(x == 0){
        ans += solve(1, y - 1);
    }
    else if(s.size() % 2 == 0){
        ans += solve(stol(s.substr(0, s.size() / 2)), y - 1);
        ans += solve(stol(s.substr(s.size() / 2, s.size() / 2)), y - 1);
    }
    else{
        ans += solve(x * 2024, y - 1);
    }
    mp1[{x, y}] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        ll s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    ll n, y = 75, ans = 0;
    for(auto x : vi){
        ans += solve(x, y);
    }
    cout << ans;
}