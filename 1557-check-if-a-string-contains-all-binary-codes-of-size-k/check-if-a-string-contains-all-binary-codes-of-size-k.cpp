class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return false;
        int val = (1<<k);
        vector<bool> pr(val);
        int dm = 0;
        for(int i=0;i<k;i++){
            dm<<=1;
            dm|=(s[i]-'0')&1;
        }
        // cout<<dm<<endl;
        pr[dm]=true;
        val--;
        for(int i=k;i<s.size();i++){
            dm<<=1;
            dm|=(s[i]-'0');
            dm&=(1<<k)-1;
            // cout<<dm<<" ";
            if(!pr[dm])pr[dm]=true, val--;
            if(val==0)return true;
        }
        return false;
    }
};