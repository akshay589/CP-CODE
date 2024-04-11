class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size(),i;
        for(i=0;i<n;i++){
            if(st.size()==0){
                st.push(num[i]);
            }
            else{
                while(k>0 && st.size()>0 && st.top()>num[i]){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            ans="0";
        }
        return ans;
    }
};