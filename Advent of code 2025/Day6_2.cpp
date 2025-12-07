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

ll get(vector<ll> vi, char symbol){
    ll sum = 0, prod = 1;
    for(auto x : vi){
        if(symbol == '+'){
            sum += x;
        }
        else{
            prod *= x;
        }
    }
    if(symbol == '+'){
        return sum;
    }
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5, m, lineCount = 0;;
    char ch[n][200000];
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin.getline(ch[i], 200000);
        
        if(strlen(ch[i]) == 0) {
            break;
        }
        lineCount++;
    }
    m = strlen(ch[0]);
    vector<ll> temp;
    char symbol = '#';
    for(int j = 0 ; j < m ; j++){
        int num = 0;
        for(int i = 0 ; i < n ; i++){
            if(ch[i][j] >= '1' && ch[i][j] <= '9'){
                num = num * 10 + (ch[i][j] - '0');
            }
            if(ch[i][j] == '*' || ch[i][j] == '+'){
                symbol = ch[i][j];
            }
        }
        if(num == 0){
            sum += get(temp, symbol);
            temp.clear();
            symbol = '#';
        }
        else{
            temp.pb(num);
        }
    }
    sum += get(temp, symbol);
    cout << sum;
}