class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size(),x=0,i,count=0,mx=0;
        stack<int> st;
        int vis[n];
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                if(st.size()>0){
                    if(s[st.top()]=='('){
                        vis[st.top()]=1;
                        vis[i]=1;
                        st.pop();
                    }
                }
            }
        }
        string s1="";
        for(i=0;i<n;i++){
            if(vis[i]==0){
                s1+=s[i];
            }
        }
        count=0;
        for(i=0;i<s1.size();i++){
            char x=s1[i];
            if(x=='*'){
                count++;
            }
            if(x==')'){
                count--;
                if(count<0){
                    return false;
                }
            }
        }
        count=0;
        for(i=s1.size()-1;i>=0;i--){
            char x=s1[i];
            if(x=='*'){
                count++;
            }
            if(x=='('){
                count--;
                if(count<0){
                    return false;
                }
            }
        }
        return true;
    }
};