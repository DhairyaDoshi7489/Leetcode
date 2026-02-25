class Solution {
public:
    int binaryGap(int n) {
        int pr = -1, i = 0, res = 0;
        while(n){
            if(n&1){
                if(pr!=-1)res = max(res, i-pr);
                pr = i;            
            }
            i++;
            n>>=1;
        }
        return res;
    }
};