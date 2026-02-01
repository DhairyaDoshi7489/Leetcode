class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        sort(ans.begin(),ans.end());
        return ans[0]+ans[1]+res;
    }
};