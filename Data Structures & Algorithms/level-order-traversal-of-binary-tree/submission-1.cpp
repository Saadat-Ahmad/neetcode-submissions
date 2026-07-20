/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> arr;
        if(!root) return res;
        deque<TreeNode*> dq;
        int count1 = 1, count2 = 0;
        dq.push_back(root);
        while(!dq.empty()){
            if(count1 == 0){
                count1 = count2;
                count2 = 0;
                res.push_back(arr);
                arr = {};
            }
            if(dq.front()->left) {dq.push_back(dq.front()->left); count2++;}
            if(dq.front()->right) {dq.push_back(dq.front()->right); count2++;}
            arr.push_back(dq.front()->val);
            dq.pop_front();
            count1--;
        }
        res.push_back(arr);
        return res;
    }
};
