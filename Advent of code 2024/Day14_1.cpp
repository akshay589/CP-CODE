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

vector<pair<ll, ll> > get_pos(vector<string> vi, ll n, ll start){
    vector<pair<ll, ll > > temp;
    for(ll i = start ; i < n ; i += 2){
        string s = vi[i], s1 = "";
        ll flag1 = 1, flag2 = 1;
        vector<ll> temp1;
        for(ll j = 0 ; j < (ll)s.size() ; j++){
            char ch = s[j];
            if(ch == '=' && s[j + 1] == '-'){
                flag1 = -1;
            }
            if(ch == ',' && s[j + 1] == '-'){
                flag2 = -1;
            }
            if(ch >= '0' && ch <= '9'){
                s1 += ch;
            }
            else{
                if(s1.size() > 0){
                    temp1.pb(stoi(s1));
                    s1 = "";
                }
            }
        }
        if(s1.size() > 0){
            temp1.pb(stoi(s1));
        }
        temp.pb({flag1 * temp1[0], flag2 * temp1[1]});
    }
    return temp;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    ll n = vi.size(), m = 103, k = 101, sec = 100, x, y, vel_x, vel_y, i, j, p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    vector<pair<ll,ll> > pos, vel;
    pos = get_pos(vi, n, 0);
    vel = get_pos(vi, n, 1);
    n = n / 2;
    vector<vector<ll> > a(m, vector<ll> (k, 0));
    for(i = 0 ; i < n ; i++){
        y = pos[i].ff;
        x = pos[i].se;
        vel_y = vel[i].ff;
        vel_x = vel[i].se;
        x += (vel_x * sec);
        y += (vel_y * sec);
        x %= m;
        y %= k;
        x += m;
        y += k;
        x %= m;
        y %= k;
        a[x][y]++;
    }
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < k ; j++){
            if(i < m / 2 && j < k / 2){
                p1 += a[i][j];
            }
            if(i < m / 2 && j > k / 2){
                p2 += a[i][j];
            }
            if(i > m / 2 && j < k / 2){
                p3 += a[i][j];
            }
            if(i > m / 2 && j > k / 2){
                p4 += a[i][j];
            }
        }
    }
    cout << (p1 * p2 * p3 * p4) << endl;
}