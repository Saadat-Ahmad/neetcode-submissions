class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), ans = 0;
        
        vector<int> lHighest(size, 0), rHighest(size, 0);
        
        for(int i = 1; i < size; i++){
            lHighest[i] = max(lHighest[i-1], height[i-1]);
        }
        for(int i = size - 2; i >= 0; i--){
            rHighest[i] = max(rHighest[i+1], height[i+1]);
        }
        for(int i = 0; i < size; i++){
            int sum = min(rHighest[i], lHighest[i]) - height[i];
            if(sum > 0) ans += sum;
        }
        return ans;
    }
};
