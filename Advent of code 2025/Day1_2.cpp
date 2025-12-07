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

pair<char, int> extract(string s){
    pair<char, int> p;
    p.ff = s[0];
    int num = 0;
    for(int i = 1 ; i < (int)s.size() ; i++){
        num = num * 10 + (s[i] - '0');
    }
    p.se = num;
    return p;
}

int solve(vector<string> &vi){
    int start = 50, pass = 0, num;
    for(int i = 0 ; i < (int)vi.size() ; i++){
        string s = vi[i];
        pair<char, int> p = extract(s);
        num = p.se;
        if(p.ff == 'L'){
            while(num > 0){
                if(start == 0){
                    start = 100;
                }
                start--;
                num--;
                if(start == 100){
                    start = 0;
                }
                if(start == 0){
                    pass++;
                }
            }
        }
        else{
            while(num > 0){
                if(start == 100){
                    start = 0;
                }
                start++;
                num--;
                if(start == 100){
                    start = 0;
                }
                if(start == 0){
                    pass++;
                }
            }
        }
    }
    return pass;
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