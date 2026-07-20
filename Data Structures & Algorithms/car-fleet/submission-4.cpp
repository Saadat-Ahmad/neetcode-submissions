class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pr; //position, speed
        int k = position.size();
        //if timex < time y && postion x > position y then x and y are in the same fleet.
        double mx = INT_MIN;
        for(int i = 0; i < position.size(); i++){
            pr.push_back({(position[i]), speed[i]});
        }
        sort(pr.rbegin(), pr.rend());
        for(auto it : pr){
            if(((double)(target - it.first) / it.second) > mx) mx = ((double)(target - it.first) / it.second);
            else k--;
        }
        return k;
    }
};
