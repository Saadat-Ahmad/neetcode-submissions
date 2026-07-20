class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Vec(26, 0), subStrVec(26, 0);
        int match = 0;
        if(s1.length()>s2.length()) return false;
        int l = 0, r = s1.size();
        for(const auto& s : s1) s1Vec[s-'a']++;
        for(int i = 0; i < r; i++) subStrVec[s2[i]-'a']++;
        for(int i = 0; i < 26; i++){
            if(s1Vec[i] == subStrVec[i]) match++;
        }
        while(r < s2.size()){
            if (match == 26) return true; 
            subStrVec[s2[r]-'a']++;
            if(s1Vec[s2[r]-'a'] == subStrVec[s2[r]-'a']) match++;
            else if(s1Vec[s2[r]-'a'] + 1 == subStrVec[s2[r]-'a']) match--;
            r++;
            
            subStrVec[s2[l]-'a']--;
            if(s1Vec[s2[l]-'a'] == subStrVec[s2[l]-'a']) match++;
            else if(s1Vec[s2[l]-'a'] - 1 == subStrVec[s2[l]-'a']) match--;
            l++;
        }
        return match==26;
    }
};