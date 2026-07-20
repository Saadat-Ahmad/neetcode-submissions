class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string cmp = to_string(s[0]);
        int ans = 0, curr = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < cmp.size(); j++){
                char c = cmp[j];
                if(c == s[i]){
                    curr = cmp.size() - j - 1;
                    cmp = cmp.substr(j+1, cmp.size()-1);
                }
            }
            curr++;
            ans = max(ans, curr);
            cmp += s[i];
        }
        return ans;
    }
};
