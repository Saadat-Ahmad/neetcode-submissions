class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> chr;
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
        if(root->chr.find(word[0]) != root->chr.end()){
            return startWithUtils(root->chr[word[0]], word.substr(1, word.size()-1));
        }
        return false; 
    }
    bool searchUtils(TrieNode* root, string word){
        if(word.size() == 0) return root->isTerminal;
        if(root->chr.find(word[0]) != root->chr.end()){
            return searchUtils(root->chr[word[0]], word.substr(1, word.size()-1));
        }
        return false; 
    }
    void insertUtils(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        if(root->chr.find(word[0]) != root->chr.end()){
            insertUtils(root->chr[word[0]], word.substr(1, word.size()-1));
        } else {
            root->chr[word[0]] = new TrieNode(word[0]);
            insertUtils(root->chr[word[0]], word.substr(1, word.size()-1));
        }
    }
};
