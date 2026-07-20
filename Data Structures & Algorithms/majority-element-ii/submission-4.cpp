class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = INT_MIN, n2 = INT_MIN, c1 = 0, c2 = 0;
        for(const auto& num : nums){
            if(num == n1){
                c1++;
            } else if (num == n2){
                c2++;
            } else if (c1 == 0){
                n1 = num;
                c1 = 1;
            } else if (c2 == 0){
                n2 = num;
                c2 = 1;
            } else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(const auto& num : nums){
            if(num == n1) c1++;
            if(num == n2) c2++;
        }
        int s = nums.size();
        nums = {};
        
        if(c1 > s/3) nums.push_back(n1);
        if(c2 > s/3) nums.push_back(n2);
        
        return nums;
    }
};