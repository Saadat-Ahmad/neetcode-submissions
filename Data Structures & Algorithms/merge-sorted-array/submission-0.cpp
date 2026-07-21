class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> ans;
        while(i < m && j < n){
            ans.push_back(min(nums1[i], nums2[j]));
            (nums1[i] < nums2[j]) ? i++ : j++;
        }
        while(j < n){
            ans.push_back(nums2[j]);
            j++;
        } 
        while(i < m){
            ans.push_back(nums1[i]);
            i++;
        }
        nums1 = ans; 
    }
};