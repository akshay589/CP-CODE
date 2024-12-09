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
    string s;
    cin >> s;
    vector<ll> a(MAXN, -1);
    ll i, x, ptr = 0, count = 0, ans = 0, l, r;
    for(i = 0 ; i < s.size() ; i++){
        if(i % 2 == 0){
            x = s[i] - '0';
            while(x > 0){
                x--;
                a[ptr] = count;
                ptr++;
            }
            count++;
        }
        else{
            x = s[i] - '0';
            while(x > 0){
                x--;
                a[ptr] = (-1);
                ptr++;
            }
        }
    }
    l = 0, r = ptr - 1;
    ptr = 0;
    while(l <= r){
        if(a[l] == -1){
            while(r >= 0 && a[r] == -1 && l <= r){
                r--;
            }
            if(r >= 0 && a[r] != -1){
                ans += a[r] * ptr;
                r--;
                l++;
            }
        }
        else{
            ans += a[l] * ptr;
            l++;
        }
        ptr++;
    }
    cout << ans;
}