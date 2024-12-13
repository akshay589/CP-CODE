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

pair<ll, ll> get(string s){
    ll sz = s.size();
    vector<ll> vi;
    string s1 = "";
    for(ll i = 0 ; i < sz ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            s1 += s[i];
        }
        else{
            if(s1.size() > 0){
                vi.pb(stoi(s1));
            }
            s1 = "";
        }
    }
    vi.pb(stoi(s1));
    pair<ll, ll> p = {vi[0], vi[1]};
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Input length is hard coded
    ll n = 320, i, ans = 0, x1, x2, y1, y2, num, den, price1, price2, p, q;
    string s1, s2, s3, s4;
    vector<pair<ll, ll> > vi1, vi2, vi3;
    for(i = 1 ; i <= n ; i++){
        getline(cin, s1); 
        getline(cin, s2); 
        getline(cin, s3); 
        getline(cin, s4); 
        vi1.pb(get(s1));
        vi2.pb(get(s2));
        vi3.pb(get(s3));
    }
    for(i = 0 ; i < n ; i++){
        x1 = vi1[i].ff;
        y1 = vi1[i].se;
        x2 = vi2[i].ff;
        y2 = vi2[i].se;
        price1 = vi3[i].ff + 10000000000000;
        price2 = vi3[i].se + 10000000000000;

        num = price1 * y1 - price2 * x1;
        den = x2 * y1 - x1 * y2;
        if(num % den == 0){
            q = num / den;
            if((price1 - x2 * q) % x1 == 0){
                p = (price1 - (x2 * q)) / x1;
                ans += p * 3 + q;
            }
        } 

    }
    cout << ans;
}