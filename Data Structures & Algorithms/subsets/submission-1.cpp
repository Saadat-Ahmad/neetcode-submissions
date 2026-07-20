class Solution {
private:
    void subetsUtil(vector<int>& nums, vector<vector<int>>& ans, vector<int>& out, int index){
        if(index == nums.size()){
            ans.push_back(out);
            return;
        } 
        out.push_back(nums[index]);
        subetsUtil(nums, ans, out, index+1);
        out.pop_back();
        subetsUtil(nums, ans, out, index+1);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        
        subetsUtil(nums, ans, out, 0);
        return ans;
    }
};