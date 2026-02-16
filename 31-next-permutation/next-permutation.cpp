class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>-1&&nums[i+1]<=nums[i])i--;
        if(i>-1){
            int j = nums.size()-1;
            while(j>-1&&nums[j]<=nums[i])j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};