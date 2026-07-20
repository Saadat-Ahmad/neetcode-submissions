class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int check = nums[0];
        int s = nums.size();
        for (int i = 1; i < s; i++) {
            if(check == nums[i]) return true;
            check = nums[i];
        }
        return false;
    }
};