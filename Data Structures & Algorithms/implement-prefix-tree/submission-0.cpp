class TrieNode {
public:
    char data;
    vector<TrieNode*>chr {26, nullptr};
    bool isTerminal = false;
    
    TrieNode(char c){
        data = c;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode(0);
    }
    
    void insert(string word) {
        insertUtils(root, word);
        return;
    }
    
    bool search(string word) {
        return searchUtils(root, word);
    }
    
    bool startsWith(string prefix) {
        return startWithUtils(root, prefix);
    }
private:
    bool startWithUtils(TrieNode* root, string word){
        if(word.size() == 0) return true;
        if(root->chr[word[0] - 'a'] != nullptr){
            return startWithUtils(root->chr[word[0] - 'a'], word.substr(1, word.size()-1));
        }
        return false; 
    }
    bool searchUtils(TrieNode* root, string word){
        if(word.size() == 0) return root->isTerminal;
        if(root->chr[word[0] - 'a'] != nullptr){
            return searchUtils(root->chr[word[0] - 'a'], word.substr(1, word.size()-1));
        }
        return false; 
    }
    void insertUtils(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        if(root->chr[word[0] - 'a'] != nullptr){
            insertUtils(root->chr[word[0] - 'a'], word.substr(1, word.size()-1));
        } else {
            root->chr[word[0] - 'a'] = new TrieNode(word[0]);
            insertUtils(root->chr[word[0] - 'a'], word.substr(1, word.size()-1));
        }
    }
};
