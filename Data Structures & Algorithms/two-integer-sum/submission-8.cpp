class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int size = nums.size();
        int compliment;
        for(int i = 0; i < size; i++){
            compliment = target - nums[i];
            if(hashMap.count(compliment)){
                return {hashMap[compliment], i};
            }
            hashMap[nums[i]] = i;
        }
        return {-1, -1};
        
    }
};
