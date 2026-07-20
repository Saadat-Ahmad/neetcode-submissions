class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        deque<int> dq;
        while(x>0){
            dq.push_back(x%10);
            x = x/10;
        }
        while(dq.size() > 1){
            if(dq.front() != dq.back()) return false;
            dq.pop_front();
            dq.pop_back();
        }
        return true;
    }
};