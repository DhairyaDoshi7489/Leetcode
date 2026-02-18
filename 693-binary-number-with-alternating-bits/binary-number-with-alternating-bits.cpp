class Solution {
public:
    bool hasAlternatingBits(int n) {
        int val = n&1;
        while(n){
            if((n&1)!=val)return false;
            val^=1;
            n>>=1;
        }
        return true;
    }
};