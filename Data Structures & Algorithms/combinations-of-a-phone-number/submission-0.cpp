class Solution {
private:
    void comboUtils(string digits, vector<string>& ans, string& res, unordered_map<int, vector<char>>& mp, int index){
    if (digits.size() == res.size()) {
        ans.push_back(res);
        return;
    }
    for(const auto& cc : mp[digits[index]]){
            res += cc;
            comboUtils(digits, ans, res, mp, index+1);
            res.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        
        unordered_map<int, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        string res = "";

        comboUtils(digits, ans, res, mp, 0);

        return ans;
    }
};
