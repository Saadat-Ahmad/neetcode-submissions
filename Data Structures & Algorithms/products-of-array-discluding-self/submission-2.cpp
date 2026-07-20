class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fwd, rev(nums.size(), 0), res;
        int prod = nums[0];
        fwd.push_back(1);
        for(int i = 1; i < nums.size(); i++){
            fwd.push_back(prod);
            prod *= nums[i];
        }

        rev[nums.size() - 1] = 1;
        prod = nums[nums.size() - 1];
        
        for(int i = nums.size() - 2; i >= 0; i--){
            rev[i] = prod;
            prod *= nums[i];
        }
        

        for(int i = 0; i < nums.size(); i++){
            res.push_back(fwd[i] * rev[i]);
        }
        return res;
    }
};
