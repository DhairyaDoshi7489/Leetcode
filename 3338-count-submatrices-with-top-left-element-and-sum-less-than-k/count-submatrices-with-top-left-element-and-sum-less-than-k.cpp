class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ct = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=grid[i][j]+(i?res[i-1][j]:0)+(j?res[i][j-1]:0)-((i&&j)?res[i-1][j-1]:0);
                // cout<<res[i][j]<<" ";
                if(res[i][j]<=k)ct++;
            }
            // cout<<endl;
        }
        return ct;
    }
};