class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(st.find(target-nums[i])!=st.end()){
                vector<int> res = {mp[target-nums[i]], i};
                return res;
            }
            else st.insert(nums[i]), mp[nums[i]]=i;
        }
        return {0,0};
    }
};