class Solution {
public:
    bool bSearch(vector<int> arr, int target){
        int l = 0, r = arr.size() - 1;
        while (l <= r){
            int mid = (l + r)/2;
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lR = 0, rR = m - 1;
        int l = 0, r = n - 1;
        while(lR <= rR){
            int mid =  (lR + rR)/2;
            if (matrix[mid][l] <= target && matrix[mid][r] >= target) return bSearch(matrix[mid], target);
            else if (matrix[mid][r] > target) rR = mid - 1;
            else lR = mid + 1;
        }
        return false;
    }
};