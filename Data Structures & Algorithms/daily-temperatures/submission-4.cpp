class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk; //temp, i
        vector<int> res (temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!stk.empty() && temperatures[i] > stk.top().first){
                auto pr = stk.top();
                res[pr.second] = i - pr.second;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return res;
    }
};