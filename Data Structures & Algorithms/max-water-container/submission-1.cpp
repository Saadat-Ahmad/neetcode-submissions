class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        for(int i = 0; i < heights.size(); i++){
            for(int j = heights.size() - 1; j > i; j--){
                mx = max(min(heights[i], heights[j])* (j-i), mx);        
            }
        }
        // for(int j = heights.size() - 1; j >= 0; j--){
        //     for(int i = 0; i < j; i++){
        //         mx = max(min(heights[i], heights[j])* j-i, mx);        
        //     }
        // }
        return mx;
    }

};
