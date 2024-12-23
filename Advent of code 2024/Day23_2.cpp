#include<bits/stdc++.h>
using namespace std;
 
#define ll              int
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


vector<pair<string, string> > edges;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

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
    ll count = 0, ptr = 0, mx = 0, i, j;
    map<string, ll> mp1;
    map<ll, string> mp2;
    for(auto edge : vi){
        string x = "";
        x += edge[0];
        x += edge[1];
        string y = "";
        y += edge[3];
        y += edge[4];
        edges.pb({x, y});
        if(mp1.find(x) == mp1.end()){
            mp1[x] = ptr;
            mp2[ptr] = x;
            ptr++;
        }
        if(mp1.find(y) == mp1.end()){
            mp1[y] = ptr;
            mp2[ptr] = y;
            ptr++;
        }
    }

    
    vector<vector<ll> >g(ptr, vector<ll> (ptr, 0));
    vector<ll> ans;
    vector<string> mxCliq;

    for(auto edge : edges){
        g[mp1[edge.ff]][mp1[edge.se]] = 1;
        g[mp1[edge.se]][mp1[edge.ff]] = 1;
    }


    vector<pair<ll, ll>> degrees;
    for (i = 0; i < ptr; ++i) {
        ll degree = accumulate(g[i].begin(), g[i].end(), 0);
        degrees.push_back({degree, i});
    }

    sort(degrees.rbegin(), degrees.rend());

    for (i = 0; i < ptr; ++i) {
        ll node = degrees[i].se;
        vector<ll> temp = {node};

        for (j = 0; j < ptr; ++j) {
            ll neighbor = degrees[j].se;

            bool isValid = true;
            for (ll v : temp) {
                if (g[neighbor][v] == 0) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                temp.push_back(neighbor);
            }
        }

        if(temp.size() > mx){
            mx = temp.size();
            ans = temp;
        }
    }

    for(auto x : ans){
        mxCliq.pb(mp2[x]);
    }
    sort(mxCliq.begin(), mxCliq.end());
    for(i = 0 ; i < mxCliq.size() ; i++){
        cout << mxCliq[i];
        if(i < mxCliq.size() - 1){
            cout << ",";
        }
    }



}