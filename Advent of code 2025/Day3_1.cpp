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

int get(string s){
    int n = s.size(), i, mx = 0, mxDigit = s[n - 1] - '0';
    for(int i = n - 2 ; i >= 0 ; i--){
        mx = max(mx, (s[i] - '0') * 10 + mxDigit);
        mxDigit = max(mxDigit, s[i] - '0');
    }
    return mx;
}

int solve(vector<string> &vi){
    int sum = 0 ;
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