class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> n = nums;
        for(const auto& it: n){
            nums.push_back(it);
        }
        return nums;
    }
};