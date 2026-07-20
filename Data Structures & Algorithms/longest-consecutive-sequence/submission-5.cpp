class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int buff = nums[0];
        int globMax = 0, currMax = 1;
        for(auto num : nums){
            if (num == buff+1){
                currMax++;
                globMax = max(globMax, currMax);
            } 
            else if(num == buff) globMax = max(globMax, currMax);
            else currMax = 1;
            buff = num;
        }
        return globMax;
    }
};
