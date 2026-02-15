class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        set<pair<int,int>> st;
        for(auto &x: nums)mp[x]++;
        for(auto &x: mp)st.insert({-x.second, x.first});
        int i =0;
        auto it = st.begin();
        vector<int> res;
        while(i<k&&it!=st.end()){
            res.push_back((*it).second);
            i++, it++;
        }
        return res;
    }
};