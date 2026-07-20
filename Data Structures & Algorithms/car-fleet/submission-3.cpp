class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> mp; //position, time
        int k = position.size();
        double mx = INT_MIN;
        //if timex < time y && postion x > position y then x and y are in the same fleet.

        for(int i = 0; i < position.size(); i++){
            mp[target - position[i]] = ((double)(target-position[i])/speed[i]);
        }
        for(const auto& [key, val] : mp){
            if(val > mx) mx = val;
            else k--;
        }
        return k;
    }
};
