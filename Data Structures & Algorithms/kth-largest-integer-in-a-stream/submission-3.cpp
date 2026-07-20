class KthLargest {
private:
    priority_queue<int> pq;
    int kth;
    int l;

    int findKth(){
        if(pq.empty()) return INT_MIN;
        stack<int> stk;
        for(int i = 1; i < l; i++){
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

public:
    KthLargest(int k, vector<int>& nums) {
        stack<int> stk;
        l = k;
        for(const auto& num : nums){
            pq.push(num);
        }   
        kth = findKth();
    }
    
    int add(int val) {
        if(val > kth){
            pq.push(val);
            kth = findKth();
        }
        return kth;
    }
};
