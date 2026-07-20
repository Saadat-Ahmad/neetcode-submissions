class Solution {
private:
    void utils(vector<string>& res, stack<string>& stk, int i, int n, string& s){
        if(stk.size() > n*2 - i) return;
        if(i == n*2) {
            res.push_back(s);
            return;
        }
        if(stk.empty()) {
            s += "(";
            stk.push("(");
            utils(res, stk, i + 1, n, s);
            stk.pop();
            s.pop_back();    
        } else {

            // choice: (
            s += "(";
            stk.push("(");
            utils(res, stk, i + 1, n, s);
            stk.pop();
            s.pop_back();

            // choice: )
            s += ")";
            stk.pop();
            utils(res, stk, i + 1, n, s);
            stk.push(")");
            s.pop_back();

        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<string> stk;
        string s = "";
        utils(res, stk, 0, n, s);
        return res;
    }
};
