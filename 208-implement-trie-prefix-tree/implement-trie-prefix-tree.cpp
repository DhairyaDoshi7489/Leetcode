class Trie {
public:
    unordered_set<string> cmp, pref; 
    Trie() {
        
    }
    
    void insert(string word) {
        cmp.insert(word);
        string res;
        for(auto &x: word){
            res.push_back(x);
            pref.insert(res);
        }
    }
    
    bool search(string word) {
        return cmp.find(word)!=cmp.end();
    }
    
    bool startsWith(string prefix) {
        return pref.find(prefix)!=pref.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */