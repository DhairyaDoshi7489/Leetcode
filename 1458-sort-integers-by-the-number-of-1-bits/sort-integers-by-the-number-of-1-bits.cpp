class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        sort(arr.begin(),arr.end(),[](int a, int b){
            if(__builtin_popcount(a)<__builtin_popcount(b))return true;
            else if(__builtin_popcount(a)==__builtin_popcount(b))return a<b;
            else return false;
        });
        return arr;
    }
};