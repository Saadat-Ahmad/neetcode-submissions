class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        unordered_map <int, int> rev_mp;
        for(auto num : nums){
            if(mp.count(num)) mp[num]++;
            else mp[num] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < k; i++){
            int max = 0, ptr = 0;
            for(auto pr : mp){
                if(pr.second >= max){
                    max = pr.second;
                    ptr = pr.first;
                }
            }
            ans.push_back(ptr);
            mp[ptr] = -1;
        }

        return ans;
    }
};
