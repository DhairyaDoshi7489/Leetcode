class Solution {
public:
    // int m = 1e9+7;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long val = 1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 1));
        // vector<vector<int>> post(n, vector<int>(m, 1));
        int mod = 12345;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                pre[i][j] = val;
                val*=grid[i][j], val%=mod;
            }
        }
        val = 1;
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                pre[i][j] = (val*pre[i][j])%mod;
                val*=grid[i][j], val%=mod;
            }
        }
        return pre;
    }
};