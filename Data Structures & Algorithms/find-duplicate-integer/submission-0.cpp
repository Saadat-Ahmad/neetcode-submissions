class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto& num : nums){
            mp[num]++;
            if(mp[num] > 1) return num;
        }
        return -1;
    }
};
