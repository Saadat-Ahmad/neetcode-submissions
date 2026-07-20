class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        vector<int> ans;
        int a = 1;
        while(i >= 0){
            digits[i] = digits[i] + a;
            a = digits[i]/10;
            ans.push_back(digits[i]%10);
            if(i == 0 && a == 1) ans.push_back(1);
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
