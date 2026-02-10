class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            set<int> a, b;
            for(int j=i;j<n;j++){
                if(nums[j]&1)a.insert(nums[j]);
                else b.insert(nums[j]);
                if(a.size()==b.size())ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};