class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;
        int l = 0, res = 0, maxFreq = 0;
        for(int r = 0; r < s.size(); r++){
            freqMap[s[r]]++;
            maxFreq = max(freqMap[s[r]], maxFreq);
            while(r-l+1 - maxFreq > k){
                freqMap[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;

    }
};