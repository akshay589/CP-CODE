class Solution {
public:
    int minSwaps(string s) {
        int i=0,sum=0,mx1=0,mx2=0,n=s.size();
        for(i=0;i<n;i++){
            if(s[i]==']'){
                sum++;
            }
            else{
                sum--;
            }
            mx1=max(mx1,sum);
        }
        sum=0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='['){
                sum++;
            }
            else{
                sum--;
            }
            mx2=max(mx2,sum);
        }
        mx1=max(mx1,mx2);
        return (mx1+1)/2;
    }
};