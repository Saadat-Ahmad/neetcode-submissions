class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(const auto& it: s){
            if(it == '(' || it == '[' || it == '{') stk.push(it);
            else if (s.size() > 0 && stk.empty()) return false;
            else if((it == ')' && stk.top()  == '(') 
                || (it == ']' && stk.top()  == '[') 
                || (it == '}' && stk.top()  == '{'))stk.pop();
            else return false;
        }
        return stk.empty();
    }
};