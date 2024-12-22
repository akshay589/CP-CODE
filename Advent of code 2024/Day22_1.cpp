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
    ll sum = 0;

    for(auto num : vi){
        ll n, _64 = 64, _32 = 32, _2048 = 2048, temp1, i;
        n = num;
        
        for(i = 1 ; i <= 2000 ; i++){
            temp1 = n * _64;
            n = temp1 ^ n;
            n = n % mod;

            temp1 = n / _32;
            n = temp1 ^ n;
            n = n % mod;

            temp1 = n * _2048;
            n = temp1 ^ n;
            n = n % mod;
        }
        sum += n;
    }
    cout << sum;
}