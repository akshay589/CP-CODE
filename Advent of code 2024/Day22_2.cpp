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
#define mod             16777216  
#define pi              3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    vector<ll> vi;
    string s1;
    while (getline(cin, s1)) {
        if (s1.empty()) break; 

        stringstream ss(s1);
        string s;
        while (ss >> s) { 
            vi.pb(stol(s));
        }
    }
    ll mx = 0;
    map<vector<ll>, ll > mp1;
    for(auto num : vi){
        ll n, _64 = 64, _32 = 32, _2048 = 2048, val, i, sz, j;
        n = num;
        vector<ll> temp1, temp2;
        map<vector<ll>, ll > mp2;
        temp2.pb(n % 10);
        for(i = 1 ; i <= 1999 ; i++){
            val = n * _64;
            n = val ^ n;
            n = n % mod;

            val = n / _32;
            n = val ^ n;
            n = n % mod;

            val = n * _2048;
            n = val ^ n;
            n = n % mod;
            temp2.pb(n % 10);
            if(temp2.size() >= 5){
                vector<ll> temp3;
                sz = temp2.size();
                for(j = sz - 5 ; j < sz - 1; j++){
                    temp3.pb(temp2[j + 1] - temp2[j]);
                }
                if(mp2.find(temp3) == mp2.end()){
                    mp2[temp3] = temp2[sz - 1];
                }
            }
        }
        for(auto x : mp2){
            mp1[x.ff] += x.se;
        }
    }
    for(auto x : mp1){
        mx = max(mx, x.se);
    }
    cout << mx;
}