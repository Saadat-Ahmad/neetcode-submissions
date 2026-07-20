class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, int> mp;
        int minNum = nums[0];
        for(const auto& num : nums){
            mp[num] = 1;
            minNum = min(minNum, num);
        }
        int buff = minNum;
        int glMax = 0, cMax = 1;
        for(auto kv : mp){
            int num = kv.first;
            if(buff == num) glMax = max(glMax, cMax);
            else if(num == buff+1){
                cMax++;
                glMax = max(glMax, cMax);
            } else {
                cMax = 1;
            }
            buff = num;
        }
        return glMax;
    }
};
