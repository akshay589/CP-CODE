#include<bits/stdc++.h>
using namespace std;
 
#define ll              int
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


class TrieNode{
public:
    TrieNode *child[26];
    int val;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        val = -1;
    };
};

class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &s, int &value){
        TrieNode *cur=root;
        for(int i = 0 ; i < s.size() ; i++){
            if(cur->child[s[i]-'a'] == NULL){
                cur->child[s[i]-'a'] = new TrieNode();
            }
            cur = cur -> child[s[i]-'a'];
        }
        if(cur->val != -1){
            cur -> val = min(cur->val , value);
        }
        else{
            cur -> val = value;
        }
    }

    int search(string &s, int idx, vector<int> &dp){
        if(idx >= (ll)s.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        TrieNode *cur = root;
        int ans=1000000000;
        for(ll i = idx ; i < s.size() ; i++){
            if(cur -> child[s[i]-'a'] == NULL){
                break;
            }
            cur = cur -> child[s[i]-'a'];
            if(cur -> val != -1){
                ans=min(ans, cur-> val + search(s, i+1,dp));
            }
        }
        dp[idx]=ans;
        return ans;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> vi, text, words;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            vi.pb(s);
        }
    }
    for(auto x : vi){
        string s = x;
        if(s.back() == ','){
            s.pop_back();
        }
        words.pb(s);
    }
    while (getline(cin, line)) {
        if (line.empty()) break; 

        stringstream ss(line);
        string s;
        while (ss >> s) { 
            text.pb(s);
        }
    }

    ll i, val = 1, count = 0;
    Trie trie;
    for(i = 0 ; i < words.size() ; i++){
        trie.insert(words[i], val);
    }

    for(i = 0 ; i < text.size() ; i++){
        string target = text[i];
        vector<int> dp(target.size()+1, -1);
        ll ans = trie.search(target,0,dp);
        if(ans != 1000000000){
            count++;
        }
    }
    cout << count;

}