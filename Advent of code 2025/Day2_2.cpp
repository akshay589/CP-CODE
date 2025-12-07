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

vector<pair<ll, ll> > parse(string s){
    ll n = s.size(), num = 0;
    vector<pair<ll, ll> > temp;
    vector<ll> vi;
    for(int i = 0 ; i < n ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + (s[i] - '0');
        }
        else{
            vi.pb(num);
            num = 0;
        }
    }
    vi.pb(num);
    for(int i = 1 ; i < vi.size(); i += 2){
        temp.pb({vi[i - 1], vi[i]});
    }
    return temp;
}

vector<ll> init(){
    set<ll> st;
    for(ll i = 1 ; i <= 99999 ; i++){
        string s = to_string(i);
        string temp = s;
        for(ll j = 1 ; j <= 6 ; j++){
            temp += s;
            if(temp.size() > 10){
                break;
            }
            st.insert(stoll(temp));
        }
    }
    vector<ll> vi(st.begin(), st.end());
    return vi;
}

ll get(vector<ll> &vi, pair<ll, ll> p){
    ll ans = 0;
    ll idx = lower_bound(vi.begin(), vi.end(), p.ff) - vi.begin();
    while(idx < vi.size()){
        if(vi[idx] >= p.ff && vi[idx] <= p.se){
            ans += vi[idx];
        }
        if(vi[idx] > p.se){
            break;
        }
        idx++;
    }
    return ans;
}

ll solve(string s){
    vector<pair<ll, ll> > vi;
    vi = parse(s);
    vector<ll> temp = init();
    ll ans = 0;
    for(auto x : vi){
        ans += get(temp, x);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;

    cout << solve(line);
}