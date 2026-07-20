class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(const auto& n : nums){
            if(mp[n] && mp[n] == INT_MIN) continue;
            
            mp[n]++;
            if(mp[n] > nums.size()/3){
                ans.push_back(n);
                mp[n] = INT_MIN;
            } 
        }
        return ans;
    }
};