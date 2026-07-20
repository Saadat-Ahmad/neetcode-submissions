class Solution {
public:
    bool isAlphaNum(char c){
        return ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                  (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j){
            if(!isAlphaNum(s[i])){
                i++;
                continue;
            }
            if(!isAlphaNum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
