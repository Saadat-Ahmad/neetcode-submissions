class Solution {
public:
    int k = 0;
    int removeElement(vector<int>& nums, int& val) {
        for(int num : nums){
            if(num != val){
                nums[k] = num;
                k++;
            }
        }
        return k;
    }
};