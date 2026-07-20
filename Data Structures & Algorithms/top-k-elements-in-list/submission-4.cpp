class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minH;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(const auto& num: nums){
            mp[num]++;
        }
        for(const auto& i : mp){
            minH.push({i.second, i.first});
            if(minH.size() > k) minH.pop();
        }
        while(minH.size()>0){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};