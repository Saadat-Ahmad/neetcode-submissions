class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> result;
        vector<vector<string>> ans;
        int size = strs.size();
        for(int i = 0; i < size; i++){
            string temp = strs[i];
            vector<int> count(26, 0);
            for(auto c : temp){
                count[c-'a']++;
            }
            string out = "";
            for(auto it: count){
                out += to_string(it) += ',';
            }
            result[out].push_back(temp);
        }
        for (auto it : result){
            ans.push_back(it.second);
        }
        return ans;
    }
};
