class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string buffer;
        int min_length = INT_MAX;
        for (auto str: strs){
            if (str.length() < min_length){
                min_length = str.length();
                buffer = str;
            }
        }
        for(auto str: strs){
            if (buffer == "") return "";
            while (str.substr(0, min_length) != buffer.substr(0, min_length)){
                min_length--;
            }
        }
        return buffer.substr(0, min_length);
    }
};