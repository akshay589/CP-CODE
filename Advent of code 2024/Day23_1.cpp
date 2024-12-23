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

map<string, set<string> > g;
vector<pair<string, string> > edges;
set<vector<string> > st;


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
    ll ans = 0;
    for(auto edge : vi){
        string x = "";
        x += edge[0];
        x += edge[1];
        string y = "";
        y += edge[3];
        y += edge[4];
        edges.pb({x, y});
        g[x].insert(y);
        g[y].insert(x);
    }

    for(auto edge : edges){
        for(auto adj_node : g[edge.ff]){
            if(g[edge.se].find(adj_node) != g[edge.se].end()){
                vector<string> temp;
                temp.pb(edge.ff);
                temp.pb(edge.se);
                temp.pb(adj_node);
                sort(temp.begin(), temp.end());
                st.insert(temp);

            }
        }
    }
    for(auto x : st){
        bool flag = 0;
        for(auto y : x){
            if(y[0] == 't'){
                flag = true;
            }
        }
        ans += flag;
    }

    cout << ans;
}