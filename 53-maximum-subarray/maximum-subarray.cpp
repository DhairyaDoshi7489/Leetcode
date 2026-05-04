class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sm = 0, mx = INT_MIN;
        for(auto &x: nums){
            sm+=x;
            mx = max(mx,sm);
            if(sm<0)sm=0;
        }
        return mx;
    }
};