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


int solve(vector<int> temp){
    int m = temp.size(), p = 0, q = 0, i;
    for(i = 0 ; i < m - 1 ; i++){
        if(temp[i] > temp[i + 1] && abs(temp[i] - temp[i + 1]) <= 3){
            p++;
        }
        if(temp[i] < temp[i + 1] && abs(temp[i] - temp[i + 1]) <= 3){
            q++;
        }
    }
    if(p + 1 == m || q + 1 == m){
        return 1;
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> vi;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        vector<int> row;
        int num;
        while (ss >> num) { 
            row.push_back(num);
        }
        vi.push_back(row);
    }
    int ans = 0, i;
    for(auto x : vi){
        if(solve(x) == 1){
            ans++;
        }
        else{
            for(int i = 0 ; i < x.size() ; i++){
                vector<int> temp;
                for(int j = 0 ; j < x.size() ; j++){
                    if(i == j){
                        continue;
                    }
                    temp.push_back(x[j]);
                }
                if(solve(temp) == 1){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}