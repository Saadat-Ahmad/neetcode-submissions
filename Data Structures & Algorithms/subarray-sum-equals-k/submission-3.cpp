class Solution {
public:
    int subarraySum(vector<int>& nums, int& k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(const auto& num : nums){
            sum += num;
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};