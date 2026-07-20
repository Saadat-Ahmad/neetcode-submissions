class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int i, arg1, arg2;
        for(const auto& s : tokens){
            if (s == "+"){
                arg1 = stk.top();
                stk.pop();
                arg2 = stk.top();
                stk.pop();
                stk.push(arg2+arg1);
            }
            else if (s == "-"){
                arg1 = stk.top();
                stk.pop();
                arg2 = stk.top();
                stk.pop();
                stk.push(arg2-arg1);
            }
            else if (s == "*"){
                arg1 = stk.top();
                stk.pop();
                arg2 = stk.top();
                stk.pop();
                stk.push(arg2*arg1);
            }
            else if (s == "/"){
                arg1 = stk.top();
                stk.pop();
                arg2 = stk.top();
                stk.pop();
                stk.push(arg2/arg1);
            }
            else{
                i = stoi(s);
                stk.push(i);
            }
        }
        return stk.top();
    }
};