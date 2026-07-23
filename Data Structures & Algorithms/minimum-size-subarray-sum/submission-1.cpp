class Solution {
public:
    int minSubArrayLen(int& target, vector<int>& nums) {
        int l = 0, r = 0;
        int curSum = 0, ans = INT_MAX;
        while(r < nums.size()) {
            curSum += nums[r];
            r++;
            while(curSum >= target){
                ans = min(r-l, ans);
                curSum -= nums[l];
                l++;
            } 
            
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};