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


void solve(map<string, ll> &mp1, map<string, vector<string> > &mp2, string s){
    if(mp1.find(s) != mp1.end()){
        return;
    }
    string s1 = mp2[s][0];
    string s2 = mp2[s][1];
    string op = mp2[s][2];
    solve(mp1, mp2, s1);
    solve(mp1, mp2, s2);
    if(mp1.find(s1) != mp1.end() && mp1.find(s2) != mp1.end()){
        if(op == "XOR"){
            mp1[s] = mp1[s1] ^ mp1[s2];
        } 
        if(op == "OR"){
            mp1[s] = mp1[s1] | mp1[s2];
        }
        if(op == "AND"){
            mp1[s] = mp1[s1] & mp1[s2];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<vector<string> > vi1, vi2;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        vector<string> temp;
        while (ss >> s) { 
            temp.pb(s);
        }
        vi1.pb(temp);
    }
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        vector<string> temp;
        while (ss >> s) { 
             temp.pb(s);
        }
        vi2.pb(temp);
    }

    ll ans = 0, i;
    map<string, ll> mp1;
    map<string, vector<string> > mp2;
    vector<pair<string, ll> > vi;

    for(auto x : vi1){
        string s1 = x[0];
        string s2 = x[1];
        s1.pop_back();
        mp1[s1] = stoi(s2);
    }

    for(auto x : vi2){
        mp2[x[4]].pb(x[0]);
        mp2[x[4]].pb(x[2]);
        mp2[x[4]].pb(x[1]);
    }

    for(auto x : vi2){
        solve(mp1, mp2, x[4]);
    }

    for(auto x : mp1){
        if(x.ff[0] == 'z'){
            vi.pb({x.ff, x.se});
        }
    }
    sort(vi.begin(), vi.end());
    for(i = 0 ; i < vi.size() ; i++){
        if(vi[i].se == 1){
            ans = ans | ((ll)1 << i);
        }
    }
    cout << ans;
}