class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> pos, neg,ab;
        int ct = 0, b=0;
        for(auto &x: matrix){
            for(auto &y: x){
                if(y<0)ct++;
                // if(y==0)b++;
                ab.push_back(abs(y));
            }
        }
        long long sm = accumulate(ab.begin(),ab.end(),0LL);
        if(ct&1)sm-=2**min_element(ab.begin(),ab.end());
        return sm;
    }
};