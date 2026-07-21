class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int buf = INT_MIN;
        for(const auto& num : nums){
            if(buf != num){
                nums[k] = num;
                k++;
            }
            buf = num;
        }
        return k;
    }
};