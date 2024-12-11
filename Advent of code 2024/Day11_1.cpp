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
    ll n, y = 25;
    while(y--){
        vector<ll> temp;
        n = vi.size();
        for(auto x : vi){
            string s = to_string(x);
            if(x == 0){
                temp.pb(1);
            }
            else if(s.size() % 2 == 0){
                temp.pb(stol(s.substr(0, s.size() / 2)));
                temp.pb(stol(s.substr(s.size() / 2, s.size() / 2)));
            }
            else{
                temp.pb(x * 2024);
            }
        }
        vi = temp;
    }
    cout << vi.size() << endl;
}