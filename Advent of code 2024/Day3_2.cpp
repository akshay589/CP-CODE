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



regex pattern("mul[(][0-9]{1,3}[,][0-9]{1,3}[)]");


ll solve(string s){
    vector<ll> vi;
    string s1 = "";
    for(ll i = 0 ; i < s.size() ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            s1 += s[i];
        }
        else{
            if(s1.size() > 0){
                vi.pb(stol(s1));
                s1 = "";
            }
        }
    }
    return vi[0] * 1ll * vi[1];
}

ll match(string s){
    ll ans = 0;
    sregex_iterator it(s.begin(), s.end(), pattern);
    sregex_iterator end;

    while (it != end) {
        smatch match = *it;
        string temp = match.str();
        ans += solve(temp);
        ++it;
    }
    return ans;
}

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

    string str = "";
    for(auto s : vi){
        str += s;
    }

    ll ans = 0, i;
    string _dont = "don't()", _do = "do()", _mul = "mul";
    bool enable = true;

    for(i = 0 ; i < str.size() ; i++){
        if(str.substr(i, _dont.size()) == _dont){
            enable = false;
        }
        if(str.substr(i, _do.size()) == _do){
            enable = true;
        }
        if(enable == true && str.substr(i, 3) == _mul){
            ans += match(str.substr(i, 12));
        }
    }

    cout << ans;
}