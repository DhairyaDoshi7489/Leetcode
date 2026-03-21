class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y;j<y+k;j++){
            int st = x, ed = x+k-1; 
            while(st<ed){
                swap(grid[st][j],grid[ed][j]);
                st++,ed--;
            }
        }
        return grid;
    }
};