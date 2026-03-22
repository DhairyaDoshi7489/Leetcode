class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(chk(mat,target))return true;
        vector<vector<int>> cp = mat;
        rotate(cp);
        while(!chk(cp, mat)){
            if(chk(cp,target))return true;
            rotate(cp);
        }
        return false;
    }
    void rotate(vector<vector<int>> &mat){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                swap(mat[i][j], mat[n-j-1][n-i-1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }
    }
    bool chk(vector<vector<int>> &a, vector<vector<int>> &b){
        // for(int i=0;i<a.size();i++){
        //     for(int j=0;j<b.size();j++){
        //         if(a[i][j]!=b[i][j])return false;
        //     }
        // }
        return a==b;
    }
};