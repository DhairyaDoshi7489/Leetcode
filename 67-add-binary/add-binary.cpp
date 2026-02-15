class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string res;
        while(i>-1&&j>-1){
            int val = c+(a[i]-'0')+(b[j]-'0');
            if(val&1)res.push_back('1');
            else res.push_back('0');
            c = (val>1);
            i--, j--;
        }
        while(i>-1){
            int val = c+(a[i]-'0');
            if(val&1)res.push_back('1');
            else res.push_back('0');
            c = (val>1);
            i--;
        }
        while(j>-1){
            int val = c+(b[j]-'0');
            if(val&1)res.push_back('1');
            else res.push_back('0');
            c = (val>1);
            j--;
        }
        if(c)res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};