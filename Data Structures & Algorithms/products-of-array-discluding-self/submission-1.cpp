class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zCount = 0;
        int zLoc;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zCount ++;
                zLoc = i;
            } 
            else prod *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(zCount > 1) res.push_back(0); 
            else if(zCount == 1){
                if(i == zLoc) res.push_back(prod);
                else res.push_back(0);
            }
            else res.push_back(prod/nums[i]);
        }
        return res;
    }
};
