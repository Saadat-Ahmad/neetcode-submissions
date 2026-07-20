class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1, curr = 1;
        int i = 0, j = 1;
        int size = s.size();
        if(!size) return 0;
        while(j<size){
            for(int k = i; k < j; k++){
                if(s[j] == s[k]){
                    i = k;
                    curr = j-i-1;
                }
            }
            j++;
            curr++;
            ans = max(ans, curr);
        }
        return ans;
    }
};
