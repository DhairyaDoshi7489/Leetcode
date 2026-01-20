class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x: nums)mp[x]++;
        for(auto &x: mp){
            if(x.second==nums.size()/2)return x.first;
        }
        return -1;
    }
};