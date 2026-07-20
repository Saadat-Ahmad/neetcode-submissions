class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        vector<int> lMin(size, 0), rMax(size, 0);
        lMin[0] = prices[0];
        rMax[size-1] = prices[size-1];
        for(int i = 1; i < size; i++){
            lMin[i] = min(lMin[i-1], prices[i]);
            rMax[size-1-i] = max(rMax[size-i], prices[size-i-1]);
        }
        for(int i = 0; i < size; i++){
            profit = max(profit, rMax[i]-lMin[i]);
        }
        return profit;
    }
};
