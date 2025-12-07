#include<bits/stdc++.h>
using namespace std;
 
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define ff              first
#define se              second
#define endl            '\n'
#define MAX             100000000
#define MAXN            200005
#define mod             998244353  

struct DSU{
    int n;
    vector<int> parent;
    void init(int sz){
        n = sz;
        parent.resize(n + 1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u != v){
            parent[u] = v;
        }
    }

    int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
};

vector<ll> parse(string s){
    vector<ll> temp;
    ll num = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] != ','){
            num = num * 10 + (s[i] - '0');
        }
        else{
            temp.pb(num);
            num = 0;
        }
    }
    temp.pb(num);
    return temp;
}

ll get(vector<string> &vi, int x, int y){
    ll dist = 0;
    vector<ll> temp1 = parse(vi[x]);
    vector<ll> temp2 = parse(vi[y]);
    for(int i = 0 ; i < 3 ; i++){
        dist += (temp1[i] - temp2[i]) * (temp1[i] - temp2[i]);
    }
    return dist;
}

ll solve(vector<string> &s){
    int n = s.size(), count = s.size(), p1, p2;
    DSU dsu;
    dsu.init(n);
    ll ans;
    vector<pair<ll, pair<int, int > > > vi;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            vi.pb({get(s, i, j), {i, j}});
        }
    }
    sort(vi.begin(), vi.end());
    for(int i = 0 ; i < vi.size() ; i++){
        if(dsu.find(vi[i].se.ff) != dsu.find(vi[i].se.se)){
            dsu.merge(vi[i].se.ff, vi[i].se.se);
            count--;
        }
        if(count == 1){
            p1 = vi[i].se.ff;
            p2 = vi[i].se.se;
            break;
        }
    }
    vector<ll> temp1 = parse(s[p1]);
    vector<ll> temp2 = parse(s[p2]);
    ans = temp1[0] * temp2[0];
    return ans;

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

    cout << solve(vi);
}