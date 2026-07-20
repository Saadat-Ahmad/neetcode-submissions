class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        unordered_map <double, vector<vector<int>>> mp;
        vector<vector<int>> ans;
        for(const auto& pt: points){
            mp[pow(pt[0], 2) + pow(pt[1], 2)].push_back(pt);
        }
        for(auto& it : mp){
            for(const auto& a : it.second){
                pq.push({it.first, a});
                if(pq.size() > k) pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};