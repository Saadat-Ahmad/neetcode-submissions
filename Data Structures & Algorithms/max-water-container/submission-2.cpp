class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int size = heights.size();
        int i = 0, j = (size - 1);
        while(i < j){
            mx = max(mx, (j - i) * min(heights[i], heights[j]));
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return mx;
    }

};
