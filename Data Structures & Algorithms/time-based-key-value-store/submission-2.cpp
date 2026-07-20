class TimeMap {
public:
    unordered_map <string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& arr = mp[key];
        int l = 0, r = arr.size() - 1, mid;
        string val = "";
        while(l <= r){
            mid = l + (r - l)/2;
            if(arr[mid].second <= timestamp){
                val = arr[mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return val;
    }
};