struct Node{
    Node *links[26];
    bool flag = false;
    bool chk(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node *node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
};
class Trie {
private: Node* root;
public:
     
    Trie() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->chk(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->chk(word[i]))return false;
            node = node->get(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->chk(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */