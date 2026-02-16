class Solution {
public:
    int reverseBits(int n) {
       int val = 0;
       for(int i=0;i<32;i++){
            if((n>>i)&1)val|=(1<<(31-i));
       } 
       return val;
    }
};