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

ll getNum(string s, int &i){
    ll num = 0;
    while(i < s.size()){
        if(s[i] != '-'){
            num = num * 10 + (s[i] - '0');
        }
        else{
            break;
        }
        i++;
    }
    return num;
}

pair<ll, ll> parse(string s){
    pair<ll, ll> p;
    int i = 0;
    p.ff = getNum(s, i);
    i++;
    p.se = getNum(s, i);
    return p;
}

int solve(vector<string> &vi1, vector<string> &vi2){
    vector<pair<ll, ll> > a;
    vector<ll> b;
    int ans = 0;
    for(auto x : vi1){
        a.pb(parse(x));
    }
    for(auto x : vi2){
        b.pb(stol(x));
    }
    for(auto num : b){
        bool flag = 0;
        for(auto p : a){
            if(p.ff <= num && num <= p.se){
                flag = 1;
            }
        }
        ans += flag;
    }
    return ans;
}

void getInput(vector<string> &vi){
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> vi1, vi2;
    getInput(vi1);
    getInput(vi2);

    cout << solve(vi1, vi2);
}