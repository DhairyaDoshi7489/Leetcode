class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        // unordered_set<int> st;
        int ct[26];
        for(int i=0;i<s.size();i++){
            memset(ct, 0, sizeof(ct));
            for(int j=i;j<s.size();j++){
                ct[s[j]-'a']++;
                // st.clear();
                bool tk = true;
                int val = -1;
                for(int k=0;k<26;k++){
                    if(ct[k]){
                        if(val!=-1){
                            if(ct[k]!=val){
                                tk = false;
                                break;
                            }
                        }
                        else val = ct[k];
                    }
                }
                if(tk)ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};