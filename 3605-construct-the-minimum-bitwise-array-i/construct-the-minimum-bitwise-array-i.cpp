class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> mnxr(1001,-1);
        for(int i=0;i<1001;i++){
            int val = i|(i+1);
            if(val<1001&&mnxr[val]==-1)mnxr[val]=i;
        }
        vector<int> res;
        for(auto &x: nums){
            res.push_back(mnxr[x]);
        }
        return res;
    }
};