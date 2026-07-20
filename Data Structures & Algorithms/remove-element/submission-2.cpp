class Solution {
public:
    int k = 0;
    int removeElement(vector<int>& nums, int& val) {
        for(const int& num : nums){
            if(num != val){
                nums[k] = num;
                k++;
            }
        }
        return k;
    }
};