class KthLargest {
private:
    priority_queue<int> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        for(const auto& num : nums){
            pq.push(num);
        }
        kth = k;
    }
    
    int add(int val) {
        pq.push(val);
        stack<int> stk;
        for(int i = 1; i < kth; i++){
            stk.push(pq.top());
            pq.pop();
        }
        int res = pq.top();
        while(!stk.empty()){
            pq.push(stk.top());
            stk.pop();
        }
        return res;
    }
};
