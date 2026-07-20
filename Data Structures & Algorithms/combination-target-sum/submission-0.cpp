class Solution {
private:
    void combinationSumUtils(vector<int>& candidate, vector<int>& out, vector<vector<int>>& ans, int& target, int index, int& sum){
        if(index >= candidate.size()){
            return;
        }
        if(sum + candidate[index] == target) {
            out.push_back(candidate[index]);
            ans.push_back(out);
            out.pop_back();
        }
        else if(sum + candidate[index] < target) {
            sum += candidate[index];
            out.push_back(candidate[index]);
            combinationSumUtils(candidate, out, ans, target, index, sum);
            out.pop_back();
            sum -= candidate[index];

        }
        combinationSumUtils(candidate, out, ans, target, index+1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        int sum = 0;
        combinationSumUtils(candidates, out, ans, target, 0, sum);
        return ans;
    }
};