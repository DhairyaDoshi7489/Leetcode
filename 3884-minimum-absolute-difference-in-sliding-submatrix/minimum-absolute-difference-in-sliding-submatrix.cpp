class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n-k+1, vector<int> (m-k+1));
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                res[i][j]=compute(i,j,k,
grid);
            }
        }
        return res;
    }
    int compute(int r, int c, int k, vector<vector<int>> &grid){
        set<int> st;
        vector<int> val;
        for(int i=r;i<r+k;i++){
            for(int j=c;j<c+k;j++){
                int x = grid[i][j];
                if(st.find(x)!=st.end())continue;
                st.insert(x), val.push_back(x);
            }
        }
        sort(val.begin(),val.end());
        int res = INT_MAX;
        if(val.size()==1)return 0;
        for(int i=1;i<val.size();i++){
            res = min(res, val[i]-val[i-1]);
        }
        return res;
    }
};