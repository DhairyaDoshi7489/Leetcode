class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<long long> sm(mx+1), ct(mx+1);
        for(int i=1;i<=mx;i++){
            for(int j=i;j<=mx;j+=i){
                sm[j]+=i;
                ct[j]++;
            }
        }
        int res = 0;
        for(auto &x: nums){
            if(ct[x]==4)res+=sm[x];
        }
        return res;
    }
};