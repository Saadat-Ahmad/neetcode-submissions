class Solution {
private:
    string s = "";
    unordered_set<string> st;
    vector<int> it;
    void util(vector<vector<int>>& ans, vector<int>& nums, int i){
        if(st.find(s) == st.end()) {
            ans.push_back(it);
            st.insert(s);
        }
        if(i == nums.size()) {        
            return;
        }
        string token = to_string(nums[i]); 
        s += token + ",";
        it.push_back(nums[i]);
        util(ans, nums, i+1);
        it.pop_back();
        s = s.substr(0, s.size() - token.size());
        s.pop_back();
        
        util(ans, nums, i+1);
    }      
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        util(ans, nums, 0);
        return ans;
    }
};
