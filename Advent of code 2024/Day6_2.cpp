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

bool isLoop(vector<string> & vi, ll x, ll y){
    ll p, q, n = vi.size(), m = vi[0].size(), count = 130 * 130;
    set<pair<ll, ll> > st;
    st.insert({x, y});
    p = -1;
    q = 0;
    while(count--){
        if(x == n || x == -1 || y == m || y == -1){
            return false;
        }
        if(vi[x][y] == '.'){
            st.insert({x, y});
        }
        else{
            x -= p;
            y -= q;
            if(p == -1 && q == 0){
                p = 0;
                q = 1;
            }
            else if(p == 0 && q == 1){
                p = 1;
                q = 0;
            }
            else if(p == 1 && q == 0){
                p = 0;
                q = -1;
            }
            else{
                p = -1;
                q = 0;
            }
        }
        x += p;
        y += q;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> vi, vi1;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    ll n = vi.size(), m = vi[0].size(), i, j, p, q, x, y, sum = 0;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '^'){
                vi[i][j] = '.';
                p = i;
                q = j;
            }
        }
    }

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(vi[i][j] == '.'){
                vi1 = vi;
                vi1[i][j] = '#';
                sum += isLoop(vi1, p, q);
            }
        }
    }

    cout << sum << endl;
}