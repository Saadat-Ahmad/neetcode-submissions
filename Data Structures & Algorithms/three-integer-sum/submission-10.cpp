class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0, size = nums.size();
        
        while(i < size){
            // Skip duplicates for i
            if(i > 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            
            int k = i+1;
            int l = size - 1;
            
            while(k < l){
                int sum = nums[i] + nums[k] + nums[l];
                
                if(sum < 0) {
                    k++;
                }
                else if (sum > 0) {
                    l--;
                }
                else {
                    // Found a triplet
                    ans.push_back({nums[i], nums[k], nums[l]});
                    
                    // Skip duplicates for k and l
                    while(k < l && nums[k] == nums[k+1]) k++;
                    while(k < l && nums[l] == nums[l-1]) l--;
                    
                    // Move pointers after finding triplet
                    k++;
                    l--;
                }
            }
            i++;
        }
        return ans;
    }
};