class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> ans;
        for(const auto& num : nums){
            mp[num] = mp[num]+1;
        }
        for(const auto& kv : mp){
            buckets[kv.second].push_back(kv.first);
        }
        for (int i = nums.size(); i > 0 && k > 0; i--){
            if(buckets[i].size() == 0) continue;
            else {
                k = k - buckets[i].size();
                for(const auto& num : buckets[i]){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};
