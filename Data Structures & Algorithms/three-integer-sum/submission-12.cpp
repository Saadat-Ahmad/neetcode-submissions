class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0, size = nums.size(), sum = 0;
        while(i < size){
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            } 
            int k = i+1;
            int l = size -1;
            while(k < l){
                sum = nums[i] + nums[k] + nums[l];
                if(sum < 0) {
                    k++;
                }
                else if (sum > 0) {
                    l--;
                }
                else {
                    ans.push_back({nums[i], nums[k], nums[l]});
                    
                    while(k < l && nums[k+1] == nums[k]) k++;
                    while(k < l && nums[l-1] == nums[l]) l--;
                    
                    l--;
                    k++;
                }
                
            }
            i++;
        }
        return ans;
    }
};
