class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> chr;
    bool isTerminal = false;
    TrieNode(char c){
        data = c;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode(0);
    }
    
    void addWord(string word) {
        addWordUtil(root, word);
        return;
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
private:
    void addWordUtil(TrieNode* root, string word){
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        if(root->chr.find(word[0]) != root->chr.end()) {
            return addWordUtil(root->chr[word[0]], word.substr(1, word.size()-1));
        } else {
            root->chr[word[0]] = new TrieNode(word[0]);
            return addWordUtil(root->chr[word[0]], word.substr(1, word.size()-1));
        }
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.size() == 0) return root->isTerminal;
        if(word[0] == '.'){
            bool ans = false;
            for(const auto& r : root->chr){
                ans = searchUtil(r.second, word.substr(1, word.size()-1));
                if(ans) return true;
            }
        } else {
            if(root->chr.find(word[0]) != root->chr.end()){
                return searchUtil(root->chr[word[0]], word.substr(1, word.size()-1));
            } else {
                return false;
            }
        }
        return false;
    }
};