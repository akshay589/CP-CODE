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

ll get(string s){
    ll n = s.size(), mx = -1, i, num = 0;
    vector<ll> temp;
    priority_queue<pair<ll, ll> > pq;
    for(i = 0 ; i < n - 11 ; i++){
        pq.push({s[i] - '0', -i});
    }
    pair<ll, ll> p = pq.top();
    pq.pop();
    temp.pb(p.ff);
    mx = -p.se;
    for(i = n - 11 ; i < n ; i++){
        pq.push({s[i] - '0', -i});
        while(pq.size() > 0){
            pair<int, int> p = pq.top();
            pq.pop();
            if(-p.se > mx){
                mx = -p.se;
                temp.pb(p.ff);
                break;
            }
        }
    }
    for(auto x : temp){
        num = num * 10 + x;
    }
    return num;
}

ll solve(vector<string> &vi){
    ll sum = 0 ;
    for(auto s : vi){
        sum += get(s);
    }
    return sum;
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