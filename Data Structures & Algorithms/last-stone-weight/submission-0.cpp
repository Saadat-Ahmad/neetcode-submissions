class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const auto& s : stones) pq.push(s);
        int f, s;
        while(pq.size() > 1){
            f = pq.top();
            pq.pop();
            s = pq.top();
            pq.pop();
            if(f != s) pq.push(f-s);
        }
        if (pq.size() == 1) return pq.top();
        else return 0;
    }
};