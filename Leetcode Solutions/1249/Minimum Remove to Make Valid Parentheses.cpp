class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size(),i;
        stack<int> st;
        string s1="";
        for(i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                if(st.size()>0 && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        map<int,int> mp1;
        while(!st.empty()){
            mp1[st.top()]=1;
            st.pop();
        }
        for(i=0;i<n;i++){
            if(mp1[i]==0){
                s1+=s[i];
            }
        }
        return s1;
    }
};