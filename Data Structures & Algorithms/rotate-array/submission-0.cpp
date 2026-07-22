class Solution {
public:
    void rotate(vector<int>& nums, int& k) {
        int s = nums.size();
        k = k % s; 
        vector<int> buf (nums.begin(), nums.begin() + s - k);
        vector<int> ans (nums.begin() + s - k, nums.end());
        for(const auto& it : buf)
            ans.push_back(it);
        nums = ans;
    }
};