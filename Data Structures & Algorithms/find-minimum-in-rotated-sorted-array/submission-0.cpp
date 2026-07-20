class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size()-1, mid;
        while(l <= r){
            mid = (l + r)/2;
            if(nums[mid] < nums[(mid+1)%nums.size()] 
            && nums[mid] < nums[(mid+nums.size()-1)%nums.size()]) return nums[mid];
            else if(nums[l] < nums[r]) return nums[l];
            else if(nums[l] > nums[mid]) r = mid-1;
            else  l = mid+1;
        }
        return nums[0];
    }
};