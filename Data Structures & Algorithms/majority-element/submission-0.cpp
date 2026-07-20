class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int buf = 0;
        int ans = -1; 
        for(const auto& it : nums){
            mp[it]++;
            if(mp[it] > buf){
                ans = it;
                buf = mp[it];
            }
        }
        return ans;
    }
};