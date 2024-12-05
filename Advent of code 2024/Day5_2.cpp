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
    vector<string> vi1, vi2;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi1.pb(s);
        }
    }
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi2.pb(s);
        }
    }
    map<string, int> mp1;
    ll ans = 0;
    for(auto x : vi1){
        mp1[x]++;
    }
    for(auto x : vi2){
        string s = x;
        vector<ll> temp;
        for(int i = 0 ; i < s.size() ; i += 3){
            ll num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            temp.pb(num);
        }
        int flag = 0;
        for(int i = 1 ; i < temp.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                string s1 = to_string(temp[i]) + '|' + to_string(temp[j]);
                if(mp1.find(s1) != mp1.end()){
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            for(int i = 0 ; i < temp.size() ; i++){
                int count = 0;
                for(int j = 0 ; j < temp.size() ; j++){
                    if(i == j){
                        continue;
                    }
                    string s1 = to_string(temp[i]) + '|' + to_string(temp[j]);
                    if(mp1.find(s1) != mp1.end()){
                        count++;
                    }
                }
                if(count == (temp.size() / 2)){
                    ans += temp[i];
                }
            }
        }
    }
    cout << ans;
}