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


ll solve(vector<vector<string> > &vi){
    int n = vi.size(), m = vi[0].size();
    ll ans = 0;
    int a[n][m];
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0 ; j < m ; j++){
            a[i][j] = stoi(vi[i][j]);
        }
    }
    for(int j = 0 ; j < m ; j++){
        ll prod = 1, sum = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            if(vi[n - 1][j] == "*"){
                prod *= a[i][j];
            }
            else{
                sum += a[i][j];
            }
        }
        if(vi[n - 1][j] == "*"){
            ans += prod;
        }
        else{
            ans += sum;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<string> > vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        vector<string> temp;
        while (ss >> s) { 
            temp.pb(s);
        }
        vi.pb(temp);
    }

    cout << solve(vi);
}