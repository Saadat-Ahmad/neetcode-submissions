class Solution {
public:
    bool isEaten(vector<int>& piles, int h, int r){
        double hrs = 0;
        for(const auto& p : piles){
            hrs += p/r;
            if(p%r != 0) hrs++;
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = INT_MIN; 
        for(const auto& p : piles){
            mx = max(mx, p);
        }
        int minRate = mx;
        int low = 1, high = mx;
        int mid;
        while(low <= high){
            mid = (low + high)/2;
            if(isEaten(piles, h, mid)){
                minRate = min(mid, minRate);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minRate;

    }
};