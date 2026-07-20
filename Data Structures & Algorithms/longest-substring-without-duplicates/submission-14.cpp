class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, curr = 0;
        int i = 0, j = 0;
        int size = s.size();
        while(j<size){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]]+1);
            }
            mp[s[j]] = j;
            curr = j-i+1;
            ans = max(ans, curr);
            j++;
        }
        return ans;
    }
};
