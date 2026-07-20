class TimeMap {
public:
    unordered_map <string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size() - 1, mid;
        string val = "";
        while(l <= r){
            mid = l + (r - l)/2;
            if(mp[key][mid].second <= timestamp){
                val = mp[key][mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return val;
    }
};