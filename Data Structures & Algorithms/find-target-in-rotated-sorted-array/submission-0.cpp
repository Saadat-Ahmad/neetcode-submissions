class Solution {
public:
    int startArr(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = startArr(nums);
        int mid;
        while (l <= r){
            mid = (l + r)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid -1; 
        }
        l = startArr(nums);
        r = nums.size() - 1;
        while (l <= r){
            mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid - 1; 
        }
        return -1;
    }
};