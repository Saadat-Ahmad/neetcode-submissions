class Solution {
private:
    
    void permuteUtil(vector<int>& out, unordered_map<string, vector<int>>& ans, int index){
        if (index == out.size()){
            string s = "";
            for(const auto& it : out){
                s += to_string(it) + ",";
            }
            ans[s] = out;
            return;
        }
        unordered_set<int> seen;
        for(int i = 0; i < out.size(); i++){
            if(seen.count(out[i])) continue;
            seen.insert(out[i]);
            swap(out[i], out[index]);
            permuteUtil(out, ans, index+1);
            swap(out[i], out[index]);
                    
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<string, vector<int>> ans;
        vector<vector<int>> res;
        permuteUtil(nums, ans, 0);
        for(const auto& it : ans) res.push_back(it.second);
        return res;
    }
};