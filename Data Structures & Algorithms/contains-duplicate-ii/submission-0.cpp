class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int& k) {
        unordered_map<int, int> mp;
        int i = 1;
        for(const auto& it : nums){
            if(mp[it] != 0 && i - mp[it] <= k) 
                return true;
            mp[it] = i;
            i++;
        }
        return false;
    }
};