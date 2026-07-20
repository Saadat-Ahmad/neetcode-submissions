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
private:
    int v = INT_MIN;
    bool ans = true;
public:
    bool isValidBST(TreeNode* root) {
        if(root && ans){
            ans = isValidBST(root->left);
            if(!ans) return false;
            if(root->val <= v) return false;
            v = root->val;
            ans = isValidBST(root->right);
        }
        return ans;
    }
};
