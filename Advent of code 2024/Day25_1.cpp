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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<vector<string>> vi;
    vector<string> currentMatrix;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {  
            if (!currentMatrix.empty()) {
                vi.push_back(currentMatrix);
                currentMatrix.clear();
            }
        } else {
            currentMatrix.push_back(line);
        }
    }

    if (!currentMatrix.empty()) {
        vi.push_back(currentMatrix);
    }

    ll i, j, k, count, ans = 0;
    vector<vector<ll> > lock, key;

    for(auto x : vi){
        vector<ll> temp;
        if(x[0][0] == '.'){
            for(j = 0 ; j < x[0].size() ; j++){
                count = -1;
                for(i = x.size() - 1 ; i >= 0 ; i--){
                    if(x[i][j] == '#'){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                temp.pb(count);
            }
            key.pb(temp);
        }
        else{
            for(j = 0 ; j < x[0].size() ; j++){
                count = -1;
                for(i = 0 ; i < x.size() ; i++){
                    if(x[i][j] == '#'){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                temp.pb(count);
            }
            lock.pb(temp);
        }
    }

    for(i = 0 ; i < (ll) lock.size() ; i++){
        for(j = 0 ; j < (ll) key.size() ; j++){
            bool is_fit = 1;
            for(k = 0 ; k < (ll)lock[i].size() ; k++){
                if(lock[i][k] + key[j][k] >= vi[0].size() - 1){
                    is_fit = 0;
                }
            }
            ans += is_fit;
        }
    }

    cout << ans;
}