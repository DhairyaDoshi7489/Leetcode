// vector<int> st;
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++){
            int ct = __builtin_popcount(i);
            if(ct==2||ct==3||ct==5||ct==7||ct==11||ct==13||ct==17||ct==19)ans++;
        }
        return ans;
    }
};