class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        if(n == 1) return true;
        if(st.count(n)) return false;
        st.insert(n);
        int x;
        while(n > 0){
            x += pow(n%10, 2);
            n /= 10;
        }
        return isHappy(x);
    }
};
