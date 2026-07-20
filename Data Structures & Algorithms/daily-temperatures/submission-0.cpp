class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk, scndStk;
        stk.push(INT_MAX);
        vector<int> res(temperatures.size(), 0);
        int k = 0;
        for(int i = temperatures.size()-1; i >= 0; i--){
            while (stk.top() <= temperatures[i]){
                scndStk.push(stk.top());
                stk.pop();
                k++;
            }
            if(stk.top() == INT_MAX) k = 0;
            while(!scndStk.empty()){
                stk.push(scndStk.top());
                scndStk.pop();
            }
            stk.push(temperatures[i]);
            res[i] = k;
            k = 1;
        }
        return res;
    }
};