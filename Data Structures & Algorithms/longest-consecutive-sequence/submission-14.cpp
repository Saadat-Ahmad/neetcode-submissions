class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet (nums.begin(), nums.end());
        int lSeq = 0, cSeq = 0;
        for(const auto& num : numSet){
            int var = num;
            bool flag = (numSet.find(var-1) == numSet.end());
            cSeq = 0;
            while(flag){
                cSeq++;
                var++;
                lSeq = max(lSeq, cSeq);
                flag = (numSet.find(var) != numSet.end()); 
            }
        }
        return lSeq;
    }
};
