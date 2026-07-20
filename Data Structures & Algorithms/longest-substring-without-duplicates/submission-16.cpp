class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, i = 0, size = s.size();
        for(int j = 0; j<size ; j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]]+1);
            }
            mp[s[j]] = j;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
