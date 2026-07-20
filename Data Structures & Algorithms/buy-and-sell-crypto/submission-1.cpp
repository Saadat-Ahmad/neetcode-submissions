class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        int lowest = prices[0];
        for(int i = 0; i < size; i++){
            profit = max(profit, prices[i]-lowest);
            lowest = min(lowest, prices[i]);
        }
        
        return profit;
    }
};
