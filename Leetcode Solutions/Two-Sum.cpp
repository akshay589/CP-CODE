// https://leetcode.com/problems/two-sum/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp1;
        vector<int> vi;
        for(int i=0;i<nums.size();i++){
            if(mp1.find(target-nums[i])!=mp1.end()){
                vi.push_back(i);
                vi.push_back(mp1[target-nums[i]]);
                // added dev1 branch
                break;
            }
            mp1[nums[i]]=i;
        }
        return vi;
    }
};